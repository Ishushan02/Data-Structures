#include <iostream>
#include <vector>

using namespace std;

/*

    CLASS, OBJECTS, ATTRIBUTES, CONSTRUCTOR, DESTRUCTOR

*/

/*

Object Oriented Programming Systems

Class - Blue PRINT
instances of class - Objects

CLass {
    Constructor // helps in creating the ojects of the class 

    attributes;
    behavious;

    Destructor // 
}


*/

class Student{
    public: // available for acces into main and other parts of the code
     
     // Attributes
     int id;
     int age;
     string name;
     int ns; // number of subjects

     // Constructor helps in creating Objects of the class
     Student(int id, int age, string name, int ns){
        cout <<" Student Default Constructor " << endl; 
        this->id = id;
        this->age = age;
        this->name = name;
        this->ns = ns;
        // Setting the parameter for this object so doin it
     }
 
     // Copy Constructor - Let's say we have to copy the attributes of Object1 to Object2,  
     Student(const Student &sourceObject){ // const means it can never be changed 
        cout <<" Student Copy Constructor " << endl; 
        this->id = sourceObject.id;
        this->age = sourceObject.age;
        this->name = sourceObject.name;
        this->ns = sourceObject.ns;
        // Settin g the parameter for this object so doin it
     }

    // Behavious / Methods / Function 
    void study(){
        cout << this->name << " Student is Studying" << endl;
    }

    // this notifies the current particular Object

    void sleep(){ 
        cout << this->name <<" Student is Sleeping" << endl;
    }


    void play(){
        cout << this->name <<" Student is Playing" << endl;
    }

    // Destructors
    ~Student(){
        cout <<" Student Default Destructor " << endl; 
     }

    // by default if constructors and Destructors are not given compiler creates a default constructor/destructor
};


int main(){

    // Student A;
    // A.id = 1;
    // A.name = "Ishan";
    // A.age = 26;
    // A.ns = 3;

    // A.sleep();
    // A.study();
    // A.play();

    Student A(1, 26, "Ishan", 3);
    A.sleep();
    A.study();
    A.play();

    Student B(2, 25, "Shiwani", 5);
    B.sleep();
    B.study();
    B.play();

    // Use of Copy COnstructor;
    Student C = A;

    cout << C.name << " " << C.age << " " << C.id << endl;
    

    // Crea ting Student via Dynamic Constructor 
    // the destructor won't be called by default, we will have to do it manually
    Student *D = new Student(3, 25, "Anand", 4);
    cout << D->age << " " << D->name << endl;
    delete D; // destructor is called



    return 0;
}