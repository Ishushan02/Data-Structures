
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

/*
    Sum of nodes on the longest path
    (https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

    int sumNodes(Node* root, int prevSum, int height, unordered_map<int, int> &ansMap){
        if(root == NULL){
            return 0;
        }
        // cout << root->data << " " << height << " - " << prevSum + root->data << endl;
        if(root->left == NULL && root->right == NULL){
            if(ansMap.find(height) == ansMap.end()){
                ansMap[height] = prevSum + root->data;
            }else{
                int temp = ansMap[height];
                ansMap[height] = max(prevSum+ root->data, temp);
            }
        }
        sumNodes(root->left, prevSum + root->data, height + 1, ansMap);
        sumNodes(root->right, prevSum + root->data, height + 1, ansMap);
        
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int ans = 0;
        if(root == NULL){
            return ans;
        }
        unordered_map<int, int> ansMap;
        int maxH = INT_MIN;
        sumNodes(root, 0, 0, ansMap);
        for(auto val:ansMap){
            // cout << val.first << ": " << val.second << endl;
            if(val.first > maxH){
                maxH = val.first;
                ans = val.second;
            }
        }
        return ans;
        
    }


    Method 2 (Good Method )

    pair<int, int> MaxSum(Node* root){
        if(root == NULL){
            return {0, 0};
        }
        
        auto lheight = MaxSum(root->left);
        auto rheight = MaxSum(root->right);
        
        int maxSum = root->data;
        
        if(lheight.first == rheight.first){ //comparing height
            if(lheight.second > rheight.second){
                maxSum += lheight.second;
            }else{
                maxSum += rheight.second;
            }
        }else if(lheight > rheight){
            maxSum += lheight.second;
        }else{
            maxSum += rheight.second;
        }
    
        return {max(lheight.first, rheight.first) + 1, maxSum};      
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        auto Sum = MaxSum(root);
        return Sum.second;
    }
    
*/