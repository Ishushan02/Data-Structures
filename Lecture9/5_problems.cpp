#include <iostream>
#include <vector>
using namespace std;

/*
2 Sum Problem in O(nlogn)

https://www.geeksforgeeks.org/problems/key-pair5616/1?page=2&difficulty=Easy&sortBy=submissions

bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    // code here
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int val = arr[i] + arr[j];
        if (val == x)
        {
            return true;
        }
        else if (val > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
*/

/*
Pivot Point - https://leetcode.com/problems/find-pivot-index/description/

int pivotIndex(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i<nums.size();i++){
            sum+=nums[i];
        }

        int leftsum = 0;
        int rightsum = sum;
        for (int i = 0; i<nums.size();i++){
            rightsum = rightsum - nums[i];
            if (leftsum == rightsum){
                return i;
            }
            leftsum = leftsum + nums[i];
        }
        return -1;

    }
*/

/*
// Remove Duplicates from Sorted Array

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Method 1. (Best)
    int removeDuplicates(vector<int>& arr) {
        
        int prev = arr[0];
        int i = 0;
        int count = 0;
        int j = i + 1;

        while(j < arr.size()){

            if(arr[i] == arr[j]){
                j++;
            }else{
                count += 1;
                arr[i+1]=arr[j];
                i = i+1;
                j = j + 1;
            }
        }


        return count+1;
    }

Method 2, (Okay Method not much efficient)
    int removeDuplicates(vector<int>& nums) {
            int prev = nums[0];
            int k = 1;
            vector<int> expectedNums ;
            expectedNums.push_back(prev);
            for(int i = 1;i<nums.size();i++){
                if (prev != nums[i]){
                    k+=1;
                    prev = nums[i];
                    expectedNums.push_back(prev);
                }
            }
            cout<<k;
            nums = expectedNums;
            return k;
        }

*/

/*
MAXIMUM CONTIGUOUS SUB ARRAY

https://leetcode.com/problems/maximum-average-subarray-i/submissions/1267111877/


double findMaxAverage(vector<int>& nums, int k) {
        int MAX = nums[0];
        if (k==1){
            for(int s =0;s<nums.size();s++){
                MAX = max(MAX, nums[s]);
            }
            return (double)MAX;
        }
        int i = 0;
        int j = i+1;
        int sum = nums[i];
        int max_sum = INT_MIN;
        while(j < nums.size()){
            sum = sum + nums[j];
            if ((j - i) == k - 1){
                max_sum = max(max_sum, sum);
                sum = sum - nums[i];
                i++;
            }
            j++;

        }
        double res = max_sum/(double)k;
        return res;

    }
*/

/*
Move all Negative Numbers to the right (no order on positive numbers, but -ve numbers should be
in the same order)

int main()
{
    vector<int> arr = {-1, 9, -7, 2, -2, 3};

    int i = 0;
    int j = 0;

    while (j < arr.size())
    {
        if (arr[i] < 0)
        {
            i++;
        }
        else if ((arr[j] < 0) & (arr[i] > 0) & (i < j))
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j++;
        }
        else
        {
            j++;
        }

    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}

*/

/*
Find Duplicate

https://leetcode.com/problems/find-the-duplicate-number/description/
//Use -ve marking strategy

int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int arr[n+1];
        fill(arr, arr+n+1, 0);

        for(int i = 0;i<n;i++){
            int value = nums[i];
            if (arr[value-1]!=-1){
                cout << value << " ";
                arr[value-1] = -1;
            }else{
                return value;
            }

        }

        return 0;

    }

*/

/*

Some Very Important Questions Needs to be Done

1. Single Number 2
2. Single Number 3
3. Row with Max 1's
4. Majority Element
5. Majority ELement 2


*/