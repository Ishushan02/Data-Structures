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

/*

1981. Minimize the Difference Between Target and Chosen Elements
(https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/)

int itterateMatrix(vector<vector<int>>& mat, int &target, int tempsum, int row){

        if(row == mat.size()){
            return abs(target - tempsum);
        }

        int ans = INT_MAX;

        for(int col = 0; col<mat[row].size();col++){

            int recursiveAns = itterateMatrix(mat, target, tempsum + mat[row][col], row+1);
            ans = min(ans, recursiveAns);
        }

        return ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int row = 0;
        int tempsum = 0;
        int ans = itterateMatrix(mat, target, tempsum, row);
        return ans;
    }



*/

/*

55. Jump Game
(https://leetcode.com/problems/jump-game/description/)

bool jumpsteps(vector<int>& nums, int index){
        if(index >= nums.size()){
            return false;
        }
        if(index == nums.size()-1){
            return true;
        }

        int maxSteps = nums[index];
        bool ans = false;
        for(int i = 1; i <= maxSteps;i++){
            ans = jumpsteps(nums, i + index);
            
            if(ans){
                return true;
            }
        }

        return ans;
    }

    bool canJump(vector<int>& nums) {
        return jumpsteps(nums, 0);
    }

*/