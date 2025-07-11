/*
    654. Maximum Binary Tree
    (https://leetcode.com/problems/maximum-binary-tree/description/)

    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start < 0 || end >= nums.size() || start >= nums.size() || end < 0){
            return NULL;
        }

        int maxIdx = -1;
        int maxElem = INT_MIN;
        for(int i = start; i <= end; i++){
            if(nums[i] > maxElem){
                maxElem = nums[i];
                maxIdx = i;
            }
        }
        cout << "start: "<< start << " End: "<< end << " :- " << maxIdx  << endl;
        TreeNode* newNode = NULL;
        if(maxIdx != -1){
            TreeNode* newNode = new TreeNode(nums[maxIdx]);
            newNode->left = buildTree(nums, start, maxIdx -1);
            newNode->right = buildTree(nums, maxIdx + 1, end);
            return newNode;
        }
        
        return newNode;

    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return buildTree(nums, 0, nums.size()-1);
    }
        
*/

/*
    111. Minimum Depth of Binary Tree
    (https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

    void height(TreeNode* root, int h, int &minHeight){
        if(root == NULL){
            return ;
        }

        if(root->left == NULL && root->right == NULL){
            minHeight = min(minHeight, h);
        }

        height(root->left, h + 1, minHeight);
        height(root->right, h + 1, minHeight);        

    }

    int minDepth(TreeNode* root) {
        
        int minHeight = INT_MAX;

        height(root, 1, minHeight);

        if(minHeight == INT_MAX){
            return 0;
        }
        return minHeight;
    }

*/

/*
    226. Invert Binary Tree
    (https://leetcode.com/problems/invert-binary-tree/description/)

    void invert(TreeNode* &root){
        if(root == NULL){
            return ;
        }

        // cout << root->left->val << " , " << root->right->val << endl;
        invert(root->left);
        invert(root->right);
        swap(root->left, root->right);

    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* leftV = root->left;
        TreeNode* rightV = root->right;

        invert(root);

        root->right = leftV;
        root->left = rightV;

        return root;
    }
*/

/*
    257. Binary Tree Paths
    (https://leetcode.com/problems/binary-tree-paths/description/)

    void traverse(TreeNode* root, string path, vector<string> &ans){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            // path +=  "->" + to_string(root->val);
            ans.push_back(path + to_string(root->val));
            // path.pop_back();
        }
        
        traverse(root->left, path +to_string(root->val) + "->", ans);
        traverse(root->right, path +to_string(root->val) + "->", ans);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        traverse(root, path, ans);
        return ans;
    }

*/

/*
    404. Sum of Left Leaves
    (https://leetcode.com/problems/sum-of-left-leaves/description/)

    void traverse(TreeNode* root, int &sum){
        if(root == NULL){
            return ;
        }

        if(root->left){
            if(root->left->left == NULL && root->left->right == NULL){
                sum += root->left->val;
            }
        }

        traverse(root->left, sum);
        traverse(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
        
*/

/*
    1123. Lowest Common Ancestor of Deepest Leaves
    (https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)

    int getParent(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root== NULL){
            return 0;
        }

        int l = getParent(root->left, p, q, ans);
        int r = getParent(root->right, p, q, ans);

        int mid = (root == p || root == q);

        if(l + r + mid >= 2){
            ans = root;
        }

        return l || r || mid;
    }



    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        unordered_map<int, vector<TreeNode*>> depthMap;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        int maxDepth = 0;

        while(!que.empty()){
            int size = que.size();

            for(int i = 0; i < size; i++){
                TreeNode* top = que.front();
                que.pop();

                if(top->left){
                    que.push(top->left);
                }

                if(top->right){
                    que.push(top->right);
                }
                depthMap[depth].push_back(top);
                maxDepth = max(maxDepth, depth);
            }
            depth += 1;
        }

        vector<TreeNode*> ansNodes = depthMap[maxDepth];

        if(ansNodes.size() == 1){
            return ansNodes[0];
        }else{

            TreeNode* parent = ansNodes[0];
            for(int i = 1; i < ansNodes.size(); i++){
                // TreeNode* 
                int a = getParent(root, parent, ansNodes[i], parent);
                // cout << parent->val << endl;
            }
            return parent;
        }



        return NULL;
    }


    OPTIMIZED

    pair<TreeNode*, int> getMaxDepthParentNode(TreeNode* root){
        if(root == NULL){
            return {NULL, 0};
        }

        pair<TreeNode*, int> leftNodes = getMaxDepthParentNode(root->left);
        pair<TreeNode*, int> rightNodes = getMaxDepthParentNode(root->right);

        if(leftNodes.second == rightNodes.second){
            return {root, leftNodes.second + 1};
        }else if(leftNodes.second > rightNodes.second){
            return {leftNodes.first, leftNodes.second + 1};
        }

        return {rightNodes.first, rightNodes.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        pair<TreeNode*, int> ansVal = getMaxDepthParentNode(root);

        return ansVal.first;
    }

*/


