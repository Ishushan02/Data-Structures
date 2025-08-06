/*

    Partition DP's VVIII and it's Tough

*/

/*
    Matrix Chain Multiplication
    (https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

    int minMatMulCost(vector<int> &arr, int i, int j, vector<vector<int>> &dpArray){
        if(i == j){
            return 0;
        }
        
        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }
        
        int minSteps = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + minMatMulCost(arr, i, k, dpArray) + minMatMulCost(arr, k+1, j, dpArray);
            minSteps = min(minSteps, steps);
        }
        
        dpArray[i][j] = minSteps;
        
        return dpArray[i][j];
        
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, -1));
        return minMatMulCost(arr, 1, n-1, dpArray);
    }

    // Tabulation Method

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, 0));
        
        for(int i = 0; i < n + 1; i++){
            dpArray[i][i] = 0;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int minSteps = 1e9;
                for(int k = i; k < j; k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dpArray[i][k] + dpArray[k+1][j];
                    minSteps = min(minSteps, steps);
                }
                dpArray[i][j] = minSteps;
            }
        }
        
        return dpArray[1][n-1];
    }

    METHOD 2
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, 0));
        
        for(int len = 2; len < n; len++){
            for(int i = 1; i < n - len + 1; i++){
                int j = i + len - 1;
                int minCounts = INT_MAX;
                for(int k = i; k < j; k++){
                    int cnt = arr[i-1] * arr[k] * arr[j] + 
                    dpArray[i][k] + 
                    dpArray[k+1][j];
                    minCounts = min(minCounts, cnt);
                }
                dpArray[i][j] = minCounts;
            }
        }
        
        return dpArray[1][n-1];
        
    }
*/

/*
    1547. Minimum Cost to Cut a Stick
    (https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        // int n = cuts.size();

        int m = cuts.size();
        vector<vector<int>> dpArray(m+1, vector<int>(m + 1, 0));

        for(int len = 2; len < m; len++){
            for(int i = 0; i + len < m; i++){
                int j = i + len;
                int minCuts = 1e9;
                for(int k = i + 1; k < j; k++){
                    int cutCost = (cuts[j] - cuts[i]) + dpArray[i][k] + dpArray[k][j];
                    minCuts = min(minCuts, cutCost);
                }
            dpArray[i][j] = minCuts;   
            }
        }

        return dpArray[0][m-1];

    }
*/

/*
    312. Burst Balloons
    (https://leetcode.com/problems/burst-balloons/description/)

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // return getMaxBurst(nums, 1, nums.size()-2);
        int n = nums.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n + 1, 0));

        for(int start = n-1; start >= 1; start--){
            for(int end = 1; end <= n - 2; end++){
                if(start > end){
                    continue;
                }
                int maxBurst = 0;
                for(int k = start; k <= end; k++){
                    int burst = nums[start - 1] * nums[k] * nums[end + 1] + getMaxBurst(nums, start, k-1) + getMaxBurst(nums, k+1, end);
                    dpArray[start][end] = max(dpArray[start][end], burst);
                }
            }
        }

        return dpArray[1][n-2];

    }


    2nd Metod
    (There are 2 Methods, check recursion and Bottom Up )

    int getMaxCoins(vector<int> &nums, int i, int j){
        if(i > j){
            return 0;
        }

        int maxCoins = 0;
        for(int k = i; k <= j; k++){
            cout << i-1 << " , " << k << " , " << j << endl;
            int coins = nums[i-1] * nums[k] * nums[j+1] +
                    getMaxCoins(nums, i, k - 1) +
                    getMaxCoins(nums, k+1, j);
            maxCoins = max(coins, maxCoins); 
        }

        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        // return getMaxCoins(nums, 1, n-2);
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, 0));

        for(int len = 1; len < n; len++){
            for(int i = 1; i + len < n; i++){
                int j = i + len - 1;
                int maxCoins = 0;
                for(int k = i; k <= j; k++){
                    int coins = nums[i-1] * nums[k] * nums[j+1] +
                            dpArray[i][k-1]+
                            dpArray[k+1][j];
                    maxCoins = max(coins, maxCoins); 
                }
                dpArray[i][j] = maxCoins;
            }
        }

        return dpArray[1][n-2];

    }
        
*/