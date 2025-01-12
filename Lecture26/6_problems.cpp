/*
    44. Wildcard Matching
    (https://leetcode.com/problems/wildcard-matching/description/)

    bool stringMatch(string &s, string &p, int i, int j){

        if(i == s.length() && j == p.length()){
            return true;
        }

        if(j >= p.length()){
            return false;
        }

        if(i == s.length()){
            while(j < p.length()){
                if(p[j] != '*'){
                    return false;
                }
                j++;
            }
            return true;
        }
        
        bool ans = true;
        if(s[i] == p[j] || p[j] == '?'){
            ans  = true && stringMatch(s, p, i+1, j+1);
        }else if(p[j] == '*'){
            // once make * as empty string
            // and then make it as same as current string
            bool matchans = stringMatch(s, p, i+1, j) || stringMatch(s, p, i, j+1);
            ans = ans && matchans;
        }else{
            // cout << " Here-- " << endl;
            return false;
        }

        return ans;

    }

    bool stringMatchDP(string &s, string &p, int i, int j, vector<vector<int>> &dpArr){

        if(i == s.length() && j == p.length()){
            return true;
        }

        if(j >= p.length()){
            return false;
        }

        if(i == s.length()){
            while(j < p.length()){
                if(p[j] != '*'){
                    return false;
                }
                j++;
            }
            return true;
        }

        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }
        
        bool ans = true;
        if(s[i] == p[j] || p[j] == '?'){
            ans  = true && stringMatchDP(s, p, i+1, j+1, dpArr);
        }else if(p[j] == '*'){
            // once make * as empty string
            // and then make it as same as current string
            bool matchans = stringMatchDP(s, p, i+1, j, dpArr) || stringMatchDP(s, p, i, j+1, dpArr);
            ans = ans && matchans;
        }else{
            // cout << " Here-- " << endl;
            return false;
        }

        dpArr[i][j] = ans; // true than it will store 1 and false then it will store 0

        return dpArr[i][j];

    }

    bool isMatch(string s, string p) {
        // return stringMatch(s, p, 0, 0);
        int m = s.length();
        int n = p.length();
        // -1 nothing, +1 true, 0, false;
        vector<vector<int>> dpArr(m+1, vector<int>(n+1, -1));
        return stringMatchDP(s, p, 0, 0, dpArr);
    }
*/