#include <iostream>

using namespace std;

/*
Leetcode 35 - (https://leetcode.com/problems/search-insert-position/)


int main()
{
    int start = 0;
    int nums[2] = {1, 3};
    int end = 2 - 1;
    int target = 2;
    int mid = (start + end) / 2;
    int ans = 0;
    while (start <= end)
    {
        if (target > nums[mid])
        {
            start = mid + 1;
            ans = mid + 1;
            cout << "T>mid " << ans << nums[mid] << endl;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
            ans = mid;
            cout << "T<mid " << ans << nums[mid] << endl;
        }
        else
        {
            ans = mid;
            break;
            cout << "T=mid " << ans << nums[mid] << endl;
        }
        mid = (start + end) / 2;
    }

    cout << "Ans " << ans << endl;
    return ans;
}
*/

/*
Leetcode  - Arrange Coins (https://leetcode.com/problems/arranging-coins/submissions/1122407491/)

Proceduere

main hint is - to fill n elements in a step we would need (n*n+1)/2 elements

hence by this we can apply BS.


class Solution {
public:
    int arrangeCoins(int n) {
        long long int start = 1;
        long long int end = n;
        int ans = n;
        long long int mid = (start) + (end-start)/2;
        long long int totalelems = 0;
        while(start <= end){
            ans = mid;
            totalelems = ((mid)*(mid+1))/2;
            if (totalelems>n){
                end= mid-1;
                ans = mid-1;
            }else if (totalelems<n){
                start = mid+1;
                ans = mid;
            }else{
                ans = mid;
                break;
            }
            mid = (start) + (end-start)/2;
        }

        return ans;

    }
};

*/

/*
1539 Leetcode - Kth Missing number
(https://leetcode.com/problems/kth-missing-positive-number/)

Method 1 O(N*logn)

class Solution {
public:
    int bs(vector<int> arr, int size, int key){
        int start = 0;
        int end = size -1;
        int mid = (start+end)/2;
        while(start<=end){
            if (key>arr[mid]){
                start = mid+1;
            }else if (key<arr[mid]){
                end = mid-1;
            }else {
                return 1;
            }
            mid = (start+end)/2;
        }
        return -1;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int last = arr[size-1];
        int count  = 0;
        for (int i = 1; i<= last+k;i++){
            int ans = bs(arr, size, i);
            cout << i << ans << endl;
            if (ans == -1){
                count++ ;
            }
            if (count == k){
                return i;
            }
        }
        return 1;
    }
};



Method 2 O(N)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;
        int n = arr.size();
        int count = 0;
        int temp = k;

        while (j < n){
            if (i != arr[j]){
                count++;
                if (k==count){
                    return i;
                }
                i++;
            }else {
                i++;
                j++;
            }
        }
        return arr[n-1] + (k-count) ;



    }
};


Method 3 O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int n = arr.size();
        int i = 0;

        while (i<n && k>0){
            if (arr[i] == num){
                i++;
            }else{
                k--;
            }
            num++;
        }

        while(k){
            num++;
            k--;
        }

        return num-1;
    }
};


Methd 4 O(logn)   -- (https://www.youtube.com/watch?v=BltzCxN1vRc)

Procedure

ex -                [2,3,4,7,11], k = 5 --
missing elements    [1,1,1,3,6] // this all is at that index

k = 5, mid = 2, s = 0, end = 4
k > (4-(2+1)) --move right, s = 3, e = 4
[7,11]
k > (7 - (3+1)) --move right s = 4, e = 4
[11]
k < (11 - (4+1)) -- stop e = 3, s = 4 (s>e so stop)

ans = s+k (4+5) --> 9




class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size()-1;
        int mid = start+ (end-start)/2;

        while(start<=end){
            int missing_element = arr[mid] - (mid+1);

            if (k > missing_element){
                start = mid+1;
            }else{
                end = mid - 1;
            }
            mid = start+ (end-start)/2;
        }

        return start + k ;
    }
};

*/

/*
Leetcode(2529) Maximum count of positive integers or Negative Integers
(https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)


Method1 - O(n)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int poscnt = 0;
        int negcnt = 0;

        for(int i = 0; i<nums.size();i++){
            if (nums[i]>0){
                poscnt++;
            }else if (nums[i]<0){
                negcnt++;
            }
        }
        int ans = max(poscnt, negcnt);
        return ans;

    }
};




Method2 - O(logn)

Procedure
- n (total elements)
- get last position of negative index (l)
- get first position of positive index (f)
- return max(l-0+1, n-f)

int lastnegindex(vector<int> arr, int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    int ans = -1;
    while(start<=end){
        if (arr[mid]<key){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return ans;
}

int firstposindex(vector<int> arr, int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    int ans = -1;
    while(start<=end){
        if (arr[mid]>key){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = (start+end)/2;
    }
    return ans;
}

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lnidx = lastnegindex(nums, 0) ;
        int fpidx = firstposindex(nums, 0);
        int n = nums.size();
        if (lnidx== -1 && fpidx == -1){
            return 0;
        }else if (fpidx == -1){
            return lnidx+1;
        }else if (lnidx== -1 ){
            return n-fpidx;
        }
        else{
            int ans = max((lnidx+1), (n-fpidx));
            return ans;
        }


    }
};

*/


