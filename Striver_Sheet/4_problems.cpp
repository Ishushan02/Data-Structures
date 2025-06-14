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