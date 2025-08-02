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

*/