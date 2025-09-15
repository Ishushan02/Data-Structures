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