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

    Method II
    bool isPossible(vector<int>& nums, int i, vector<int> &dpArr){
        if(i == nums.size() -1){
            return true;
        }

        if(i >= nums.size()){
            return false;
        }

        if(dpArr[i] != -1){
            return dpArr[i];
        }

        bool ans = false;
        for(int j = 1; j <= nums[i]; j++){
            ans = ans || isPossible(nums, j+i, dpArr);
            if(ans){
                dpArr[i] = true;
                return true;
            }
        }

        dpArr[i] = ans;

        return dpArr[i];
    }

    bool canJump(vector<int>& nums) {
        vector<int> dpArr(nums.size()+1, -1);
        return isPossible(nums, 0, dpArr);
    }

*/

/*

45. Jump Game II
(https://leetcode.com/problems/jump-game-ii/description/)

int minSteps(vector<int> &nums, int index, int tempcount, int& mincount){

        if(index == nums.size()-1){
            return tempcount;
        }

        if(index >= nums.size()){
            return -1;
        }



        int stepcount = 0;
        int maxSteps = nums[index];

        for(int i = 1; i <= maxSteps;i++){
            stepcount = minSteps(nums, index + i, tempcount+1, mincount);
            if(stepcount != -1){
                mincount = min(stepcount, mincount);
            }
        }

        return mincount;

    }

    int jump(vector<int>& nums) {
        int minCount = INT_MAX;
        int ans =  minSteps(nums, 0, 0, minCount);
        return ans;
    }

*/

/*

120. Triangle

// remember in this itterate it via triangle structure
(https://leetcode.com/problems/triangle/description/)

    int itterateTriangle(vector<vector<int>>& triangle, int row, int col){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        int elem1 = triangle[row][col] + itterateTriangle(triangle, row+1, col);
        int elem2 = triangle[row][col] + itterateTriangle(triangle, row+1, col+1);


        return min(elem1, elem2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return itterateTriangle(triangle, 0, 0);
    }

    Method 2
    int getminSum(vector<vector<int>>& triangle, int i, int j, vector<vector<int>> &dpArr){
        if(i >= triangle.size()){
            return 0;
        }

        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }

        int sum = triangle[i][j] + min(getminSum(triangle, i+1, j, dpArr), getminSum(triangle, i+1, j+1, dpArr));
        dpArr[i][j] = sum;

        return dpArr[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dpArr(triangle.size(), vector<int>(col, -1));
        return getminSum(triangle, 0, 0, dpArr);
    }

*/