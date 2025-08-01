/*

    LIS - Patterns

*/

/*

    300. Longest Increasing Subsequence
    (https://leetcode.com/problems/longest-increasing-subsequence/description/)

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
    300. Longest Increasing Subsequence (All Methods I have done earlier, this is BS method -- VVI Important)
    (https://leetcode.com/problems/longest-increasing-subsequence/description/)

    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{

                auto prevsmallerIndex = lower_bound(ans.begin(), ans.end(), nums[i]);
                int index = prevsmallerIndex - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
*/

/*
    368. Largest Divisible Subset
    (https://leetcode.com/problems/largest-divisible-subset/description/)

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        vector<int> prevIdx(n+1, -1);
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= -1; j--){
                int inc = 0;
                if(j == -1 || nums[i] % nums[j] == 0){
                    inc = 1 + next[i+1];
                }
                int exc = next[j+1];
                if(inc > exc){
                    prevIdx[j+1] = i;
                }
                curr[j+1] = max(inc, exc);
            }
            next = curr;
        }

        int index = 0;
        while(prevIdx[index] != -1){
            int val = prevIdx[index];
            ans.push_back(nums[val]);
            index = val + 1;
        }

        return ans;
    }
*/

/*
    1048. Longest String Chain 
    (https://leetcode.com/problems/longest-string-chain/)

    struct check{
        bool operator()(string &a, string &b){
            return a.length() < b.length();
        }
    };

    bool stringComp(string &a, string &b){
        if(a.length() != b.length()-1){
            return false;
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < a.length() && j < b.length()){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                count += 1;
                j++;
            }

            if(count > 1){
                return false;
            }
        }

        if(count > 1 || i < a.length()){
            return false;
        }
        return true;
    }

    int longestIncreasingSubs(vector<string> &words, int pre, int i, vector<vector<int>> &dpArray){
        if(i >= words.size()){
            return 0;
        }

        if(dpArray[i][pre+1] != -1){
            return dpArray[i][pre+1];
        }
        int inc = 0;

        if(pre == -1 || stringComp(words[pre], words[i])){
            inc = 1 + longestIncreasingSubs(words, i, i + 1, dpArray);
        }

        int exc = longestIncreasingSubs(words, pre, i+1, dpArray);

        maxLen = max({maxLen, inc, exc});
        dpArray[i][pre+1] = max(inc, exc);
        return dpArray[i][pre+1];
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n == 1){
            return 1;
        }
        sort(words.begin(), words.end(), check());
        vector<vector<int>> dpArray(n + 2, vector<int>(n + 2, -1));
        return longestIncreasingSubs(words, -1, 0, dpArray);
       
    }
 
*/


/*

    Longest Bitonic subsequence
    (https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1)

    (TLE)

    int longestDecSubseq(vector<int> &nums, int pre, int i, vector<vector<int>> &dpArray){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dpArray[i][pre + 1] != -1){
            return dpArray[i][pre + 1];
        }
        
        int inc = 0;
        if(pre == -1 || nums[i] < nums[pre]){
            inc = 1 + longestDecSubseq(nums, i, i + 1, dpArray);
        }
        int exc = longestDecSubseq(nums, pre, i+1, dpArray);
        dpArray[i][pre + 1] = max(inc, exc);
        
        return dpArray[i][pre + 1];
    }
  
    
    int longestIncSubseq(vector<int> &nums, int pre, int i, vector<vector<int>> &dpArray){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dpArray[i][pre + 1] != -1){
            return dpArray[i][pre + 1];
        }
        
        int inc = 0;
        if(pre == -1 || nums[i] > nums[pre]){
            inc = 1 + longestIncSubseq(nums, i, i + 1, dpArray);
        }
        
        int exc = longestIncSubseq(nums, pre, i + 1, dpArray);
        dpArray[i][pre + 1] = max(inc, exc);
        
        return dpArray[i][pre + 1];
        
    }
  
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            vector<vector<int>> lisdpArray(n + 1, vector<int>(n + 2, -1));
            vector<vector<int>> ldsdpArray(n + 1, vector<int>(n + 2, -1));
            
            vector<int> incvec(nums.begin(), nums.begin() + i + 1);
            vector<int> decvec(nums.begin() + i, nums.end());
            int lis = longestIncSubseq(incvec, -1, 0, lisdpArray);
            int lds = longestDecSubseq(decvec, -1, 0, ldsdpArray);
            if(lis > 1 && lds > 1){
                maxLen = max(maxLen, lis + lds - 1);
            }
            
        }
        
        return maxLen;
    }


    EFFICIENT METHOD(VVVV Important Question)

    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    inc[i] = max(inc[i], inc[j] + 1);
                }
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    dec[i] = max(dec[i], dec[j] + 1);
                }
            }
        }
        
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if(inc[i] > 1 && dec[i] > 1){
                maxLen = max(maxLen, inc[i] + dec[i] - 1);
            }
        }

        return maxLen;
    }

*/

