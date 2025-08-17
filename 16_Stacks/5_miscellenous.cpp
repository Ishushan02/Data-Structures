/*
    503. Next Greater Element II
    (https://leetcode.com/problems/next-greater-element-ii/)

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++){
            int j = i + 1;
            int loop = n;
            bool temp = false;
            while(loop){
                int idx = j % n;
                if(nums[idx] > nums[i]){
                    temp = true;
                    ans.push_back(nums[idx]);
                    break;
                }
                j += 1;
                loop -= 1;
            }
            if(temp == false){
                ans.push_back(-1);
            }
        }

        return ans;
    }
        
*/