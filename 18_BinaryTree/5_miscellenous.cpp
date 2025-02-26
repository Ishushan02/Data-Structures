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