/*
    673. Number of Longest Increasing Subsequence
    (https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dpArray(n + 1, 1);
        vector<int> count(n + 1, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dpArray[i] == 1 + dpArray[j]){
                        count[i] += count[j];
                    }else if(1 + dpArray[j] > dpArray[i]){
                        dpArray[i] = 1 + dpArray[j];
                        count[i] = count[j];
                    }
                }
                
            }
        }

        int LIS = *max_element(dpArray.begin(), dpArray.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dpArray[i] == LIS){
                ans += count[i];
            }
        }

        return ans;
    }

*/


/*

    1498. Number of Subsequences That Satisfy the Given Sum Condition
    (https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)
    I Didnot get this Intution, complete it again, do it again.. VVVIIII Question, good logic

    int MOD = 1000000007;

    int numSubseq(vector<int>& nums, int target) {
        vector<int> temp;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> preComputePow(n+1, 0);
        preComputePow[0] = 1;

        for(int i = 1; i <= n; i++){
            preComputePow[i] = (2 * preComputePow[i-1])%MOD;
        }
        int i = 0; 
        int j = nums.size()-1;
        while(i <= j){
            if(nums[i] + nums[j] > target){
                j--;
            }else{
                int s = preComputePow[j- i] % MOD;
                ans = (ans + s) % MOD;
                i++;
            }
        }

        return ans;
    }
*/

/*
    491. Non-decreasing Subsequences
    (https://leetcode.com/problems/non-decreasing-subsequences/description/)

    void allSubseq(vector<int> nums, vector<int> &temp, int prev, int i, set<vector<int>> &ans){
        if(i >= nums.size()){
            if(temp.size() >= 2){
                ans.insert(temp);
            }
            return;
        }

        if(prev == -1 || nums[i] >= nums[prev]){
            temp.push_back(nums[i]);
            allSubseq(nums, temp, i, i+1, ans);
            temp.pop_back();
        }

        allSubseq(nums, temp, prev, i+1, ans);

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> temp;
        allSubseq(nums, temp, -1, 0, ans);

        vector<vector<int>> ANS(ans.begin(), ans.end());
        return ANS;
    }

*/

/*

    334. Increasing Triplet Subsequence
    (https://leetcode.com/problems/increasing-triplet-subsequence/description/)

    bool increasingTriplet(vector<int>& nums) {
        
        int firstSmall = INT_MAX;
        int secondSmall = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] < firstSmall){
                firstSmall = nums[i];
            }else if(nums[i] > firstSmall && nums[i] < secondSmall){
                secondSmall = nums[i];
            }

            if(nums[i] > firstSmall && nums[i] > secondSmall){
                return true;
            }
        }
        return false;
    }
*/

/*

    392. Is Subsequence
    (https://leetcode.com/problems/is-subsequence/description/)

    bool isSubseq(string &s, string &t, int i, int j, vector<vector<int>> &dpArray){
        
        if(j >= t.length()){
            if(i >= s.length()){
                return true;
            }
            return false;
        }

        if(i >= s.length()){
            return true;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        bool subseq = false;
        if(s[i] == t[j]){
            bool inc = isSubseq(s, t, i+1, j+1, dpArray);
            bool exc = isSubseq(s, t, i, j+1, dpArray);
            subseq = inc || exc ;
        }else{
            subseq = isSubseq(s, t, i, j+1, dpArray);
        }
        dpArray[i][j] = subseq;
        return dpArray[i][j];
    }

    bool isSubsequence(string s, string t) {
        vector<vector<int>> dpArray(s.length()+1, vector<int>(t.length()+1, -1));
        return isSubseq(s, t, 0, 0, dpArray);
    }
        
*/