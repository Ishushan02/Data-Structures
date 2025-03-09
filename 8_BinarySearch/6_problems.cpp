#include <iostream>

using namespace std;

/*

Given  a sorted array arr[] of size N, some elements of arr are
moved to either of the adjacent positions, i.e arr[i] may be
present at arr[i+1] or at arr[i-1] i.e arr[i] can only be swaped
with either arr[i+1] or arr[i-1]. The task is to search for an
element in this array.

// Inp Array arr[]={10,3,40,20,50,80,70}, key = 40
Output = 2 (index of 40)

// Inp Array arr[]={10,3,40,20,50,80,70}, key = 90
Output = -1

Search in an almost Sorted Array
(https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1)

    int findTarget(vector<int>& arr, int target) {
        // Your code here
        int start = 0;
        int n = arr.size();
        int end = n-1;
        int mid = start + (end - start)/2;
        
        while(start <= end){
            
            if(arr[mid] == target){
                return mid;
            }else if(mid-1 >= 0 && arr[mid-1] == target){
                return mid-1;
            }else if(mid + 1 < n && arr[mid+1] == target){
                return mid + 1;
            }
            
            if(target > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        
        return -1;
    }

*/


/*
    162. Find Peak Element
    (https://leetcode.com/problems/find-peak-element/ )

    int findPeakElement(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;

        while(start <= end){

            if(mid + 1 < n && nums[mid + 1] > nums[mid]){
                ans = mid + 1;
                start = mid + 1;
            }else if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
                ans = mid - 1;
                end = mid - 1;
            }else{
                return mid;
            }
            mid = start + (end - start)/2;
        }

        return ans;
    }
    
*/