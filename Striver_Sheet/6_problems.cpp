/*
    31. Next Permutation
    (https://leetcode.com/problems/next-permutation/)
    
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());

        priority_queue<int> que;
        int n = nums.size();

        for(int i = n-1; i >= 0; i--){
            int num = nums[i];
            que.push(num);
            if(que.top() != num){
                priority_queue<int, vector<int>, greater<int>> minque;
                int prev = num;

                while(que.top() != num){
                    prev = que.top();
                    que.pop();
                    if(que.top() == num){
                        break;
                    }
                    minque.push(prev);
                }
                nums[i] = prev;
                
                while(!que.empty()){
                    minque.push(que.top());
                    que.pop();
                }

                for(int j = i + 1; j < n; j++){
                    nums[j] = minque.top();
                    minque.pop();
                }

                return ;
            }
        }

        reverse(nums.begin(), nums.end());
    }
        
*/