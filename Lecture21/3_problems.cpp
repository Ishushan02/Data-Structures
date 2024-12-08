/*

    DO IT GOOD QUESTION 
    2653. Sliding Subarray Beauty - Time limit Exceeded
    (https://leetcode.com/problems/sliding-subarray-beauty/)

    void rearrange(deque<int>& que, int idx, vector<int>& nums){
        if(que.empty()){
            que.push_back(idx);
            return ;
        }

        int val = que.back();
        if(nums[idx] > nums[val]){
            que.pop_back();
            rearrange(que, idx, nums);
            que.push_back(val);
        }else{
            que.push_back(idx);
        }

        return;

    }

    void storeans(vector<int>& ans, deque<int>& que, int count, int x, int k, vector<int>& nums){
        
        vector<int> store;

        if(x > k){
            ans.push_back(0);
            return;
        }

        for(int i = 0; i < x-1; i++){
            store.push_back(que.back());
            que.pop_back();
        }


        if(nums[que.back()] < 0){
            ans.push_back(nums[que.back()]);
        }
        

        reverse(store.begin(), store.end());

        
        for(auto i:store){
            que.push_back(i);
        }

        return;

    }

    void deleteelem(deque<int>& que, int k, int idx, int &negcnt, vector<int> &nums){
        
        vector<int> store;

        while(!que.empty()){
            int val = que.front();
            if(idx - val >= k){
                if(nums[val] < 0){
                    negcnt -= 1;
                }
                que.pop_front();
            }else{
                store.push_back(val);
                que.pop_front();
            }  
        }
        
        for(auto i:store){
            que.push_back(i);
        }

        return ;
    }


    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        deque<int> que;
        vector<int> ans;

        int negcount = 0;
        for(int i = 0; i < k; i++){
            int curr = nums[i];
            if(que.empty()){
                que.push_back(i);
            }else{
                rearrange(que, i, nums);
            }
            if(curr < 0){
                negcount += 1;
            }
            
        }

        
        for(int idx = k; idx < nums.size(); idx++){

            if(negcount < x ){
                ans.push_back(0);
            }else{
                storeans(ans, que, 0, x, k, nums);
            }
    
            deleteelem(que, k, idx, negcount, nums);
        
            
            rearrange(que, idx, nums);
            // printqueue(que, nums);
            if(nums[idx] < 0){
                negcount += 1;
            }

        }
        
        
        // store answer for last window
        if(negcount < x ){
            ans.push_back(0);
        }else{
            storeans(ans, que, 0, x, k, nums);
        }

        
        // storeans(ans, que, 0, x, k, nums);

        return ans;

    }
*/

/*

IMPLEMENT K QUEUES IN AN ARRAY 

    - Very Important Question based on Interviews Perspective

Method 1 Brute Force Approach

    let's array of size (N)4 and k with (K)2 hence there will be (N / K) total queses possible
    here in this case 2 queues will be possible, (for this example both are of size 4 each)
    - We create Q1(0 -> 3) and Q2(4 -> 8) 
    let's say Q1 is filled comwith 4 elemets and next elemet is to be filled, what it will do is 
    while inserting Q1 it will throw error saying Q1 is fully filled
    - but array is still not completely filled, hence this is not an optimal Use of Space
    - This is known as Fragmentation Problem (even though space is available we are not able to insert elements in the queue)
    - So, this method is discarded


Method 2

*/