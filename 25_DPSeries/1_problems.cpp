
/*

    GRID BASED DP PROBLEMS ONLY ----

*/


/*

    Test 1
    
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev = 0;
        int curr = 1;
        int i = 2;
        while(i <= n){
            int val = curr + prev;
            prev = curr;
            curr = val;
            i += 1;
        }

        return curr;
    }
*/


/*
    70. Climbing Stairs
    (https://leetcode.com/problems/climbing-stairs/description/)

    Tabular DP
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        vector<int>Fn(n+1, 0);
        Fn[0] = 1;
        Fn[1] = 1;

        for(int i = 2; i <= n; i++){
            Fn[i] = Fn[i-2] + Fn[i-1];
        }
        
        return Fn[n];
    }

    Space Optimization
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        int prev = 1;
        int curr = 1;

        for(int i = 2; i <= n; i++){
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        
        return curr;
    }

*/

/*
    Frog Jump(GFG)
    (https://www.geeksforgeeks.org/problems/geek-jump/1)

    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> minCosts(height.size(), INT_MAX);
        
        minCosts[0] = 0;
        minCosts[1] = abs(height[0] - height[1]);
        for(int i = 0; i < height.size(); i++){
            if(i+1 < n){
                int energy = minCosts[i] +  abs(height[i] - height[i+1]);
                minCosts[i+1] = min(minCosts[i+1], energy);
            }
            if(i+2 < n){
                int energy = abs(height[i] - height[i+2]);
                minCosts[i+2] = minCosts[i] + min(minCosts[i+2], energy);
            }
        }
        
        return minCosts[n-1];
    }

*/

/*

    Maximum sum of non-adjacent elements
    (https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTabValue=PROBLEM)
    // optimized bottom Up Solution
    int maximumNonAdjacentSum(vector<int> &nums){

    int maxSum = 0;
    int n = nums.size();
    vector<int> dpArray(nums.size() + 3, 0);
    
    for(int i = n-1; i >= 0; i--){
        int include = 0;
        int exclude = 0;
        include = nums[i] + dpArray[i+2];
        exclude = dpArray[i+1];
        
         
        dpArray[i] = max(include, exclude);
    }

    return dpArray[0];    
}
*/

/*  
    198. House Robber
    House Robber
    (https://leetcode.com/problems/house-robber/description/)
    Optimized Solution

    int rob(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();
        vector<int> dpArray(nums.size() + 3, 0);
        
        for(int i = n-1; i >= 0; i--){
            int include = 0;
            int exclude = 0;
            include = nums[i] + dpArray[i+2];
            exclude = dpArray[i+1];
            
            
            dpArray[i] = max(include, exclude);
        }

        return dpArray[0];
    }

    OR SPACE OPTIMIZED
    int rob(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();
        
        int ith = 0;
        int i1st = 0;
        int i2nd = 0;
        for(int i = n-1; i >= 0; i--){
            int include = 0;
            int exclude = 0;
            include = nums[i] + i2nd;
            exclude = i1st;
            ith = max(include, exclude);
            i2nd = i1st;
            i1st = ith;
        }

        return ith;
    }
        
*/

/*
     Ninja’s Training
    (https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003?leftPanelTabValue=PROBLEM)

    int getMaxPoints(vector<vector<int>> &points, int i, int j, vector<vector<int>> &dpArray){
        if(i >= points.size()){
            return 0;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }
        int maxReward = 0;
        for(int k = 0; k < 3; k++){
            if(k != j){
                int temp = getMaxPoints(points, i + 1, k, dpArray);
                maxReward = max(maxReward, temp);
            }
        }

        dpArray[i][j] = points[i][j] + maxReward;
        return dpArray[i][j];
    }


    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // Write your code here.
        int maxReward = 0;
        for(int j = 0; j < 3; j++){
            // cout << j << endl;
            vector<vector<int>> dpArray(points.size(), vector<int>(4, -1));
            int r = getMaxPoints(points, 0, j, dpArray);

            maxReward = max(maxReward, r);
        }

        return maxReward;

    }
*/

