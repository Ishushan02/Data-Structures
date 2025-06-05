/*

    Problem 51
    (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
    114. Flatten Binary Tree to Linked List

    void flattenCurrentNode(TreeNode* &root){
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        TreeNode* pred = root->left;

        while(pred->right){
            pred = pred->right;
        }

        root->right = NULL;
        pred->right = rightNode;
        root->left = NULL;
        root->right = leftNode;

    }

    void traverse(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left){
            flattenCurrentNode(root);
        }

        traverse(root->right);
    }

    void flatten(TreeNode* root) {
        traverse(root);
    }
        
*/