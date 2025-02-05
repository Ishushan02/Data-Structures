#include<iostream>

using namespace std;

/*
    // Simple but it is 1 of the Important Question
    (104. Maximum Depth of Binary Tree) 
    (https://leetcode.com/problems/maximum-depth-of-binary-tree/)

    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        ldepth = depth(root->left);
        rdepth = depth(root->right);

        return max(ldepth, rdepth) + 1;

    }

    int maxDepth(TreeNode* root) {
        int maxdepth = depth(root);
        return maxdepth;
    }

*/


/*
    543. Diameter of Binary Tree
    (https://leetcode.com/problems/diameter-of-binary-tree/description/)

    Method 1 O(n^2)

    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);

        return max(leftH, rightH) + 1;
    }


    int getDiameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        // option1 max diam is present in left part
        int opt1 = getDiameter(root->left);

        // option2 max height is present in right part
        int opt2 = getDiameter(root->right);

        // option 3 max diam is present in by combining both the height
        int opt3 = getHeight(root->left) + getHeight(root->right);

        int maxDiam = max(opt1, max(opt2, opt3));

        return maxDiam;

    }


    int diameterOfBinaryTree(TreeNode* root) {
        return getDiameter(root);
    }


    Method 2 O(n)

    int height(TreeNode* node, int &diameter){
        if(node == NULL){
            return 0;
        }
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        if (lh + rh > diameter){
            diameter = lh + rh;
        }

        return max(lh, rh) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        int h = height(root, diameter);

        return diameter;
    }
    
*/


/*

    110. Balanced Binary Tree (Asked in Many Interview Questions)
    (https://leetcode.com/problems/balanced-binary-tree/) O(n2)

    int height(TreeNode* node){

        if(node == NULL){
            return 0;
        }

        int leftheight = height(node->left);
        int rightheight = height(node->right);

        return max(leftheight, rightheight) + 1;
    }

    bool balance(TreeNode* node){
        if(node == NULL){
            return true;
        }

        int lheight = height(node->left);
        int rheight = height(node->right);

        // cout << "Node: " << node->val << "-" << lheight << ", " << rheight << endl;
        
        // the upper node is balanced or not
        bool balanced = true;
        if(abs(lheight - rheight) > 1){
            balanced = false;
        }

        bool lbalanced = balance(node->left);
        bool rbalanced = balance(node->right);

        if(balanced && lbalanced && rbalanced){
            return true;
        }

        return false;
    }

    bool isBalanced(TreeNode* root) {
        return balance(root);
    }


    Method 2 O(n)

    int getHeight(TreeNode* root, bool &isbalanced){
        if(root == NULL){
            return 0;
        }

        int lh = getHeight(root->left, isbalanced);
        int rh = getHeight(root->right, isbalanced);

        if(abs(lh - rh) > 1){
            isbalanced = false;
        }

        return max(lh, rh) + 1;
    }


    bool isBalanced(TreeNode* root) {
        
        bool isbalanced = true;

        int h = getHeight(root, isbalanced);

        return isbalanced;
    }

*/


/*
    THE ABOVE 3 PROBLEMS ARE SO IMPORTANT PLEASE SEE THE LOGIC AGAIN AND AGAIN- VVVVVIIIIIIMPORTANT
*/



