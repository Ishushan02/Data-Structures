/*
    Problem 31
    190. Reverse Bits
    (https://leetcode.com/problems/reverse-bits/)

    uint32_t reverseBits(uint32_t n) {
        
        int s = 0;
        uint32_t ans = 0;
        while(n){
            ans = ans << 1;
            if(n & 1){
                ans += 1;
            }else{
                ans += 0;
            }
            s++;
            n = n >> 1;
        }

        // cout << s << endl;
        for(int i = s; i < 32; i++){
            ans = ans << 1;
        }
        

        return ans;
    }
*/

/*
    Problem 32
    191. Number of 1 Bits
    (https://leetcode.com/problems/number-of-1-bits/)

    int hammingWeight(int n) {
        
        int count = 0;

        while(n){

            if(n & 1){
                count = count + 1;
            }
            n = n >> 1;
        }

        return count;
    }
        
*/

/*
    Problem 33
    322. Coin Change
    (https://leetcode.com/problems/coin-change/)

    int allDenominations(vector<int>& coins, int amount, vector<int> &dpArray){
        if(dpArray[amount] != -1){
            return dpArray[amount];
        }
        
        if(amount == 0){
            return 0;
        }

        int minSteps = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            // cout << i << endl;
            if(amount - coins[i] >= 0){
                int ans = allDenominations(coins, amount - coins[i], dpArray);
                if(ans != INT_MAX){
                    minSteps = min(minSteps, ans+1);
                }   
                
            }
        }

        dpArray[amount] = minSteps;
        return dpArray[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dpArray(amount + 1, -1);
        int ans = allDenominations(coins, amount, dpArray);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }

*/

/* 
    Problem 34
    70. Climbing Stairs
    (https://leetcode.com/problems/climbing-stairs/)

    int allPossibility(int n, vector<int> &dpArray){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }

        if(dpArray[n] != -1){
            return dpArray[n];
        }

        dpArray[n] = allPossibility(n -1, dpArray) + allPossibility(n - 2, dpArray);
        return dpArray[n];
    }

    int climbStairs(int n) {
        vector<int> dpArray(n+1, -1);
        return allPossibility(n, dpArray);
    }

*/

/*
    Problem 35
    198. House Robber
    (https://leetcode.com/problems/house-robber/)

    int robHouse(vector<int>& nums, int i, vector<int> &dpArray){
        if(i >= nums.size()){
            return 0;
        }
        if(dpArray[i] != -1){
            return dpArray[i];
        }

        int include = nums[i] + robHouse(nums, i + 2, dpArray);
        int exclude = robHouse(nums, i + 1, dpArray);
        dpArray[i] = max(include, exclude);
        return dpArray[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dpArray(nums.size(), -1);
        return robHouse(nums, 0, dpArray);
    }
*/

/*
    Problem 36
    200. Number of Islands
    (https://leetcode.com/problems/number-of-islands/)

    void visit(int m, int n, int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){

        if(i < 0 || i >= m || j < 0 || j >= n){
            return ;
        }

        if(visited[i][j] == false && grid[i][j] == '1'){
            visited[i][j] = true;
            visit(m, n, i+1, j, grid, visited);
            visit(m, n, i, j+1, grid, visited);
            visit(m, n, i-1, j, grid, visited);
            visit(m, n, i, j-1, grid, visited);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] =='1' && visited[i][j] == false){
                    ans += 1;
                    visit(m, n, i, j, grid, visited);
                }
            }
        }

        return ans;

    }
*/

/*
    Problem 37
    73. Set Matrix Zeroes
    (https://leetcode.com/problems/set-matrix-zeroes/)

    void setCol(int m, int n, int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
        for(int i = 0; i < m; i++){
            if(i != row && matrix[i][col] != 0){
                matrix[i][col] = 0;
                visited[i][col] = true;
            }
        }

    }

    void setRow(int m, int n, int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
        for(int i = 0; i < n; i++){
            if(i != col && matrix[row][i] != 0){
                matrix[row][i] = 0;
                visited[row][i] = true;
            }
        }
        
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == false && matrix[i][j] == 0){
                    // cout << i << " , " << j << endl;
                    setRow(m ,n, i, j, matrix, visited);
                    setCol(m ,n, i, j, matrix, visited);
                }
            }
        }
    }

*/

/*
    Problem 38
    206. Reverse Linked List
    (https://leetcode.com/problems/reverse-linked-list/)

    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp){
            ListNode* nextElem = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextElem;
        }

        return prev;
    }

*/

/*
    Problem 39
    79. Word Search
    (https://leetcode.com/problems/word-search/)

    bool wordPresent(int m, int n, int row, int col, vector<vector<char>>& board, string word, int i, vector<vector<bool>>& visited){
        if(i >= word.length()){
            return true;
        }

        if( row < 0 || row >= m || col < 0 || col >= n){
            return false;
        }

        if(visited[row][col] == false && word[i] == board[row][col]){
            visited[row][col] = true;
            bool ansVal = wordPresent(m, n, row+1, col, board, word, i+1, visited) || wordPresent(m, n, row-1, col, board, word, i+1, visited) || wordPresent(m, n, row, col+1, board, word, i+1, visited) ||  wordPresent(m, n, row, col-1, board, word, i+1, visited) ;
            if(ansVal){
                return true;
            }
            visited[row][col] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    vector<vector<bool>> visited(m ,vector<bool>(n, false));
                    bool ans = wordPresent(m, n, i, j, board, word, 0, visited);
                    if(ans){
                        return true;
                    }
                }
            }
        }

        return false;
    }
*/

