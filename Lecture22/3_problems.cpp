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

/*

    (DO IT AGAIN ------- IT's Good INTERVIEW LEVEL QUESTION)

    222. Count Complete Tree Nodes
    (https://leetcode.com/problems/count-complete-tree-nodes/description/)


    // logn n time
    int lheight(TreeNode* root, int height){
        if(root == NULL){
            return height;
        }

        return lheight(root->left, height + 1);
    }

    // logn n time
    int rheight(TreeNode* root, int height){
        if(root == NULL){
            return height;
        }

        return rheight(root->right, height + 1);
    }

    int getCount(TreeNode* root, int lh, int rh, int nodes){
        if(root == NULL){
            return nodes;
        }

        lh = lheight(root, 0);
        rh = rheight(root, 0);

        if(lh == rh){

            nodes += pow(2, lh) - 1;
            return nodes;
        }

        int lans = getCount(root->left, lh, rh, nodes);
        int rans = getCount(root->right, lh, rh, nodes);
        

        return 1 + lans + rans;
    }   

    int countNodes(TreeNode* root) {
        int ans = 0;

        int lh = 0;
        int rh = 0; 
        int nodes = 0;
        // cout << lheight(root, 0) << endl;
        // cout << rheight(root, 0) << endl;

        return getCount(root, lh, rh, nodes);

    }
*/

/*

    968. Binary Tree Cameras
    (https://leetcode.com/problems/binary-tree-cameras/submissions/1480616371/)

    // 2 Installed, 1 Covered, 0 not covered, TRaverse from Bottom to Top(Post Order)
    // 1  (cov) and 1 (cov) -> ret 0 curr not covered
    // 0 or anything --> ret 2 install camera in curr node
    // 2 or anything --> ret 1 current node is covered

    int coverNodes(TreeNode* root, int &camCount){
        if(root == NULL){
            return 1; // asssuming leaves to be covered
        }

        int leftCov = coverNodes(root->left, camCount);
        int rightCov = coverNodes(root->right, camCount);

        if(leftCov == 0 || rightCov == 0){
            camCount++;
            return 2; // need to install camera
        }

        if(leftCov == 2 || rightCov == 2){
            return 1; // already covered
        }
        
        
        return 0; // this is not covered

    }


    int minCameraCover(TreeNode* root) {

        int ans = 0;
        int rootState = coverNodes(root, ans);
        if(rootState == 0){
            ans++ ; // installing camera at root Node
        }
        
        return ans;
    }

*/

/*

    100. Same Tree
    (https://leetcode.com/problems/same-tree/description/)

    void isIdenticalTree(TreeNode* proot, TreeNode* qroot, bool &isIdentical){
        if(proot == NULL && qroot == NULL){
            return ;
        }else if (proot == NULL && qroot != NULL){
            isIdentical = false;
            return ;
        }else if (proot != NULL && qroot == NULL){
            isIdentical = false;
            return ;
        }

        if(proot->val != qroot->val){
            isIdentical = false;
        }

        isIdenticalTree(proot->left, qroot->left, isIdentical);
        isIdenticalTree(proot->right, qroot->right, isIdentical);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool isIdentical = true;
        isIdenticalTree(p, q, isIdentical);
        return isIdentical;

    }
*/

/*
    103. Binary Tree Zigzag Level Order Traversal
    (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> que;
        vector<vector<int>> ans;
        map<int, vector<int>> values;

        if(root == NULL){
            return ans;
        }


        que.push(make_pair(root, 0));

        while(!que.empty()){

            pair<TreeNode*, int> frontElem = que.front();
            TreeNode* node = frontElem.first;
            int height = frontElem.second;
            values[height].push_back(node->val);
            que.pop();

            if(node->left){
                que.push(make_pair(node->left, height + 1));
            }
            if(node->right){
                que.push(make_pair(node->right, height + 1));
            }
            
        }

        bool reverseVal = false;
        for(auto val:values){
            
            vector<int> arr = val.second;
            if(reverseVal){
                reverse(arr.begin(), arr.end());
                ans.push_back(arr);
                reverseVal = false;
            }else{
                ans.push_back(arr);
                reverseVal = true;
            }
            
        }

        return ans;

    }
*/