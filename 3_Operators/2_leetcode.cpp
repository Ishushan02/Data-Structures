#include <iostream>

using namespace std;

/*
int main()
{

    // Leetcode 1281 - https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
    int n = 15;
    int digitsum = 0;
    int digitmul = 1;

    int qut = 0;
    int div = 0;
    int nextnum = n;

    while (nextnum % 10 != nextnum)
    {
        int digit = nextnum % 10;
        nextnum = nextnum / 10;

        digitmul = digitmul * digit;
        digitsum = digitsum + digit;

        cout << digit << " "
             << "-- ";
    }

    int firstdigit = nextnum % 10;
    cout << firstdigit << " "
         << "-- ";
    digitmul = digitmul * firstdigit;
    digitsum = digitsum + firstdigit;
}


*/

int main()
{
    // Leetcode 191 - https://leetcode.com/problems/number-of-1-bits/

    int n = 128;
    int digits = 0;

    while (n > 0)
    {
        if (n & 1)
        {
            digits++;
        }
        n = n >> 1;
    }
    cout << " Digits " << digits << " ";
}