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

// Search Space Solution

// https://leetcode.com/problems/divide-two-integers/

// The only question is why  isn't abs(-2147483648) not working in C++


int divide(int dividend, int divisor) {

        int tempdivd = abs(dividend);
        int tempdivs = abs(divisor);
        int s = 0;
        int e = tempdivd;
        int mid = (s + e)/2;
        int ans = 0;

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

Nearly Sorted Array
Solve in O(logn)

Given a Sorted array arr[] of SIze N, some elements of Array are 
moved to eitgher of the adjacent positions, i.e, arr[i] may be
present at arr[i+1] or arr[i-1], i.e arr[i] can only be swapped
with either arr[i+1] or arr[i-1]. The task is to search for an 
element in this array.

Inp - {10, 3, 40, 20,  50, 80, 70}; Key = 40 Output is 2  .
Inp - {10, 3, 40, 20,  50, 80, 70}; Key = 40 Output is -1 .


int main(){
    int arr[] =  {10, 3, 40, 20,  50, 80, 70};
    int n = 7;
    int s = 0;
    int e = 6;
    int mid = (s+e)/2;
    int target = 70;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == target){
            ans = mid;
            break;
        }
        if(mid -1 >= 0 && arr[mid-1] == target){
            ans = mid-1;
            break;
        }
        if(mid+1 < n && arr[mid+1] == target){
            cout << mid << endl;
            ans = mid+1;
            break;
        }

        if (target > arr[mid]){
            s = mid+1;
        }else if (target < arr[mid]){
            e = mid - 1;
        }

        mid = (s+e)/2;

    }

    cout << "The key ans is " << ans;
}

*/ 

/*
GOOD Question

540. Single Element in a Sorted Array

// It can work simply by EX-OR Method solve it using O(logn) time complexity
 
https://leetcode.com/problems/single-element-in-a-sorted-array/description/


Logic

(Movement)
- If the pair starts at even index than the answer is in right, because
it is correct format and no single element is present in prior to them
- If pair starts at odd index the answer is in left

- (To find which index is the answer)
- if start = end and only one element is left that is the answer return it
- if arr[mid]!= arr[mid-1] and arr[mid]!=arr[mid+1] prior elements are not equal then return arr[mid];
- Let's say at the end 2 elements are left [2, 3] (Ans is 2) how do we find that index,
store that ans in even part of condition where arr[mid]!= arr[mid+1]

int singleNonDuplicate(vector<int>& nums) {
     
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int mid = (s+e)/2;
        int ans = -1;

        while(s<=e){
            if (s==e){
                ans = nums[mid];
                return nums[mid];
            }
            if (mid-1>=0 && nums[mid] != nums[mid-1] && mid+1<n && nums[mid]!= nums[mid+1]){
                ans = nums[mid];
                return nums[mid];
            }

           if (mid%2==0){
                if (mid+1 < n && nums[mid]==nums[mid+1]){
                    s = mid+1;
                }else{
                    ans = nums[mid];
                    e = mid - 1;
                }
           }else{
                if (mid-1 >=0 && nums[mid]==nums[mid-1]){
                    s = mid+1;
                }else{
                    e = mid - 1;
                }

           }


            mid = (s+e)/2;
        }
        return ans;
    }


*/


/*
Odd Occuring ELements
- All element occurs even number of times except one
- Elements repeats itself in pair
- no pair repeat itself in a single stretch
- find element that occur odd number of times

Above solution can work in both sorted and not sorted arrays (Almost similar question as of above except 
in this question the problem is not sorted)

*/