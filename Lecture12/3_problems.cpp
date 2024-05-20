#include <iostream>

using namespace std;

/*
Find the Pivot element in a given array
- Here pivot means the lower or higher end of a mountain question

Ex - [7, 9, 1, 2, 3] ---> 1 is the output



// Method 1
int main()
{
    int arr[10] = {7, 1, 2, 3, 4, 5};

    int start = 0;
    int end = 10 - 1;

    int mid = (start + end) / 2;

    while (start < end)
    {
        if ((arr[mid]< arr[mid-1]) && (arr[mid]<arr[mid+1])){
            break;
        }
        else if ( arr[mid] > arr[mid + 1] )
        {
            start = mid +1;
        }
        else
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }

    cout<< "The Lower Pivot is "<< mid << endl;
}


// Method 2 this is in reference with the start element
int main()
{
    int arr[6] = {9, 11, 13, 7, 8, 10};

    int start = 0;
    int end = 5;
    int mid = (start + end) / 2;

    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    cout << "The Lower Pivot is " << start << endl;
}

*/

/*
Search in Rotated Sorted Array - (https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM)
Good Question

(mixture of lower pivot and BS)

int pivot(vector<int> arr, int n){
    int start = 0;
    int end = n-1;
    int mid = (start + ((end-start)/2));
    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = (start + ((end-start)/2));
    }
    return start;

}

int bs(vector<int> arr, int start,int end,int key){
    end = end-1;
    int mid = (start + ((end-start)/2));

    while(start<=end){
        if (key>arr[mid]){
            start = mid+1;
        }else if (key<arr[mid]){
            end = mid-1;
        }else{
            return mid;
        }
        mid = (start + ((end-start)/2));
    }

    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int pivotindex = pivot(arr, n);
    int ans = -1;
    // cout << "index is " << pivotindex << " element is "<< (arr[pivotindex]) << endl;
    ans = bs(arr, pivotindex, n, k);
    if (ans!= -1){
        return ans;
    }else{
        ans = bs(arr, 0, pivotindex, k);
    }

    return ans;
}


*/

/*
Find SQRT of a number - Leetcode 69 (only the integer part and not decimal part)

ex  n - 36
processs 1 [1, 2, 3 ......., 36]
find mid and then check
-mid*mid > n --> end = mid
-mid*mid < n --> start = mid+1
-else return mid

{comparing mid*mid > n as (mid > n/mid) because of integer overflow}


class Solution {
public:
    int mySqrt(int x) {
     if (x==0 ){
         return 0;
     }else if (x==1){
         return 1;
     }
     int start = 0;
     int end = x;
     int ans = 1;
    int mid = start+((end-start)/2);
     while (start < end){
         if (mid > x/mid){ // mid^2
             end = mid;
         }else if (mid <x/mid){
             start = mid+1;
             ans = mid;
         }else{
             ans = mid;
             break;
         }
         mid = start+((end-start)/2);

     }

    return ans;
    }
};
IMPORTANT - The space of all feasible solutions
(the set of solutions among which the desired solution resides)
 is called search space (also state space).

n = 37 ---> o/p will be 6
Let's say you also have to find the value till k digits precision.
//apply normal brute force and check

int ans = 6
int factor = 1;
for (int i =0;i<k;i++){
    factor = factor/10     // 0.1, 0.01, 0.001, 0.0001, .....
    while(True){
        ans = ans+factor;
        if (ans*ans>n){
            break;
        }
    }
}

*/

/*
Find Smallest Number greater than target - Leetcode 744
(https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int start = 0;
        char ans = letters[0];
        int end = letters.size()-1;
        int mid = (start+end)/2;

        //edge cases
        if (target=='z'){
            return letters[0];
        }else if (target>=letters[end]){
            return letters[0];
        }

        while (start<end){
            if (target< letters[mid]){
                ans = letters[mid];
                end = mid;
            }else{
                start = mid+1;
                ans = letters[start];
            }
            mid = (start+end)/2;
        }
        return ans;
    }
};



*/

/*
Find position of an element in a sorted array of infinite numbers
(https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/)

- The Solution is go in the chunks and do binary search in it.
- Increase the chunk size as 1, 2, 4, 8, 16, 32 , .... so it will be logn steps.
Ex -
{1, 2, 5, 9, 11, 16,27, 30, 35, 36, 38, 40, 42, 43, 46, 47, 49, 50, ..... }

target elem = 99

1st chunk {1} not equal create next chunk
2nd chunk {2, 5} (target >= 2 or target <= 5) not equal create next chunk
3rd chunk {9, 11, 16, 27} (target >= 9 or target <= 27) not equal create next chunk
4th chunk {30, 35, 36, 38, 40, 42, 43, 46} not equal create next chunk
5th chunk .. size 16,    6th chunk size 32

lets say if it satisfies the condtion that the target element is in 8th chunk do Binary search in 8th chunk.

*/