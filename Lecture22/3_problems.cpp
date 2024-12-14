#include <iostream>
using namespace std;

/*
    102. Binary Tree Level Order Traversal
    (https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        vector< vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        que.push(make_pair(root, 0));
        // int height = 0;
        unordered_map<int, vector<int>> storeAns;
        int minheight = INT_MAX;
        int maxheight = INT_MIN;
        while(!que.empty()){

            pair<TreeNode*, int> topelemPair =  que.front();
            TreeNode* topNode = topelemPair.first;
            int height = topelemPair.second;

            minheight = min(minheight, height);
            maxheight = max(maxheight, height);

            que.pop();

            storeAns[height].push_back(topNode->val);

            // cout << topNode->val << " ";

            if(topNode->left){
                que.push(make_pair(topNode->left, height + 1));
            }

            if(topNode->right){
                que.push(make_pair(topNode->right, height + 1));
            }

        }

        for(int i = minheight; i <= maxheight; i++){
            ans.push_back(storeAns[i]);
        }

        return ans;
    }
*/

/*
    107. Binary Tree Level Order Traversal II
    (https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        vector< vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        que.push(make_pair(root, 0));
        // int height = 0;
        unordered_map<int, vector<int>> storeAns;
        int minheight = INT_MAX;
        int maxheight = INT_MIN;
        while(!que.empty()){

            pair<TreeNode*, int> topelemPair =  que.front();
            TreeNode* topNode = topelemPair.first;
            int height = topelemPair.second;

            minheight = min(minheight, height);
            maxheight = max(maxheight, height);

            que.pop();

            storeAns[height].push_back(topNode->val);

            // cout << topNode->val << " ";

            if(topNode->left){
                que.push(make_pair(topNode->left, height + 1));
            }

            if(topNode->right){
                que.push(make_pair(topNode->right, height + 1));
            }

        }

        for(int i = maxheight ; i >= minheight; i--){
            ans.push_back(storeAns[i]);
        }

        return ans;
    }
*/


/*
    Bottom View of Binary Tree
    (https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*, int>> que;
        map<int, int> ansMap;
        
        que.push(make_pair(root, 0));
        ansMap[0] = root->data;
        
        while(!que.empty()){
            
            pair<Node*, int> topelem = que.front();
            Node* topNode = topelem.first;
            int height = topelem.second;
            
            que.pop();
            
            ansMap[height] = topNode->data;
            
            if(topNode->left){
                que.push(make_pair(topNode->left, height - 1));
            }
            if(topNode->right){
                que.push(make_pair(topNode->right, height + 1));
            }
            
        }
        
        for(auto i:ansMap){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
    
*/