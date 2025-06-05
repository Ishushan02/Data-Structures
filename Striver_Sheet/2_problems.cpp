/*
    Problem 26
    50. Pow(x, n)
    (https://leetcode.com/problems/powx-n/)

    double pow(double x, long long int n){
        double ans = 1;
        while(n){

            if(n & 1){
                ans = ans * x;
            }

            x = x * x;
            n = n >> 1;
        }

        return ans;
    }

    double myPow(double x, long long int n) {

        if(n < 0){
            double ans = pow(x, abs(n));
            return 1/ans;
        }

        return pow(x, n);
    }
*/

/*
    Problem 27
    51. N-Queens
    (https://leetcode.com/problems/n-queens/description/)

    bool isSafe(int n, vector<vector<string>> &board, int i, int j){

        int row = i;
        int col = j;

        for(int k = 0; k < n; k++){
            if(board[row][k] == "Q"){
                return false;
            }
        }

        for(int k = 0; k < n; k++){
            if(board[k][col] == "Q"){
                return false;
            }
        }

        row = i;
        col = j;

        while(row >= 0 && col >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
            col--;
        }

        row = i;
        col = j;
        while(row < n && col < n){
            if(board[row][col] == "Q"){
                return false;
            }
            row++;
            col++;
        }

        row = i;
        col = j;
        while(row >= 0 && col < n){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
            col++;
        }

        row = i;
        col = j;
        while(row < n && col >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    unordered_map<int, bool> valMap;
    void placeQueens(int n, int i, vector<vector<string>> &board, vector<vector<string>> &res){     
        // cout << i << endl;
        if(valMap[i]){
            return ;
        }
        if(i >= n){
            vector<string> tempAns;
            for(int p = 0; p < n; p++){
                string temp;
                for(int q = 0; q < n; q++){
                    temp += board[p][q];
                }
                tempAns.push_back(temp);
            }
            res.push_back(tempAns);
            return ;
        }

        for(int row = i; row < n; row++){
            for(int col = 0; col < n; col++){
                if(isSafe(n, board, row, col)){
                    board[row][col] = "Q";
                    valMap[row] = true;
                    placeQueens(n, i+1, board, res);
                    valMap[row] = false;
                    board[row][col] = ".";
                }
            }
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> res;

        placeQueens(n, 0, board, res);

        return res;
    }

*/

/*
    Problem 28
    53. Maximum Subarray
    (https://leetcode.com/problems/maximum-subarray/)

    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN;
        int tempSum = 0;

        for(auto i: nums){

            tempSum += i;
            maxSum = max(maxSum, tempSum);
            if(tempSum < 0){
                tempSum = 0;
            }
        }

        return maxSum;
    }
        
*/

/*
    VVVIII Question 
    Problem 29
    60. Permutation Sequence
    (https://leetcode.com/problems/permutation-sequence/)

    int factorial(int n){
        if(n == 1 || n == 0){
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    void permuteStringSeq(int n, int k, string &ans, string &s){
        if(n == 1){
            ans += s[0];
            return ;
        }

        int fct = factorial(n-1);
        int idx = k / fct;
        if(k % fct == 0){
            idx--;
        }

        ans += s[idx];
        s.erase(idx, 1);
        k = k - (idx * fct);
        permuteStringSeq(n-1, k, ans, s);
    }

    string getPermutation(int n, int k) {

        string s;
        for(auto i = '1'; i <= n + '0'; i++){
            s += i;
        }
        cout << s << endl;
        string ans;
        permuteStringSeq(n, k, ans, s);
        return ans;
    }

*/

/*
    61. Rotate List
    Problem 30
    (https://leetcode.com/problems/rotate-list/description/)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* temphead = head;
        ListNode* temptail = NULL;
        int n = 0;

        while(temphead){
            n += 1;
            temptail = temphead;
            temphead = temphead->next;
        }
        if(n == k){
            return head;
        }
        // cout << temptail->val << endl;

        temptail->next = head;
        
        int rotations = 0;

        if(n > k){
            rotations = n - k + 1;
        }else{
            // cout << k % n << endl;
            rotations = n - (k % n)+1;
        }

        // cout << rotations << endl;
        ListNode* prev = temptail;
        ListNode* ans = NULL;
        

        while(rotations){
            ans = temptail->next;
            prev = temptail;
            temptail = temptail->next;
            rotations--;
        }
        prev->next = NULL;
        // cout << ans->val << " , " << prev->val << endl;
        
        return ans;
    } 
*/

