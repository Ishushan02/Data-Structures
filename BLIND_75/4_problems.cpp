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

/*
    Problem 51
    230. Kth Smallest Element in a BST
    (https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

    void getElements(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }

        getElements(root->left, ans);
        ans.push_back(root->val);
        getElements(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        getElements(root, ans);
        return ans[k-1];
    }

*/

/*
    Problem 52
    104. Maximum Depth of Binary Tree
    (https://leetcode.com/problems/maximum-depth-of-binary-tree/)

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);
        return max(l, r) + 1;
    }

    int maxDepth(TreeNode* root) {
        return height(root);
    }

*/

/*
    Problem 53
    105. Construct Binary Tree from Preorder and Inorder Traversal
    (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

    TreeNode* Tree(vector<int>& preorder, vector<int>& inorder, int &preidx, int inStart, int inEnd){
        if(preidx >= preorder.size()){
            return NULL;
        }
        if(inStart > inEnd){
            return NULL;
        }
        // cout << preorder[preidx] << " : " << inStart << " , " << inEnd << endl;
        TreeNode* root = new TreeNode(preorder[preidx]);
        auto it = find(inorder.begin(), inorder.end(), preorder[preidx]);
        preidx++;
        int inorderIdx = distance(inorder.begin(), it);
        root->left = Tree(preorder, inorder, preidx, inStart, inorderIdx-1);
        root->right = Tree(preorder, inorder, preidx, inorderIdx+1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {


        int n = preorder.size();
        int preidx = 0;
        return Tree(preorder, inorder, preidx, 0, n-1);
    }
*/

/*
    Problem 54
    238. Product of Array Except Self
    (https://leetcode.com/problems/product-of-array-except-self/)

    vector<int> productExceptSelf(vector<int>& nums) {
        
        long long int prod = 1;
        vector<int> ans(nums.size(), 0);
        int zerCount = 0;
        for(auto v: nums){
            if(v == 0){
                zerCount++;
            }else{
                prod = prod * v;
            }
        }

        if(zerCount > 1){
            return ans;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans[i] = prod;
            }else if(zerCount == 1){
                ans[i] = 0;
            }else{
                ans[i] = prod/nums[i];
            }   
            
        }

        return ans;
    }
*/

/*
    Problem 55
    242. Valid Anagram
    (https://leetcode.com/problems/valid-anagram/)

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for(auto c:s){
            mapS[c]++;
        }

        for(auto c:t){
            mapT[c]++;
        }

        for(auto &[key, val]:mapS){
            if(mapT.find(key) == mapT.end()){
                return false;
            }else{
                if(val != mapT[key]){
                    return false;
                }
            }
        }
        return true;

    }

*/

/*  
    Problem 56
    371. Sum of Two Integers
    (https://leetcode.com/problems/sum-of-two-integers/)

    int getSum(int a, int b) {
        
        int sum = a ^ b;
        int carry = a & b;
        carry = carry << 1;

        if(carry != 0){
            sum = getSum(sum, carry);
        }

        return sum;
    }

*/

/*
    Problem 57
    125. Valid Palindrome
    (https://leetcode.com/problems/valid-palindrome/)

    bool isPalindrome(string s) {
        string modified;


        for(auto c:s){
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){
                modified += c;
            }else if(c >= 'A' && c <= 'Z'){
                cout << c << endl;
                char x = c + 32;
                // cout <<  x  << endl;
                modified += x;
            }
        }

        int i = 0;
        int j = modified.length()-1;

        while(i <= j){
            if(modified[i] != modified[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
*/