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