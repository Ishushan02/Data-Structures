
/*

    THe idea is we travel from currNode, get it's predecessor of left part and link it with currNode
    to the right of predecessor.
    continue it till your left get null
    one thing to note is make sure you don't visit currNode again so you also have to delete it, if it's recursively
    being called 

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
                }else{                               // Means we have currNode in predcessors right
                    predecessor->right = NULL;       // deleting the currNode as it's being recursively called again
                    ans.push_back(currNode->val);    // so we are delelting that extra link which we created to currNode
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

/*
    Maximum sum of Non-adjacent nodes (Good Question )
    (https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)

    // include, exclude
    pair<int, int> getSum(Node* root){
        if(root == NULL){
            return {0,0};
        }
        
        auto lsum = getSum(root->left);
        auto rsum = getSum(root->right);
        
        // include
        int a = root->data + lsum.second + rsum.second;
        
        // exclude
        int b = max(lsum.first, lsum.second) + max(rsum.first, rsum.second);
        

        return {a, b};
    }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = getSum(root);
        return max(ans.first, ans.second);
    }


*/

/*
    Burning Tree
    (https://www.geeksforgeeks.org/problems/burning-tree/1)

    void getParent(Node* root, unordered_map<Node*, Node*> &parentNode){
        
        if(root == NULL){
            return ;
        }
        
        if(root->left){
            parentNode[root->left] = root;
        }
        if(root->right){
            parentNode[root->right] = root;
        }
        
        
        getParent(root->left, parentNode);
        getParent(root->right, parentNode);
        
    }
    
    Node* getTarget(Node* root, int target){
        if(root == NULL){
            return NULL;
        }
        
        if(root->data == target){
            return root;
        }
        Node* n1 = getTarget(root->left, target);
        
        Node* n2 = getTarget(root->right, target);
        if(n1 != NULL && n1->data == target){
            return n1;
        }else if(n2 != NULL && n2->data == target){
            return n2;
        }
        
        return NULL;
    }
  
    int minTime(Node* root, int target) {
        // code here
        
        unordered_map<Node*, Node*> parentNode;
        getParent(root, parentNode);
        unordered_map<Node*, bool> visitedNode;
        
        // cout << parentNode.size() << endl;
        Node* targetNode = getTarget(root, target);
        
        // cout << targetNode->left->data << " - " << targetNode->right->data << endl;
        
        queue<Node*> que;
        que.push(targetNode);
        visitedNode[targetNode] = true;
        
        int ans = -1;
        while(!que.empty()){
            
            int size = que.size();
            
            for(int i = 0; i < size; i++){
                
                Node* frontNode = que.front();
                // cout << frontNode->data << " ";
                
                if(frontNode->left != NULL && visitedNode.find(frontNode->left) == visitedNode.end()){
                    que.push(frontNode->left);
                    visitedNode[frontNode->left] = true;
                }
                if(frontNode->right != NULL && visitedNode.find(frontNode->right) == visitedNode.end()){
                    que.push(frontNode->right);
                    visitedNode[frontNode->right] = true;
                }
                
                if(parentNode.find(frontNode) != parentNode.end()){
                    Node* parent = parentNode[frontNode];
                    if(visitedNode.find(parent) == visitedNode.end()){
                        que.push(parent);
                        visitedNode[parent] = true;
                    }
                }
                que.pop();
            }
            // cout << endl;
            ans += 1;
            
            
        }
        
        return ans;
    }
*/


/*
    958. Check Completeness of a Binary Tree
    (https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/)

    bool isCompleteTree(TreeNode* root) {
        
        // same logic of we got Null previously after that if element is present then it is not CBT
        queue<TreeNode* > que;
        que.push(root);
        bool frontNull = false;
        while(!que.empty()){

            TreeNode* frontelem = que.front();
            que.pop();
            if(frontelem == NULL){
                frontNull = true;
            }else{

                if(frontNull == true){
                    return false;
                }else{
                    que.push(frontelem->left);
                    que.push(frontelem->right);
                }
            }
        }

        return true;
    }
*/