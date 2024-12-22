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