/*
    It is Very Very Important Question - VVVIII
    
    236. Lowest Common Ancestor of a Binary Tree 
    (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)


    Method 1

    bool ifexists(TreeNode* root, int checkNode){
        if(root == NULL){
            return false;
        }
        if(root->val == checkNode){
            return true;
        }

        bool lcheck = ifexists(root->left, checkNode);
        bool rcheck = ifexists(root->right, checkNode);

        return lcheck || rcheck ;
    }


    void checkNodes(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root == NULL){
            return ;
        }

        if(ifexists(root, p->val) && ifexists(root, q->val)){
            ans = root;
            cout << "Ans: " << ans->val << endl;
        }

        checkNodes(root->left, p, q, ans) ;
        checkNodes(root->right, p, q, ans) ;

        // return ans;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // cout << ifexists(root, -1) << endl;

        // root node is p
        if(ifexists(p, q->val)){
            return p;
        }

        // root node is q
        if(ifexists(q, p->val)){
            return q;
        }
        
        TreeNode* ans = NULL;
        checkNodes(root, p, q, ans);

        return ans;
    }


    Method 2 (both have same complexity and Runtime so both answers are equally correct)
    TreeNode* process(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL){
            return NULL;
        }

        // p case
        if(root->val == p->val){
            return p;
        }
        // q case
        if(root->val == q->val){
            return q;
        }

        TreeNode* leftAns = process(root->left, p, q);
        TreeNode* rightAns = process(root->right, p, q);

        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }else if(rightAns == NULL && leftAns != NULL){
            return leftAns;
        }

        return root;



    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return process(root, p, q);
    }

*/


/*
    112. Path Sum (VVIII)
    (https://leetcode.com/problems/path-sum/description/)

    bool targetSumprocess(TreeNode* root, int targetSum, int currentSum){
        if(currentSum == targetSum && root->left == NULL && root->right == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }

        bool lsum = false;
        bool rsum = false;
        if(root->left){
         lsum = targetSumprocess(root->left, targetSum, currentSum + root->left->val);
        }
        if(root->right){
         rsum = targetSumprocess(root->right, targetSum, currentSum + root->right->val);
        }

        return lsum || rsum ;
        
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return targetSumprocess(root, targetSum, root->val);
    }
*/

/*
    113. Path Sum II
    (https://leetcode.com/problems/path-sum-ii/description/)

    void storeSum(TreeNode* root, int targetSum, int currentSum, vector<int>& ans, vector<vector<int>>& sol){
        if(currentSum == targetSum && root->left == NULL && root->right == NULL){
            sol.push_back(ans);
            return;
        }

        if(root == NULL){
            return ;
        }

        if(root->left){
            ans.push_back(root->left->val);
            storeSum(root->left, targetSum, currentSum + root->left->val, ans, sol);
            ans.pop_back();
        }

        if(root->right){
            ans.push_back(root->right->val);
            storeSum(root->right, targetSum, currentSum + root->right->val, ans, sol);
            ans.pop_back();
        }
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> sol;

        if(root == NULL){
            return sol;
        }
        int currentSum = root->val;
        vector<int> ans = {root->val};
        
        
        storeSum(root, targetSum, currentSum, ans, sol);

        return sol;
    }
*/

/*
    437. Path Sum III
    (https://leetcode.com/problems/path-sum-iii/description/)

    void eachNodePathSum(TreeNode* root, long long int tempSum, int targetSum, int &count){
        if(root == NULL){
            return;
        }

        if(tempSum + root->val == targetSum){
            count = count + 1;
        }
        eachNodePathSum(root->left, root->val + tempSum, targetSum, count);
        eachNodePathSum(root->right, root->val + tempSum, targetSum, count);


    }


    void traverse(TreeNode* root, int targetSum, int &count){
        if(root == NULL){
            return ;
        }

        long long int temp = 0;
        eachNodePathSum(root, temp,targetSum, count);
        traverse(root->left, targetSum, count);
        traverse(root->right, targetSum, count);

    }

    int pathSum(TreeNode* root, int targetSum) {

        int count = 0;
        traverse(root, targetSum, count);
        return count;
    }

*/

