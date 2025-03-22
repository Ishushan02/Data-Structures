/*
    678. Valid Parenthesis String
    (https://leetcode.com/problems/valid-parenthesis-string/description/)

    (map<pair<int, int>, bool> dpArr;
    bool validate(string &s, int open, int i){
        if(i >= s.length()){
            if(open == 0){
                return true;
            }
            return false;
        }

        if(dpArr.find({i, open}) != dpArr.end()){
            return dpArr[{i, open}];
        }

        bool ans = false;
        if(s[i] == '('){
            ans = ans || validate(s, open + 1, i+1);
        }else{
            if(s[i] == '*'){
                ans = ans || validate(s, open, i + 1) || validate(s, open + 1, i + 1);
                if(open > 0) {
                    ans = ans || validate(s, open - 1, i + 1); 
                }
            }else{
                if(open > 0){
                    ans = ans || validate(s, open-1, i+1);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        dpArr[{i, open}] = ans;

        return dpArr[{i, open}];
    }

    bool checkValidString(string s) {
        stack<char> st;
        int open = 0;
        return validate(s, open, 0);
    })

*/