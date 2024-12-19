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