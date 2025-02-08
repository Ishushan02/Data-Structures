#include <iostream>

using namespace std;

int main()
{

    /*
    int a = 4;
    int b = 6;

    cout << "A AND B  " << (a && b) << endl;
    cout << "A OR B   " << (a || b) << endl;
    cout << "NOT A   " << (~a) << endl;
    cout << "A EXOR B " << (a ^ b) << endl;

    cout << endl;
    // in most of the cases the left shift operators are doubled or halved (not always)
    cout << "Left Shift " << (6 << 1) << endl;
    cout << "Left Shift " << (12 << 2) << endl;
    cout << "Right Shift " << (21 >> 1) << endl;
    cout << "Right Shift " << (12 >> 2) << endl;
    cout << endl;
    // post increment and pre increment
    int c = 4;
    int d = c++;

    cout << "c and d are " << c << " " << d << endl;

    int k1 = 5 + (d++);
    cout << "k1 and d are " << k1 << " " << d << endl;

    c = 4;
    d = ++c;

    cout << "c and d are " << c << " " << d << endl;

    k1 = 5 + (++d);
    cout << "k1 and d are " << k1 << " " << d << endl;


*/

    /*
    Fibonacci Series -- > 0, 1, 1, 2, 3, 5, 8, 13, 21, ....


    int prev = 0;
    int current = 1;
    int n = 15;
    int i = 0;

    while (i < n)
    {
        int sum = prev + current;
        cout << prev << " ";
        prev = current;
        current = sum;
        i++;
    }
,
    */

    /*
    Continue - It skips the next statement

    */

    for (int i = 0; i <= 5; i++)
    {
        cout << "hii" << endl;
        cout << "Hey" << endl;
        cout << i << endl;
        cout << endl;
        continue;
        // skipping this statement
        cout << "Reply Please" << endl;
    }
    return 0;
}