/*

    Problem 76
    (https://leetcode.com/problems/number-of-islands/)
    200. Number of Islands

    void markIslands(vector<vector<char>> &grid, int x, int y){
        // cout << i << " , " << j << endl;
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1'){
            return ;
        }
        // cout << x << " , " << y << endl;
        grid[x][y] = '0';
        // cout << grid[x][y] << endl;
        markIslands(grid, x+1, y);
        markIslands(grid, x, y+1);
        markIslands(grid, x-1, y);
        markIslands(grid, x, y-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    markIslands(grid, i, j);
                }
            }
        }

        return count;
    }

*/

/*

    Problem 77
    (https://leetcode.com/problems/reverse-linked-list/)
    206. Reverse Linked List

    ListNode* reverseNode(ListNode* head){
        ListNode* reverse = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = reverse;
            reverse = temp;
            temp = nextNode;
        }

        return reverse;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        return reverseNode(head);
    }
        
*/

/*

    Problem 78
    (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
    235. Lowest Common Ancestor of a Binary Search Tree


    TreeNode* getParent(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val){
            return p;
        }

        if(root->val == q->val){
            return q;
        }

        TreeNode* ans = NULL;
        if(p->val < root->val && q->val < root->val ){
            // left
            return getParent(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val ){
            // right
            return getParent(root->right, p, q);

        }
        
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> nodeMap;
        if(root == NULL){
            return NULL;
        }

        return getParent(root, p, q);

    }
*/

/*

    Problme 79
    (https://leetcode.com/problems/course-schedule/description/)
    207. Course Schedule

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> courseMap;
        unordered_map<int, int> indegree;
        for(int i = 0; i < numCourses; i++){
            courseMap[i] = {};
            indegree[i] = 0;
        }

        for(int i = 0; i < prerequisites.size(); i++){
            courseMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        
        // for(int i = 0; i < numCourses; i++){
            for(auto &[key, val]:courseMap){
                for(auto v: val){
                    indegree[v]++;
                }
            }
        // }

        queue<int> que;

        for(auto &[key, val]:indegree){
            if(val==0){
                que.push(key);
            }
        }
        vector<int> ans;
        while(!que.empty()){
            int frontNode = que.front();
            que.pop();
            ans.push_back(frontNode);

            for(auto val:courseMap[frontNode]){
                indegree[val]--;
                if(indegree[val] == 0){
                    que.push(val);
                }
            }

        }

        if(ans.size() != numCourses){
            return false;
        }

        return true;
    }
*/

/*
    Problem 80
    208. Implement Trie (Prefix Tree)
    (https://leetcode.com/problems/implement-trie-prefix-tree/)

    class TrieNode{
        public: 
            unordered_map<char, TrieNode*> nodeMap;
            bool isTerminal = false;

            TrieNode(char c, bool eow = false){
                this->isTerminal = eow;
            }

            void insertNode(TrieNode* node, int i, string &word){
                if(i == word.length()-1){
                    if(node->nodeMap.find(word[i]) == node->nodeMap.end()){
                        TrieNode* newNode = new TrieNode(word[i], true);
                        node->nodeMap[word[i]] = newNode;
                    }else{
                        node->nodeMap[word[i]]->isTerminal = true;
                    }
                    return ;
                }

                if(node->nodeMap.find(word[i]) == node->nodeMap.end()){
                    TrieNode* newNode = new TrieNode(word[i]);
                    node->nodeMap[word[i]] = newNode;
                    insertNode(newNode, i+1, word);
                }else{
                    insertNode(node->nodeMap[word[i]], i+1, word);
                }

            }


            bool searchWord(TrieNode* node, int i, string &word){
                if(i == word.length()-1){
                    if(node->nodeMap.find(word[i]) != node->nodeMap.end()){
                        return node->nodeMap[word[i]]->isTerminal;
                    }
                    return false;
                }

                if(node->nodeMap.find(word[i]) == node->nodeMap.end()){
                    return false;
                }      
                return searchWord(node->nodeMap[word[i]], i+1, word);
            }


            bool startsWithWord(TrieNode* node, int i, string &word){
                if(i == word.length()-1){
                    if(node->nodeMap.find(word[i]) != node->nodeMap.end()){
                        return true;
                    }
                    return false;
                }

                if(node->nodeMap.find(word[i]) == node->nodeMap.end()){
                    return false;
                }      
                return startsWithWord(node->nodeMap[word[i]], i+1, word);
            }
    };


    class Trie {
    public:

        TrieNode* node = new TrieNode('-');
        Trie() {
            
        }
        
        void insert(string word) {
            node->insertNode(node, 0, word);
        }
        
        bool search(string word) {
            return node->searchWord(node, 0, word);
        }
        
        bool startsWith(string prefix) {
            return node->startsWithWord(node, 0, prefix);
        }
    };

*/

