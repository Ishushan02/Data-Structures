/*
    173. Binary Search Tree Iterator (Asked in many interviews)
    (https://leetcode.com/problems/binary-search-tree-iterator/description/)

    public:

    stack<TreeNode* > st;

    void pushLeftNode(TreeNode* root){

        while(root){
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeftNode(root);
    }
    
    int next() {
        
        TreeNode* topnode =  st.top();
        st.pop();

        if(topnode->right){
            pushLeftNode(topnode->right);
        }

        return topnode->val;
    }
    
    bool hasNext() {
        
        if(st.empty()){
            return false;
        }
        return true;
    }



*/

/*
    The ABove question is about printing elements in left order (Increasing Order)
    The current one is about printing the elements in decreasing element. (Decreasing Order)
    It doesn't have any question just implemented it, for Interview Perspective.

    class BSTIterator {
public:

    stack<TreeNode*> reverseSt; // reverse Order traversal


    void pushRightNode(TreeNode* root){
        if(root){
            reverseSt.push(root);
            root = root->right;
        }
    }

    BSTIterator(TreeNode* root) {
        pushRightNode(root);
    }
    

    int before(){
        TreeNode* topNode = reverseSt.top();
        reverseSt.pop();

        if(topNode->left){
            pushRightNode(topNode);
        }
        return topNode->val;
    }

    bool hasBefore(){
        if(reverseSt.empty()){
            return false;
        }
        return true;
    }
    
};
*/


/*

    Other Application of BST Iterator
    Two Sum can be done by storing BST elements into vectors and then apply two sum on it.

    But the below method itterates over froward and backward of elements and we can apply two sum directly

    653. Two Sum IV - Input is a BST
    (https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)



class BSTIterator{
    public:
    stack<TreeNode*> forwardStack;
    stack<TreeNode*> backwardStack;

    void storeLeftNodes(TreeNode* root){
        while(root){
            forwardStack.push(root);
            root = root->left;
        }
    } 

    void storeRightNodes(TreeNode* root){
        while(root){
            backwardStack.push(root);
            root = root->right;
        }
    }

    bool hasnextElem(){
        if(forwardStack.empty()){
            return false;
        }
        return true;
    }

    bool hasprevElem(){
        if(backwardStack.empty()){
            return false;
        }
        return true;
    }

    int nextElement(){
        TreeNode* topNode = forwardStack.top();
        forwardStack.pop();
        if(topNode->right){
            storeLeftNodes(topNode->right);
        }
        return topNode->val;
    }

    int prevElement(){
        TreeNode* topNode = backwardStack.top();
        backwardStack.pop();
        if(topNode->left){
            storeRightNodes(topNode->left);
        }
        return topNode->val;
    }

    BSTIterator(TreeNode* root){
        storeLeftNodes(root);
        storeRightNodes(root);
        
    }

    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        
        BSTIterator bstiter(root);

        int front = bstiter.nextElement(); // start element of BST
        int back = bstiter.prevElement(); // end element of BST

        while(front < back){
            int sum = front + back;
            cout << front << " - " << back << endl;
            if(sum == k){
                return true;
            }else if(sum < k ){
                front = bstiter.nextElement();
            }else{
                back = bstiter.prevElement();
            }
           

        }

        
        
        // cout << front << "--" << back <<endl;
        return false;
    }
    };

*/


