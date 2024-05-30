#include <iostream>

using namespace std;

/*

Question is to find the first and last element of an element in a sorted array
- (https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?interviewProblemRedirection=true&leftPanelTabValue=SUBMISSION)
ex -[0, 1, 1, 5], k =1  --- O/P -> 1, 2
ex -[0, 0, 1, 1, 2, 2, 2, 2], k = 2 -- O/P -> 4, 7

Method 1 is by doing 1 linear search over the array

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans;
    ans.first = -1;
    ans.second = -1;
    int count = 0;
    for (int i =0;i<n;i++){
        if (arr[i]==k){
            if (count==0){
            ans.first = i;
            count++;
            }else{
                ans.second = i;
                count++;
            }

        }
    }

    if (ans.first != -1 && ans.second==-1 ){
        ans.second = ans.first;
    }

    return ans;

}
*/

/*
Method 2 of above question

using binary search.
    - First is to find the 1st occurence (it will be in either mid or left elements to array)
    - Find the last occurence (it will be in either mid or right elements to array)


#include <bits/stdc++.h>

int firstoccurence(vector<int> arr, int size, int k){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;

    int index = -1;
    while(start<= end){
        if (k > arr[mid]){
            start = mid+1;
        }else if (k < arr[mid]){
            end = mid - 1;
        }else{
            index = mid;
            end = mid -1;
        }
        mid = (start+end)/2;
    }
    return index;
}


int lastoccurence(vector<int> arr, int size, int k){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;

    int index = -1;
    while(start<=end){
        if (k > arr[mid]){
            start = mid+1;
        }else if (k < arr[mid]){
            end = mid - 1;
        }else{
            index = mid;
            start = mid + 1;
        }
        mid = (start+end)/2;
    }
    return index;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans;
    ans.first = -1;
    ans.second = -1;
    ans.first = firstoccurence(arr, n, k);
    ans.second = lastoccurence(arr, n, k);
    return ans;

}

*/

/*
Question 2 - Find total occurence of an element in an array (use binary search not linear search)
EX - {1, 2, 3, 3, 3, 3, 7}
    total = (5-2) + 1 = 4
Ans -
total occurence = (last occurence - first occurence + 1)

*/

/*
Question 3 - Peak index in a mountain
Leetcode 852 (https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

process -

the condition of question is
arr.length >=3 && {arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] }

sol -

if arr[mid]<arr[mid+1]:
    // move right as max is in the right side
    // start = mid+1
else:
    // make that point as end point, because max is in the left of it only
    // end = mid



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;
        int mid = (start + ((end-start)/2)); // (start + mid)/2;
        while (start<end){
            if (arr[mid]<arr[mid+1]){
                start = mid+1;
            }else{
                end = mid;
            }
            mid = (start + ((end-start)/2));
        }
        return mid;
    }
};
*/

/*
Find Pivot Index of an array - Leetcode 724
Q -> an index i it's where left sum is equal to right sum
Ans -> [1, 7, 3, 6, 5, 6] --> O/P - 3(index)

Process -
-find total sum or array
- iterate through the array and check if the left side sum(store in a variable) is equal to
right side of sum
- right side sum is (totalsum-leftsum-current element)


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;

        int total_sum = 0;

        for (int i = 0; i<nums.size();i++){
            total_sum = total_sum + nums[i];
        }


        for (int i = 0; i<nums.size();i++){
            int rightsum = total_sum - leftsum - nums[i];
            if (rightsum==leftsum){
                return i;
            }
            leftsum = leftsum+nums[i];
        }

        return -1;
    }
};

*/

/*
Find Pivot Integer - Leetcode(2485)

- same logic as above just mintue conditional changes

class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = (n)*(n+1)/2;
        int leftsum = 0;

        for (int i=1;i<=n;i++){
            leftsum = leftsum + i ;
            int rightsum = total_sum - leftsum + i;
            if (leftsum == rightsum){
                return i;
            }
        }
        return -1;

    }
};




*/

