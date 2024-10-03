// #include <bits/stdc++.h>
#include "bird.h"
using namespace std;

/*

Abstraction
    Under the umbrella of Abstraction everything comes (Polymorphism, Encapsulation, Inheritance every concept of OOPS.)
    - Delivering only essential details to ouside world while masking the ackground details.
    - It is a design and programming method that seperates interface from implementation
    - Let's take sort function sort(vector.being(), vctor.end()) or it also take sort(string.begin(), string.end())
        so inspite of anything given we doesn't care about internal functioning and thinks of output (sorted elements)

    - Abstract does is creates interface and on that interface and once you write the code in interface, it 

*/


void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
}
int main()
{
    // Bird *bird = new Sparrow();
    // Bird *bird = new Eagle();
    Bird *bird = new Pigeion();
    birdDoesSomething(bird);
    // interface same h but functionality alag ho skti h ya changes ho skte h humme code mai koi change nhi krna
    return 0;
}
