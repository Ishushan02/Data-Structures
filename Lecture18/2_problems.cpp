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


/*

473. Matchsticks to Square
(https://leetcode.com/problems/matchsticks-to-square/description/)

// It's a DP Question try solving it using DP as well 


    bool checkpossibility(vector<int>& matchsticks, vector<int>& eachsides, int index){
        if(index == matchsticks.size()){ // reached the end, check whether each sides is 0 or not
            
            return ((eachsides[0] == 0) && (eachsides[1] == 0) && (eachsides[2] == 0) && (eachsides[3] == 0)) ;
        } 

        bool ans = false;

        for(int i = 0; i < eachsides.size();i++){

            // before subtracting checking if eachsides[i] > matchstick index
            if (eachsides[i] >= matchsticks[index]){
                eachsides[i] = eachsides[i] - matchsticks[index];
                ans = ans || checkpossibility(matchsticks, eachsides, index+1);
                if(ans){
                    return true;
                }
                eachsides[i] = eachsides[i] + matchsticks[index];
            }
        }

        return ans;
    }

    static bool customcmp(int a, int b){
        return a > b;
    } 


    bool makesquare(vector<int>& matchsticks) {

        if(matchsticks.size()<4){
            return false;
        }

        int totalsum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (totalsum%4 != 0){
            return false;
        }

        int length = totalsum/4;

        vector<int> eachsides(4, length);

        int index = 0;
        
        // just sorting in decreasing order such that number of recursive call decreases
        sort(matchsticks.begin(), matchsticks.end(), customcmp); // sort(matchsticks.rbegin(), matchsticks.end());
        // or else you will get TLE

        return checkpossibility(matchsticks, eachsides, index);
    }

*/