/*
    99. Recover Binary Search Tree
    (https://leetcode.com/problems/recover-binary-search-tree/description/)


    Method 1 (Good Approach)
    class Solution {
    public:
    TreeNode* frontviolation = NULL;
    TreeNode* backviolation = NULL;
    TreeNode* prev = NULL;

    void getvoilateNodes(TreeNode* root){
        if(root == NULL){
            return ;
        }

        getvoilateNodes(root->left);
        // compute

        if(prev != NULL && prev->val > root->val){

            if(frontviolation == NULL){
                frontviolation = prev;
            }
            backviolation = root;

        }
        prev = root;
        getvoilateNodes(root->right);
    }


    void recoverTree(TreeNode* root) {
        
        getvoilateNodes(root);
        if(frontviolation && backviolation){
            swap(backviolation->val, frontviolation->val);
        }
    }
    };


    Method 2 (Just to show Application of Iterator)
    Application 2 of BSTIterator

    class BSTIterator{
    public:
    stack<TreeNode*> forwardStack;
    stack<TreeNode*> backwardStack;

    void storeLeftNodes(TreeNode* root){
        while(root){
            forwardStack.push(root);
            root = root->left;
        }
    } 

    void storeRightNodes(TreeNode* root){
        while(root){
            backwardStack.push(root);
            root = root->right;
        }
    }

    bool hasnextElem(){
        if(forwardStack.empty()){
            return false;
        }
        return true;
    }

    bool hasprevElem(){
        if(backwardStack.empty()){
            return false;
        }
        return true;
    }

    int nextElement(){
        TreeNode* topNode = forwardStack.top();
        forwardStack.pop();
        if(topNode->right){
            storeLeftNodes(topNode->right);
        }
        return topNode->val;
    }

    int prevElement(){
        TreeNode* topNode = backwardStack.top();
        backwardStack.pop();
        if(topNode->left){
            storeRightNodes(topNode->left);
        }
        return topNode->val;
    }

    BSTIterator(TreeNode* root){
        storeLeftNodes(root);
        storeRightNodes(root);
        
    }

    
};

class Solution {
public:

    TreeNode* getNodes(TreeNode* root, int elem){
        if(root == NULL){
            return NULL;
        }

        if(root->val == elem){
            return root;
        }

        TreeNode* lNode = getNodes(root->left, elem);
        TreeNode* rNode = getNodes(root->right, elem);

        if(rNode == NULL && lNode == NULL){
            return NULL;
        }else if(rNode != NULL && lNode == NULL){
            return rNode;
        }else if(rNode == NULL && lNode != NULL){
            return lNode;
        }

        return root;
    }

    void recoverTree(TreeNode* root) {
        
        BSTIterator itr(root);

        int start = itr.nextElement();
        int end = itr.prevElement();
        int prevStart = start;
        int prevend = end;

        while(start){
            prevStart = start;
            start = itr.nextElement();
            if(prevStart > start){
                break;
            }
        }
        while(end){
            prevend = end;
            end = itr.prevElement();
            if(end > prevend){
                break;
            }
        }
        TreeNode* e1 = getNodes(root, prevStart);
        TreeNode* e2 = getNodes(root, prevend);
        swap(e1->val, e2->val);

        
    }
};
*/


/*

    Get Predecessor of any Node in BST (the just smaller Node )

    void inOrder(TreeNode* root, int &elem, int &prev){
        if(root == NULL){
            return ;
        }

        
        inOrder(root->left, elem, prev);
        if(root->val == elem){
            cout << prev << " Predecessor" << endl;
        }
        prev = root->val;
        inOrder(root->right, elem, prev);
        
    }

    int preorderTraversal(TreeNode* root) {
        
        int elem = 4;
        int pred = 0;
        inOrder(root, elem, pred);

        retur pred;

    }
*/


/*

    Get Successor of any Node in BST (the just bigger Node )

    void inOrder(TreeNode* root, int &elem, int &succ){
        if(root == NULL){
            return ;
        }

        inOrder(root->right, arr, elem, succ);
        if(root->val == elem){
            cout << succ << " Successor of " << elem << endl;
        }
        succ = root->val;
        inOrder(root->left, arr, elem, succ);
        
    }

    int preorderTraversal(TreeNode* root) {
        
        int elem = 7;
        int succ = 0;
        inOrder(root, elem, succ);

        return arr;
    }
*/


/*

    (DO IT AGAIN AND AGAIN, YOU COULDN"T COMPLETE THIS SIMPLE QUESTION IN ANY METHOD)

    1008. Construct Binary Search Tree from Preorder Traversal
    (https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)


    (TreeNode* buildBST(TreeNode* root, int &index, int min, int max, vector<int>& preorder){
        if(index >= preorder.size()){
            return NULL;
        }

        TreeNode* newNode = NULL;
        if(preorder[index] > min && preorder[index] < max){
            newNode = new TreeNode(preorder[index]);
            index = index + 1;
            newNode->left = buildBST(root, index, min, newNode->val, preorder);
            newNode->right = buildBST(root, index, newNode->val, max, preorder);
        }
        
        return newNode;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        int index = 0;
        root = buildBST(root, index, INT_MIN, INT_MAX, preorder);
        return root;
    })
*/

/*

    Count Pair from 2 BST whose Sum is X (OR) Brothers from DIfferent Root

    (https://www.geeksforgeeks.org/problems/brothers-from-different-root/1)

    bool searchNode(Node* root, int elem){
        if(root == NULL){
            return false;
        }
        
        if(root->data == elem){
            return true;
        }else if(root->data < elem){
            return searchNode(root->right, elem);
        }else{
            return searchNode(root->left, elem);
        }
        
        return false;
    }
    
    void traverse(Node* root1, Node* root2, int x, int &count){
        if(root1 == NULL){
            return ;
        }
        traverse(root1->left, root2, x, count);

        
        int var = x - root1->data;
        
        if(searchNode(root2, var)){
            // cout << root1->data << " - " << var << endl;
            count += 1;
        }
        traverse(root1->right, root2, x, count);
        
    }

    int countPairs(Node* root1, Node* root2, int x)
    {   
        int count = 0;
        traverse(root1, root2, x, count);
        return count;
    }

    Method 2

    Store in Vector and do 2 pointer Approach (but it takes extra O(n) space )
*/