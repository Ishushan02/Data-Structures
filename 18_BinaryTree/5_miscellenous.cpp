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