/*
    Problem 31
    (https://leetcode.com/problems/unique-paths/description/)

    int allPossiblePaths(int x, int y, int m, int n, vector<vector<int>> &dpArr){
        if(x == m - 1 && y == n - 1){
            return 1;
        }
        
        if(x >= m || y >= n){
            return 0;
        }

        if(dpArr[x][y] != -1){
            return dpArr[x][y];
        }
        
        int count = 0;
        count = allPossiblePaths(x + 1, y, m, n, dpArr) + allPossiblePaths(x, y + 1, m, n, dpArr);

        dpArr[x][y] = count;
        return dpArr[x][y];
    }

    int uniquePaths(int m, int n) {
        
        int ans = 0;
        vector<vector<int>> dpArr(m+1, vector<int>(n+1, -1));
        return allPossiblePaths(0, 0, m, n, dpArr);
        
    }
*/

/*
    Problem 32
    Minimum Path Sum
    (https://leetcode.com/problems/minimum-path-sum/)

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dpArr(row+1, vector<int>(col+1, 0));

        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                if(i == row - 1){
                    dpArr[i][j] = grid[i][j] + dpArr[i][j+1];
                }else if(j == col - 1){
                    dpArr[i][j] = grid[i][j] + dpArr[i+1][j];
                }else{
                     int val1 = dpArr[i+1][j] + grid[i][j];
                     int val2 = dpArr[i][j+1] + grid[i][j];
                    dpArr[i][j] = min(val1, val2);
                }
                
            }
        }


        return dpArr[0][0];
    }
        
*/

/*
    Problem 33
    (https://leetcode.com/problems/edit-distance/description/)

    int modifyStrings(int i, int j, string &word1, string &word2, vector<vector<int>> &dpArr){

        if(i >= word1.length() && j >= word2.length()){
            return 0;
        }else if(i >= word1.length()){
            return word2.length()-j;
        }else if(j >= word2.length()){
            return word1.length()-i;
        }

        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }

        int operations = 0;
        if(word1[i] == word2[j]){
            operations = 0 + modifyStrings(i+1, j+1, word1, word2, dpArr);
        }else{

            int insertop = 1 + modifyStrings(i, j+1, word1, word2, dpArr);
            int deleteop = 1 + modifyStrings(i+1, j, word1, word2, dpArr);
            int replaceop = 1 + modifyStrings(i+1, j+1, word1, word2, dpArr);

            operations = min(insertop, min(deleteop, replaceop));
        }

        dpArr[i][j] = operations;
        return dpArr[i][j];
    }

    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dpArr(word1.length()+1, vector<int>(word2.length()+1, -1));
        return modifyStrings(0, 0, word1, word2, dpArr);
    }
*/

/*
    Problem 34
    Set Matrix Zeroes
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

    Problem 35
    Search a 2D Matrix
    (https://leetcode.com/problems/search-a-2d-matrix/description/)

    bool binarySearch(vector<int> &arr, int target){
        int start = 0;
        int end = arr.size()-1;
        int mid = (start + end)/2;

        while(start <= end){
            cout << start << " , " << mid << " , " << end << endl;
            if(arr[mid] == target){
                return true;
            }else if(target < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }
        
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row-1;
        int mid = (start + end)/2;

        int idx = 0;
        while(start <= end){
            if(target >= matrix[mid][0]){
                idx = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return binarySearch(matrix[idx], target);
    }
*/

/*
    Problem 36
    Sort Colors
    (https://leetcode.com/problems/sort-colors/)

    void sortColors(vector<int>& nums) {
        
        int start = 0;
        int mid = 0;
        int end = nums.size()-1;

        while(mid <= end){

            if(nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                mid++;
                start++;
            }else{
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }

*/

