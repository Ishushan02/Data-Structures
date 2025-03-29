/*
    Problem 31
    190. Reverse Bits
    (https://leetcode.com/problems/reverse-bits/)

    uint32_t reverseBits(uint32_t n) {
        
        int s = 0;
        uint32_t ans = 0;
        while(n){
            ans = ans << 1;
            if(n & 1){
                ans += 1;
            }else{
                ans += 0;
            }
            s++;
            n = n >> 1;
        }

        // cout << s << endl;
        for(int i = s; i < 32; i++){
            ans = ans << 1;
        }
        

        return ans;
    }
*/

/*
    Problem 32
    191. Number of 1 Bits
    (https://leetcode.com/problems/number-of-1-bits/)

    int hammingWeight(int n) {
        
        int count = 0;

        while(n){

            if(n & 1){
                count = count + 1;
            }
            n = n >> 1;
        }

        return count;
    }
        
*/

/*
    Problem 33
    322. Coin Change
    (https://leetcode.com/problems/coin-change/)

    int allDenominations(vector<int>& coins, int amount, vector<int> &dpArray){
        if(dpArray[amount] != -1){
            return dpArray[amount];
        }
        
        if(amount == 0){
            return 0;
        }

        int minSteps = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            // cout << i << endl;
            if(amount - coins[i] >= 0){
                int ans = allDenominations(coins, amount - coins[i], dpArray);
                if(ans != INT_MAX){
                    minSteps = min(minSteps, ans+1);
                }   
                
            }
        }

        dpArray[amount] = minSteps;
        return dpArray[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dpArray(amount + 1, -1);
        int ans = allDenominations(coins, amount, dpArray);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }

*/

/* 
    Problem 34
    70. Climbing Stairs
    (https://leetcode.com/problems/climbing-stairs/)

    int allPossibility(int n, vector<int> &dpArray){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }

        if(dpArray[n] != -1){
            return dpArray[n];
        }

        dpArray[n] = allPossibility(n -1, dpArray) + allPossibility(n - 2, dpArray);
        return dpArray[n];
    }

    int climbStairs(int n) {
        vector<int> dpArray(n+1, -1);
        return allPossibility(n, dpArray);
    }

*/

/*
    Problem 35
    198. House Robber
    (https://leetcode.com/problems/house-robber/)

    int robHouse(vector<int>& nums, int i, vector<int> &dpArray){
        if(i >= nums.size()){
            return 0;
        }
        if(dpArray[i] != -1){
            return dpArray[i];
        }

        int include = nums[i] + robHouse(nums, i + 2, dpArray);
        int exclude = robHouse(nums, i + 1, dpArray);
        dpArray[i] = max(include, exclude);
        return dpArray[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dpArray(nums.size(), -1);
        return robHouse(nums, 0, dpArray);
    }
*/

/*
    Problem 36
    200. Number of Islands
    (https://leetcode.com/problems/number-of-islands/)

    void visit(int m, int n, int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){

        if(i < 0 || i >= m || j < 0 || j >= n){
            return ;
        }

        if(visited[i][j] == false && grid[i][j] == '1'){
            visited[i][j] = true;
            visit(m, n, i+1, j, grid, visited);
            visit(m, n, i, j+1, grid, visited);
            visit(m, n, i-1, j, grid, visited);
            visit(m, n, i, j-1, grid, visited);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] =='1' && visited[i][j] == false){
                    ans += 1;
                    visit(m, n, i, j, grid, visited);
                }
            }
        }

        return ans;

    }
*/