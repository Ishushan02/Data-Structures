#include <iostream>

using namespace std;

/*

416. Partition Equal Subset Sum
(https://leetcode.com/problems/partition-equal-subset-sum/description/)

bool subsetsum(vector<int> &nums, int tempsum, int targetsum, int index){

        if(tempsum < 0 || index >= nums.size()){
            return false;
        }

        if (tempsum==targetsum){
            return true;
        }

        //include
        bool ans1 =  subsetsum(nums, tempsum+nums[index], targetsum, index+1);
        //exclude
        bool ans2 = subsetsum(nums, tempsum, targetsum, index+1);

        return ans1 || ans2;

    }

    bool canPartition(vector<int>& nums) {

        int arrsum = 0;
        for(int i = 0; i < nums.size();i++){
            arrsum += nums[i];
        }

        // if arrsum if odd then division isnot possible
        if(arrsum & 1){
            return false;
        }

        // so now we know that the arrsum is even, hence we make
        // the target sum into 2 halves if that's equal so other half would be present

        return subsetsum(nums, 0, arrsum/2, 0);

    }

*/