/*

    239. Sliding Window Maximum (VVIII Question)
    (https://leetcode.com/problems/sliding-window-maximum/description/)

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // always try using deque as we can perform back operation on it
        deque<int> que;
        vector<int> ans;

        for(int i = 0; i< k; i++){

            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }

        for(int i = k; i < nums.size(); i++){

            // store answer for prev window
            ans.push_back(nums[que.front()]);

            // remove if prev window idx exist
            if(!que.empty() && i - que.front() >= k){
                que.pop_front();
            }

            // remove any smaller elem's from the window from back
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

    Stream First Non-repeating
    (https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1 )

    string FirstNonRepeating(string &s) {
        // Code here
        
        unordered_map<char, int> charCount;
        queue<char> que;
        string ans;
        
        for(int i = 0; i < s.length(); i++){
            charCount[s[i]] += 1;
            que.push(s[i]);
            
            while(!que.empty()){
                
                if(charCount[que.front()] == 1){
                    ans += que.front();
                    break;
                }else{
                    que.pop();
                }
            }
            
            if(que.empty()){
                ans += '#';
            }
            
        }
        
        return ans;
    }
*/



/*
    Very Good Question, Do it again n again

    Procedure: (Simple thinking, maxSum is totalSum - minSum)
    // Use Kadanes Algorithm
        - get totalSum of the Array
        - get maxSum of the Array
        - get minSum of the Array

    if(maxSum < 0 && totSum < 0) -- >this means that all elements are negative
        - hence return the max(totalSum, maxSum)

    check max(totalSum - minSum, maxSum) --> return ans;


    918. Maximum Sum Circular Subarray
    https://leetcode.com/problems/maximum-sum-circular-subarray/

    int maxSubarraySumCircular(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int minsum = 0;
        int maxsum = 0;

        for(int i = 0; i < n; i++){

            minsum += nums[i];
            maxsum += nums[i];

            maxSum = max(maxSum, maxsum);
            minSum = min(minSum, minsum);

            if(maxsum < 0){
                maxsum = 0;
            }

            if(minsum > 0){
                minsum = 0;
            }
        }

        // cout << "Total Sum: " << totalSum << " MinSum: " << minSum << " MaxSum: " << maxSum << endl;

        if(totalSum < 0 && maxSum < 0){
            return max(totalSum, maxSum);
        }

        int ans = max(totalSum - minSum, maxSum);
        return ans;
    }


*/
