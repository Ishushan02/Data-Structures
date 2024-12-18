
/*

    Morris Traversal :- Google Interview Question

    It is sama as to that of Inorder Traversal, but the difference is in Space Complexity

    Inorder Traversal - Time Complexity O(n), Space Complexity O(n)
    Morris Traversal - Time Complexity O(n), Space Complexity O(1) {Space Difference}

    94. Binary Tree Inorder Traversal
    (https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* currNode = root;

        while(currNode){

            if(currNode->left == NULL){
                ans.push_back(currNode->val);
                currNode = currNode->right;
            }else{

                TreeNode* predecessor = currNode->left;

                while(predecessor->right != currNode && predecessor->right){
                    predecessor = predecessor->right;
                }

                if(predecessor->right == NULL){
                    predecessor->right = currNode;
                    currNode = currNode->left;
                }else{
                    predecessor->right = NULL;
                    ans.push_back(currNode->val);
                    currNode = currNode->right;
                }

            }
        }


        return ans;
    }

*/

/*
    114. Flatten Binary Tree to Linked List (Think Like Morris Traversal)
    (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

    void flatten(TreeNode* root) {
        
        if(root == NULL){
            return ;
        }

        TreeNode* currNode = root;

        while(currNode){
            // like Morris Traversal point get the right most and pin it to root->right
            if(currNode->left){
                TreeNode* predecessor = currNode->left;
                while(predecessor->right){
                    predecessor = predecessor->right;
                }

                predecessor->right = currNode->right;
                currNode->right = currNode->left;
                currNode->left = nullptr;
                
            }
            currNode = currNode->right;

        }

    }
*/