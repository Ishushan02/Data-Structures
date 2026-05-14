#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include <set>
#include <deque>

using namespace std;
 
class MusicService {
    int RECENT_WINDOW = 3;
    int MIN_STREAMS = 10;
 
    unordered_set<string> loggedIn;
    unordered_map<string, deque<pair<string,string>>> recent;  // user -> last 3 (artist, genre)
    unordered_map<string, int> totalStreams;
    map<pair<string,string>, int> popularity;                  // (artist, genre) -> count
 
public:
    void login(const string& user) { loggedIn.insert(user); }
 
    void stream(const string& user, const string& artist, const string& genre) {
        if (!loggedIn.count(user)) throw runtime_error(user + " not logged in");
        auto& dq = recent[user];
        dq.push_back({artist, genre});
        if ((int)dq.size() > RECENT_WINDOW) dq.pop_front();
        totalStreams[user]++;
        popularity[{artist, genre}]++;
    }
 
    string recommend(const string& user) {
        if (totalStreams[user] < MIN_STREAMS) return "";
        auto& dq = recent[user];
        if (dq.empty()) return "";
 
        unordered_map<string,int> recentGenres, recentArtists;
        set<pair<string,string>> alreadyPlayed;
        for (auto &[a, g] : dq) {
            recentGenres[g]++; recentArtists[a]++;
            alreadyPlayed.insert({a, g});
        }
 
        pair<string,string> best;
        int bestScore = -1;
        for (auto &[key, pop] : popularity) {
            if (alreadyPlayed.count(key)) continue;
            int score = recentGenres[key.second] * 5
                      + recentArtists[key.first] * 3
                      + pop;
            if (score > bestScore) { bestScore = score; best = key; }
        }
        if (bestScore < 0) return "";
        return best.first + " (" + best.second + ")";
    }
};
 
int main() {
    MusicService svc;
    svc.login("Ishan");
    // for (int i = 0; i < 10; i++) svc.stream("alice", "Adele", i < 7 ? "Pop" : "Soul");
    svc.stream("Ishan", "Arjit", "Soul");
    svc.stream("Ishan", "Sonu", "Soul");
    svc.stream("Ishan", "ArRahman", "Sufi");
    svc.stream("Ishan", "Sonu", "Slow");
    svc.stream("Ishan", "Arjit", "Romantic");
    svc.stream("Ishan", "Arjit", "Soul");
    svc.stream("Ishan", "Sonu", "Romantic");
    svc.stream("Ishan", "Arjit", "Slow");
    svc.stream("Ishan", "Sonu", "Slow");
    svc.stream("Ishan", "Arjit", "Romantic");



    cout << svc.recommend("Ishan") << endl;
}