/*
    62. Unique Paths
    (https://leetcode.com/problems/unique-paths/)

    Optimized
    int uniquePaths(int m, int n) {
        vector<vector<int>> dpArray(m+2, vector<int>(n+2, 0));
        dpArray[m-1][n-1] = 1;

        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                dpArray[i][j] += dpArray[i+1][j] + dpArray[i][j+1];
            }
        }
        return dpArray[0][0];
    }

    Space Optimized
    int uniquePaths(int m, int n) {
        vector<int> bottomSum(n+1, 0);
        bottomSum[n-1] = 1;
        int currSum = 0;

        for(int i = m-1; i >= 0; i--){
            int rightSum = 0;
            for(int j = n-1; j >= 0; j--){
                currSum = bottomSum[j] + rightSum;   
                bottomSum[j] = currSum;
                rightSum = currSum;
            }
        }
        return currSum;

    }

*/

/*
    63. Unique Paths II
    (https://leetcode.com/problems/unique-paths-ii/description/)

    long long int allPaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<long long int>> &dpArray){
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1){
            return 1;
        }
        if(i >= obstacleGrid.size() || j >= obstacleGrid[0].size()){
            return 0;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        if(obstacleGrid[i][j] != 1){
            dpArray[i][j] = allPaths(obstacleGrid, i+1, j, dpArray) + allPaths(obstacleGrid, i, j+1, dpArray);
            return dpArray[i][j];
        }

        return 0;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        
        vector<vector<long long int>> dpArray(m, vector<long long int>(n + 1, -1));
        return allPaths(obstacleGrid, 0, 0, dpArray)%2000000000;
    }

    OPtimized SOlution

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        vector<vector<long long int>> dpArray(m+1, vector<long long int>(n + 1, 0));
        dpArray[m-1][n-1] = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(obstacleGrid[i][j] != 1){
                    dpArray[i][j] += dpArray[i+1][j] + dpArray[i][j+1];
                }
            }
        }


        return dpArray[0][0]%2000000000;
    }


    Space Optimized
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        long long int currSum = 0;
        vector<long long int> bottomSum(n + 1, 0);
        bottomSum[n-1] = 1;

        for(int i = m - 1; i >= 0; i--){
            int rightSum = 0;
            for(int j = n - 1; j >= 0; j--){
                if(obstacleGrid[i][j] != 1){
                    currSum = bottomSum[j] + rightSum;
                    bottomSum[j] = currSum;
                    rightSum = currSum;
                }else{
                    rightSum = 0;
                    bottomSum[j] = 0;
                }
            }
        }

        return currSum%2000000000;
    }

*/

/*  

    64. Minimum Path Sum
    (https://leetcode.com/problems/minimum-path-sum/description/)

    OPtimized Solution

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long int>> dpArray(m+1, vector<long long int>(n+1, INT_MAX));

        dpArray[m-1][n-1] = grid[m-1][n-1];
        dpArray[m][n-1] = 0;
        dpArray[m-1][n] = 0;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                dpArray[i][j] = min(grid[i][j] + dpArray[i+1][j], grid[i][j] + dpArray[i][j+1]);                
            }
        }

        return dpArray[0][0];

    }

    SPACE OPTIMIZED
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<long long int> linearDP(n, INT_MAX);
        linearDP[n-1] = 0;

        for(int i = m - 1; i >= 0; i--){
            long long int right = INT_MAX;
            for(int j = n - 1; j >= 0; j--){
                int minSum = min(grid[i][j] + linearDP[j], grid[i][j] + right);    
                linearDP[j] = minSum;
                right = minSum;
            }
        }

        return linearDP[0];

    }
*/

/*
    120. Triangle
    (https://leetcode.com/problems/triangle/description/)

    OPtimized SOlution
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle.size();

        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                if(i >= j){
                    dpArray[i][j] = min(triangle[i][j] + dpArray[i+1][j], triangle[i][j] + dpArray[i+1][j+1] );
                }
            }
        }
        return dpArray[0][0];
    }

    Space Optimized
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle.size();
        vector<int> linearDP(n + 1, 0);

        for(int i = m-1; i >= 0; i--){
            vector<int> temp(n + 1, 0);
            for(int j = i; j >= 0; j--){
                if(i >= j){
                    int sum = min(triangle[i][j] + linearDP[j], triangle[i][j] + linearDP[j+1]);
                    temp[j] = sum;
                }
            }
            linearDP = temp;
        }
        return linearDP[0];
    }

*/