/*

InPlace Merge Sort (VVI -- Out of the Box Topic, but better be thorough with it)

    Generally we do it by because while doing merge operation of 2 sorted arrays,
    we use extra space. So, to remove that extra space we use inplace merge sorting.

    Method 1

    Let's say we have given 2 sorted arrays and we have to merge it.

    arr1 -> 1, 7, 9, 15, 18, 22
    arr2 -> 6, 8, 10, 13, 17, 21

    i is iterating arr1 and j is itterating arr2

    i = 0, j = 0, 1 < 6 so i ++

    i = 1, j = 0, 7 > 6 hence swap it and rearrange 7 in it's correct place
    arr1 -> 1, 6, 9, 15, 18, 22
    arr2 -> 7, 8, 10, 13, 17, 21

    i = 2, j = 0 9 > 7 hence swap it and rearrange 9 in it's correct place
    arr1 -> 1, 6, 7, 15, 18, 22
    arr2 -> 9, 8, 10, 13, 17, 21 ---> 8, 9, 10, 13, 17, 21

    i = 3, j = 0 15 > 8 swap and reaarange it
    arr1 -> 1, 6, 7, 8, 18, 22
    arr2(after rearranging) -> 9, 10, 13, 15, 17, 21
    i = 4, j = 0 18 > 9 Swap, reaarange

    arr1 -> 1, 6, 7, 8, 9, 22
    arr2 -> 10, 13, 15, 17, 18, 21

    //ly

    arr1 -> 1, 6, 7, 8, 9, 10
    arr2 -> 10, 13, 15, 17, 18, 21, 22

    //---- Now we can directly merge both the array's without using any spaces as both of them are sorted .



    Method 2

    GAP Method
    arr1 -> 1, 7, 9, 15, 18, 22
    arr2 -> 6, 8, 10, 13, 17, 21

    int n = arr1.size(), int m = arr2.size();

    // combine both the arrays
    int gap = ceil[ (m+n)/2 ]
    int i = 0;
    int j = i + gap;

        if(arr[i] > arr[j]){
            swap(arr[i], arr[j]);
        }
        i++;
        j++;
        // continue above iteration till i & j reaches the end of array

    continue this process till gap is 1, and stop it after that iteration.


    gap = ceil(6+6/2) = 6
    i = 0, j = 6

    arr -> 1, 7, 9, 15, 18, 22, 6, 8, 10, 13, 17, 21 
           i                    j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 9, 15, 18, 22, 6, 8, 10, 13, 17, 21 
              i                    j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 9, 15, 18, 22, 6, 8, 10, 13, 17, 21 
                 i                    j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 9, 15, 18, 22, 6, 8, 10, 13, 17, 21 
                     i                    j
           if(a[i]> a[j]) -> yes swap(15, 13) i++, j++

           1, 7, 9, 13, 18, 22, 6, 8, 10, 15, 17, 21 
                         i                    j
           if(a[i]> a[j]) -> yes swap(18, 17) i++, j++

           1, 7, 9, 13, 17, 22, 6, 8, 10, 15, 18, 21 
                             i                    j
           if(a[i]> a[j]) -> yes swap(22, 21) i++, j++

           1, 7, 9, 13, 17, 21, 6, 8, 10, 15, 18, 22
                             i                    j

           iteration 1 is completed
           now gap = ceil(gap/2) -> 3

           i = 0, j = 3
           1, 7, 9, 13, 17, 21, 6, 8, 10, 15, 18, 22
           i             j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 9, 13, 17, 21, 6, 8, 10, 15, 18, 22
              i             j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 9, 13, 17, 21, 6, 8, 10, 15, 18, 22
                 i              j
           if(a[i]> a[j]) -> yes swap(9, 6)  i++, j++

           1, 7, 6, 13, 17, 21, 9, 8, 10, 15, 18, 22
                    i              j
           if(a[i]> a[j]) -> yes swap(13, 8)  i++, j++

           1, 7, 6, 8, 17, 21, 9, 13, 10, 15, 18, 22
                        i              j
           if(a[i]> a[j]) -> yes swap(17, 10)  i++, j++

            1, 7, 6, 8, 10, 21, 9, 13, 17, 15, 18, 22
                            i              j
           if(a[i]> a[j]) -> yes swap(21, 15)  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
                               i              j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
                                   i              j
           if(a[i]> a[j]) -> no  i++, j++


           2nd iteration is completed
           gap = ceil(gap/2) = ceil(1.5) = 2
           i = 0, j = 2

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
           i     j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
              i     j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
                 i     j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
                    i      j
           if(a[i]> a[j]) -> no  i++, j++

           1, 7, 6, 8, 10, 15, 9, 13, 17, 21, 18, 22
                        i      j
           if(a[i]> a[j]) -> yes swap(10, 9)  i++, j++

           1, 7, 6, 8, 9, 15, 10, 13, 17, 21, 18, 22
                           i      j
           if(a[i]> a[j]) -> yes swap(15, 13)  i++, j++

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
                               i      j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
                                   i      j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
                                       i      j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
                                           i      j
           if(a[i]> a[j]) -> no i++, j++


           3rd iteration is completed
           gap = ceil(gap/2) = 1
           //   as gap is 1 hence this is the last iteration
           i = 0, j = 1

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
           i  j
           if(a[i]> a[j]) -> no i++, j++

           1, 7, 6, 8, 9, 13, 10, 15, 17, 21, 18, 22
              i  j
           if(a[i]> a[j]) -> yes swap(7, 6) i++, j++

           1, 6, 7, 8, 9, 13, 10, 15, 17, 21, 18, 22
                           i  j
           if(a[i]> a[j]) -> yes swap(7, 6) i++, j++
           // skipping the process till i reaches 13

           if(a[i]> a[j]) -> yes swap(13, 10) i++, j++
           
           1, 6, 7, 8, 9, 10, 13, 15, 17, 21, 18, 22
                                           i  j
            swap(21, 18) i++, j++

           1, 6, 7, 8, 9, 10, 13, 15, 17, 18, 21, 22
                                               i  j

           Hence the Array is Sorted via Inplace merge sort
           the time complexity remains same, but the space complexity decrease as compared to prev normal merge sort.

        // Code
        void mergeInplace(vector<int>& nums, int start, int mid, int end){
        int length = end - start + 1;
        int gap = length/2 + length%2; //this is ceil function (actually ceil isn't working in this case)

        while(gap > 0){
            int i = start;
            int j = start + gap;

            while(j <= end){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
            
            gap = gap <= 1 ? 0 : gap/2 + gap%2;
            
        }

    }


*/