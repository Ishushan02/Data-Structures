/*
    1143. Longest Common Subsequence
    (https://leetcode.com/problems/longest-common-subsequence/)

    // So the logic is that
        - if both the indices match increase 1 in ans
        - else don't increase anything ans check ans by changing both the indices and get max one out of it


    int getMaxSubsequenceRecursion(string &text1, string &text2, int i, int j){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }
        
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + getMaxSubsequenceRecursion(text1, text2, i + 1, j + 1);
        }else{
            ans = 0 + max(getMaxSubsequenceRecursion(text1, text2, i+1, j), getMaxSubsequenceRecursion(text1, text2, i, j+1));
        }

        return ans;
    }

    int getMaxSubsequenceDP(string &text1, string &text2, int i, int j, vector<vector<int>> &dpArr){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }
        
        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + getMaxSubsequenceDP(text1, text2, i + 1, j + 1, dpArr);
        }else{
            ans = 0 + max(getMaxSubsequenceDP(text1, text2, i+1, j, dpArr), getMaxSubsequenceDP(text1, text2, i, j+1, dpArr));
        }

        dpArr[i][j] = ans;
        return dpArr[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return getMaxSubsequenceRecursion(text1, text2, 0, 0);
        
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dpArr(m+1, vector<int>(n+1, -1));
        return getMaxSubsequenceDP(text1, text2, 0, 0, dpArr);
    }

*/


/*  
    1691. Maximum Height by Stacking Cuboids
    (https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/)


    // your thought was area, but why make it complex just compare there l,h,w

    bool isSafe(vector<int>& cube1, vector<int>& cube2){
        if((cube1[0] <= cube2[0]) && (cube1[1] <= cube2[1]) && (cube1[2] <= cube2[2])){
            return true;
        }

        return false;
    }


    int getMaxCuboidsHeight(vector<vector<int>>& cuboids,int prevIdx, int index){

        if(index >= cuboids.size()){
            return 0;
        }

        int include = 0;
        int exclude = 0;
        // include
        if(prevIdx== -1 || isSafe(cuboids[prevIdx], cuboids[index])){
            include = cuboids[index][2] + getMaxCuboidsHeight(cuboids, index, index + 1);
        }

        // exclude
        exclude = 0 + getMaxCuboidsHeight(cuboids, prevIdx, index + 1);

        int height = max(include, exclude);

        return height;
    }


    int getMaxCuboidsHeightDP(vector<vector<int>>& cuboids,int prevIdx, int index, vector<vector<int>> &dpArr){

        if(index >= cuboids.size()){
            return 0;
        }

        if(dpArr[index][prevIdx+1] != -1){
            return dpArr[index][prevIdx+1];
        }

        int include = 0;
        int exclude = 0;
        // include
        if(prevIdx== -1 || isSafe(cuboids[prevIdx], cuboids[index])){
            include = cuboids[index][2] + getMaxCuboidsHeightDP(cuboids, index, index + 1, dpArr);
        }

        // exclude
        exclude = 0 + getMaxCuboidsHeightDP(cuboids, prevIdx, index + 1, dpArr);

        dpArr[index][prevIdx+1] = max(include, exclude);

        return dpArr[index][prevIdx+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        // first sort all cuboids internally it will take O(1) time

        for(int i = 0; i < cuboids.size(); i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        // now we sort all cuboids based on there first elements
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<vector<int>> dpArr(n+1, vector<int>(n + 1, -1));
        // return getMaxCuboidsHeight(cuboids, -1, 0);
        return getMaxCuboidsHeightDP(cuboids, -1, 0, dpArr);
    }

*/


/*  
    354. Russian Doll Envelopes
    (https://leetcode.com/problems/russian-doll-envelopes/description/)
    // This is not solved check the assignment question to Solve it { using Binary Search }
    
    bool canfit(vector<int> & env1, vector<int> &env2){
        if((env1[0] < env2[0]) && (env1[1] < env2[1])){
            return true;
        }

        return false;
    }

    int maxCount(vector<vector<int>>& envelopes, int prevIdx, int index){
        if(index >= envelopes.size()){
            return 0;
        }

        int include = 0;
        int exclude = 0;
        if(prevIdx == -1 || canfit(envelopes[prevIdx], envelopes[index])){
            include = 1 + maxCount(envelopes, index, index + 1);
        }

        exclude = 0 + maxCount(envelopes, prevIdx, index + 1);

        int ans = max(include, exclude);

        return ans;
    }

    int maxCountDP(vector<vector<int>>& envelopes, int prevIdx, int index, vector<vector<int>> &dpArr){
        if(index >= envelopes.size()){
            return 0;
        }

        int include = 0;
        int exclude = 0;

        if(dpArr[index][prevIdx+1] != -1){
            return dpArr[index][prevIdx+1];
        }

        if(prevIdx == -1 || canfit(envelopes[prevIdx], envelopes[index])){
            include = 1 + maxCountDP(envelopes, index, index + 1, dpArr);
        }

        exclude = 0 + maxCountDP(envelopes, prevIdx, index + 1, dpArr);

        dpArr[index][prevIdx+1] = max(include, exclude);

        return dpArr[index][prevIdx+1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<vector<int>> dpArr(n + 1, vector<int>(n+1, -1));

        // return maxCount(envelopes, -1, 0);
        return maxCountDP(envelopes, -1, 0, dpArr);

    }

*/