/*

    Problem 81
    (https://leetcode.com/problems/flood-fill/description/)
    733. Flood Fill

    void colorGrid(vector<vector<int>>& image, int i, int j, map<pair<int, int>, bool> &visited, int &srcVal, int color){

        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != srcVal || visited.find({i, j}) != visited.end()){
            return ;
        }
        visited[{i, j}] = color;
        image[i][j] = color;
        colorGrid(image, i+1, j, visited, srcVal, color);
        colorGrid(image, i, j+1, visited, srcVal, color);
        colorGrid(image, i-1, j, visited, srcVal, color);
        colorGrid(image, i, j-1, visited, srcVal, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        map<pair<int, int>, bool> visited;
        int srcColor = image[sr][sc];
        colorGrid(image, sr, sc, visited, srcColor, color);

        return image;
    }

*/

/*

    Problem 82
    (https://leetcode.com/problems/implement-stack-using-queues/)
    225. Implement Stack using Queues

    class MyStack {
    public:

        queue<int> que1;    
        queue<int> que2;

        MyStack() {
            
        }
        
        void push(int x) {
            que1.push(x);
        }
        
        int pop() {
            while(que1.size() > 1){
                que2.push(que1.front());
                que1.pop();
            }
            int elem = que1.front();
            que1.pop();

            while(!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }

            return elem;
        }
        
        int top() {
            while(que1.size() > 1){
                que2.push(que1.front());
                que1.pop();
            }
            int elem = que1.front();
            que2.push(elem);
            que1.pop();

            while(!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }
            return elem;
        }
        
        bool empty() {
            return que1.empty();
        }
    };

*/

/*

    Problem 83
    (https://leetcode.com/problems/kth-largest-element-in-an-array/)
    215. Kth Largest Element in an Array

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> que;

        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            if(que.top() < nums[i]){
                que.pop();
                que.push(nums[i]);
            }
        }

        return que.top();
    }
*/

/*

    Problem 84
    (https://leetcode.com/problems/longest-common-subsequence/)
    1143. Longest Common Subsequence

    int getMaxSubseq(string &text1, string &text2, int i, int j, vector<vector<int>> &dpArray){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }

        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + getMaxSubseq(text1, text2, i+1, j+1, dpArray);
        }else{
            ans = 0 + max(getMaxSubseq(text1, text2, i+1, j, dpArray), getMaxSubseq(text1, text2, i, j+1, dpArray));
        }

        dpArray[i][j] = ans;
        return dpArray[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dpArray(text1.length()+1, vector<int>(text2.length()+1, -1));

        return getMaxSubseq(text1, text2, 0, 0, dpArray);
    }
*/

/*

    Problem 85
    (https://leetcode.com/problems/majority-element-ii/)
    229. Majority Element II

    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int elem1 = NULL;
        int elem2 = NULL;

        for(auto v: nums){

            if(count1 == 0 && v != elem2){
                count1++;
                elem1 = v;
            }else if(count2 == 0 && v != elem1){
                count2++;
                elem2 = v;
            }else if(v == elem1){
                count1++;
            }else if(v == elem2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        vector<int> ans;

        for(auto v:nums){
            if(elem1 == v){
                count1++;
            }
            if(elem2 == v){
                count2++;
            }
        }

        if(count1 > n/3){
            ans.push_back(elem1);
        }
        if(count2 > n/3 && elem2 != elem1){
            ans.push_back(elem2);
        }
        
        return ans;
    }
*/

/*
    Problem 86
    (https://leetcode.com/problems/implement-queue-using-stacks/)
    232. Implement Queue using Stacks

    class MyQueue {
    public:
        stack<int> st1;
        stack<int> st2;
        MyQueue() {
            
        }
        
        void push(int x) {
            st1.push(x);
        }
        
        int pop() {
            while(st1.size()>1){
                st2.push(st1.top());
                st1.pop();
            }
            int elem = st1.top();
            st1.pop();

            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            return elem;
        }
        
        int peek() {
            while(st1.size()>1){
                st2.push(st1.top());
                st1.pop();
            }
            int elem = st1.top();

            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            return elem;
        }
        
        bool empty() {
            return st1.empty();
        }
    };
*/

