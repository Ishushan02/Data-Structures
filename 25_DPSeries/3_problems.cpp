
/*

    SERIES BASED DP PROBLEMS ONLY ----

*/


/*  

    1143. Longest Common Subsequence
    (https://leetcode.com/problems/longest-common-subsequence/description/)

    int longestCommonSubsequence(string text1, string text2) {
        int maxCount = 0;
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));

        for(int i = m -1 ; i>= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dpArray[i][j] = 1 + dpArray[i+1][j+1];
                }else{
                    dpArray[i][j] = max(dpArray[i][j+1], dpArray[i+1][j]);
                }
            }
        }
        return dpArray[0][0];
    }
*/

/*

    Longest Common SUbstring
    (https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));
        int maxCount = 0;
        for(int i = m-1; i>= 0; i--){
            for(int j = n-1; j >= 0; j--){
                
                if(s1[i] == s2[j]){
                    dpArray[i][j] = 1 + dpArray[i+1][j+1];
                    maxCount = max(maxCount, dpArray[i][j]);
                }else{
                    dpArray[i][j] = 0;
                }
            }
        }
        
        return maxCount;
    }

*/

/*

    Longest Increasing Subsequence
    (https://leetcode.com/problems/longest-increasing-subsequence/description/)

    Tabulation
    int lengthOfLIS(vector<int>& nums) {
        int maxCount = 0;
        vector<vector<int>> dpArray(nums.size()+1, vector<int>(nums.size()+1, 0));

        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            for(int prev = i - 1; prev >= -1; prev--){
                int include = 0;

                if(prev == -1 || nums[i] > nums[prev]){
                    include = 1 + dpArray[i+1][i+1];
                }
                int exclude = 0 + dpArray[i+1][prev+1];

                dpArray[i][prev+1] = max(include, exclude);
            }
        }

        return dpArray[0][0];
    }

    SPACE OPTIMIZED
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpVal(nums.size()+1, 0);
        for(int i = n - 1; i >= 0; i--){
            for(int prev = i - 1; prev >= -1; prev--){
                int include = 0;

                if(prev == -1 || nums[i] > nums[prev]){
                    include = 1 + dpVal[i+1];
                }
                int exclude = 0 + dpVal[prev+1];

                dpVal[prev+1] = max(include, exclude);
            }
        }

        return dpVal[0];
    }
*/

/*

    516. Longest Palindromic Subsequence
    (https://leetcode.com/problems/longest-palindromic-subsequence/description/)

    int longestPSubs(string &s, int i, int j, int &maxCount, vector<vector<int>> &dpArray){
        if(i > j || i >= s.length() || j < 0){
            return 0;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        int plen = 0;
        if(s[i] == s[j] && i != j){
            plen = 2 + longestPSubs(s, i + 1, j - 1, maxCount, dpArray);
        }else if(s[i] == s[j] && i == j){
            plen = 1 + longestPSubs(s, i + 1, j - 1, maxCount, dpArray);
        }else{
            plen = max(longestPSubs(s, i + 1, j, maxCount, dpArray), longestPSubs(s, i, j - 1, maxCount, dpArray));
        }

        dpArray[i][j] = max(maxCount, plen);

        return dpArray[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int maxCount = 0;
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, -1));
        return longestPSubs(s, 0, n - 1, maxCount, dpArray);
    }
*/