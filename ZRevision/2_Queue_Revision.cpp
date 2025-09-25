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


/*
    2653. Sliding Subarray Beauty
    (https://leetcode.com/problems/sliding-subarray-beauty/description/)

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        vector<int> vecNum(102, 0);
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < k; i++){
            int idx = nums[i] + 50;
            vecNum[idx] += 1;
        }

        int prevIdx = 0;
        for(int i = k; i < n; i++){

            bool gotAns = false;    
            int count = x;

            for(int j = 0; j < 50; j++){
                if(vecNum[j] > 0){
                    if(count > vecNum[j]){
                        count -= vecNum[j];
                    }else{
                        count = 0;
                    }
                }
                if(count == 0){
                    gotAns = true;
                    ans.push_back(j - 50);
                    break;
                }

            }

            vecNum[nums[prevIdx] + 50] -= 1;
            prevIdx += 1;

            if(!gotAns) ans.push_back(0);
            int idx = nums[i] + 50;
            vecNum[idx] += 1;
        }

        bool gotAns = false;    
        int count = x;

        for(int j = 0; j < 50; j++){
            if(vecNum[j] > 0){
                if(count > vecNum[j]){
                    count -= vecNum[j];
                }else if(count < vecNum[j]){
                    vecNum[j] = vecNum[j] - count;
                    count = 0;
                }else{
                    vecNum[j] = 0;
                    count = 0;
                }
            }
            if(count == 0){
                gotAns = true;
                ans.push_back(j - 50);
                break;
            }

        }
        if(!gotAns) ans.push_back(0);

        return ans;
    }
*/


/*
    2327. Number of People Aware of a Secret
    (https://leetcode.com/problems/number-of-people-aware-of-a-secret/)

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<long long int> allAwarePerson(2 * n, 0);
        allAwarePerson[1] = 1;
        int mod = 1e9 + 7;

        for(int i = 1; i <= n; i++){
            for(int j = i + delay; j < i + forget; j++){
                allAwarePerson[j] = (allAwarePerson[i] + allAwarePerson[j]) % mod;
            }
        }

        long long int ans = 0;

        for(int i = n; i >= n - forget + 1; i--){
            ans += (allAwarePerson[i]);
            ans = ans % mod;
        }

        return ans;
    }
        
*/