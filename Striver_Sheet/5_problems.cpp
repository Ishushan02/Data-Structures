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

/*

    Problem 102
    (https://leetcode.com/problems/max-consecutive-ones/)
    485. Max Consecutive Ones

    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0;
        int maxcnt = 0;

        for(auto i: nums){
            if(i == 1){
                cnt += 1;
                maxcnt = max(maxcnt, cnt);
            }else{
                cnt = 0;
            }
        }
        return maxcnt;
    }

*/

/*
    Problem 103
    (https://leetcode.com/problems/next-greater-element-i/)
    496. Next Greater Element I
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nextGreater;
        for(int i = 0; i < nums2.size(); i++){
            int num = nums2[i];
            int nextNum = -1;
            for(int j = i + 1; j < nums2.size(); j++){
                if(nums2[j] > num){
                    nextNum = nums2[j];
                    break;
                }
            }
            nextGreater.push_back(nextNum);
        }

        
        unordered_map<int, int> idxMap2;
        for(int i = 0; i < nums2.size();i++ ){
            idxMap2[nums2[i]] = i;
        }

        vector<int> ans;
        unordered_map<int, int> idxMap1;
        for(int i = 0; i < nums1.size();i++ ){
            int idx = idxMap2[nums1[i]];
            ans.push_back(nextGreater[idx]);
        }
        return ans;
    }
*/