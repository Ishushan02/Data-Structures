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