/*

    Problem 87
    (https://leetcode.com/problems/palindrome-linked-list/)
    234. Palindrome Linked List

    ListNode* reverseList(ListNode* head, ListNode* thresh) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != thresh){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        // curr->next = prev;
        // prev = curr;

        return prev;
    }

    bool checkPalindrome(ListNode* a, ListNode* b){

        ListNode* temp1 = a;
        ListNode* temp2 = b;

        while(temp1 && temp2){
            if(temp1->val != temp2->val){
                return false;
            }
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* cnt = head;
        int count = 0;
        while(cnt){
            count += 1;
            cnt = cnt->next;
        }
        
        ListNode* rab = head;
        ListNode* tor = head;
        ListNode* prev = NULL;

        while(rab && rab->next){
            prev = tor;
            tor = tor->next;
            rab = rab->next->next;
        }   

        if(count & 1){
            ListNode* rightNode = tor->next;
            tor->next = NULL;
            ListNode* temp3 = head;
            ListNode* reversed = reverseList(temp3, tor);

            while(reversed){
                // cout << reversed->val << " , " << rightNode->val << endl;
                if(reversed->val != rightNode->val){
                    return false;
                }
                
                reversed = reversed->next;
                rightNode = rightNode->next;
            }

        }else{
            ListNode* rightNode = prev->next;
            if(rightNode->val != prev->val){
                return false;
            }
            rightNode = rightNode->next;
            prev->next = NULL;
            ListNode* temp4 = head;
            ListNode* reversed = reverseList(temp4, prev);
            while(reversed){
                // cout << reversed->val << " , " << rightNode->val << endl;
                if(reversed->val != rightNode->val){
                    return false;
                }
                
                reversed = reversed->next;
                rightNode = rightNode->next;
            }
        }

        

        return true;
    }
*/

/*

    Problem 88
    (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
    236. Lowest Common Ancestor of a Binary Tree

    bool traverse(TreeNode* a, TreeNode* b){
        if(a == NULL){
            return false;
        }
        if(a == b){
            return true;
        }
        return traverse(a->left, b) || traverse(a->right, b);

    }

    void traverseRoot(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ansNode){
        if(root == NULL){
            return ;
        }

        bool ans = traverse(root, p) && traverse(root, q);
        if(ans){
            ansNode = root;
            // return;
        }

        traverseRoot(root->left, p, q, ansNode);
        traverseRoot(root->right, p, q, ansNode);

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        // if(traverse(p, q)){
        //     return p;
        // }else if(traverse(q, p)){
        //     return q;
        // }

        TreeNode* ansNode = NULL;
        traverseRoot(root, p, q, ansNode);
        return ansNode;
    }

*/

/*

    Problem 89
    (https://leetcode.com/problems/delete-node-in-a-linked-list/)
    237. Delete Node in a Linked List

    void deleteNode(ListNode* node) {
        
        ListNode* temp = node;

        while(temp){
            if(temp->next){
                swap(temp->val, temp->next->val);
            }
            temp = temp->next;
        }

        temp = node;
        ListNode* prev = temp;
        while(temp){
            if(temp->next == NULL){
                prev->next = NULL;
                delete temp;
                return ;
            }
            prev = temp;
            temp = temp->next;
        }
        
    }

*/

/*

    Problem 90
    (https://leetcode.com/problems/sliding-window-maximum/)
    239. Sliding Window Maximum

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;

        for(int i = 0; i < k; i++){
            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }

            que.push_back(i);
        }

        ans.push_back(nums[que.front()]);

        for(int i = k; i < nums.size(); i++){

            while(!que.empty() && que.front() <= i - k){
                que.pop_front();
            }

            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);

            ans.push_back(nums[que.front()]);
        }

        return ans;
    }
*/

/*

    Problem 91
    (https://leetcode.com/problems/valid-anagram/)
    242. Valid Anagram

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for(auto c:s){
            mapS[c]++;
        }

        for(auto c:t){
            mapT[c]++;
        }

        for(auto &[key, val]:mapS){
            if(mapT.find(key) == mapT.end()){
                return false;
            }else{
                if(val != mapT[key]){
                    return false;
                }
            }
        }
        return true;

    }

*/

/*

    Problem 92
    (https://leetcode.com/problems/search-in-a-binary-search-tree/)
    700. Search in a Binary Search Tree

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == val){
            return root;
        }else if(val > root->val){
            return searchBST(root->right, val);
        }

        return searchBST(root->left, val);
    }

*/

/*

    Problem 93
    (https://leetcode.com/problems/kth-largest-element-in-a-stream/)
    703. Kth Largest Element in a Stream

    class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>> minque;
        int k;

        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (int num : nums) {
                add(num);
            }
        }

        int add(int val) {
            if(minque.size() < k){
                minque.push(val);
            }else if(val > minque.top()){
                minque.pop();
                minque.push(val);
            }

            return minque.top();
        }
    };

*/

