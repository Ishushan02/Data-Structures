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