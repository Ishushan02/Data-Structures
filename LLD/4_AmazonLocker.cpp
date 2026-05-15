#include <iostream>
#include <map>

using namespace std;
 
enum class Size { SMALL = 1, MEDIUM = 2, LARGE = 3, XLARGE = 4 };
 
struct Package {
    string pid;
    Size size;
};
 
struct Locker {
    string lid;
    Size size;
    bool isOccupied = false;
    Package* pkg = nullptr;
 
    bool canHold(const Package& p) const {
        return !isOccupied && (int)size >= (int)p.size;
    }
};
 
class PickupLocation {
    unordered_map<string, Locker*> lockers;
    // size -> min-heap of locker IDs (lex smallest first)
    map<int, priority_queue<string, vector<string>, greater<string>>> availableBySize;
 
public:
    PickupLocation(vector<Locker*> lks) {
        for (auto* l : lks) {
            lockers[l->lid] = l;
            availableBySize[(int)l->size].push(l->lid);
        }
    }
 
    Locker* assign(Package& p) {
        // best-fit: smallest size that fits
        for (int s = (int)p.size; s <= (int)Size::XLARGE; s++) {
            auto& heap = availableBySize[s];
            while (!heap.empty()) {
                string lid = heap.top(); heap.pop();
                Locker* l = lockers[lid];
                if (!l->isOccupied) {
                    l->isOccupied = true;
                    l->pkg = &p;
                    return l;
                }
            }
        }
        return nullptr;
    }
 
    void release(const string& lid) {
        Locker* l = lockers[lid];
        l->isOccupied = false;
        l->pkg = nullptr;
        availableBySize[(int)l->size].push(lid);
    }
};
 
int main() {
    Locker l1{"L1", Size::SMALL}, l2{"L2", Size::MEDIUM},
           l3{"L3", Size::LARGE}, l4{"L4", Size::XLARGE};
    PickupLocation loc({&l1, &l2, &l3, &l4});
 
    Package pkg{"PKG-01", Size::MEDIUM};
    Locker* assigned = loc.assign(pkg);
    cout << "Assigned to " << assigned->lid << endl;  // L2 (best-fit)
}
