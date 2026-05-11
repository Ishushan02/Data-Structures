#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Movie {
    string title;
    int year, month, day;
    int toDays() const { return year * 365 + month * 31 + day; }
};

vector<Movie> movies;

void addMovie(string title, int y, int m, int d) {
    movies.push_back({title, y, m, d});
}

Movie* findClosest(int y, int m, int d) {
    int target = y * 365 + m * 31 + d;
    Movie* best = nullptr;
    for (auto& mv : movies)
        if (!best || abs(mv.toDays() - target) < abs(best->toDays() - target))
            best = &mv;
    return best;
}

int main() {
    addMovie("The Godfather", 1972, 3, 14);
    addMovie("Apollo 13", 1995, 6, 30);

    cout << findClosest(1972, 3, 14)->title << endl;  // The Godfather
    cout << findClosest(1995, 10, 18)->title << endl;  // Apollo 13
}