/*

    Problem 37
    84. Largest Rectangle in Histogram
    (https://leetcode.com/problems/largest-rectangle-in-histogram/)

    vector<int> prevSmallerElem(vector<int>& heights){
        vector<int> ans(heights.size(), 0);
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }

        // for(auto v:ans){
        //     cout << v << " ";
        // }
        return ans;
    }

    vector<int> nextSmallerElem(vector<int>& heights){
        vector<int> ans(heights.size(), 0);
        stack<int> st;

        for(int i = heights.size()-1; i >=0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = heights.size();
            }else{
                ans[i] = st.top();
            }

            st.push(i);
        }

        // for(auto v:ans){
        //     cout << v << " ";
        // }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> prevElements = prevSmallerElem(heights);
        vector<int> nextElements = nextSmallerElem(heights);

        int maxAns = 0;

        for(int i = 0; i < heights.size(); i++){
            maxAns = max(maxAns, ((nextElements[i] - prevElements[i] - 1) * heights[i]));
        }

        return maxAns;
    }
*/

/*
    Problem 38
    88. Merge Sorted Array
    (https://leetcode.com/problems/merge-sorted-array/)

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){

            if(nums2[j] >= nums1[i]){
                nums1[k] = nums2[j];
                j--;
            }else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }

        while(i >= 0){
            nums1[k] = nums1[i];
            i--;
            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
*/

/*
    Problem 39
    (https://leetcode.com/problems/subsets-ii/)

    90. Subsets II
    void uniquePowerSet(vector<int>& nums, int idx, vector<int> &ans, vector<vector<int>> &res){
        res.push_back(ans);

        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i-1] == nums[i]) continue;

            ans.push_back(nums[i]);
            uniquePowerSet(nums, i + 1, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        uniquePowerSet(nums, 0, ans, res);

        return res;
    }
*/


/*

    Problem 40
    (https://leetcode.com/problems/binary-tree-inorder-traversal/)

    94. Binary Tree Inorder Traversal
    void tranverse(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }

        tranverse(root->left, ans);
        ans.push_back(root->val);
        tranverse(root->right, ans);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        tranverse(root, ans);

        return ans;
    }
*/

/*

    Problem 41
    (https://leetcode.com/problems/validate-binary-search-tree/)

    98. Validate Binary Search Tree
    bool checkValidity(TreeNode* root, long long int leftrange, long long int rightrange){
        
        if(root == NULL){
            return true;
        }
        if(root->left){
            int leftVal = root->left->val;

            if(leftVal >= root->val || leftVal <= leftrange ){
                return false;
            }
        }

        if(root->right){
            int rightVal = root->right->val;

            if(rightVal <= root->val || rightVal >= rightrange){
                return false;
            }
        }

        long long int lmin = leftrange;
        long long int lmax = root->val;

        long long int rmin = root->val;
        long long int rmax = rightrange;

        return checkValidity(root->left, lmin, lmax) && checkValidity(root->right, rmin, rmax);
    }

    bool isValidBST(TreeNode* root) {

        if(root == NULL){
            return true;
        }
        
        return checkValidity(root, LONG_MIN, LONG_MAX);
    }
*/

/*

    Problem 42
    100. Same Tree
    (https://leetcode.com/problems/same-tree/)

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }else if(p != NULL && q == NULL){
            return false;
        }else if(p == NULL && q != NULL){
            return false;
        }else if(p->val != q->val){
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }  

*/

/*

    Problem 43
    (https://leetcode.com/problems/symmetric-tree/)
    101. Symmetric Tree

    bool isMirror(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }else if(p == NULL && q != NULL || p != NULL && q == NULL){
            return false;
        }else if(p->val != q->val){
            return false;
        }


        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {

        return isMirror(root->left, root->right);
    }
*/

/*

    Problem 44
    102. Binary Tree Level Order Traversal
    (https://leetcode.com/problems/binary-tree-level-order-traversal/)

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        que.push(root);

        while(!que.empty()){
            vector<int> temp;
            int size = que.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                temp.push_back(node->val);

                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
                que.pop();
            }

            ans.push_back(temp);
        }

        return ans;
    }

*/

