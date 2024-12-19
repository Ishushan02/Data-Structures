/*
    450. Delete Node in a BST
    (https://leetcode.com/problems/delete-node-in-a-bst/description/)

    int getMax(TreeNode* root){
        if(root == NULL){
            return -1;
        }

        while(root->right){
            root = root->right;
        }

        return root->val;
    }

    TreeNode* deleteBSTNode(TreeNode* root, int key){
        if(root == NULL){
            return NULL;
        }

        if(root->val == key){

            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
                TreeNode* leftchild = root->left;
                root->left = NULL;
                delete root;
                return leftchild;
            }else if(root->right != NULL && root->left == NULL){
                TreeNode* rightchild = root->right;
                root->right = NULL;
                delete root;
                return rightchild;
            }else{

                int maxVal = getMax(root->left);
                root->val = maxVal;

                root->left = deleteBSTNode(root->left, maxVal);

                return root;
            }

        }else{

            if(key < root->val){
                root->left = deleteBSTNode(root->left, key);
            }else{
                root->right = deleteBSTNode(root->right, key);
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* node = deleteBSTNode(root, key);

        return node;
    }

*/

/*
    653. Two Sum IV - Input is a BST
    (https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

    void preOrder(TreeNode* root, vector<int> &nodes){
        if(root == NULL){
            return ;
        }
        
        preOrder(root->left, nodes);
        nodes.push_back(root->val);
        preOrder(root->right, nodes);

    }

    bool twoPointerSum(vector<int> arr, int k){
        int start = 0;
        int n = arr.size();
        int end = n -1 ;

        while(start < end){
            int sum = arr[start] + arr[end];

            if(sum == k){
                return true;
            }
            else if(sum > k){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        
        vector<int> arr;
        preOrder(root, arr);

        return twoPointerSum(arr, k);
    }
*/

/*
    1038. Binary Search Tree to Greater Sum Tree
    (https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

    void getSum(TreeNode* root, TreeNode* currNode, int &ans){

        if(root == NULL){
            return ;
        }

        if(root->val > currNode->val){
            ans += root->val;
        }
        getSum(root->left, currNode, ans);
        getSum(root->right, currNode, ans);

    }

    void storeNodes(TreeNode* root, TreeNode* rootNode, unordered_map<int, int> &ansMap){
        if(root == NULL){
            return;
        }
        int ans = root->val;
        getSum(rootNode, root, ans);
        ansMap[root->val] = ans;

        
        storeNodes(root->left, rootNode, ansMap);
        storeNodes(root->right, rootNode, ansMap);

    }

    void changeNodes(TreeNode* &root, unordered_map<int, int> &ansMap){
        if(root == NULL){
            return;
        }
        root->val = ansMap[root->val];
        
        changeNodes(root->left, ansMap);
        changeNodes(root->right, ansMap);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        unordered_map<int, int> ansMap;
        storeNodes(root, root, ansMap);
        changeNodes(root, ansMap);
        // for(auto values:ansMap){
        //     // cout << values.first->val << " ParentNode: " << values.second->val << endl;
        //     // int sum = getSum(values.second, values.first->val, values.first->val);
        //     cout << values.first << ": " << values.second << endl;

        // }
        


        return root;

    }
*/

/*
    230. Kth Smallest Element in a BST
    (https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

    void inorderTraversal(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> arr;
        inorderTraversal(root, arr);

        return arr[k - 1];
    }


    // Method 2 (Same procedure without Space)

    // method 2 without extra O(n) space

    void inOrderTraversal(TreeNode* root, int &count, int &ans, int k){
        if(root == NULL){
            return ;
        }
        
        inOrderTraversal(root->left, count, ans, k);
        count = count + 1;
        if(count == k){
            ans = root->val;
            cout << ":--"<< ans << endl;
            // k = 100000;
        }
        inOrderTraversal(root->right, count, ans, k);

    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;
        inOrderTraversal(root, count, ans, k);

        return ans;
    }
*/