/*
    // In both the questions remember that you have to maintain the order of the recursive call, 
    // based on which traversal you are getting help from

    CONSTRUCT Tree FROM PREORDER AND INORDER TRAVERSAL (VVVVVIIIIIII Question)

    Method 1 O(n2) {going on each node * searching for index in inorder Index}

    105. Construct Binary Tree from Preorder and Inorder Traversal
    (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

    int getInorderIdx(vector<int>& inorder, int element){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == element){
                return i;
            }
        }

        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int &preorderstartIdx, int inorderstartIdx, int inorderendIdx, int arrSize){

        if(preorderstartIdx >= arrSize){
            return NULL;
        }

        if(inorderstartIdx > inorderendIdx){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preorderstartIdx]);
        

        cout << preorder[preorderstartIdx] << endl;
        int idx = getInorderIdx(inorder, preorder[preorderstartIdx]);
        preorderstartIdx++;

        root->left = buildTree(preorder, inorder, preorderstartIdx, inorderstartIdx, idx -1, arrSize);
        root->right = buildTree(preorder, inorder, preorderstartIdx, idx + 1, inorderendIdx, arrSize);

        return root;
        

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderstartIdx = 0;
        int inorderstartIdx = 0;
        int arrSize = inorder.size();
        int inorderendIdx = arrSize - 1;
        return buildTree(preorder, inorder, preorderstartIdx, inorderstartIdx, inorderendIdx, arrSize);
    }


    Method 2 O(n)

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inorderIndex, int &preorderstartIdx, int inorderstartIdx, int inorderendIdx, int arrSize){

        if(preorderstartIdx >= arrSize){
            return NULL;
        }

        if(inorderstartIdx > inorderendIdx){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preorderstartIdx]);
        

        // cout << preorder[preorderstartIdx] << endl;
        int idx = inorderIndex[preorder[preorderstartIdx]];
        preorderstartIdx++;

        root->left = buildTree(preorder, inorder, inorderIndex, preorderstartIdx, inorderstartIdx, idx -1, arrSize);
        root->right = buildTree(preorder, inorder, inorderIndex, preorderstartIdx, idx + 1, inorderendIdx, arrSize);

        return root;
        

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderstartIdx = 0;
        int inorderstartIdx = 0;
        int arrSize = inorder.size();
        int inorderendIdx = arrSize - 1;
        // TO get index we store index value in map by which time complexity will change
        // from O(n) - O(1) for accessing index of inorder element

        unordered_map<int, int> inorderIndex;
        for(int i = 0; i < arrSize; i++){
            inorderIndex[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, inorderIndex, preorderstartIdx, inorderstartIdx, inorderendIdx, arrSize);
    }
    
*/


/*

    106. Construct Binary Tree from Inorder and Postorder Traversal
    (https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)

    TreeNode* GenerateTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inorderIdxMap, int &postorderIdx, int inorderStartIdx, int inorderendIdx){

        if(postorderIdx < 0){
            return NULL;
        }

        if(inorderStartIdx > inorderendIdx){
            return NULL;
        }

        int rootElem = postorder[postorderIdx];
        postorderIdx--;

        int idx = inorderIdxMap[rootElem];

        TreeNode* root = new TreeNode(rootElem);

        root->right = GenerateTree(inorder, postorder, inorderIdxMap, postorderIdx, idx+1, inorderendIdx);
        root->left = GenerateTree(inorder, postorder, inorderIdxMap, postorderIdx,inorderStartIdx, idx-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> inorderIdxMap;
        for(int i = 0; i < inorder.size(); i++){
            inorderIdxMap[inorder[i]] = i;
        }

        int postorderIdx = postorder.size() - 1;
        int inorderStartIdx = 0;
        int inorderendIdx = inorder.size() - 1;

        return GenerateTree(inorder, postorder, inorderIdxMap, postorderIdx, inorderStartIdx, inorderendIdx);
    }
*/

/*

    YOU HAVE TO NOTE 1 THING IN BOTH THE ABOVE QUESTIONS, THAT WHILE PROPAGATING POSTORDER OR PREDORDER INDEX
    WE HAVE SENT THE ADDRESS OF THE INDEX BECAUSE WE DON'T WANT TO USE THE SAME ELEMENT AGAIN FOR COMPUTATION.

    NOTE THIS IN MIND, IT'S VERY IMPORTANT FOR THIS TYPE OF PROBLEMS

*/

