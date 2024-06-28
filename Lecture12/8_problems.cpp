#include <iostream>

// Mega Class Binary Search
/*
1st question is Sqrt with precision
cout only prints till 5 digits, use printf to print more digit precision

1. find precision with Normal Method as well as BS method(State Space Solution)
*/

/*
2.
Find division of 2 numbers using BS
Leetcode : 29 (https://leetcode.com/problems/divide-two-integers/)

int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long int tempdivd = abs(dividend);
        long long int tempdivs = abs(divisor);
        long long int s = 0;
        long long int e = tempdivd;
        long long int mid = (s + e)/2;
        long long  ans = 0;

        while(s <= e){

            if (mid * tempdivs == tempdivd){
                ans = mid ;
                break;
            }
            else if(tempdivs * mid > tempdivd){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid+1;
            }
            mid = (s+e)/2;
        }

        if ((dividend < 0 && divisor>0 )||( dividend > 0 && divisor < 0 )){
            return 0 - ans ;
        }

        return ans ;
    }
*/

/*
Good IMP Question (State Space Solution)
LeetCode - 875 (https://leetcode.com/problems/koko-eating-bananas/description/)


using namespace std;
class Solution {
public:
    bool check(int k, vector<int> arr, int h){
        bool ans = false;


        double totalHours = 0;
        for(int i = 0; i < arr.size(); i++){
            totalHours += ceil(arr[i]/(double)k);
        }


        return totalHours <= h;

    }



    int minEatingSpeed(vector<int>& piles, int h) {

        int ans = 0;
        int n = piles.size();
        // if(n == 1){

        //     return (int)(ceil(((float)piles[0])/((float)h))) ;
        // }

        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int mid = (s+e)/2;

        while(s<=e){
            bool totalHours = check(mid, piles, h);
            cout<< " Total Hours " << totalHours << " low "<< s << ", high "<< e <<" and k is "<< mid<< endl;
            if(totalHours){
                e = mid-1;
                ans = mid;
            }else{
                s = mid+1;

            }
            mid = (s+e)/2;

        }

        return ans;
    }
};
*/

/*
IMP Question

Leetcode 1482 (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1302069667/)


class Solution {
public:

    bool checkbloom(vector<int>& bloomDay, int m, int k, int Dday){

        int counter = 0;
        for(int i = 0;i<bloomDay.size();i++){

            // check if flower is bloomed
            if (bloomDay[i]<= Dday) counter++;

            // if k flowers are counted and bloomed then make the counter 0 again

            if(counter==k){
                m--;
                counter = 0;
                if (m==0) break;
            }

            // if it's not adjacent again start from 0 ;
            if(bloomDay[i]>Dday){
                counter = 0;
            }
        }

        if (m==0){
            return true;
        }else{
            return false;
        }
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();
        double data = (double)m * (double)k;
        if (n < data ) return -1; // not possible to bloom

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int mid = (s+e)/2;

        while(s<=e){
            bool res = checkbloom(bloomDay, m, k, mid);

            if (res){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            mid = (s+e)/2;
        }

        return ans;

    }
};


*/