/*
    Problem 40
    207. Course Schedule
    (https://leetcode.com/problems/course-schedule/)

    bool dfs(int node, unordered_map<int, vector<int>> &graph, vector<bool> &visited){

        visited[node] = true;
        for(auto each_node: graph[node]){
            if(visited[each_node] == false){
                bool temp = dfs(each_node, graph, visited);
                if(temp){
                    // cout << node << " , " << each_node << endl;
                    return true;
                }
            }else{
                // cout << node << " here , " << each_node << endl;
                return true;
            }
        }
        visited[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> graph;
        

        for(auto v: prerequisites){
            graph[v[1]].push_back(v[0]);
        }

        // dfs is giving TLE

        vector<int> indegree(numCourses, 0);

        for(auto &[key, values]:graph){
            for(auto node: values){
                indegree[node]++;
            }
        }

        queue<int> que;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        int ans = 0;

        while(!que.empty()){
            int front = que.front();
            que.pop();
            ans++;

            for(auto node: graph[front]){
                indegree[node]--;
                if(indegree[node] == 0){
                    que.push(node);
                }
            }
        }

        if(ans == numCourses){
            return true;
        }

        return false;

    }

*/

/*
    Problem 41
    338. Counting Bits
    (https://leetcode.com/problems/counting-bits/)

    vector<int> countBits(int n) {
        
        vector<int> ans;

        for(int i = 0; i <= n; i++){
            int count = 0;
            int k = i;
            while(k){
                if(k & 1)
                    count++;
                k = k >> 1;
            }
            ans.push_back(count);
        }

        return ans;
    }
*/

/*
    Problem 42
    208. Implement Trie (Prefix Tree)
    (https://leetcode.com/problems/implement-trie-prefix-tree/)

    class TrieNode{

        public: 
            unordered_map<char, TrieNode*> child;
            bool isTerminal;
            char value;
            TrieNode(char c){
                value = c;
                isTerminal = false;
            }

            void insert(TrieNode* root, string word){
                if(word.length()==0){
                    root->isTerminal = true;
                    return ;
                }

                TrieNode* newNode;
                char c = word[0];
                if(root->child.count(c) == 1){
                    newNode = root->child[c];
                }else{
                    newNode = new TrieNode(c);
                    root->child[c] = newNode;
                }
                insert(newNode, word.substr(1));
            }

            bool search(TrieNode* root, string word){
                if(word.length()==0){
                    return root->isTerminal;
                }

                TrieNode* newNode;
                char c = word[0];
                if(root->child.find(c) != root->child.end()){
                    newNode = root->child[c];
                }else{
                    return false;
                }
                return search(newNode, word.substr(1));
            }

            bool startsWith(TrieNode* root, string word){
                if(word.length()==0){
                    return true;
                }

                TrieNode* newNode;
                char c = word[0];
                if(root->child.find(c) != root->child.end()){
                    newNode = root->child[c];
                }else{
                    return false;
                }
                return startsWith(newNode, word.substr(1));
            }
    };


    class Trie {
    public:

        TrieNode* root;

        Trie() {
            root = new TrieNode('-');
        }
        
        void insert(string word) {
            root->insert(root, word);
        }
        
        bool search(string word) {
            return root->search(root, word);
        }
        
        bool startsWith(string prefix) {
            return root->startsWith(root, prefix);
        }
};
*/

/*
    Problem 43
    211. Design Add and Search Words Data Structure
    (https://leetcode.com/problems/design-add-and-search-words-data-structure/)

    class Trie{
        public:
            char value;
            unordered_map<char, Trie*> child;
            bool isTerminal;

            Trie(char c){
                isTerminal = false;
                value = c;
            }

            void insert(Trie* root, string word){
                if(word.length() == 0){
                    root->isTerminal = true;
                    return ;
                }

                Trie* childNode;
                char c = word[0];

                if(root->child.count(c) == 1){
                    childNode = root->child[c];
                }else{
                    childNode = new Trie(c);
                    root->child[c] = childNode;
                }
                insert(childNode, word.substr(1));
            }

            bool search(Trie* root, string word){
                if(word.length() == 0){
                    return root->isTerminal;
                }

                Trie* childNode;
                char c = word[0];
                bool ans = false;
                if(root->child.find(c) != root->child.end()){
                    childNode = root->child[c];
                    ans = ans || search(childNode, word.substr(1));
                }else if(c == '.'){
                    for(auto &[c, val]:root->child){
                        ans = ans || search(val, word.substr(1));
                    }
                    // childNode = root;
                }else{
                    ans = false;
                }
                return ans;
            }
    };

    class WordDictionary {
    public:

        Trie* root;

        WordDictionary() {
            root = new Trie('-');
        }
        
        void addWord(string word) {
            root->insert(root, word);
        }
        
        bool search(string word) {
            return root->search(root, word);
        }
    };

*/