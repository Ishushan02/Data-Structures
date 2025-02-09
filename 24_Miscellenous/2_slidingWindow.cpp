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