/*
    865. Smallest Subtree with all the Deepest Nodes
    (https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

    int getParent(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root== NULL){
            return 0;
        }

        int l = getParent(root->left, p, q, ans);
        int r = getParent(root->right, p, q, ans);

        int mid = (root == p || root == q);

        if(l + r + mid >= 2){
            ans = root;
        }

        return l || r || mid;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        unordered_map<int, vector<TreeNode*>> depthMap;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        int maxDepth = 0;

        while(!que.empty()){
            int size = que.size();

            for(int i = 0; i < size; i++){
                TreeNode* top = que.front();
                que.pop();

                if(top->left){
                    que.push(top->left);
                }

                if(top->right){
                    que.push(top->right);
                }
                depthMap[depth].push_back(top);
                maxDepth = max(maxDepth, depth);
            }
            depth += 1;
        }

        vector<TreeNode*> ansNodes = depthMap[maxDepth];

        if(ansNodes.size() == 1){
            return ansNodes[0];
        }else{

            TreeNode* parent = ansNodes[0];
            for(int i = 1; i < ansNodes.size(); i++){
                // TreeNode* 
                int a = getParent(root, parent, ansNodes[i], parent);
                // cout << parent->val << endl;
            }
            return parent;
        }



        return NULL;
    }

    OPTIMIZED

    pair<TreeNode*, int> getMaxDepthParentNode(TreeNode* root){
        if(root == NULL){
            return {NULL, 0};
        }

        pair<TreeNode*, int> leftNodes = getMaxDepthParentNode(root->left);
        pair<TreeNode*, int> rightNodes = getMaxDepthParentNode(root->right);

        if(leftNodes.second == rightNodes.second){
            return {root, leftNodes.second + 1};
        }else if(leftNodes.second > rightNodes.second){
            return {leftNodes.first, leftNodes.second + 1};
        }

        return {rightNodes.first, rightNodes.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        pair<TreeNode*, int> ansVal = getMaxDepthParentNode(root);

        return ansVal.first;
    }

*/

/*
    129. Sum Root to Leaf Numbers
    (https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)

    long long int valSum(TreeNode* root, int sum, long long int &ansSum){
        if(root == NULL){
            return sum;
        }
        if(root->left == NULL && root->right == NULL){
            ansSum += sum * 10 + root->val;
            // cout << sum * 10 + root->val << endl; 
        }

        int prev = sum * 10 + root->val;
        
        long long int left = valSum(root->left, prev, ansSum);
        long long int right = valSum(root->right, prev, ansSum);
        
        
        return left + right;
    }

    int sumNumbers(TreeNode* root) {
       long long int ansSum = 0;
       auto c =  valSum(root, 0, ansSum);
       return ansSum;
    }
       
*/

/*
    563. Binary Tree Tilt
    (https://leetcode.com/problems/binary-tree-tilt/description/)

    int sumDiff(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        int lSum = sumDiff(root->left, ans);
        int rSum = sumDiff(root->right, ans);

        // cout << root->val << " : " << lSum << " , " << rSum << endl;

        ans += abs(lSum - rSum);
        return root->val + lSum + rSum;
    }

    int findTilt(TreeNode* root) {
        int ans = 0;
        auto c =  sumDiff(root, ans);
        return ans;
    }
        
*/