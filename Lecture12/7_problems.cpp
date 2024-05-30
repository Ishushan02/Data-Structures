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