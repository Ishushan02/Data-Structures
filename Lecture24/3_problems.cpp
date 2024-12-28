/*
    347. Top K Frequent Elements
    (https://leetcode.com/problems/top-k-frequent-elements/description/)


    class Info{
        public: 
        int key;
        int val;

        Info(int a, int b){
            key = a;
            val = b;
        }
    };

    class Solution {
    public:

        struct comp{
            bool operator()(Info* a, Info* b){
                return a->val < b->val;
            }
        };

        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> ans;
            unordered_map<int, int> mapVal;
            for(int i = 0; i<nums.size(); i++){
                mapVal[nums[i]]++;
            }

            priority_queue<Info*, vector<Info*>, comp> que;
            
            for(auto data:mapVal){
                Info* temp = new Info(data.first, data.second);
                que.push(temp);
            }

            while(k){
                Info* top = que.top();
                que.pop();
                ans.push_back(top->key);
                k--;
            }
            

            return ans;
        }
    };
*/

/*
    1753. Maximum Score From Removing Stones
    (https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

    int maximumScore(int a, int b, int c) {
        priority_queue<int> que;

        que.push(a);
        que.push(b);
        que.push(c);

        int ans = 0;

        while(true && que.size() > 1){
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            a = a - 1;
            b = b - 1;
            ans += 1;
            if(a != 0){
                que.push(a);
            }
            if(b != 0){
                que.push(b);
            }
            
        }

        return ans;
    }
*/


/*

    355. Design Twitter

*/