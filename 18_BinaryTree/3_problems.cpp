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



    Method 2
    (BFS MEthod -- Good Approach, think like graph)

    void tranverseNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &connectedNodes){
        if(root == NULL){
            return ;
        }

        if(root->left){
            connectedNodes[root->left] = root;
        }

        if(root->right){
            connectedNodes[root->right] = root;
        }

        tranverseNodes(root->left, connectedNodes);
        tranverseNodes(root->right, connectedNodes);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // cre
        unordered_map<TreeNode*, TreeNode*> parentNodes;
        tranverseNodes(root, parentNodes);

        // vector<int> ans;

        // we can do BFS on this starting from target Node
        queue<TreeNode*> que;
        unordered_map<TreeNode*, bool> visited;

        que.push(target);
        int level = 0;

        if(k == 0){
            return {target->val};
        }

        while(!que.empty()){
            int size = que.size();

            level += 1;
            vector<int> ans;
            // cout <<" level  "<< level <<" ";
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = que.front();
                que.pop();
                    visited[frontNode] = 1;
                
                    // left child
                    if(frontNode->left && visited[frontNode->left] == 0){
                        visited[frontNode->left] = 1;
                        que.push(frontNode->left);
                        ans.push_back(frontNode->left->val);
                    }
                    // right child
                    if(frontNode->right && visited[frontNode->right] == 0){
                        visited[frontNode->right] = 1;
                        que.push(frontNode->right);
                        ans.push_back(frontNode->right->val);

                    }

                    // parent
                    if(parentNodes.find(frontNode) != parentNodes.end() && visited[parentNodes[frontNode]] == 0){                       
                        visited[parentNodes[frontNode]] =1;
                        que.push(parentNodes[frontNode]);
                        ans.push_back(parentNodes[frontNode]->val);

                    }
            
            }

            if(level == k){
                return ans;
            }
        }

        return {};


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



    Method 2(Efficient Method) 
    // think like while you are creating heap, the numbering of it.

    int ans = 0;
    void totalCount(TreeNode* root, int count){
        if(root == NULL){
            return ;
        }
       
        if(root->left){
            totalCount(root->left, 2 * count);
        }

        if(root->right){
            totalCount(root->right, 2 * count + 1);
        }
        ans = max(ans, count);
    }

    int countNodes(TreeNode* root) {
        
        totalCount(root, 1);
        return ans;
    }
*/

/*

    968. Binary Tree Cameras
    (https://leetcode.com/problems/binary-tree-cameras/)

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

    bool isIdenticalTree(TreeNode* proot, TreeNode* qroot){
        if(proot == NULL && qroot == NULL){
            return true;
        }else if (proot == NULL && qroot != NULL){
            return false;
        }else if (proot != NULL && qroot == NULL){
            return false;
        }

        if(proot->val != qroot->val){
            return false;
        }

        return isIdenticalTree(proot->left, qroot->left) && isIdenticalTree(proot->right, qroot->right);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isIdenticalTree(p, q);
        // return isIdentical;

    }
*/

/*
    103. Binary Tree Zigzag Level Order Traversal
    (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int size = que.size();
            vector<int> tempAns;
            for(int i = 0; i < size; i++){
                TreeNode* curr = que.front();
                tempAns.push_back(curr->val);
                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
                
                que.pop();
            }
            res.push_back(tempAns);
        }

        bool rev = false;
        for(auto &value:res){
            if(rev){
                reverse(value.begin(), value.end());
                rev = false;
            }else{
                rev = true;
            }
        }

        return res;
    }
*/

/*
    Transform to Sum Tree
    (https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1)

    int addNodes(Node* node){
        if(node == NULL){
            return 0;
        }
        
        
        int lSum = addNodes(node->left);
        int rSum = addNodes(node->right);
        
        int totalSum = node->data + lSum + rSum;
        // cout << node->data << " - " << totalSum << " - " << lSum + rSum << endl;
        node->data = lSum + rSum;
        
        
        return totalSum;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        
        addNodes(node);
    }

*/

/*

    Method 1 Diagonal Tree Traversal

    (https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1)

    void numberNodes(Node* root, int height, map<int, vector<int>> &ansMap){
    if(root == NULL){
        return;
    }
    
    if(root->right){
        numberNodes(root->right, height, ansMap);
    }
    if(root->left){
        numberNodes(root->left, height + 1, ansMap);
    }
    ansMap[height].push_back(root->data);
    
    // cout << root->data << ": " << height << endl;
    }

    vector<int> diagonal(Node *root)
    {
    // your code here
    int height = 0;
        map<int, vector<int>> ansMap;
    numberNodes(root, height, ansMap);
    vector<int> ans ;
    
    for(auto val:ansMap){
        vector<int> arr = val.second;
        reverse(arr.begin(), arr.end());
        //   for(auto j : arr){
        //       cout << j << " ";
        //   }
        //   cout << endl;
        ans.insert(ans.end(), arr.begin(), arr.end());
        
    }
    
    return ans;
    }


    // Method 2 
    // Procedure is (get the root node initially in the que),

    // ans vector
    // store all the right node of the node present in que in to Ans Vector
    // ans check in between if there is left of it, store that in que  

    // repeat this untill que is empty


    vector<int> diagonal(Node *root)
    {
    // your code here
    
    queue<Node*> que;
    vector<int> ans;
    
    que.push(root);
        
    while(!que.empty()){
        
            Node* topNode = que.front();
            que.pop();
            
            while(topNode){
                ans.push_back(topNode->data);
                if(topNode->left){
                    que.push(topNode->left);
                }
                
                topNode = topNode->right;
            }
        
    }
    
    return ans;
    
    
    }

*/

/*
    MULTISET - 
    a multiset is a container from the Standard Template Library (STL) 
    that stores elements in a sorted order, similar to a set, but unlike a set, 
    it allows duplicate elements. This means that multiple instances of the 
    same element can exist in a multiset.

    {Do it Again -- }


    987. Vertical Order Traversal of a Binary Tree (NEW CONCEPT: multiset)
    (https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

    void assignOrder(TreeNode* root, int col, int row, map<int, vector<int>> &rowMap, map<int, map<int, multiset<int>>> &valMap){
        if(root == NULL){
            return;
        }

        // {
        //     col : 
        //     {
        //         row : data;
        //     }
        // }

        // { col : {row : x, y, z, a ,. ... }} {inside elements will be sorted because of multiset}
  
        valMap[col][row].insert(root->val);
        assignOrder(root->right, col+1,  row + 1, rowMap, valMap);
        assignOrder(root->left, col-1, row +1, rowMap, valMap);


    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }
        int col = 0;
        int row = 0;
        map<int, vector<int>> rowMap;
        map<int, map<int, multiset<int>>> valMap;
        assignOrder(root, col, row, rowMap, valMap);

        for(auto v:valMap){
            map<int, multiset<int>> data = v.second;
            vector<int> temp;
            for (auto each_val : data){
                // cout << each
                temp.insert(temp.end(), each_val.second.begin(), each_val.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }

*/