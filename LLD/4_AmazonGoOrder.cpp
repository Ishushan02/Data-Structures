#include <iostream>
#include <iomanip> 

using namespace std;
 
// Catalog as a single source of truth - adding an item is one line.
enum class Item {
    COOKIES, CHIPS, PLAIN_PIZZA, COCA_COLA,
    SALAD, COFFEE, BEER, LIQUOR
};
 
struct Catalog {
    static string label(Item i) {
        static const unordered_map<int, string> m = {
            {(int)Item::COOKIES, "Cookies"}, {(int)Item::CHIPS, "Chips"},
            {(int)Item::PLAIN_PIZZA, "Plain Pizza"}, {(int)Item::COCA_COLA, "Coca-Cola"},
            {(int)Item::SALAD, "Salad"}, {(int)Item::COFFEE, "Coffee"},
            {(int)Item::BEER, "Beer"}, {(int)Item::LIQUOR, "Liquor"}
        };
        return m.at((int)i);
    }
    // Prices stored as cents (int) - never use float for money
    static int priceCents(Item i) {
        switch (i) {
            case Item::COOKIES: return 299;
            case Item::CHIPS: return 199;
            case Item::PLAIN_PIZZA: return 599;
            case Item::COCA_COLA: return 199;
            case Item::SALAD: return 499;
            case Item::COFFEE: return 299;
            case Item::BEER: return 199;
            case Item::LIQUOR: return 999;
        }
        return 0;
    }
};
 
class Order {
    vector<Item> items;
public:
    void add(Item i, int qty = 1) {
        for (int k = 0; k < qty; k++) items.push_back(i);
    }
    int totalCents() const {
        int t = 0;
        for (auto& i : items) t += Catalog::priceCents(i);
        return t;
    }
    void printReceipt() const {
        for (auto& i : items)
            cout << "  " << Catalog::label(i) << " $" << Catalog::priceCents(i)/100.0 << "\n";
        cout << "  TOTAL $" << fixed << setprecision(2) << totalCents()/100.0 << "\n";
    }
};
 
int main() {
    Order o;
    o.add(Item::COOKIES, 2);
    o.add(Item::COFFEE);
    o.add(Item::SALAD);
    o.printReceipt();
}

