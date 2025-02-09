/*
    Sliding Windowe Applications

    - Same Size Sliging Window Application (Priority Queue)
    - Different Size Sliding Window Application 
    - 2 pointer Approach



*/

/*
    239. Sliding Window Maximum
    (https://leetcode.com/problems/sliding-window-maximum/)

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;

        int maxNum = -1;
        int maxIdx = 0;
        for(int i = 0; i < k; i++){
            
            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }

            que.push_back(i);
        }

        vector<int> ans;
        for(int i = k; i < nums.size(); i++){

            ans.push_back(nums[que.front()]);

            while(!que.empty() && i - que.front() >= k){
                que.pop_front();
            }

            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }

            que.push_back(i);
        }

        ans.push_back(nums[que.front()]);

        return ans;


    }

*/

/*  

    Vry Important APplication of Variable Size SUbaray

    209. Minimum Size Subarray Sum
    (https://leetcode.com/problems/minimum-size-subarray-sum/description/)

        - Variable size Window Application
        - If Sum < target expand the Window 
        - If Sum >= target shrink the Window


    int minSubArrayLen(int target, vector<int>& nums) {

        int ans = INT_MAX;

        int start = 0;
        int end = 0;
        int n = nums.size();
        int sum = 0;

        while(end < n){
            sum += nums[end];

            while(sum >= target){
                // shrink
                ans = min(ans, end - start + 1);

                sum = sum - nums[start];
                start++;
            }
            
            // expand
            end++;
            
        }

        if(ans == INT_MAX){
            return 0;
        }

        return ans;

    }


*/


/*
    1. Two Sum
    (https://leetcode.com/problems/two-sum/description/)

    struct comp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        
        // 

        vector<pair<int, int>> values;

        int start = 0;
        int end = nums.size() - 1;

        for(int i = 0; i < nums.size(); i++){
            values.push_back({nums[i], i});
        }

        sort(values.begin(), values.end(), comp());

        while(start < end){
            int sum = values[start].first + values[end].first;

            // cout << start << ", "<< end  << " : " << sum << endl;

            if(sum == target){
                return {values[start].second, values[end].second};
            }

            if(sum > target){
                end = end - 1;
                // cout << " Mod:, end "<< end << endl;
            }else{
                start = start + 1;
                // cout << " Mod:, start "<< start << endl;

            }
        }

        return {0, 0};
    }

    
*/