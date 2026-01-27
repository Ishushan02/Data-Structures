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


/*
    bool incExcSum(vector<int>& matchsticks, vector<int>& newSides, int idx){
        if(idx >= matchsticks.size()){
            return newSides[0] == 0 && newSides[1] == 0 && newSides[2] == 0 && newSides[3] == 0;
        }

        bool ans = false;
        for(int k = 0; k < 4; k++){
            if(newSides[k] >= matchsticks[idx]){
                newSides[k] -= matchsticks[idx];
                ans = ans || incExcSum(matchsticks, newSides, idx + 1);
                if(ans) return true;
                newSides[k] += matchsticks[idx];
            }
        }
        return ans;
    }

    bool makesquare(vector<int>& matchsticks) {
        
        unordered_map<int, int> storeSum;
        int totSum = 0;
        for(auto v: matchsticks){
            totSum += v;
        }

        if(totSum % 4 != 0) return false;
        int eachLen = totSum / 4;
        vector<int> newSides(4, eachLen);
        int sum = 0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return incExcSum(matchsticks, newSides, 0);
    }
*/