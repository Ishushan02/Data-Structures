#include <iostream>
#include <math.h>

using namespace std;
/*
int main()
{

    //  Convert Decimal to Binary

    int n = 19;
    int binary = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 2;
        binary = (digit * pow(10, i)) + binary; // cout << digit;
        n = n / 2;
        i = i + 1;
    }
    cout << binary;
    // This will print Binary numbers in opposite.
    return 0;
}

*/
/*
int main()
{

    // 2nd method to convert decimals to Binary

    int binary = 0;
    int n;
    cin >> n;
    int i = 0;
    while (n != 0)
    {
        int digit = n & 1;
        binary = (digit * pow(10, i)) + binary;
        // cout << "Digit is " << digit << " i is " << i << " and sum is " << sum << endl;

        n = n >> 1;
        i++;
    }

    cout << "The Binary of is " << binary << endl;

    // This Program is correct and output is coming correctly in online compiler
}

*/

int main()
{

    // convert negative number into binary

    // -6  --> (2'scomplement and then find its binary)
    // -6 -->{ 1's complement ---> + 1 } == 2's complement

    int n = 12;
    int i = 0;
    int binary = 0;
    int count = 0;
    int compl_num = 0;
    cout << sizeof(n) << endl;
    while (count < 4)
    {
        int digit = n & 1;
        if (n & 1)
        {
            digit = 0; // 1's complement
            compl_num = compl_num + (pow(2, i) * 0);
        }
        else
        {
            digit = 1; // 1's complement
            compl_num = compl_num + (pow(2, i) * 1);
        }

        binary = (digit * pow(10, i)) + binary;
        cout << "Digit is " << digit << " Binary is " << binary << endl;
        count = count + 1;
        n = n >> 1;
        i++;
    }

    // binary summation
    //  binary = binary + 1;

    int x = 1; // adding1
    int num = compl_num;
    i = 0;
    int result = 0;
    while (num != 0)
    {
        if (n & 1)
        {
            x = 1;
            result = (0 * pow(10, i)) + num;
        }
        else
        {
            x = 0;
            result = (1 * pow(10, i)) + num;
        }
        num = num >> 1;
        i++;
    }
    cout << "Binary is " << result;
}
