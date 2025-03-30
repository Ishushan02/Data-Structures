/*
    Problem 46
    347. Top K Frequent Elements
    (https://leetcode.com/problems/top-k-frequent-elements/)

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> valMap;
        for(auto v:nums){
            valMap[v]++;
        }

        priority_queue<pair<int, int>> que;

        vector<int> ans;
        int count = 0;
        for(auto &[key, val]:valMap){
            que.push({val, key});
        }

        while(k && !que.empty()){
            auto c = que.top();
            ans.push_back(c.second);
            que.pop();
            k--;
        }

        return ans;

    }
*/

/*
    Problem 47
    98. Validate Binary Search Tree
    (https://leetcode.com/problems/validate-binary-search-tree/)

    bool isBST(TreeNode* root, long minVal, long maxVal){
        if(root == NULL){
            return true;
        }

        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        
        return isBST(root->left, LONG_MIN, root->val) && isBST(root->right, root->val, LONG_MAX);
    }
        
*/