/*

    Maximum Path Sum in the matrix
    (https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTabValue=PROBLEM)

    long long int maxSumVal(vector<vector<int>> &matrix, int i, int j, vector<vector<long long int>> &dpArray){

        if(i >= matrix.size() || j < 0 || j >= matrix[0].size()){
            return LLONG_MIN;
        }

        if(i == matrix.size()-1 && j >= 0 && j < matrix[0].size()){
            return matrix[i][j];
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        long long int leftDiag =  maxSumVal(matrix, i+1, j-1, dpArray);
        long long int rightDiag =  maxSumVal(matrix, i+1, j+1, dpArray);
        long long int bottom =  maxSumVal(matrix, i+1, j, dpArray);

        if(leftDiag != LLONG_MIN){
            leftDiag += matrix[i][j];
        }

        if(rightDiag != LLONG_MIN){
            rightDiag += matrix[i][j];
        }

        if(bottom != LLONG_MIN){
            bottom += matrix[i][j];
        }

        dpArray[i][j] = max({leftDiag, rightDiag, bottom});

        return dpArray[i][j];
    }

    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        //  Write your code here.
        int m = matrix.size();
        int n = matrix[0].size();
        long long int maxSum = LLONG_MIN;
        vector<vector<long long int>> dpArray(m + 1, vector<long long int>(n+1, -1));
        for(int j = 0; j < matrix[0].size(); j++){
            long long int val = maxSumVal(matrix, 0, j, dpArray);
            // cout << val << endl;
            if(val >= maxSum){
                maxSum = val;
            }
        }

        return maxSum;
    }

    OPTIMIZED SOLUTION

    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        //  Write your code here.
        int m = matrix.size();
        int n = matrix[0].size();

        vector< long long int> linearDP(n + 2, 0);
        linearDP[0] = LONG_MIN;
        linearDP[n+1] = LONG_MIN;
        long long int maxSum = LONG_MIN;
        for(int i = m - 1; i >= 0; i--){
            vector< long long int> temp(n+2, LONG_MIN);
            for(int j = n; j >= 1; j--){
                temp[j] = max({linearDP[j-1], linearDP[j], linearDP[j+1]});
                if(temp[j] != LONG_MIN){
                    temp[j] += matrix[i][j-1];
                }
            }

            linearDP = temp;
        }

        for(auto v: linearDP){
            if(v > maxSum){
                maxSum = v;
            }
        }

        return maxSum;

    }
        
*/

/*
    1463. Cherry Pickup II
    (https://leetcode.com/problems/cherry-pickup-ii/description/)

    int getmaximumCherry(vector<vector<int>>& grid, int i, int j, int n, vector<vector<vector<int>>> &dpArray){
        if(i == grid.size()-1 && j >= 0 && j < grid[0].size() && n >= 0 && n < grid[0].size()){
            if(j == n){
                return grid[i][j];
            }
            return grid[i][j] + grid[i][n];
        }

        if(i < 0 || i >= grid.size() || j >= grid[0].size() || j < 0 || n >= grid[0].size() || n < 0 ){
            return -1e-9;
        }
        if(dpArray[i][j][n] != -1){
            return dpArray[i][j][n];
        }
        int xCherry = grid[i][j];
        int yCherry = grid[i][n];

        int sum = 0;

        int move1 =  max({getmaximumCherry(grid, i+1, j-1, n-1, dpArray), getmaximumCherry(grid, i+1, j-1, n, dpArray), getmaximumCherry(grid, i+1, j-1, n+1, dpArray)});
        int move2 = max({getmaximumCherry(grid, i+1, j, n-1, dpArray), getmaximumCherry(grid, i+1, j, n, dpArray), getmaximumCherry(grid, i+1, j, n+1, dpArray)});
        int move3 = max({getmaximumCherry(grid, i+1, j+1, n-1, dpArray), getmaximumCherry(grid, i+1, j+1, n, dpArray), getmaximumCherry(grid, i+1, j+1, n+1, dpArray)});
        if(j == n){
            sum = xCherry + max({move1, move2, move3});
        }else{
            sum = xCherry + yCherry + max({move1, move2, move3});
        }

        dpArray[i][j][n] = sum;
        
        return dpArray[i][j][n];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dpArray(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return getmaximumCherry(grid, 0, 0, n-1, dpArray);
    }
*/


