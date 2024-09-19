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