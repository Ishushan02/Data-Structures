/*

    Problem 51
    (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
    114. Flatten Binary Tree to Linked List

    void flattenCurrentNode(TreeNode* &root){
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        TreeNode* pred = root->left;

        while(pred->right){
            pred = pred->right;
        }

        root->right = NULL;
        pred->right = rightNode;
        root->left = NULL;
        root->right = leftNode;

    }

    void traverse(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left){
            flattenCurrentNode(root);
        }

        traverse(root->right);
    }

    void flatten(TreeNode* root) {
        traverse(root);
    }

*/

/*

    Problem 52
    (https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
    116. Populating Next Right Pointers in Each Node

    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> que;
        que.push(root);

        while(!que.empty()){

            int size = que.size();
            Node* initialright = NULL;

            for(int i = 0; i < size; i++){
                Node* topNode = que.front();
                if(topNode->right){
                    topNode->right->next = initialright;
                    initialright = topNode->right;
                    topNode->left->next = initialright;
                    initialright = topNode->left;
                    que.push(topNode->right);
                    que.push(topNode->left);
                }
                que.pop();
            }
            // que.pop();
        }

        return root;
    }
*/