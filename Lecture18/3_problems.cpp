#include <iostream>
#include <vector>

using namespace std;


/*

53. Maximum Subarray
(https://leetcode.com/problems/maximum-subarray/description/)

- We can do this using Kadane's Algorithm, but doing it using Divide and Conquer

    int divide(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }

        int maxLeftBordersum = INT_MIN;
        int maxRightBordersum = INT_MIN;
        int mid = (start + end)/2;

        int leftSum = divide(nums, start, mid);
        int rightSum = divide(nums, mid+1, end);

        int leftBorderSum = 0;
        int rightBorderSum = 0;

        for(int i = mid; i >= start; i--){
            leftBorderSum += nums[i];
            maxLeftBordersum = max(maxLeftBordersum, leftBorderSum);
        }

        for(int i = mid+1; i <= end; i++){
            rightBorderSum += nums[i];
            maxRightBordersum = max(maxRightBordersum, rightBorderSum);
        }

        int crossBordersum = maxLeftBordersum + maxRightBordersum;
        return max(leftSum, max(crossBordersum, rightSum));
    }

    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }

*/