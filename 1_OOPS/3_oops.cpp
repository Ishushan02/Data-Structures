#include <iostream>
#include <vector>

using namespace std;

/*

    INHERITANCE

*/

/*

    - Child Inherits the attributes and behaviours from parent
    - Inheritance is a way to create class from existing class 
    - Use Interitance wherever there is IS-A relationship.

    Ex:- Animal Parent Class 
            - Mammal
            - Reptile
            - Bird
            So, Mammal IS A 'n Animal, Reptile IS A Animal, Bird IS A Animal

    - Mode Of Inheritance
        Signs of Diagram (+ is Public, - is Private, # is Protected)

        Direct Private is also not accessed by the derived / child classes,
        thats where the  Protected class comes in to play. So, if a attribute
        is defined as protected class by the parent class then it's still not 
        accessible by the main class but will be accessible by the child class.

    - Generally Protected type is mainly used for either Inheritance or Encapsulation.


                    Derived Class        Derived Class       Derived Class
    Base Class      Private Mode        Protected Mode        Public Mode
    Private         Not Inherited        Not Inherited        Not Inherited
    Protected        Private              Protected             Protected
    Public           Private              Protected             Public


    Types of Inheritance
     - Single Inheritance
     - Multilevel Inheritance
     - Hierarchial Inheritance
     - Multiple Inheritance
     - Hybrid Inheritance

    Syntax
    class DerivedClass : accessSpecifier BaseClass{
            // accessSpecifier is the mode in which you are inheriting {Private, Public, Protected}
    }
        
*/

class Vehicle{

    private:
        string oiltype;

    public:
        string name;
        string model;
        int noOfTyers;

    // getter for getting private Attribute
        string getoil(){
            return oiltype;
        }

    Vehicle(const string name, string model, int noOfTyers, string oilType){
        this->name = name;
        this->model = model;
        this->noOfTyers = noOfTyers;
        this->oiltype = oilType;
    }
    
    public:
        void start_engine(){
            cout << " Engine is Starting of " << name << " and model " << model << endl;
        }

        void stop_engine(){
            cout << " Engine is Stoping " << name << " and model " << model << endl;
        }

    ~Vehicle(){
        cout << " I am inside Vehicles Destructor " << endl;
    }
};

class Car: public Vehicle{

    public:
        int doors;
        int noofSeats;

    Car(const string name, string model, int noOfTyers, string oilType, int doors, int noofSeats):Vehicle(name, model, noOfTyers, oilType){
        this->doors = doors;
        this->noofSeats = noofSeats;
    }
    
    void StartAC(){
        cout <<  " AC is started of " << name << " and model " << model << endl;
    }

    ~Car(){
        cout << " I am inside Car Destructor " << endl;
    }
};

/*
class MultipleInheritance: public class1, public class2, protected class3{

};
DERIVED THE CLASS FROM MULTIPLE BASE CLASSES

// constructior
    MultipleInheritance(string attr1, int attr2, string attr3, int attr 4):class1(int at1, string at2), 
                                            class2 (int at3, string at4), class2 (int at3, string at4)

*/

/*

Similarily Multiup level Inheritance

base class {

};

derived class1:base class{
};

derived class2: class1 {

};

*/
int main(){

    Car A("MercedesAMG", "G", 5, "Petrol", 2, 2);
    A.start_engine();

    A.StartAC();

    string oilTpye = A.getoil(); // getter method for accessing private variable
    cout << " The Oil type is " << oilTpye << endl;

    A.stop_engine();


    return 0;
}

/*

                |    Derived Class        Derived Class       Derived Class
    Base Class  |    Private Mode        Protected Mode        Public Mode
    ------------|----------------------------------------------------------
    Private     |    Not Inherited        Not Inherited        Not Inherited
    Protected   |     Private              Protected             Protected
    Public      |     Private              Protected             Public

Similarily all properties follow the rule for the above Table

// Also note that the derived class destructor is called first and then later the base class

*/