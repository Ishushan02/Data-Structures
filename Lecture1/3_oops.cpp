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
     

        
*/