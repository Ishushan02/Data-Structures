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

/*

    Very Good Question
    907. Sum of Subarray Minimums (TLE)
    (https://leetcode.com/problems/sum-of-subarray-minimums/)

    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int minVal = arr[i];
            for(int j = i; j < n; j++){
                minVal = min(minVal, arr[j]);
                ans += minVal;
            }
            ans = ans % 1000000007;
        }

        return ans % 1000000007;
    }

    

*/