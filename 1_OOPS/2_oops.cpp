#include <iostream>
#include <vector>

using namespace std;


/*

    ENCAPSULATION

*/

/*
    - It binds data methods in a class
    - provides secular layer
    - expose only needed information to external world
    - As we are hiding data, the word Encapsulation is also known as Data Hiding
    - The Goal of Encapsulation is in a way that it prevents unauthorized access to or 
        modification of the original contents of a class by it's instance (or objects).
        The underlying algorithm of each class may not be known to each other but they can communicate
        to each other.

    - Access Modifiers
        Public
        - members declared under Public are accessible from any point of the code.
        - They can be accessed by the objects and also the external Codes.

        Private
        - members declared as private are only accessible within the same class
        - They are not accessible from the outside class including the derived classes

        Protected
        - members declared under protected are accessible by same class and derived class as well
        - They are not directly accesible from external Code


    - SOmetimes all the attributes are private so how do we access those, we do it by getter and setter public methods
       this helps in accessing the values of them


    Class{

    // attributes
        id public
        age private
        nos public
        name private
        gf private

    // functions
        play public
        study public
        chatting private
    } 

*/

class Student {
        // Attributes
    public:
        int id;
        string name;
        int age;

    protected:  // Changing gpa and bloodgroup to protected
        int gpa;
        string blodgroup;

    public:
        void setGpa(int b){
            this->gpa = b;
        }

        int getGpa() const{
            return this->gpa;
        }

    public:
        Student(int id, string name, int age, int gpa, string bloodgroup){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gpa = gpa;
            this->blodgroup = bloodgroup; 
        }

    Student(const Student &sourceObject){ // Copy Constructor
        cout << "Student Copy Constructor" << endl; 
        this->id = sourceObject.id;
        this->age = sourceObject.age;
        this->name = sourceObject.name;
        this->gpa = sourceObject.gpa;
        this->blodgroup = sourceObject.blodgroup;
    }

    // Methods/ Functions/ Behaviours
    void study(){
        cout << this->name << " is studying " << endl;
    }

    void play(){
        cout << this->id << " is playing " << endl;
    }

private:
    void testScore(){
        cout <<" The test score of "<< this->id << " is " << this->gpa << endl;
    }

    // Destructor (commented out)
    // ~Student(){
    //     cout << " Default Destructor" << endl;
    // }
};

// Derived class
class GraduateStudent : public Student {
public:
    GraduateStudent(int id, string name, int age, int gpa, string bloodgroup)
        : Student(id, name, age, gpa, bloodgroup) {}

    void printGpaAndBloodGroup() {
        // Accessing protected variables from the base class
        cout << this->name << "'s GPA: " << this->gpa << endl;
        cout << this->name << "'s Blood Group: " << this->blodgroup << endl;
    }

    void study() {
        cout << this->name << " is studying for the thesis." << endl;
    }
};

int main() {
    GraduateStudent gs1(1, "John", 25, 3, "O+");
    gs1.study();  // Calling overridden study method
    gs1.printGpaAndBloodGroup();  // Accessing protected variables from base class
    
    return 0;
}
