/*

Requirements:
1. System supports three vehicle types: Motorcycle, Car, Large Vehicle
2. When a vehicle enters, system automatically assigns an available compatible spot
3. System issues a ticket at entry.
4. When a vehicle exits, user provides ticket ID
   - System validates the ticket
   - Calculates fee based on time spent (hourly, rounded up)
   - Frees the spot for next use
5. Pricing is hourly with same rate for all vehicles
6. System rejects entry if no compatible spot is available
7. System rejects exit if ticket is invalid or already used

Out of scope:
- Payment processing
- Physical gate hardware
- Security cameras or monitoring
- UI/display systems
- Reservations or pre-booking

*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <stdexcept>

using namespace std;

enum class VehicleSize {
    MOTORCYCLE,
    CAR,
    LARGE_VEHICLE
};

struct HourlyPrice {
    static int price(VehicleSize vehicle) {
        switch (vehicle) {
            case VehicleSize::CAR:           return 10;
            case VehicleSize::MOTORCYCLE:    return 7;
            case VehicleSize::LARGE_VEHICLE: return 15;
        }
        return 0;
    }
};

struct Time {
    int d;
    int m;
    int y;
    int hh;
    int mm;
    int ss;
};

double calculateHours(Time entryTime, Time exitTime) {
    auto toSeconds = [](Time t) -> long long {
        return ((long long)t.y * 365 + t.m * 30 + t.d) * 86400LL
               + t.hh * 3600 + t.mm * 60 + t.ss;
    };
    return (toSeconds(exitTime) - toSeconds(entryTime)) / 3600.0;
}

class Vehicle {
public:
    VehicleSize size;
    string VehicleId;
    Time entryTime;

    Vehicle(VehicleSize sz, string id, Time entry)
        : size(sz), VehicleId(id), entryTime(entry) {}

    string getId() { return VehicleId; }
    Time getEntryTime() { return entryTime; }
    VehicleSize getSize() { return size; }
};

struct Spot {
    string spotId;
    bool isOccupied = false;
    VehicleSize size;
    Vehicle* vehicle = nullptr;

    Spot(string id, VehicleSize sz)
        : spotId(id), size(sz) {}

    bool canPark(VehicleSize sz) {
        return !isOccupied && sz == size;
    }
};

class ParkingLot {
    vector<vector<Spot*>> allSpots;
    unordered_map<string, Spot*> vehicleSpots;
    int row;
    int col;
    int vehicleCount = 0;

public:
    ParkingLot(int row, int col) : row(row), col(col) {
        for (int i = 0; i < row; i++) {
            vector<Spot*> rowSpots;
            for (int j = 0; j < col; j++) {
                string spId = "R-" + to_string(i) + "C-" + to_string(j);

                // Row 0 = LARGE_VEHICLE, Row 1 = CAR, Row 2+ = MOTORCYCLE
                VehicleSize sz;
                if (i == 0) {
                    sz = VehicleSize::LARGE_VEHICLE;
                } else if (i == 1) {
                    sz = VehicleSize::CAR;
                } else {
                    sz = VehicleSize::MOTORCYCLE;
                }

                Spot* sp = new Spot(spId, sz);  // properly allocated
                rowSpots.push_back(sp);
            }
            allSpots.push_back(rowSpots);
        }
    }

    ~ParkingLot() {
        for (auto& rowSpots : allSpots) {
            for (auto* sp : rowSpots) {
                delete sp;
            }
        }
    }

    string getReservationId(Spot* spot, Vehicle* vehicle) {
        return spot->spotId + "XX" + vehicle->getId();
    }

    Spot* getAvailableSpot(Vehicle* vehicle) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {  // fixed loop condition
                Spot* sp = allSpots[i][j];
                if (sp->canPark(vehicle->getSize())) return sp;
            }
        }
        return nullptr;
    }

    string parking(Vehicle* vehicle) {
        if (vehicleCount == row * col) {
            throw runtime_error("No Spots Free For Parking");
        }

        Spot* freespot = getAvailableSpot(vehicle);
        if (freespot == nullptr) {
            throw runtime_error("No matching spot available for this vehicle size");
        }

        freespot->isOccupied = true;
        freespot->vehicle = vehicle;
        vehicleCount += 1;

        string reservationId = getReservationId(freespot, vehicle);
        vehicleSpots[reservationId] = freespot;
        return reservationId;
    }

    double unPark(string reservationId, Time exitTime) {
        if (vehicleSpots.find(reservationId) == vehicleSpots.end()) {
            throw runtime_error("Not a valid reservationId");
        }

        Spot* reservedSpot = vehicleSpots[reservationId];

        // Read vehicle data BEFORE clearing the pointer
        int hourlyPrice = HourlyPrice::price(reservedSpot->vehicle->getSize());
        Time entryTime = reservedSpot->vehicle->getEntryTime();

        reservedSpot->isOccupied = false;
        reservedSpot->vehicle = nullptr;
        vehicleCount -= 1;

        vehicleSpots.erase(reservationId);
        double hoursParked = calculateHours(entryTime, exitTime);

        return hoursParked * hourlyPrice;
    }
};

int main() {
    ParkingLot* parkingLot = new ParkingLot(3, 2);

    // Properly allocated Vehicle objects, each assigned to the correct variable
    Vehicle* v1 = new Vehicle(VehicleSize::CAR,
                              "BR-CAL-101",
                              Time{14, 5, 2026, 10, 45, 10});

    Vehicle* v2 = new Vehicle(VehicleSize::MOTORCYCLE,
                              "KA-SEA-105",
                              Time{14, 5, 2026, 12, 45, 10});

    Vehicle* v3 = new Vehicle(VehicleSize::LARGE_VEHICLE,
                              "BR-KA-109",
                              Time{14, 5, 2026, 9, 45, 10});

    string id1 = parkingLot->parking(v1);
    cout << "Vehicle parked and id is: " << id1 << endl;

    string id2 = parkingLot->parking(v2);
    cout << "Vehicle parked and id is: " << id2 << endl;

    string id3 = parkingLot->parking(v3);
    cout << "Vehicle parked and id is: " << id3 << endl;

    double price = parkingLot->unPark(id1, Time{14, 5, 2026, 15, 45, 10});
    cout << "The Car with Reservation: " << id1
         << " has to Pay: " << fixed << setprecision(2) << price << endl;

    Vehicle* v4 = new Vehicle(VehicleSize::MOTORCYCLE,
                              "KA-SEA-106",
                              Time{14, 5, 2026, 13, 45, 10});

    string id4 = parkingLot->parking(v4);
    cout << "Vehicle parked and id is: " << id4 << endl;
    
    Vehicle* v5 = new Vehicle(VehicleSize::MOTORCYCLE,
                              "KA-SEA-106",
                              Time{14, 5, 2026, 2, 45, 10});

    // string id5 = parkingLot->parking(v5);
    // cout << "Vehicle parked and id is: " << id5 << endl;

    // Cleanup
    delete v1;
    delete v2;
    delete v3;
    delete parkingLot;

    return 0;
}