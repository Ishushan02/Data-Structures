/*
    120. Triangle
    (https://leetcode.com/problems/triangle/description/)

    OPtimized SOlution
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle.size();

        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
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
            for(int j = n - 1; j >= 0; j--){
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