#include <iostream>

using namespace std;

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