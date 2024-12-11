#include<iostream>

using namespace std;

/*
    (104. Maximum Depth of Binary Tree)
    (https://leetcode.com/problems/maximum-depth-of-binary-tree/)

    int depth(TreeNode* root, int ldepth, int rdepth){
        if(root == NULL){
            return 0;
        }
        
        ldepth = depth(root->left, ldepth + 1, rdepth);
        rdepth = depth(root->right, ldepth, rdepth + 1);

        return max(ldepth, rdepth) + 1;

    }

    int maxDepth(TreeNode* root) {
        int maxdepth = depth(root, 0, 0);
        return maxdepth;
    }

*/