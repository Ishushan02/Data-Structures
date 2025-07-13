
/*

    SUBSET/SUBSEQUENCES DP PROBLEMS ONLY ----

*/

/*
     Subset Sum Equal To K
    (https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM)

    bool subsetSum(vector<int> &arr, int i, int k, vector<vector<int>> &dpArrary){
        if(k == 0){
            dpArrary[i][k] = 1;
            return dpArrary[i][k];
        }

        if(i >= arr.size()){
            return false;
        }

        if(dpArrary[i][k] != -1){
            return dpArrary[i][k];
        }

        bool ans = false;
        if(k - arr[i] >= 0){
            ans = ans || subsetSum(arr, i+1, k - arr[i], dpArrary);
        }
        
        ans = ans || subsetSum(arr, i+1, k, dpArrary);
        dpArrary[i][k] = ans;
        return dpArrary[i][k];

    }

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.    
        vector<vector<int>> dpArrary(n+1, vector<int>(k+1, -1));
        return subsetSum(arr, 0, k, dpArrary);

    }

    TOP DOWN

    bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.    
    vector<vector<bool>> dpArrary(n, vector<bool>(k+1,false));

    for(int i = 0; i < n; i++){
        dpArrary[i][0] = true;
    }

    dpArrary[0][arr[0]] = true;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            bool ans = false;
            if(j >= arr[i]){
                ans = dpArrary[i-1][j - arr[i]];
            }
            dpArrary[i][j] = dpArrary[i-1][j] | ans;
        }
    }


    return dpArrary[n-1][k];

}
*/

/*
    (GOOD QUESTION)
    Array partition with minimum difference
    (https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM)

        int minSubsetSumDifference(vector<int>& nums, int n)
    {
        // Write your code here.
        int totalSum = 0;
            for(auto v:nums){
                totalSum += v;
            }

            vector<vector<bool>> dpArray(nums.size()+1, vector<bool>(totalSum+1, false));

            for(int i = 0; i < nums.size(); i++){
                dpArray[i][0] = true;
            }

            if(nums[0] <= totalSum){
                dpArray[0][nums[0]] = true;
            }

            for(int i = 1; i < nums.size(); i++){
                for(int j = 1; j <= totalSum; j++){
                    bool include = false;
                    if(j >= nums[i]){
                        include = dpArray[i-1][j-nums[i]];
                    }
                    bool exclude = dpArray[i-1][j];

                    dpArray[i][j] = include || exclude;
                }
            }

            int minSum = INT_MAX;
            for(int i = 0; i <= totalSum; i++){
                int k = nums.size()-1;
                if(dpArray[k][i] == true){
                    int sum1 = i;
                    int sum2 = totalSum - i;
                    int diff = abs(sum1 - sum2);
                    minSum = min(minSum, diff);
                }
            }

            return minSum;
        
    }

*/

/*
    Count Subsets with Sum K
    (https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM)

    int ways(vector<int> &arr, int sum, int i, vector<vector<int>> &dpArray){
        if (sum == 0){
            return 1;
        }

        if(i >= arr.size()){
            return 0;
        }

        if(dpArray[i][sum] != -1){
            return dpArray[i][sum];
        }

        int include = 0;

        if(sum >= arr[i]){
            include += ways(arr, sum - arr[i], i+1, dpArray);
        }
        int exclude = ways(arr, sum, i+1, dpArray);

        dpArray[i][sum] = include + exclude;

        return dpArray[i][sum];
    }


    int findWays(vector<int>& arr, int k)
    {
        // Write your code here.
        vector<vector<int>> dpArray(arr.size()+1, vector<int>(k+1, -1));
        int ans = ways(arr, k, 0, dpArray);
        if(ans == -1){
            return 0;
        }
        // cout << ans << endl;

        return ans;
    }


    OPTIMIZED

    int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<long long int>> dpArray(arr.size()+1, vector<long long int>(k+1, 0));
	

	for(int i = 0; i <= n; i++){
		dpArray[i][0] = 1;
	}

	for(int i = n-1; i >= 0; i--){
		for(int j = k; j >= 0; j--){
			long long int include = 0;
			long long int exclude = 0;

			if(j >= arr[i]){
				include += dpArray[i+1][j - arr[i]];
			}
			exclude += dpArray[i+1][j];
			dpArray[i][j] = include + exclude;
		}	
	}

	return dpArray[0][k]%1000000007;
}



*/

