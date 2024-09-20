#include <iostream>

using namespace std;

/*

Do Inplace Merging, it's very Important
*/

/*

17. Letter Combinations of a Phone Number
(https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

    void traverse(string digits, string tempans,  int index, map<char, string>& data, vector<string>& ans){
        
        if(tempans.length()==digits.length()){
            // cout << tempans << " ";
            ans.push_back(tempans);
            return;
        }
        char val = digits[index];
        string value =  data[val];
        for(int i = 0; i < value.length(); i++){
            // tempans += value[i];
            traverse(digits, tempans + value[i], index+1, data, ans);
        }
    }
    

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> number = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        if(digits.length()==0) return ans;
        traverse(digits, "", 0, number, ans);

        return ans;
    }

*/

/*

1079. Letter Tile Possibilities
Do it (Very Important Question)

*/

/*

22. Generate Parentheses
(https://leetcode.com/problems/generate-parentheses/description/)
(Important Question )

    void allParenthesis(int n, int bopen, int bclose, string ans, vector<string> &res){

        if(bopen + bclose == (2 * n)){
            res.push_back(ans);
            return;
        }
        

        if(bopen < n){
            allParenthesis(n, bopen+1, bclose, ans + "(", res);
        }
        if(bclose < bopen){
            allParenthesis(n, bopen, bclose+1, ans + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
       
        vector<string> res;

        allParenthesis(n, 0, 0, "", res);

        return res;
    }
*/

/*

Leetcode Question No. 240

*/

/*

77. Combinations
(https://leetcode.com/problems/combinations/description/)

    void totalComb(int n, int k, vector<int>& ans,vector<vector<int>>& res, int index){
        
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }

        if(index > n){
            return;
        }

        // include
        ans.push_back(index);
        totalComb(n, k, ans, res, index+1);
        ans.pop_back();

        // exclude
        totalComb(n, k, ans, res, index+1);
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> ans;
        totalComb(n, k, ans, res, 1);

        return res;
    }

*/

/*

79. Word Search
(https://leetcode.com/problems/word-search/description/)

    bool traverseMat(vector<vector<char>>& board, string& word, int index, int x, int y, int m, int n){     
        
        if(index >= word.length()){
            return true;
        }

        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[index]){
            return false;
        }

        char c = board[x][y];
        board[x][y] = '*';
        bool ans = traverseMat(board, word, index+1, x, y+1, m, n) ||
                   traverseMat(board, word, index+1, x+1, y, m, n) ||
                   traverseMat(board, word, index+1, x-1, y, m, n) ||
                   traverseMat(board, word, index+1, x, y-1, m, n)  ;
        board[x][y] = c;

        if (ans){
            return true;
        }

        return false;

        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
    
        
        for(int i = 0; i < m;i++){
            for(int j = 0; j<n; j++){
                int index = 0;
                if(traverseMat(board, word, index, i, j, m, n)){
                    return true;
                }
            }
        }
        return false;
    }

*/

/*

52. N-Queens II
(https://leetcode.com/problems/n-queens-ii/description/)

    bool isSafe(vector<vector<char>>& chess, int x, int y, int n){
        int tempx;
        int tempy;
        // right
        tempx = x;
        tempy = y + 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempy = tempy + 1;
        }

        // left
        tempx = x;
        tempy = y - 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempy = tempy - 1;
        }

        // up
        tempx = x - 1;
        tempy = y ;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx - 1;
        }

        // down
        tempx = x + 1;
        tempy = y ;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx + 1;
        }

        // diagUpRi
        tempx = x - 1;
        tempy = y + 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx - 1;
            tempy = tempy + 1;
        }

        // diagUpLe
        tempx = x - 1;
        tempy = y - 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx - 1;
            tempy = tempy - 1;
        }

        // diagBottL
        tempx = x + 1;
        tempy = y - 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx + 1;
            tempy = tempy - 1;
        }

        // diagBottR
        tempx = x + 1;
        tempy = y + 1;
        while(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n){
            if(chess[tempx][tempy] == 'Q'){
                return false;
            }
            tempx = tempx + 1;
            tempy = tempy + 1;
        }

        return true;

    }

    void traverseChess(vector<vector<char>>& chess, int col, int& res, int n){

        if(col == n){
            res = res + 1;
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(chess, row, col, n)){
                chess[row][col] = 'Q';
                traverseChess(chess, col+1, res, n);
                chess[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> chess(n, vector<char>(n, '.'));
        int res = 0;
        int col = 0;
        traverseChess(chess, col, res, n);

        return res;

    }

*/