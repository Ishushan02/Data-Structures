
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

    Tabulation
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int maxCount = 0;
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < n; i++){
            dpArray[i][i] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    dpArray[i][j] = 2 + dpArray[i+1][j-1];
                }else{
                    dpArray[i][j] = max(dpArray[i+1][j], dpArray[i][j-1]);
                }
            }
        }
        
        return dpArray[0][n-1];
    }
*/

/*

    1312. Minimum Insertion Steps to Make a String Palindrome
    (https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

    int minPalInsertions(string &s, int i, int j, vector<vector<int>> &dpArray){
        if(i >= s.length() || j < 0|| i > j){
            return 0;
        }

        int count = 0;

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        if(s[i] == s[j]){
            count = 0 + minPalInsertions(s, i+1, j-1, dpArray);
        }else{
            int count1 = 1 + minPalInsertions(s, i+1, j, dpArray);
            int count2 = 1 + minPalInsertions(s, i, j-1, dpArray);
            count = min(count1, count2);
        }
        dpArray[i][j] = count;

        return dpArray[i][j];
    }

    int minInsertions(string s) {
        
        int n = s.length();
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, -1));
        return minPalInsertions(s, 0, n-1, dpArray);

    }

    // METHOD 2 
    Maximum Insertion is total Length - longest palindromic Subsequence
    (think about it .. )

    int minInsertions(string s) {
        
        int n = s.length();
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1,0));

        for(int i = 0; i < n; i++){
            dpArray[i][i] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int count = 0;
                if(s[i] == s[j]){
                    dpArray[i][j] = 2 + dpArray[i+1][j-1];
                }else{
                    dpArray[i][j] = max(dpArray[i+1][j], dpArray[i][j-1]);
                }
            }
        }

        int maxPlaindromicSubseq = dpArray[0][n-1];

        return abs(n - maxPlaindromicSubseq);

    }

*/

/*
    (VVI and Good Question)
    1092. Shortest Common Supersequence 
    (https://leetcode.com/problems/shortest-common-supersequence/description/)

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int include = 0;
                if(str1[i] == str2[j]){
                    include = 1 + dpArray[i+1][j+1];
                }
                int exclude = max(dpArray[i+1][j], dpArray[i][j+1]);

                dpArray[i][j] = max(include, exclude);
            }
        }

        string lcs;
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(str1[i] == str2[j]){
                lcs += str1[i];
                i += 1;
                j += 1;
            }else{
                if(dpArray[i+1][j] > dpArray[i][j+1]){
                    lcs += str1[i];
                    i = i + 1;
                }else{
                    lcs += str2[j];
                    j = j + 1;
                }
            }
        }

        if(lcs == ""){
            return str1 + str2;
        }

        while(i < m){
            lcs += str1[i];
            i += 1;
        }

        while(j < n){
            lcs += str2[j];
            j += 1;
        }

        return lcs;

    }
*/

/*
    (DO IT AGAIN)
    115. Distinct Subsequences 
    (https://leetcode.com/problems/distinct-subsequences/)

    long long int distSubseq(string &s, string &t, int i, int j, vector<vector<int>> &dpArray){

        if(j >= t.length()){
            return 1;
        }
        if(i >= s.length() || j >= t.length()){
            return 0;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }
        
        long long int ans = 0;
        if(s[i] == t[j]){
            long long int inc = distSubseq(s, t, i + 1, j + 1, dpArray);
            long long int exc = distSubseq(s, t, i + 1, j, dpArray);
            if(inc + exc > ans){
                ans = inc + exc;
            }
            // maxAns = max(maxAns, inc + exc);
        }else{
            long long int next = distSubseq(s, t, i + 1, j, dpArray);
            if(next > ans){
                ans = next;
            }
        }

        dpArray[i][j] = ans;
        return dpArray[i][j];

    }

    int numDistinct(string s, string t) {
        long long int ans = 0;
        vector<vector<int>> dpArray(s.length()+1, vector<int>(t.length()+1, -1));
        return distSubseq(s, t, 0, 0, dpArray);

    }

    // TABULATION

    int numDistinct(string s, string t) {
        long long int ans = 0;
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dpArray(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m+1; i++){
            dpArray[i][n] = 1;
        }

        for(int i = m -1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int ans = 0;
                if(s[i] == t[j]){
                    long long int inc = dpArray[i+1][j+1];
                    long long int exc = dpArray[i+1][j];
                    if(inc + exc > ans){
                        ans = inc + exc;
                    }
                    
                }else{
                    long long int next = dpArray[i+1][j];
                    if(next > ans){
                        ans = next;
                    }
                }
                dpArray[i][j] = ans;

            }
        }

        return dpArray[0][0];
    }

    // SPACE Optimization
    int numDistinct(string s, string t) {
        long long int ans = 0;
        int m = s.length();
        int n = t.length();

        vector<int> dpLinear(n+1, 0);
        dpLinear[n] = 1;

       
        for(int i = m -1; i >= 0; i--){
            vector<int> tempDP = dpLinear;
            for(int j = n - 1; j >= 0; j--){
                int ans = 0;
                if(s[i] == t[j]){
                    long long int inc = dpLinear[j+1];
                    long long int exc = dpLinear[j];
                    if(inc + exc > ans){
                        ans = inc + exc;
                    }
                    
                }else{
                    long long int next = dpLinear[j];
                    if(next > ans){
                        ans = next;
                    }
                }
                tempDP[j] = ans;

            }
            dpLinear = tempDP;
        }

        return dpLinear[0];
    }
*/