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

/*
    Problem 48
    226. Invert Binary Tree
    (https://leetcode.com/problems/invert-binary-tree/)

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()){

            TreeNode* top = que.front();
            que.pop();

            if(top->left != NULL && top->right != NULL){
                que.push(top->right);
                que.push(top->left);
                cout << top->left->val << " , "<< top->right->val << endl;
                swap(top->left, top->right);

            }else if(top->left != NULL && top->right == NULL){
                que.push(top->left);
                TreeNode* newNode = top->left;
                top->left = NULL;
                top->right = newNode;
            }else if(top->left == NULL && top->right != NULL){
                que.push(top->right);
                TreeNode* newNode = top->right;
                top->right = NULL;
                top->left = newNode;
            }else{
                
            }
        }

        return root;

    }

*/

/*
    Problem 49
    100. Same Tree
    (https://leetcode.com/problems/same-tree/)

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL){
            return false;
        }else if (p != NULL && q == NULL){
            return false;
        }else if(p == NULL && q == NULL){
            return true;
        }

        if(p->val != q->val){
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
*/

/*
    Problem 50
    102. Binary Tree Level Order Traversal
    (https://leetcode.com/problems/binary-tree-level-order-traversal/)

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        
        
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;

            for(int i = 0; i < size; i++){
                TreeNode* fr = que.front();
                temp.push_back(fr->val);

                if(fr->left){
                    que.push(fr->left);
                }
                if(fr->right){
                    que.push(fr->right);
                }
                que.pop();
            }
            res.push_back(temp);
        }

        return res;

    }

*/