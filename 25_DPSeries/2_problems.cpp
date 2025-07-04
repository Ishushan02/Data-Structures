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