/*

    Problem 94
    (https://leetcode.com/problems/is-graph-bipartite/)
    785. Is Graph Bipartite?

    void dfsColorGraph(int node, unordered_map<int, vector<int>> &graphMap, unordered_map<int, char> &graphColors, unordered_map<int, bool> &visited, char color){
        graphColors[node] = color;
        visited[node] = true;
        // cout << node << endl;

        for(auto child:graphMap[node]){
            if(visited.find(child) == visited.end()){
                if(color == 'r'){
                    dfsColorGraph(child, graphMap, graphColors, visited, 'b');
                }else{
                    dfsColorGraph(child, graphMap, graphColors, visited, 'r');
                }
            }
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        unordered_map<int, vector<int>> graphMap;
        unordered_map<int, char> graphColors;
        unordered_map<int, bool> visited;

        for(int i = 0; i < graph.size(); i++){
            graphMap[i] = graph[i];
            graphColors[i] = 'x';
        }

        for(auto &[key, val]:graphMap){
            if(visited.find(key) == visited.end()){
                dfsColorGraph(key, graphMap, graphColors, visited, 'b');
            }
        }

        

        for(auto &[key, val]: graphMap){
            char parentColor = graphColors[key];

            for(auto each_child:val){
                if(graphColors[each_child] == parentColor){
                    return false;
                }
            }
        }
        
        return true;
    }
*/

/*

    Problem 95
    (https://leetcode.com/problems/longest-increasing-subsequence/)
    300. Longest Increasing Subsequence

    int longestIS(vector<int> &nums, int idx, int previdx, vector<vector<int>> &dpArray){
        if(idx >= nums.size()){
            return 0;
        }
        

        // int count = 0;
        if(dpArray[idx][previdx+1] != -1){
            return dpArray[idx][previdx+1];
        }
        int maxCount = 0;

        for(int i = idx; i < nums.size(); i++){
            if(previdx == -1 || nums[i] > nums[previdx]){
                int count = 1 + longestIS(nums, i+1, i, dpArray);
                maxCount = max(maxCount, count);
            }
        }

        dpArray[idx][previdx+1] = maxCount;
        return maxCount;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dpArray(nums.size()+2, vector<int>(nums.size()+2, -1));
        return longestIS(nums, 0, -1, dpArray);
    }

*/

/*

    Problem 96
    (https://leetcode.com/problems/coin-change/)
    Coin Change

    int minCoins(vector<int> &coins, int amount, vector<int> &dpArray){
        if(amount == 0){
            return 0;
        }
        
        if(dpArray[amount] != -1){
            return dpArray[amount];
        }

        int minCount = INT_MAX;
        // int count = 0;
        for(int i = 0; i < coins.size(); i++){

            if(coins[i] <= amount){
                int count = minCoins(coins, amount - coins[i], dpArray);
                if(count != INT_MAX){
                    minCount = min(count+1, minCount);
                    dpArray[amount] = minCount;
                }
            }
        }

        dpArray[amount] = minCount;
        return minCount;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dpArray(amount + 1, -1);
        int ans =  minCoins(coins, amount, dpArray);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
*/

/*

    Problem 97
    (BEST METHOD)
    (https://leetcode.com/problems/top-k-frequent-elements/)
    347. Top K Frequent Elements

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> countMap;

        for(auto v:nums){
            countMap[v]++;
        }

        vector<vector<int>> frqVal(nums.size()+1);

        for(auto &[key, val]:countMap){
            // cout << val << " , "<< key << endl;
            frqVal[val].push_back(key);
        }

        // cout << frqVal.size() << endl;

        vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; --i) {
            for (int num : frqVal[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;

    }

*/

/*

    Problme 98
    (https://leetcode.com/problems/middle-of-the-linked-list/)
    876. Middle of the Linked List

    ListNode* middleNode(ListNode* head) {
        ListNode* tor = head;
        ListNode* rab = head;

        while(rab && rab->next){
            tor = tor->next;
            rab = rab->next->next;
        }

        return tor;
    }

*/

/*

    Problem 99
    (https://leetcode.com/problems/partition-equal-subset-sum/)
    416. Partition Equal Subset Sum

    bool equalSubsetSum(vector<int> &nums, int i, int sum, int totSum, vector<vector<int>> &dpArr){
        if(i >= nums.size()){
            return false;
        }

        if(dpArr[i][sum] != -1){
            return dpArr[i][sum];
        }
        if(sum == totSum){
            return true;
        }

        bool includeans = equalSubsetSum(nums, i+1, nums[i]+sum, totSum, dpArr);
        bool excludeans = equalSubsetSum(nums, i+1, sum, totSum, dpArr);

        dpArr[i][sum] = includeans || excludeans;

        return dpArr[i][sum];
    }

    bool canPartition(vector<int>& nums) {
        
        int totSum = 0;

        for(auto v:nums){
            totSum += v;
        }

        if(totSum&1){
            return false;
        }

        vector<vector<int>> dpArr(nums.size()+1, vector<int>(totSum+1, -1));
        return equalSubsetSum(nums, 0, 0, totSum/2, dpArr);
    }

*/