/*

    Problem 101
    (https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)
    1373. Maximum Sum BST in Binary Tree

    struct NodeBlock{
        // int TreeNode* node;
        int sum = 0;
        bool isBST = false;
        int min = 500000;
        int max = -500000;
    };  

    class Solution {
    public:

        NodeBlock traverseNodes(TreeNode* root, int &maxSum){
            if(root == NULL){
                NodeBlock nb;
                nb.isBST = true;
                return nb;
            }

            NodeBlock leftNodes = traverseNodes(root->left, maxSum);
            NodeBlock rightNodes = traverseNodes(root->right, maxSum);
            NodeBlock currentNode;
            if(
            leftNodes.isBST && 
            rightNodes.isBST && 
            root->val > leftNodes.max && 
            root->val < rightNodes.min){
            currentNode.isBST = true;
            currentNode.sum = root->val + leftNodes.sum + rightNodes.sum;
                maxSum = max(maxSum, currentNode.sum);
                currentNode.min = min(root->val, leftNodes.min);
                currentNode.max = max(root->val, rightNodes.max);
                return currentNode;
            }
            
            currentNode.isBST = false;
            return currentNode;
        }


        int maxSumBST(TreeNode* root) {
            int maxSum = 0;
            auto n = traverseNodes(root, maxSum);

            return maxSum;
        }
    };
*/