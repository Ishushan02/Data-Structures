/*

    LIS - Patterns

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
    1048. Longest String Chain (TLE)
    (https://leetcode.com/problems/longest-string-chain/)

    struct check{
        bool operator()(string &a, string &b){
            return a.length() < b.length();
        }
    };

    bool checkSubsequences(string &a, string &b, string &temp, int i, map<pair<string, int>, bool> &dpMap){
        if(i >= b.length()){
            if(temp == a){
                return true;
            }
            return false;
        }

        if(temp == a){
            return true;
        }

        if(dpMap.find({temp, i}) != dpMap.end()){
            return dpMap[{temp, i}];
        }

        string pre = temp;
        bool inc = false;
        temp += b[i];
        inc = checkSubsequences(a, b, temp, i+1, dpMap);
        bool exc = checkSubsequences(a, b, pre, i+1, dpMap);    

        dpMap[{temp, i}] = inc || exc;
        return dpMap[{temp, i}];

    }

    int getSubsequences(vector<string>& words, int prev, int i, vector<vector<int>> &dpArray){

        if(i >= words.size()){
            return 0;
        }

        if(dpArray[i][prev+1] != -1){
            return dpArray[i][prev+1];
        }

        int include = 0;
        string temp;
        map<pair<string, int>, bool> dpMap;
        if(prev == -1 || ((words[prev].length() == words[i].length() - 1) && (checkSubsequences(words[prev], words[i], temp, 0, dpMap)))){
            include = 1 + getSubsequences(words, i, i+1, dpArray);
        }

        int exclude = getSubsequences(words, prev, i+1, dpArray);
        dpArray[i][prev+1] = max(include, exclude);
        return dpArray[i][prev+1];

    }


    int longestStrChain(vector<string>& words) {
        
        // sort(words.begin(), words.end(), check());
        int n = words.size();
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, -1));

        return getSubsequences(words, -1, 0, dpArray);

        // return ans;
    }
*/