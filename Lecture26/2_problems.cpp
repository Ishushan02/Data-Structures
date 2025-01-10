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

    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        int lastelem = INT_MIN;
        int lastidx = -1;
        vector<vector<int>> dpArr(n + 2, vector<int>(n+1, -1));

        // return getMax(nums, lastelem, 0);
        return getMaxDPSol(nums, dpArr, lastidx, 0);
    }

*/