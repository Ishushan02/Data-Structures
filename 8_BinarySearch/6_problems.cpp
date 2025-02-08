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
        int end = arr.size() - 1;
        int mid = (start + end)/2;
        
        int ans = -1;
        while(start <= end){
            if(target == arr[mid]){
                ans= mid;
                break;
            }else if(target > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            
            if(mid -1>=0 && arr[mid-1] == target){
                ans = mid - 1;
                break;
            }
            if(mid +1 < arr.size() && arr[mid+1] == target){
                ans = mid + 1;
                break;
            }
            
            mid = (start + end)/2;
        }
        
        return ans;
    }

*/


/*
    162. Find Peak Element
    (https://leetcode.com/problems/find-peak-element/ )

    int findPeakElement(vector<int>& nums) {
        // Remeber we have to return Local Maxima and not Global MAxima
        int ans = -1;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(start == end){
                return mid;
            }
            if(mid-1 >= 0 && mid + 1<n && nums[mid] > nums[mid-1] && nums[mid+1] < nums[mid]){
                ans = mid;
                break;
                // return mid;
            }else if(mid-1 >= 0 && nums[mid-1] > nums[mid]){
                end = mid - 1;
            }else if(mid + 1 < n && nums[mid] < nums[mid+1]){
                start = mid + 1;
            }else if(mid+ 1 >= n){
                start = mid ;
            }else if(mid -1 < 0){
                end = mid ;
            }
            mid = (start + end)/2;

        }
        return ans;
    }
    
*/