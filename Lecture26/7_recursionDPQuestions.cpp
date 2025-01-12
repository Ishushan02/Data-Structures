/*
        213. House Robber II
        (https://leetcode.com/problems/house-robber-ii/)

        int totalVal(vector<int>& nums, int start, int end, vector<vector<int>> &dpArr){
        
        if(start > end){
            return 0;
        }
        
        if(dpArr[start][end]!= -1){
            return dpArr[start][end];
        }

        int includeans = nums[start] + totalVal(nums, start + 2, end, dpArr);
        int excludeans = 0 + totalVal(nums, start + 1, end, dpArr);

        int ans = max(includeans, excludeans);

        dpArr[start][end] = ans;

        return dpArr[start][end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        return max(totalVal(nums, 0, n-2, dpArr), totalVal(nums, 1, n-1, dpArr));
    }
*/


/*
    Painting the Fence
    (https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

    int totalWays(int n, int k, vector<int> &dpArr){
        if(n == 1){
            return k;
        }
        
        if(n ==2){
            return k + (k * (k-1)) ;
        }
        
        if(dpArr[n]!= -1){
            return dpArr[n];
        }
        
        int sameans = (k -1) * (totalWays(n -2, k, dpArr));
        int diffans = (k -1) * (totalWays(n -1, k, dpArr));
        
        dpArr[n] = sameans + diffans;
        return dpArr[n];
    }
    
    int countWays(int n, int k) {
        // code here
        vector<int> dpArr(n+1, -1);
        return totalWays(n, k, dpArr);
    }
    
*/