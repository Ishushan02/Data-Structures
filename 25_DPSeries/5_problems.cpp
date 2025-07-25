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