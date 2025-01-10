/*
    198. House Robber
    (https://leetcode.com/problems/house-robber/description/)

    Method 1 using TOp Down and Memosiation

    int robHouses(vector<int> &nums, int index, vector<int> &dpArr){
        if(index>= nums.size()){
            return 0;
        }   
        
        if(dpArr[index] != -1){
            return dpArr[index];
        }

        int includeans = nums[index] + robHouses(nums, index + 2, dpArr);
        int excludeans = 0 + robHouses(nums, index + 1, dpArr);
        dpArr[index] = max(includeans, excludeans);


        return dpArr[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpArr(n+1, -1);

        return robHouses(nums, 0, dpArr);
    }


    Method 2 Bottom Up - Iterative

    int robHousesBottomUp(vector<int> &nums){
        int n = nums.size();
        vector<int> dpArr(n+2, 0);

        for(int i = n; i >= 0; i--){
            int includeAns = nums[i] + dpArr[i+2];
            int exclude = 0 + dpArr[i+1];

            dpArr[i] = max(includeAns, exclude);
        }

        return dpArr[0];

    }

    Method 3 Space Optimization
    int robHouseSpaceOpt(vector<int> &nums){
        int next1 = 0;
        int next2 = 0;
        int n = nums.size();

        for(int i = n -1; i >= 0; i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;

            int maxVal = max(include, exclude);

            next2 = next1;
            next1 = maxVal;
        }

        return next1;
    }


*/


/*
    300. Longest Increasing Subsequence
    (https://leetcode.com/problems/longest-increasing-subsequence/description/)

    int getMaxRecursionSol(vector<int> &nums, int last, int index){
        if(index >= nums.size()){
            return 0;
        }


        int include = 0;
        if(nums[index] > last){
            include = 1 + getMaxRecursionSol(nums, nums[index], index + 1);
        }

        int exclude = 0 + getMaxRecursionSol(nums, last, index + 1);

        int finalAns = max(include, exclude);

        return finalAns;
    }


    // DP Solution
    So, the logic is first, as 2 variables are changing, we have to create 2D Array
    now the size of 2D array is n+2, n+1.. because initially in recursion procedure we had 
    lastindex as -1 now as we are accessing and storing matrix we will shift the storage by 1.. hence dim is n+2

    // logic is same and only change is that now we are playing with indices rather than values
    // store the values of lastindex, index and in between if it is not -1 return that value 
    // which means it's getting calculated again



    int getMaxDPSol(vector<int> &nums, vector<vector<int>> &dpArr, int lastidx, int index){
        if(index >= nums.size()){
            return 0;
        }

        if(dpArr[lastidx+1][index] != -1){  // dp Step 3
            return dpArr[lastidx+1][index];
        }

        int include = 0;
        if(lastidx == -1 || nums[index] > nums[lastidx]){
            include = 1 + getMaxDPSol(nums, dpArr, index, index+1);
        }

        int exclude = 0 + getMaxDPSol(nums, dpArr, lastidx, index+1);
        
        dpArr[lastidx+1][index] = max(include, exclude); // dp Step 2

        return dpArr[lastidx+1][index];
         

    }

    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        int lastelem = INT_MIN;
        int lastidx = -1;
        vector<vector<int>> dpArr(n + 2, vector<int>(n+1, -1)); // DPStep 1

        // return getMax(nums, lastelem, 0);
        return getMaxDPSol(nums, dpArr, lastidx, 0);
    }

*/


/*
    322. Coin Change
    (https://leetcode.com/problems/coin-change/)
    // See the DP Solution

    void allPossibilitiesRecursion(vector<int>& coins, int tempAmount, int steps, int &ans){

        if(tempAmount == 0){
            ans = min(ans, steps);
            return ;
        }

        for(int i = 0; i < coins.size(); i++){
            if(tempAmount >= coins[i]){
                allPossibilitiesRecursion(coins, tempAmount - coins[i], steps+1, ans);
            }
        }
    }

    int allPossibilitiesDP(vector<int>& coins, int tempAmount, vector<int> &dpArr){

        if(tempAmount == 0){
            return 0;
        }

        if(dpArr[tempAmount] != -1){
            return dpArr[tempAmount];
        }

        int minCoin = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(tempAmount >= coins[i]){
                int totCoins = allPossibilitiesDP(coins, tempAmount - coins[i], dpArr);
                if(totCoins != INT_MAX){
                    minCoin = min(minCoin, 1 + totCoins);
                }
                
            }
        }
        dpArr[tempAmount] = minCoin;
        return dpArr[tempAmount];

    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        // allPossibilitiesRecursion(coins, amount, 0, ans);
        int n = coins.size();

        vector<int> dpArr(amount+1, -1);
        
        ans =  allPossibilitiesDP(coins, amount, dpArr);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }

*/