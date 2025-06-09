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

/*

    Problem 55
    (https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)
    124. Binary Tree Maximum Path Sum

    int getMaxSum(TreeNode* root, int &maxSum){
        if(root == NULL){
            return 0;
        }
        
        // int currmaxSum = -1000;
        int lSum = getMaxSum(root->left, maxSum);
        int rSum = getMaxSum(root->right, maxSum);
        int adjSum = 0;

        int propSum = 0;
        adjSum = lSum + rSum + root->val;
        maxSum = max(maxSum, adjSum);
        propSum = root->val + max(lSum, rSum);
        
        // cout << root->val << " , " << propSum << " , " << maxSum << endl;
        if(propSum >= 0){
            return propSum;
        }else{
            return 0;
        }
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = -1000;
        auto val = getMaxSum(root, maxSum);

        return maxSum;
    }
*/

/*
    Great Question 

    Problem 56 
    (https://leetcode.com/problems/longest-consecutive-sequence/)
    128. Longest Consecutive Sequence

    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> setMap(nums.begin(), nums.end());
        int maxAns = 0;

        for(auto v:setMap){

            if(setMap.find(v-1) == setMap.end()){
                int curr = v;
                int ans = 0;

                
                while(setMap.find(curr) != setMap.end()){
                    ans += 1;
                    curr += 1;
                }

                maxAns = max(maxAns, ans);
            }
        }

        return maxAns;

    }

    // Even though this is a nested loop, each number is only visited once over all
    // iterations of the outer loop because we skip non-starting elements.
    // find only takes O(logn) time in unordered_set 

    // Hence it is just O(n)
*/

/*
    Problem 57
    (https://leetcode.com/problems/palindrome-partitioning/description/)
    131. Palindrome Partitioning

    bool isPalindrome(string &s){
        int i = 0;
        int j = s.length()-1;

        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }


    void getPalindromicSubstr(string &s, int idx, vector<string> &tempAns, vector<vector<string>> &ans){
        if(idx >= s.length()){
            if(tempAns.size() > 0){
                ans.push_back(tempAns);
            }
            // tempAns = {};
            return ;
        }

        string tempStr;
        for(int i = idx; i < s.length(); i++){
            tempStr += s[i];
            if(isPalindrome(tempStr)){
                // cout << tempStr << endl;
                tempAns.push_back(tempStr);
                getPalindromicSubstr(s, i+1, tempAns, ans);
                tempAns.pop_back();
            }
        }
        

    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        getPalindromicSubstr(s, 0, temp, ans);

        return ans;
    }
*/

/*
    Problem 58
    (https://leetcode.com/problems/clone-graph/)
    133. Clone Graph

    (Node* createClone(Node* node, unordered_map<int, Node*> &nodeMap){

        if(node == NULL){
            return NULL;
        }

        if(nodeMap[node->val]){
            return nodeMap[node->val];
        }
        Node* newNode = new Node(node->val);
        nodeMap[node->val] = newNode;

        for(auto eachNode:node->neighbors){
            Node* currNode = createClone(eachNode, nodeMap);
            newNode->neighbors.push_back(currNode);
        }    

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> nodeMap;
        return createClone(node, nodeMap);
    })
*/

/*

    Problem 59
    (https://leetcode.com/problems/set-mismatch/submissions/)
    645. Set Mismatch

    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n, 0);
        vector<int> ans;

        for(auto v:nums){
            if(present[v-1] == 0){
                present[v-1] = 1;
            }else{
                ans.push_back(v);
            }
        }

        for(int i = 0; i < n; i++){
            if(present[i] == 0){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
*/


/*
    Problem 60
    // STANDARD PARTITIONING OR CUT PROBLEMS ARE SOLVED IN THIS METHOD
    1547. Minimum Cost to Cut a Stick
    (https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)

    int getminCost(vector<int>& cuts, int start, int end, vector<vector<int>> &dpArr){
        if(end - start < 2){
            return 0;
        }

        if(dpArr[start][end] != -1){
            return dpArr[start][end];
        }
        int minCost = INT_MAX;
        for(int i = start+1; i <= end - 1; i++){
            int cost = (cuts[end] - cuts[start]) + getminCost(cuts, start, i, dpArr) + getminCost(cuts, i, end, dpArr);
            minCost = min(minCost, cost);
        }

        dpArr[start][end] = minCost;

        return minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dpArr(cuts.size()+1, vector<int>(cuts.size()+1, -1));

        return getminCost(cuts, 0, cuts.size()-1, dpArr);
    }

*/

/*

    Problem 61
    (https://leetcode.com/problems/copy-list-with-random-pointer/)
    138. Copy List with Random Pointer

    Node* newList(Node* head, unordered_map<Node*, Node*> &nodeMap){
        if(head == NULL){
            return NULL;
        }

        if(nodeMap.find(head) != nodeMap.end()){
            return nodeMap[head];
        }

        Node* newNode = new Node(head->val);
        nodeMap[head] = newNode;
        if(head->random != NULL){
            newNode->random = newList(head->random, nodeMap);
        }

        newNode->next = newList(head->next, nodeMap);
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        auto c = newList(head, nodeMap);
        return nodeMap[head];
    }

*/

/*

    Problem 62
    (https://leetcode.com/problems/linked-list-cycle/)
    141. Linked List Cycle

    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;

        while(fastptr && fastptr->next){
            if(fastptr == slowptr){
                return true;
            }

            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        return false;
    }
*/

/*

    Problem 63
    (https://leetcode.com/problems/linked-list-cycle-ii)
    142. Linked List Cycle II

    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slowptr = head;
        ListNode* fastptr = head;

        while (fastptr && fastptr->next) {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            // 2*X1 + 2*X2 = X1 + X2 + X3 + X2
            if (slowptr == fastptr) {
                ListNode* initial = head;
                while (initial != slowptr) {
                    initial = initial->next;
                    slowptr = slowptr->next;
                }
                return initial; 
            }
        }

        return NULL; 
    }
*/