#include <iostream>
using namespace std;
 
enum class SeatClass { ECONOMY, BUSINESS, FIRST };
enum class SeatStatus { AVAILABLE, RESERVED, BOOKED };
 
struct Passenger { string pid, name; };
 
struct Seat { string sid; SeatClass sclass; };
 
class Flight {
public:
    string fid, origin, dest;
    // chrono::system_clock::time_point depart;
    unordered_map<string, Seat> seats;
    unordered_map<string, SeatStatus> status;
    mutex mtx;
 
    Flight(string id, string o, string d, vector<Seat> s)
        : fid(move(id)), origin(move(o)), dest(move(d)) {
        for (auto& seat : s) {
            seats[seat.sid] = seat;
            status[seat.sid] = SeatStatus::AVAILABLE;
        }
    }
 
    vector<Seat> availableSeats(SeatClass cls) {
        vector<Seat> out;
        for (auto& [sid, st] : status)
            if (st == SeatStatus::AVAILABLE && seats[sid].sclass == cls)
                out.push_back(seats[sid]);
        return out;
    }
};
 
class Reservation {
public:
    string rid;
    Passenger* passenger;
    Flight* flight;
    Seat seat;
    string statusStr = "CONFIRMED";
};
 
class ReservationService {
    unordered_map<string, Flight*> flights;
    unordered_map<string, Reservation*> reservations;
    int ctr = 0;
public:
    void addFlight(Flight* f) { flights[f->fid] = f; }
 
    Reservation* reserve(Passenger& p, const string& fid, const string& sid) {
        Flight* f = flights[fid];
        Reservation* r;
        {
            lock_guard<mutex> lock(f->mtx);
            if (f->status[sid] != SeatStatus::AVAILABLE)
                throw runtime_error("Seat not available");
            f->status[sid] = SeatStatus::BOOKED;
            r = new Reservation{"R" + to_string(++ctr), &p, f, f->seats[sid]};
        }
        reservations[r->rid] = r;
        return r;
    }
 
    void cancel(const string& rid) {
        Reservation* r = reservations[rid];
        lock_guard<mutex> lock(r->flight->mtx);
        r->flight->status[r->seat.sid] = SeatStatus::AVAILABLE;
        r->statusStr = "CANCELLED";
    }
};


int main() {
    // --- Create seats for a flight ---
    vector<Seat> seats = {
        {"1A", SeatClass::FIRST},    {"1B", SeatClass::FIRST},
        {"2A", SeatClass::BUSINESS}, {"2B", SeatClass::BUSINESS},
        {"3A", SeatClass::ECONOMY},  {"3B", SeatClass::ECONOMY},
        {"3C", SeatClass::ECONOMY},
    };

    Flight flight1("FL100", "NYC", "LAX", seats);

    // --- Create passengers ---
    Passenger p1{"P1", "Alice"};
    Passenger p2{"P2", "Bob"};
    Passenger p3{"P3", "Charlie"};

    // --- Set up the service ---
    ReservationService service;
    service.addFlight(&flight1);

    // 1. List available seats per class
    cout << "=== Available Seats ===\n";
    for (auto cls : {SeatClass::FIRST, SeatClass::BUSINESS, SeatClass::ECONOMY}) {
        string label = (cls == SeatClass::FIRST) ? "First" :
                       (cls == SeatClass::BUSINESS) ? "Business" : "Economy";
        auto avail = flight1.availableSeats(cls);
        cout << label << ": ";
        for (auto& s : avail) cout << s.sid << " ";
        cout << "\n";
    }

    // 2. Successful reservations
    cout << "\n=== Reservations ===\n";
    Reservation* r1 = service.reserve(p1, "FL100", "1A");
    cout << r1->rid << ": " << r1->passenger->name
         << " -> seat " << r1->seat.sid << " [" << r1->statusStr << "]\n";

    Reservation* r2 = service.reserve(p2, "FL100", "3A");
    cout << r2->rid << ": " << r2->passenger->name
         << " -> seat " << r2->seat.sid << " [" << r2->statusStr << "]\n";

    // 3. Try booking an already-booked seat
    cout << "\n=== Double-booking attempt ===\n";
    try {
        service.reserve(p3, "FL100", "1A");
    } catch (const runtime_error& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // 4. Verify seat count changed
    cout << "\n=== Seats after bookings ===\n";
    auto firstAvail = flight1.availableSeats(SeatClass::FIRST);
    cout << "First class available: " << firstAvail.size() << "\n";  // expect 1

    // 5. Cancel a reservation
    cout << "\n=== Cancellation ===\n";
    service.cancel(r1->rid);
    cout << r1->rid << " status: " << r1->statusStr << "\n";

    // 6. Seat should be available again after cancellation
    firstAvail = flight1.availableSeats(SeatClass::FIRST);
    cout << "First class available after cancel: " << firstAvail.size() << "\n";  // expect 2

    // 7. Re-book the cancelled seat with a different passenger
    cout << "\n=== Re-booking cancelled seat ===\n";
    Reservation* r3 = service.reserve(p3, "FL100", "1A");
    cout << r3->rid << ": " << r3->passenger->name
         << " -> seat " << r3->seat.sid << " [" << r3->statusStr << "]\n";

    // Cleanup
    delete r1;
    delete r2;
    delete r3;

    return 0;
}
