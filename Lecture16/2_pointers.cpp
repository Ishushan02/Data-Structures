#include <iostream>

using namespace std;

int main()
{

    // pointer is a type of variable which store address of another variable

    int a = 5;
    int *c = &a;

    cout << " Address of a is " << &a << endl;
    cout << " Address of a is " << *c << endl;

    // 1. Pointers: Can point to different variables, can be null, support arithmetic
    // operations, and require explicit dereferencing.
    // 2. References: Must be initialized when declared, cannot be null, cannot be reassigned,
    // do not support arithmetic operations, and are automatically dereferenced.

    // pointers are always of 8Byte irrespective of which variable data type it uses.
    // because it is storing hexadecimal value of address
    // size of pointers is based on Architecture 32 bit Arch has 4 Bytes
    // and similarily 64 bit Arch has 8 Bytes

    int p = 10;
    int *q = &p;
    int *r = q; // this is how we copy pointers

    cout << " p " << p << endl;
    cout << " q " << q << endl;
    cout << " &q " << &q << endl;
    cout << " *q " << *q << endl;
    cout << " r " << r << endl;
    cout << " *r " << *r << endl;
    cout << " &r " << &q << endl;

    // let's run this same example in an Array

    // int arr[] = {1, 2, 3, 4, 5};
    // int* p = arr;
    // int* q = arr + 1;

    // cout << " arr " << arr << endl;
    // cout << " &arr " << &arr << endl;
    // cout << " arr[0] " << arr[0] << endl;
    // cout << " &arr[0] " << &arr[0] << endl;
    // cout << " p " << p << endl;
    // cout << " &p " << &p << endl;
    // cout << " *p " << *p << endl;
    // cout << " q " << q << endl;
    // cout << " &q " << &q << endl;
    // cout << " *q " << *q << endl;
    // cout << " arr " << arr << endl;
    // cout << " arr " << arr << endl;
    // cout << " &p + 1 " << &p + 1 << endl;
    // cout << " (*p) + 2 " << (*p) + 2 << endl;
    // cout << " *(p+2) " << *(p + 2) << endl;

    // Similarily with Char Array
    // char ch[10] = "RacecaR";
    // char *p = &ch;
    // char *q = &ch[0];

    // cout << " ch " << ch << endl;
    // cout << " &ch " << &ch << endl;
    // cout << " *(ch+3) " << *(ch + 3) << endl;
    // cout << " p " << p << endl;
    // cout << " *p " << *p << endl;
    // cout << " *(p+3) " << *(p + 3) << endl;
    // cout << " p+2 " << p + 2 << endl;
    // cout << " p+4 " << p + 4 << endl;

    // Void Pointers are pointers which can point to any data type.
    // Wild pointer points to non-existence address
    // A Dangling pointer is the pointer which points to memory location that has been freed

    
}