#include <iostream>

using namespace std;

/*

int binary_search(int arr[], int start, int end, int mid, int key, int ans)
{
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    cout << ans << " ";
    return ans;
}

int main()
{

    int arr[11] = {10, 20, 20, 30, 30, 30, 30, 40, 50, 65, 78};

    int ans = 0;
    int start = 0;
    int end = 10;
    int key = 30;

    int mid = (start + end) / 2;

    ans = binary_search(arr, start, end, mid, key, ans);
    cout << "The first Occurence is " << ans << endl;
}

*/

/*
First Occuring Element

https://www.geeksforgeeks.org/problems/first-repeating-element4018/1

// use unordered hash map

int firstRepeated(int arr[], int n) {

        unordered_map<int, int> hash;

        for(int i = 0;i<n;i++){
            hash[arr[i]]++;
        }

        for(int i = 0;i<n;i++){
            if (hash[arr[i]]>1){
                return i+1;
            }
        }
        return -1;

        // code here
    }
*/

/*
Missing Number

LeetCode 268 - https://leetcode.com/problems/missing-number/

// X_OR Method, we can do it by summation method also(sum of n numbers) or even Binary Search

int missingNumber(vector<int>& nums) {

        //X-OR Method

        int n = nums.size();
        int ans = 0 ;

        for(int i = 1;i<=n;i++){
            ans = ans ^ i;
        }


        for(int i = 0;i<n;i++){
            ans = ans ^ nums[i];
        }

        return ans;

    }


*/

// Very VERY Important

/*

//

33. Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/description/



    int bs(vector<int> nums, int start, int end, int target){
        int n = nums.size();
        int mid = (start + (end-start)/2);

        while(start <= end){
            if (target>nums[mid]){
                start = mid+1;
            }else if(target < nums[mid]){
                end = mid - 1;
            }else{
                return mid;
            }
            mid = (start + (end-start)/2);
        }
        return -1;
    }

    int find_pivot(vector<int> nums){
        int start = 0;
        int n = nums.size();
        int end = nums.size()-1;
        int mid = (start + end)/2;
        cout << "start " <<start << " mid " << mid << " end " << end << endl;
        while(start <= end){
            if ((mid+1<n) && nums[mid] > nums[mid+1] ){
                return mid;
            }else if((mid-1>=0) && nums[mid]<nums[mid-1] ){
                return mid-1;
            }else if(nums[start]>nums[mid] ){
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = (start + end)/2;
            cout << "start " <<start << " mid " << mid << " end " << end << endl;
        }

        cout << " returning pivot " << mid << endl;
        return mid;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size()==1 ){
            int ans = bs(nums, 0, nums.size()-1, target);
            return ans;
        }

        int pivot = find_pivot(nums);
        int end = nums.size()-1;

        cout << "pivot is "<< pivot << endl;
        int res = -1;
        if (target<=nums[pivot] && target >= nums[0]){
            res = bs(nums, 0, pivot, target);
        }else  {
            res = bs(nums, pivot+1, end, target);
        }


        return res;
    }

*/


/*



*/