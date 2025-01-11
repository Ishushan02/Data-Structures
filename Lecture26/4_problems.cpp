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