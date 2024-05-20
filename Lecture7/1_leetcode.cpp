#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

/*
int main()
{
    // Leetcode 7 - https://leetcode.com/problems/reverse-integer/
    int i = 0;
    int opposite = 0;
    int x = 654; // 2147483646
    while (x != 0)
    {
        int rem = x % 10;
        if ((opposite > (INT_MAX / 10)) || (opposite < (INT_MIN / 10)))
        {
            cout << 0;
            return 0;
        }
        opposite = rem + (opposite * 10);
        x = x / 10;
    }
    cout << opposite;
    return opposite;
}
*/

int main()
{
    // Leetcode 1009 - https://leetcode.com/problems/complement-of-base-10-integer/description/

    // Method1

    /*
    int n = 38;
    if (n == 0)
    {
        return 1;
    }

    int i = 0;
    int result = 0;
    while (n != 0)
    {
        int digit = 0;
        if (n & 1)
        {
            digit = 0;
        }
        else
        {
            digit = 1;
        }
        result = (digit * pow(2, i)) + result;
        ;
        n = n >> 1;
        i++;
    }
    return result;
    */

    // Method2
    /*
        Procedure
        INT 5 (101) --->O/P (010) 2

        (5 representation in bits) 00000......101 --> (negate) 11111......010
        We have to take only the last 3 bits which means we have to mask it.

        Masking
        if we create (MASK) --> 0000......111 (and do and operation with negation) we will get
        00000......010 (which is our answer)

        Procedure of creating a mask

        take number n
        do right shift.
        continue it till 0
        we will get number till where we have to do mask
        000....0101 >> 000....0010 >> 000....0001 >> 000....0000

        to that n right shift and do a OR operation with 1
        000....0000 | 1 --> 000.....0001 <<(left shift) 000....0010 | 1 --> 000 .....0011
        << (left shift) 000......110 | 1 -- > 000......111 (created a mask)



    */

    int n = 10;
    int mask = 0;
    int tempnum = n;
    if (n == 0)
    {
        return 1;
    }

    while (tempnum != 0)
    {
        mask = (mask << 1) | 1;
        tempnum = tempnum >> 1;
    }

    int answer = ((~n) & mask);
    return answer;
}

/*
int main(){
    // Leetcode 231 - https://leetcode.com/problems/power-of-two/description/

    int count = 0;

        while (n!=0){
            if (n&1){
                if (count > 1){
                    return false;
                }
                count = count+1;
            }
            n = n >> 1;
        }

        if (count==1){
            return true;
        }else{
            return false;
        }
    }
}
*/