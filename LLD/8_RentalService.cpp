#include <iostream>
#include <unordered_set>
using namespace std;

enum class TitleType{
    DVD,
    STREAMS
};

enum class Plan{
    BASIC,
    STANDARD,
    PREMIUM
};

class MovieTitle{
public:
    string name;
    string id;
    TitleType type;
    int rentDay;
};

struct Limitations{
public:
    static int dvdDueDays(Plan p){
        switch(p){
            case Plan::BASIC : return 1;
            case Plan::STANDARD: return 5;
            case Plan::PREMIUM: return 12;
        }

        return 0;
    }

    static int streamLimit(Plan p){
        switch(p){
            case Plan::BASIC: return 1;
            case Plan::STANDARD: return 3;
            case Plan::PREMIUM: return 5;
        }
    }

};

struct Payment{
public:
    static int dvdPerRate(Plan p){
        switch(p){
            case Plan::BASIC: return 2;
            case Plan::STANDARD: return 11;
            case Plan::PREMIUM: return 30;
        }
        return 0;
    }

    static int dvdLatePenalty(int days){
        return 2 * days;
    }

    static int streamRate(Plan p){
        switch(p){
            case Plan::BASIC: return 1;
            case Plan::STANDARD: return 5;
            case Plan::PREMIUM: return 11;
        }
        return 0;
    }
};


class User{
public:
    string username;
    string name;
    Plan* plan;
    unordered_map<MovieTitle*, int> allrent;
    User(string userN, string nm, Plan* p):username(userN), name(nm), plan(p){}
};


class RentalService{
    unordered_map<MovieTitle*, int> inventory;

public:
    unordered_map<User*, bool> allUsers;

    void addMovies(MovieTitle* newMovie, int items){
        inventory[newMovie] += items;
    }

    void rentMovie(MovieTitle* movie, User* user){

        if(!inventory.count(movie)){
            cout << "We do not have this Movie "<< movie->name << " either to stream or Rent, Please come again Later. " << endl;
            return ;
        }

        int available = inventory[movie];
        if(available == 0){
            cout << "The DVD or the Streams are out of Limit, please come again later " << endl;
            return ;
        }

        user->allrent[movie] += 1;
        int cost = 0;
        Plan* p = user->plan;
        if(movie->type == TitleType::DVD){
            cost = Payment::dvdPerRate(*p);
        }else{
            cost = Payment::streamRate(*p);
        }

        cout << " Please pay the amount $"<< cost << " . Enjoy your Movie "<< endl;
    }


    void returnMovie(MovieTitle* movie, User* user, int currDay){
        if(!user->allrent.count(movie) || user->allrent[movie] == 0){
            cout << user->name << " has not rented " << movie->name << endl;
            return;
        }

        int penalty = 0;
        Plan* p = user->plan;

        if(movie->type == TitleType::DVD){
            int daysHeld = currDay - movie->rentDay;
            int overdue = daysHeld - Limitations::dvdDueDays(*p);
            if(overdue > 0){
                penalty = Payment::dvdLatePenalty(overdue);
                cout << movie->name << " is overdue by " << overdue
                    << " day(s). Penalty: $" << penalty << endl;
            }
        }

        user->allrent[movie] -= 1;
        if(user->allrent[movie] == 0){
            user->allrent.erase(movie);
        }

        inventory[movie] += 1;

        cout << movie->name << " returned successfully by " << user->name;
        if(penalty > 0){
            cout << ". Please pay penalty: $" << penalty;
        }
        cout << endl;
    }

};

int main(){
    // Create plans
    Plan basic = Plan::BASIC;
    Plan standard = Plan::STANDARD;
    Plan premium = Plan::PREMIUM;

    // Create users
    User user1("john_d", "John Doe", &basic);
    User user2("jane_s", "Jane Smith", &standard);
    User user3("bob_p", "Bob Parker", &premium);

    // Create movies (DVDs)
    MovieTitle dvd1;
    dvd1.name = "Inception";
    dvd1.id = "DVD001";
    dvd1.type = TitleType::DVD;
    dvd1.rentDay = 0;

    MovieTitle dvd2;
    dvd2.name = "The Dark Knight";
    dvd2.id = "DVD002";
    dvd2.type = TitleType::DVD;
    dvd2.rentDay = 0;

    // Create streams
    MovieTitle stream1;
    stream1.name = "Stranger Things";
    stream1.id = "STR001";
    stream1.type = TitleType::STREAMS;
    stream1.rentDay = 0;

    MovieTitle stream2;
    stream2.name = "Breaking Bad";
    stream2.id = "STR002";
    stream2.type = TitleType::STREAMS;
    stream2.rentDay = 0;

    // Setup rental service
    RentalService service;
    service.allUsers[&user1] = true;
    service.allUsers[&user2] = true;
    service.allUsers[&user3] = true;

    // Add inventory: DVDs and streams
    service.addMovies(&dvd1, 3);
    service.addMovies(&dvd2, 2);
    service.addMovies(&stream1, 5);
    service.addMovies(&stream2, 4);

    // --- Renting movies ---
    cout << "=== Renting Movies ===" << endl;
    dvd1.rentDay = 1;
    service.rentMovie(&dvd1, &user1);   // John (BASIC) rents Inception

    dvd2.rentDay = 2;
    service.rentMovie(&dvd2, &user2);   // Jane (STANDARD) rents Dark Knight

    stream1.rentDay = 1;
    service.rentMovie(&stream1, &user3); // Bob (PREMIUM) streams Stranger Things

    stream2.rentDay = 1;
    service.rentMovie(&stream2, &user1); // John (BASIC) streams Breaking Bad

    // --- Renting a movie not in inventory ---
    cout << "\n=== Renting Unavailable Movie ===" << endl;
    MovieTitle unknown;
    unknown.name = "Unknown Movie";
    unknown.id = "DVD999";
    unknown.type = TitleType::DVD;
    unknown.rentDay = 0;
    service.rentMovie(&unknown, &user1);

    // --- Returning on time (no penalty) ---
    cout << "\n=== Returning On Time ===" << endl;
    service.returnMovie(&dvd2, &user2, 5);  // Jane returns Dark Knight on day 5 (due 5, no penalty)

    // --- Returning late (penalty) ---
    cout << "\n=== Returning Late ===" << endl;
    service.returnMovie(&dvd1, &user1, 10); // John returns Inception on day 10 (due 1, overdue 8)

    // --- Returning a stream (no penalty) ---
    cout << "\n=== Returning Stream ===" << endl;
    service.returnMovie(&stream1, &user3, 15); // Bob returns Stranger Things

    // --- Returning a movie user hasn't rented ---
    cout << "\n=== Returning Non-Rented Movie ===" << endl;
    service.returnMovie(&dvd2, &user3, 10); // Bob never rented Dark Knight

    return 0;
}
