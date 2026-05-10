#include <iostream>
#include <vector>

using namespace std;
 
enum class Base { REGULAR, GLUTEN_FREE };
enum class Size { SMALL, MEDIUM, LARGE, EXTRA_LARGE };
enum class Topping { CHEESE, PEPPERONI, PINEAPPLE };
 
struct Pricing {
    static double basePrice(Base b) {
        switch (b) {
            case Base::REGULAR: return 2.00;
            case Base::GLUTEN_FREE: return 5.00;
        }
        return 0;
    }
    static double sizeMultiplier(Size s) {
        switch (s) {
            case Size::SMALL: return 1.00;
            case Size::MEDIUM: return 2.00;
            case Size::LARGE: return 4.00;
            case Size::EXTRA_LARGE: return 5.00;
        }
        return 0;
    }
    static double toppingPrice(Topping t) {
        switch (t) {
            case Topping::CHEESE: return 1.50;
            case Topping::PEPPERONI: return 2.50;
            case Topping::PINEAPPLE: return 3.50;
        }
        return 0;
    }
};
 
class Pizza {
    Base base;
    Size size;
    vector<Topping> toppings;
public:
    Pizza(Base b, Size s, vector<Topping> t = {}) : base(b), size(s), toppings(move(t)) {}
    void addTopping(Topping t) { toppings.push_back(t); }
 
    // Total = (base + sum(toppings)) * size_multiplier
    double price() const {
        double sum = Pricing::basePrice(base);
        for (auto t : toppings) sum += Pricing::toppingPrice(t);
        return sum * Pricing::sizeMultiplier(size);
    }
};
 
int main() {
    Pizza p1(Base::GLUTEN_FREE, Size::MEDIUM, {Topping::CHEESE, Topping::PINEAPPLE});
    cout << "Pizza 1: $" << p1.price() << endl;  // 20.00
 
    Pizza p2(Base::REGULAR, Size::EXTRA_LARGE, {Topping::CHEESE});
    cout << "Pizza 2: $" << p2.price() << endl;  // 17.50
}