/*  
     Partitions With Given Difference
    (https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?leftPanelTabValue=SUBMISSION)

    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int count = 0;
        
        long long int totSum = 0;
        for(auto v:arr){
            totSum += v;
        }
        int diff = totSum - d;
        if(diff < 0 || (diff % 2 != 0)){
            return 0;
        }
        int k = diff/2;
        // cout << k << endl;

        n = arr.size();
        vector<vector<long long int>> dpArray(n+1, vector<long long int>(k+1, 0));
        

        for(int i = 0; i <= n; i++){
            dpArray[i][0] = 1;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = k; j >= 0; j--){
                long long int include = 0;
                long long int exclude = 0;

                if(j >= arr[i]){
                    include += dpArray[i+1][j - arr[i]];
                }
                exclude += dpArray[i+1][j];
                dpArray[i][j] = include + exclude;
            }	
        }

        return dpArray[0][k] % 1000000007;
    }
*/

/*
    0 - 1 Knapsack Problem
    (https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                int include = 0;
                if (wt[i - 1] <= w) {
                    include = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
                }
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            }
        }
    
        return dp[n][W];
        
    }

    SPACE OPTIMIZATION
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<int> dpVal(W+1, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int w = W; w >= 0; w--) {
                int include = 0;
                if (wt[i] <= w) {
                    include = dpVal[w - wt[i]] + val[i];
                }
                int exclude = dpVal[w];
                dpVal[w] = max(include, exclude);
            }
        }
        
        return dpVal[W];
        
    }

*/

/*

    322. Coin Change
    (https://leetcode.com/problems/coin-change/description/)

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<long long int > dpWt(amount + 1, INT_MAX);

        dpWt[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                long long int cnt = INT_MAX;
                if(j >= coins[i]){
                    cnt = dpWt[j-coins[i]];
                    if(cnt != INT_MAX){
                        cnt = cnt + 1;
                    }
                }

                dpWt[j] = min(dpWt[j], cnt);

            }
        }

        if(dpWt[amount] == INT_MAX){
            return -1;
        }
        return dpWt[amount];
    }
*/

/*
    518. Coin Change II
    (https://leetcode.com/problems/coin-change-ii/description/)

    int allPossibleCombinations(vector<int> &coins, int amount, int idx, vector<vector<int>> &dpArray){
        if(amount == 0){
            return 1;
        }

        if(dpArray[idx][amount] != -1){
            return dpArray[idx][amount];
        }
        
        int totalCount = 0;
        for(int i = idx; i < coins.size(); i++){
            if(amount - coins[i] >= 0){
                totalCount += allPossibleCombinations(coins, amount - coins[i], i, dpArray);
            }
        }

        dpArray[idx][amount] = totalCount;
        return dpArray[idx][amount];

    }

    int change(int amount, vector<int>& coins) {
        int count = 0;
        int n = coins.size();
        vector<vector<long long int>> dpArray(n + 1, vector<long long int>(amount + 1, 0));
        // return allPossibleCombinations(coins, amount, 0, dpArray);

        for(int i = 0; i < n; i++){
            dpArray[i][0] = 1;
        }

        for(int i = n -1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){

                dpArray[i][j] = dpArray[i+1][j];

                if(j >= coins[i]){
                    dpArray[i][j] += (dpArray[i][j-coins[i]] % INT_MAX);
                }
            }
        }


        return dpArray[0][amount];
    }


    SPACE OPTIMIZED

    int change(int amount, vector<int>& coins) {
        int count = 0;
        int n = coins.size();
        vector<long long int> dpCount(amount + 1, 0);
    

        dpCount[0] = 1;

        for(int i = n -1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i]){
                    dpCount[j] += (dpCount[j-coins[i]] % INT_MAX);
                }
            }
        }


        return dpCount[amount];
    }
        
*/