/*

    Tree Boundary Traversal
    (https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)


    void getleft(Node* root, vector<int> &leftNode){
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        
        leftNode.push_back(root->data);
        
        if(root->left){
            getleft(root->left, leftNode);
        }else{
            getleft(root->right, leftNode);
        }
        
        
    }
    
    void getright(Node* root, vector<int> &rightNode){
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        
        if(root->right){
            getright(root->right, rightNode);
        }else{
            getright(root->left, rightNode);
        }
        
        rightNode.push_back(root->data); // to reverse it
    }
    
    void getleaf(Node* root, vector<int> &leafNode, int val){
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL && root->data != val){
            leafNode.push_back(root->data);
        }
        
        getleaf(root->left, leafNode, val);
        getleaf(root->right, leafNode, val);
        
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        getleft(root->left, ans);
        getleaf(root, ans, root->data); // as root is goin, check it
        getright(root->right, ans);
        
    
        
        return ans;
        
    }

*/


/*

    Left View of Binary Tree
    (https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)


    void levelNodes(Node* root, map<int, vector<int>> &values, int height){
        if(root == NULL){
            return ;
        }
        
        values[height].push_back(root->data);
        levelNodes(root->left, values, height+1);
        levelNodes(root->right, values, height+1);
        
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        // ans.push_back(root->data);
        
        // getLeftNodes(root, ans, root->data);
        map<int, vector<int>> values;
        levelNodes(root, values, 0);
        
        for(auto idx:values){
            // vector<int> val = idx
            ans.push_back(idx.second[0]);
        }
        return ans;
    }

    Method 2.

    void leftView(Node* root, int height, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        
        if(ans.size() == height){
            ans.push_back(root->data);
        }
        
        leftView(root->left, height + 1, ans);
        leftView(root->right, height + 1, ans);
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        leftView(root, 0, ans);
        
        return ans;
    }
    
    
*/

/*
    199. Binary Tree Right Side View
    (https://leetcode.com/problems/binary-tree-right-side-view/description/)



    Method 1
    void levelNodes(TreeNode* root, map<int, vector<int>> &values, int height){
        if(root == NULL){
            return ;
        }
        
        values[height].push_back(root->val);
        levelNodes(root->left, values, height+1);
        levelNodes(root->right, values, height+1);
        
    }
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        map<int, vector<int>> values;
        levelNodes(root, values, 0);
        
        for(auto idx:values){
            // vector<int> val = idx
            int size = idx.second.size();
            ans.push_back(idx.second[size - 1]);
        }
        return ans;
    }


    Method 2 (Good Method  and Efficient One the same can also be used in Left View)

    void levelNodes(TreeNode* root, vector<int> &ans, int height){
        if(root == NULL){
            return ;
        }

        if(height == ans.size()){
            ans.push_back(root->val);
        }
        
        levelNodes(root->right, ans, height+1);
        levelNodes(root->left, ans, height+1);
        
    }
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        levelNodes(root, ans, 0);
    
        return ans;
    }


*/


/*
    Very Very Important Question- Took very much of my Time
    Top View of Binary Tree 
    (https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<Node*, int>> que;
        unordered_map<int, Node*> minDistmap;
        que.push(make_pair(root, 0));
        
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        while(!que.empty()){
            pair<Node*, int> value = que.front();
            Node* topNode = value.first;
            int dist = value.second;
            que.pop();
            
            minDist = min(minDist, dist);
            maxDist = max(maxDist, dist);
            
            if(minDistmap[dist] == 0){
                minDistmap[dist] = topNode;
            }
            
            if(topNode->left){
                que.push(make_pair(topNode->left, dist-1));
            }
            if(topNode->right){
                que.push(make_pair(topNode->right, dist+1));
            }
            
        }
        
        for(int i = minDist; i <= maxDist; i++){
            Node* node = minDistmap[i];
            ans.push_back(node->data);
        }
        
        return ans;
    }
*/
