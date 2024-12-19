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