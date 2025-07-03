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
*/