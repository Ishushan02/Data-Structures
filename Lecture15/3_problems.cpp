#include <iostream>

/*
205. Isomorphic Strings (https://leetcode.com/problems/isomorphic-strings/description/)

bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sstring;
        unordered_map<char, char> tstring;

        char repl = 'a';
        for(int i = 0; i<s.length();i++){
            if(sstring.count(s[i]) == 0){
                sstring[s[i]] = repl;
                repl++;
            }
        }
        string temp1;
        for(int i = 0; i<s.length();i++){
            temp1 += sstring[s[i]];
        }

        repl = 'a';
        for(int i = 0; i<t.length();i++){
            if(tstring.count(t[i]) == 0){
                tstring[t[i]] = repl;
                repl++;
            }
        }

        string temp2;
        for(int i = 0; i<t.length();i++){
            temp2 += tstring[t[i]];
        }

        if (temp1==temp2){
            return true;
        }else{
            return false;
        }

    }

*/

/*
49. Group Anagrams (https://leetcode.com/problems/group-anagrams/description/)

    1st Method
    map<char, int> getDict(string s) {
        map<char, int> maps;

        for(int i = 0; i < s.length();i++){
            maps[s[i]] += 1;
        }

        return maps;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<map<char, int>> values;
        for(int i = 0; i<strs.size();i++){

            string var = strs[i];
            map<char, int> dict1;
            dict1 = getDict(var);
            values.push_back(dict1);

        }

        int i = 0;
        while(i < values.size()){
            int j = i + 1;
            map<char, int> tempdict;
            vector<string> tempans;
            while(j < values.size()){
                if (values[i] == values[j]){
                    if (strs[j] != "ABCD"){
                    tempans.push_back(strs[j]);
                    strs[j] = "ABCD";
                    }
                    // values.erase(values.begin()+j);
                }
                j++;
            }
            if (strs[i] != "ABCD"){
            tempans.push_back(strs[i]);
            strs[i] = "ABCD";
             }
            if (tempans.size()>0){
            ans.push_back(tempans);
            }
            i++;
        }

        return ans;

    }



    2nd Method
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> tempdict;
        for(auto str:strs){
            string temp = str;
            sort(temp.begin(), temp.end());

            tempdict[temp].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it = tempdict.begin(); it != tempdict.end();it++){
            ans.push_back(it->second);
        }

        return ans;
    }

*/