/*

    741. Cherry Pickup
    (https://leetcode.com/problems/cherry-pickup/description/)

    Instead of taking one rounf from top left to bottom right why don't you think of getting
    2 robots at once from top left to bottom right simultaneously.. isn't that same.. 

    int allPossiblePaths(vector<vector<int>>& grid, int n, int i, int j, int p, int q, bool &reached, vector<vector<vector<vector<int>>>> &dpArray){

        if(i >= n || j >= n || p >= n || q >= n || grid[i][j] == -1 || grid[p][q] == -1){
            return INT_MIN;
        }

        if(i == n - 1 && j == n - 1 && p == n - 1 && q == n - 1){
            reached = true;
            return grid[i][j];
        }

        if(dpArray[i][j][p][q] != -1){
            return dpArray[i][j][p][q];
        }
        
        int cherries = 0;

        if(i == p && j == q){
            cherries += grid[i][j];
        }else{
            cherries += grid[i][j] + grid[p][q];
        }

        int path1 = allPossiblePaths(grid, n, i, j+1, p, q+1, reached, dpArray);
        int path2 = allPossiblePaths(grid, n, i, j+1, p+1, q, reached, dpArray);
        int path3 = allPossiblePaths(grid, n, i+1, j, p+1, q, reached, dpArray);
        int path4 = allPossiblePaths(grid, n, i+1, j, p, q+1, reached, dpArray);

        int maxVal = max({path1, path2, path3, path4});

        if(maxVal != INT_MIN){
            dpArray[i][j][p][q] = maxVal + cherries;
        }else{
            dpArray[i][j][p][q] = INT_MIN;
        }

        return dpArray[i][j][p][q];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        bool reached = false;

        vector<vector<vector<vector<int>>>> dpArray(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1))));
        int ans = allPossiblePaths(grid, n, 0, 0, 0, 0, reached, dpArray);

        if(reached){
            return ans;
        }
        return 0;

    }

    OPTIMIZED - SPACE // ALways thing why i + j == p + q (at each step both are taking same step simultaneously)

    int allPossiblePaths(vector<vector<int>>& grid, int n, int i, int j, int p , bool &reached, vector<vector<vector<int>>> &dpArray){
        
        int q = i + j - p;
        if(i >= n || j >= n || p >= n || q >= n || grid[i][j] == -1 || grid[p][q] == -1){
            return INT_MIN;
        }

        if(i == n - 1 && j == n - 1 && p == n - 1 && q == n - 1){
            reached = true;
            return grid[i][j];
        }

        if(dpArray[i][j][p] != -1){
            return dpArray[i][j][p];
        }
        
        int cherries = 0;

        if(i == p && j == q){
            cherries += grid[i][j];
        }else{
            cherries += grid[i][j] + grid[p][q];
        }

        int path1 = allPossiblePaths(grid, n, i, j+1, p, reached, dpArray);
        int path2 = allPossiblePaths(grid, n, i, j+1, p+1, reached, dpArray);
        int path3 = allPossiblePaths(grid, n, i+1, j, p+1, reached, dpArray);
        int path4 = allPossiblePaths(grid, n, i+1, j, p, reached, dpArray);

        int maxVal = max({path1, path2, path3, path4});

        if(maxVal != INT_MIN){
            dpArray[i][j][p] = maxVal + cherries;
        }else{
            dpArray[i][j][p] = INT_MIN;
        }

        return dpArray[i][j][p];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        bool reached = false;

        vector<vector<vector<int>>> dpArray(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        int ans = allPossiblePaths(grid, n, 0, 0, 0, reached, dpArray);

        if(reached){
            return ans;
        }
        return 0;

    }
*/