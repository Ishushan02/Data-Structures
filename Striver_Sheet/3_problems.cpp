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

/*

    Problem 53
    (https://leetcode.com/problems/pascals-triangle/description/)
    118. Pascal's Triangle

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0){
            return ans;
        }
        ans.push_back({1});

        int col = 2;
        for(int i = 1; i < numRows; i++){
            vector<int> temp;
            int size = ans[i-1].size();
            for(int j = 0; j < col; j++){
                // cout << i << " , " << j << endl;
                int left = 0;
                int right = 0;
                if(i-1 < 0 || j-1 < 0){
                    left = 0;
                }else{
                    left = ans[i-1][j-1];
                }

                if(i-1 < 0 || j < 0 || j >= size ){
                    right = 0;
                }else{
                    right = ans[i-1][j];
                }

                if(left + right == 0){
                    temp.push_back(1);
                }else{
                    temp.push_back(left + right);
                }
                
            }
            ans.push_back(temp);
            col += 1;
        }

        return ans;
    }
*/

/*
    Problem 54
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
    121. Best Time to Buy and Sell Stock

    int maxProfit(vector<int>& prices) {
        
        stack<int> st;
        int maxProfit = 0;

        for(auto val:prices){

            if(st.empty()){
                st.push(val);
            }else{
                if(st.top() <= val){
                    maxProfit = max(maxProfit, val - st.top());
                }else{
                    st.push(val);
                }
            }
        }

        return maxProfit;
    }
*/