/*

    Problem 45
    103. Binary Tree Zigzag Level Order Traversal
    (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        bool reverseFlag = false;
        que.push(root);

        while(!que.empty()){
            vector<int> temp;
            int size = que.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                temp.push_back(node->val);

                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
                que.pop();
            }

            if(reverseFlag){
                reverse(temp.begin(), temp.end());
                reverseFlag = false;
            }else{
                reverseFlag = true;
            }
            
            ans.push_back(temp);
        }

        return ans;
    }
    
*/

/*

    Problem 46
    (https://leetcode.com/problems/maximum-depth-of-binary-tree/)
    104. Maximum Depth of Binary Tree

    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = depth(root->left);
        int rh = depth(root->right);
        return max(lh, rh) + 1;
    }

    int maxDepth(TreeNode* root) {
        return depth(root);   
    }
*/

/*

    Problem 47
    (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
    105. Construct Binary Tree from Preorder and Inorder Traversal

    TreeNode* treeNodeMake(vector<int>& preorder, vector<int>& inorder, int &idx, int start, int end, unordered_map<int, int> &indexMap){
        if(start >= end){
            return NULL;
        }

        if(idx >= preorder.size()){
            return NULL;
        }
        
        TreeNode* rootNode = new TreeNode(preorder[idx]);
        int inorderdidx = indexMap[preorder[idx]];
        idx++;
        rootNode->left = treeNodeMake(preorder, inorder, idx, start, inorderdidx, indexMap);
        rootNode->right = treeNodeMake(preorder, inorder, idx, inorderdidx+1, end, indexMap);

        return rootNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if( n == 0){
            return NULL;
        }
        unordered_map<int, int> indexMap;
        for(int i = 0; i < n; i++){
            indexMap[inorder[i]] = i;
        }

        int idx = 0;
        TreeNode* root = treeNodeMake(preorder, inorder, idx, 0, n, indexMap);

        return root;
    }
        
*/

/*

    Problem 48
    (https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
    106. Construct Binary Tree from Inorder and Postorder Traversal

    TreeNode* getTreeNode(vector<int>& inorder, vector<int>& postorder, int &idx, int start, int end, unordered_map<int, int> &indexMap){
        if(idx <= 0){
            return NULL;
        }
        if(start >= end){
            return NULL;
        }

        idx--;
        int inorderidx = indexMap[postorder[idx]];
        TreeNode* rootNode = new TreeNode(inorder[inorderidx]);
        
        rootNode->right = getTreeNode(inorder, postorder, idx, inorderidx+1, end, indexMap);
        rootNode->left = getTreeNode(inorder, postorder, idx, start, inorderidx, indexMap);
        
        return rootNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0){
            return NULL;
        }

        unordered_map<int, int> indexMap;
        int idx = n;
        for(int i = 0; i < n; i++){
            indexMap[inorder[i]] = i;
        }

        return getTreeNode(inorder, postorder, idx, 0, n, indexMap);
    }
*/

/*

    Problem 49
    (https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
    108. Convert Sorted Array to Binary Search Tree

    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start >= end){
            return NULL;
        }

        int mid = (start+end)/2;
        TreeNode* rootNode = new TreeNode(nums[mid]);

        rootNode->left = buildTree(nums, start, mid);
        rootNode->right = buildTree(nums, mid+1, end);

        return rootNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return NULL;
        }

        return buildTree(nums, 0, n);
    }
*/

/*

    Problem 50
    110. Balanced Binary Tree
    (https://leetcode.com/problems/balanced-binary-tree/description/)

    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return max(lh, rh) + 1;
    }

    void traverse(TreeNode* root, bool &isBalanced){
        if(root == NULL){
            return ;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(abs(lh - rh) > 1){
            isBalanced = false;
            return ;
        }


        traverse(root->left, isBalanced);
        traverse(root->right, isBalanced);

    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        traverse(root, isBalanced);

        return isBalanced;
    }

*/