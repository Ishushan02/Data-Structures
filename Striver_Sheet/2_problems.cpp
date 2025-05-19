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