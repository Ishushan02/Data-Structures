#include <iostream>

using namespace std;

/*
Get me the output of set bit of 2 given numbers. (Total number of 1's)
*/

int setbits(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count = count + 1;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{

    int a = 5; // 101
    int b = 3; // 011

    int totalsetbits = setbits(a) + setbits(b);

    cout << "Total Set bits is " << totalsetbits << endl;
}