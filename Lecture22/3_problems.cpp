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

/*
    662. Maximum Width of Binary Tree
    (https://leetcode.com/problems/maximum-width-of-binary-tree/description/)

    void levelOrderTraversal(queue<pair<TreeNode*, int>> &que, map<int, vector<unsigned long long int>> &ansMap, unsigned long long int parentIndex){
        if(que.empty()){
            return ;
        }

        pair<TreeNode*, int> frontElem = que.front();
        TreeNode* currNode = frontElem.first;
        int height = frontElem.second;
        que.pop();

        ansMap[height].push_back(parentIndex);

        unsigned long long int leftChild = 2 * parentIndex;
        unsigned long long int rightChild = 2 * parentIndex + 1;

        if(currNode->left){
            que.push(make_pair(currNode->left, height + 1));
            levelOrderTraversal(que, ansMap, leftChild);
        }
        if(currNode->right){
            que.push(make_pair(currNode->right, height + 1));
            levelOrderTraversal(que, ansMap, rightChild);
        }


        
    }


    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> que;
        map< int, vector<unsigned long long int>> ansMap;
        unsigned long long int index = 1;
        que.push(make_pair(root, 0));
        levelOrderTraversal(que, ansMap, index);

        unsigned long long maxWidth = 1;
        for(auto val:ansMap){
            vector<unsigned long long > arr = val.second;
            int n = arr.size();
            if(n > 1){
                // cout << val.first <<": " <<arr[0] << " " << arr[n - 1] << endl;
                maxWidth = max(maxWidth, arr[n - 1] - arr[0] + 1);
            }

        }

        return maxWidth;

    }


    Method 2 (Efficient Method)

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long int>> que;
        unsigned long long int maxWidth = 0;

        if (root == NULL){
            return maxWidth;
        }

        que.push(make_pair(root, 1));

        while(!que.empty()){

            int size = que.size();

            pair<TreeNode*, unsigned long long int> firstelem = que.front();
            pair<TreeNode*, unsigned long long int> lastelem = que.back();

            maxWidth = max(maxWidth, lastelem.second - firstelem.second + 1);

            for(int i = 0; i < size; i++){
                pair<TreeNode*, unsigned long long int> frontElem = que.front();
                que.pop();

                TreeNode* node = frontElem.first;
                unsigned long long int currIdx = frontElem.second;

                if(node->left){
                    que.push(make_pair(node->left, currIdx * 2));
                }
                if(node->right){
                    que.push(make_pair(node->right, currIdx * 2 + 1));
                }

            }

        }
        return maxWidth;


    }
*/

/*

    Very Very Good Question

    863. All Nodes Distance K in Binary Tree
    (https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

    void  traverseNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &nodeMap){
        if(root == NULL){
            return ;
        }

        // cout << root->val << " -- " << dist << " -- " << sol << endl;
        if(root->left){
            nodeMap[root->left] = root;
        }

        if(root->right){
            nodeMap[root->right] = root;
        }

        // sol = dist;
        traverseNodes(root->left, nodeMap);
        traverseNodes(root->right, nodeMap);
        
    }


    vector<int>  TraverseSol(TreeNode* target, unordered_map<TreeNode*, TreeNode*> &nodesConnected, int dist, int k){

        unordered_map<int, bool> visited;
        queue<TreeNode* > que;

        que.push(target);
        visited[target->val] = true;
        int distance = 0;

        while(!que.empty()){
            
            int size = que.size();
            // que.pop();

            if(distance == k){
                break;
            }

            for(int i = 0; i < size; i++) {
                TreeNode* frontNode = que.front();
                if(frontNode->left && visited.find(frontNode->left->val) == visited.end()){
                    que.push(frontNode->left);
                    visited[frontNode->left->val] = true;
                }

                if(frontNode->right && visited.find(frontNode->right->val) == visited.end()){
                    que.push(frontNode->right);
                    visited[frontNode->right->val] = true;

                }

                if(nodesConnected.find(frontNode) != nodesConnected.end()){
                    TreeNode* parentNode = nodesConnected[frontNode];
                    if(visited.find(parentNode->val) == visited.end()){
                        que.push(parentNode);
                        visited[parentNode->val] = true;
                    }
                }
                que.pop();
            
            }
            distance += 1;

        }

        vector<int> ans;
        while(!que.empty()){
            TreeNode* frontNode = que.front();
            ans.push_back(frontNode->val);
            que.pop();
        }

        return ans;

    }
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        int dist = 0;
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> nodesConnected;
        // nodesConnected[root] = NULL;
        traverseNodes(root, nodesConnected);

        // for(auto value:nodesConnected){
        //     cout << value.first->val << " : " << value.second->val << endl;
        // }

        return TraverseSol(target, nodesConnected, 0, k);

        // return ans;
    }

*/