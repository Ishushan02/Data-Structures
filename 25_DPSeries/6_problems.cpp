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