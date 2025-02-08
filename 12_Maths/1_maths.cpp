#include <iostream>

/*

IMP Question

204. Count Primes (https://leetcode.com/problems/count-primes/)

Method 1 - TIME LIMIT EXCEEDED (Brute Force Approach)

class Solution {
public:

    int checkPrime(int num){

        for(int j = 2; j < num ; j++){
            if (num % j == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {

        int ans = 0;

        // bool p = checkPrime(100);
        // cout << p << endl;
        for(int i = 2;i<n;i++){
            if (checkPrime(i)){
                ans += 1;
            }
        }
        return ans;
    }
};

Method 2 - SQRT Approach TIME LIMIT EXCEEDED (SQRT Approach)

if there exist a factor then (n = a * b which means  (n = sqrt(n) * sqrt(n)))
so atleast 1 factor will be between 2 and sqrt(n)

class Solution {
public:

    int checkPrime(int num){
        int k = sqrt(num);
        for(int j = 2; j <= k ; j++){
            if (num % j == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {

        int ans = 0;

        // bool p = checkPrime(100);
        // cout << p << endl;
        for(int i = 2;i<n;i++){
            if (checkPrime(i)){
                ans += 1;
            }
        }
        return ans;
    }
};


Method 3 - Solution Accepted
(Sieve Eratosthenes Theorem)

if n = 10
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{F, F, T, T, T, T, T, T, T, T}
 i = 2 Mark F (4, 6, 8, 10)
 i = 3 Mark F (6, 9)
 i = 4 Mark F (8)
 i = 5 Mark F (10)


class Solution {
public:
    int countPrimes(int n) {

        if (n == 0) return 0;
        int ans = 0;
        vector<bool> primenumbers(n, true);

        primenumbers[0] = primenumbers[1] = true;

        for(int i = 2;i < n;i++){

            if (primenumbers[i]){
                ans += 1;
                int j = 2 * i;
                while(j < n){
                    primenumbers[j] = false;
                    j = j + i;
                }
            }
        }

        return ans;
    }

};

Time complexity of method 3
N * (n/2 + n/3 + n / 4+ n/5 + .... )
N * (logn(logn)) [ Tailor Series ]


*/

/*

Optimization of Sieve Eratosthenes Theorem

OPTIMIZATION 1.

when i = 2 we use to mark --> 4, 6, 8, 10, 12, 14, 16, 18, 20, 22 ...
when i = 3 we use to mark --> 6, 9, 12, 15, 18, 21 ...
when i = 4 we use to mark --> 8, 12, 16, 20, 24 ...
when i = 5 we use to mark --> 10, 15, 20, 25 ...

see in 3 (we are marking again 6, 12, 18 ..etc )
..  in 4 (we are marking again 8, 12, 16 ..etc )
..  in 5 (we are marking again 10, 15, 20 ..etc )

so to remove the marking again we will start our marking from i*i and not 2 * i;
because if we see before that all would have been marked so now,

marking from i * i
when i = 2 we use to mark --> 4, 6, 8, 10, 12, 14, 16, 18, 20, 22 ...
when i = 3 we use to mark --> 9, 12, 15, 18, 21 ...
when i = 4 we use to mark --> 16, 20, 24 ...
when i = 5 we use to mark --> 25, 30,  ...

OPTIMIZATION 2.
Go till sqrt(n) instead of n

class Solution {
public:
    int countPrimes(int n) {

        if (n == 0) return 0;
        int ans = 0;
        vector<bool> primenumbers(n, true);

        primenumbers[0] = primenumbers[1] = true;

        for(int i = 2;i < sqrt(n);i++){

            if (primenumbers[i]){
                ans += 1;
                int j = i * i;
                while(j < n){
                    primenumbers[j] = false;
                    j = j + i;
                }
            }
        }

        return ans;
    }

};



Method 3
Given 2 integers L ,...... R (L and R), find all the primes in between L and R

// In any array the max size of creating arry type of

// int, double, char array with limit of 10^6 size
// bool array with limit of 10^7 size
// Global Array of int, double, char array with limit of 10^6 size
// Global Array of bool  with limit of 10^6 size



*/

/*

GCD(a, b) = GCD(a - b, b) if a > b
            GCD(b - a, a) if b > a

(or)

GCD(a, b) = GCD(a % b, b) if a > b
            GCD(b % a, a) if b > a

Method 1 is better as modulous operator is very costly

GCD of 2 Numbers (https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1)
class Solution {
  public:
    int gcd(int a, int b) {
        // code here

        if (a == 0){
            return b;
        }else if (b == 0){
            return a;
        }

        while(a > 0 && b > 0){
            if ( a > b){
                a = a - b;
            }else{
                b = b - a;
            }
        }

        return a == 0 ? b:a;
    }
};

*/

/*

LCM(a, b)

LCM(a, b) * HCF(a, b) = a * b ;

so you know optimal way of finding FCF/GCD hence you can find LCM as well.

LCM(a,b) = (a*b)/GCD(a,b)

*/

/*

Fast Exponential
IMP Question - if required Learn the Code

int power(int a, int b){

    int ans = 1;
    while(b > 0){

        if (b & 1) {// odd
            ans = ans * a ;
        }

        a = a * a ;
        b = b >> 1; // b/2
    }
    return ans;

}

Time Complexity is O(logb)

*/

/*

Modular Exponentiation for large numbers
(https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1)

IMP Question
class Solution
{
    public:
        long long int PowMod(long long int x,long long int n,long long int M)
        {
            // Code here
            long long int ans = 1;

            while(n > 0){
                if (n & 1){
                    ans = (ans * x) % M; // we are doing this because product might be too large
                }
                x = (x * x) % M;  // we are doing this because product might be too large
                n = n >> 1;

            }

            return ans % M;

        }
};

*/

/*

IMP CP Level Maths Concept
1. Pigeon Hole
2. Catalan Number (BST)
3. Inclusion-Exclusion Principle
4. Chinese Reminder Theorem
5. Lucas Theorem
6. Fermat's Theorem
7. Probability Concept

*/