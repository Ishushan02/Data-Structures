#include<iostream>

using namespace std;

/*
    // Simple but it is 1 of the Important Question
    (104. Maximum Depth of Binary Tree) 
    (https://leetcode.com/problems/maximum-depth-of-binary-tree/)

    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        ldepth = depth(root->left);
        rdepth = depth(root->right);

        return max(ldepth, rdepth) + 1;

    }

    int maxDepth(TreeNode* root) {
        int maxdepth = depth(root);
        return maxdepth;
    }

*/


/*
    543. Diameter of Binary Tree
    (https://leetcode.com/problems/diameter-of-binary-tree/description/)

    Method 1 O(n^2)

    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);

        return max(leftH, rightH) + 1;
    }


    int getDiameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        // option1 max diam is present in left part
        int opt1 = getDiameter(root->left);

        // option2 max height is present in right part
        int opt2 = getDiameter(root->right);

        // option 3 max diam is present in by combining both the height
        int opt3 = getHeight(root->left) + getHeight(root->right);

        int maxDiam = max(opt1, max(opt2, opt3));

        return maxDiam;

    }


    int diameterOfBinaryTree(TreeNode* root) {
        return getDiameter(root);
    }
*/


/*
    THE ABOVE 2 PROBLEMS ARE SO IMPORTANT PLEASE SEE THE LOGIC AGAIN AND AGAIN- VVVVVIIIIIIMPORTANT
*/


/*

    110. Balanced Binary Tree (Asked in Many IV Questions)
    (https://leetcode.com/problems/balanced-binary-tree/)

    int height(TreeNode* node){

        if(node == NULL){
            return 0;
        }

        int leftheight = height(node->left);
        int rightheight = height(node->right);

        return max(leftheight, rightheight) + 1;
    }

    bool balance(TreeNode* node){
        if(node == NULL){
            return true;
        }

        int lheight = height(node->left);
        int rheight = height(node->right);

        // cout << "Node: " << node->val << "-" << lheight << ", " << rheight << endl;
        
        // the upper node is balanced or not
        bool balanced = true;
        if(abs(lheight - rheight) > 1){
            balanced = false;
        }

        bool lbalanced = balance(node->left);
        bool rbalanced = balance(node->right);

        if(balanced && lbalanced && rbalanced){
            return true;
        }

        return false;
    }

    bool isBalanced(TreeNode* root) {
        return balance(root);
    }

*/

/*
    236. Lowest Common Ancestor of a Binary Tree
    (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

    bool ifexists(TreeNode* root, int checkNode){
        if(root == NULL){
            return false;
        }
        if(root->val == checkNode){
            return true;
        }

        bool lcheck = ifexists(root->left, checkNode);
        bool rcheck = ifexists(root->right, checkNode);

        return lcheck || rcheck ;
    }


    void checkNodes(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root == NULL){
            return ;
        }

        if(ifexists(root, p->val) && ifexists(root, q->val)){
            // ans = NULL;
            ans = root;
            cout << "Ans: " << ans->val << endl;
        }

        checkNodes(root->left, p, q, ans) ;
        checkNodes(root->right, p, q, ans) ;

        // return ans;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // cout << ifexists(root, -1) << endl;

        // root node is p
        if(ifexists(p, q->val)){
            return p;
        }

        // root node is q
        if(ifexists(q, p->val)){
            return q;
        }
        
        TreeNode* ans = NULL;
        checkNodes(root, p, q, ans);

        return ans;
    }

*/