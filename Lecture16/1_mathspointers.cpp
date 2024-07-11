#include <iostream>

/*

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


*/