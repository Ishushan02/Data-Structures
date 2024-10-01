#include <iostream>
#include <vector>

using namespace std;

/*

POLYMORPHISM

- The ability to work on different ways based on the object it is acting upon the need.
- There are 2 types of Polumorphism
    - Compile Time Polymorphism /static
        : Function Overloading
        : Operator Overloading
    - RunTime Polymorphism /dynamic

*/

/*
Function Overloading
*/

class Add{

    public:
        int sum(int x, int y){
            return x + y;
        }

        int sum(int x, int y, int z){
            return x + y + z;
        }

        double sum(double x, double y){
            return x + y;
        }
};


/*

Operator Overloading
    In C++ when functions are overloaded, they execute user defined functions whenever used allowing for customized behaviour

*/

class Complex{
    public:
        int real;
        int img;

    Complex(){
        real = img = -1;
    }

    Complex(int r, int i){
        real = r;
        img = i;
    };

    //operator overload // making a operator function in multiple ways

    Complex operator+(const Complex &B){
        Complex temp;
        temp.real = this->real + B.real;
        temp.img = this->img + B.img;

        return temp;
    }

    Complex operator-(const Complex &B){
        Complex temp;
        temp.real = this->real - B.real;
        temp.img = this->img - B.img;

        return temp;
    }

    bool operator==(const Complex &B){
        return this->real == B.real && this->img == B.img ;
    }

    void print(){
        printf("( %d + %d i ) \n", this->real, this->img);
    }

};


/*

RunTime Polymorphism

- Virtual Keyword is a way to achieve Polymorphism by deffering binding decision to runtime
- Override keyword helps to make the intention clear and allows the compiler to enforce
    overriding rules making your code safer and easier to understand.

*/

class Shape{
    public:
        virtual void drawing(){
            cout << " Generic Drawing " << endl;
        }
};

class Circle:public Shape{
    public:
         void drawing() override { // without override key word also it will execute smoothly
            cout << " Circle Drawing " << endl;
        }
};

class Rectangle:public Shape{
    public:
        void drawing() {
            cout << " Rectangle Drawing " << endl;
        }
};

void ShapeDrawing(Shape *s){
    s->drawing();
}



int main(){

    /*
    Function Overloading
    Add A;
    double a = 5, b = 6;
    cout << A.sum(1, 2) << " -- " << A.sum(1, 2, 3) << " -- "<< A.sum(a, b) << endl;
    return 0;
    */

    /*
    Operator Overloading
    Complex A(2, 5);
    A.print();
    Complex B(3, 9);
    B.print();

    Complex C = A + B;
    C.print();

    Complex D = A - B;
    D.print();

    bool val = A==B;
    cout << val << endl;
    */

   Circle c;
   ShapeDrawing(&c);
   Rectangle r;
   ShapeDrawing(&r);

    cout << "------------- Upcasting and DownCasting -------------" << endl;
   // Upcasting 
   Shape *s =  new Shape();
   s->drawing();

   Shape *s3 = new Circle();
   s3->drawing();

   // Downcasting
   Circle *s2 = new Circle();
   s2->drawing();

   Shape *s4 = new Shape();
   Circle *c3 = (Circle *)s4;
   c3->drawing();

   /*
   Final Keyword, in C++ Final keyword is used in two main contexts: with classes and with virtual member
    - When you inherit class as final it means that no other class can inherit from it
    - The final keyword is also used in virtual functions to prevent them from being overridden from derived classes
   
   */

}