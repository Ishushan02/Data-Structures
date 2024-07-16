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

/*

5. Longest Palindromic Substring
(https://leetcode.com/problems/longest-palindromic-substring/description/)


    string getsubstring(int i, int j, string s){

        string temp ;
        while(i >= 0 && j < s.length() && s[i]==s[j]){
            string subs = s.substr(i, j-i+1);
            if (temp.size() < subs.size()){
                temp = subs;
            }
            i--;
            j++;
        }
        return temp;

    }

    string longestPalindrome(string s) {




        string ans ;


        for(int centre = 0; centre < s.length();centre++){
            string tempans;


            // odd substring
            tempans = getsubstring(centre, centre, s);
            if (tempans.size() > ans.size()){
                ans = tempans;
            }
            // even substring
            if (centre+1 < s.length()){
                tempans = getsubstring(centre, centre + 1, s);
                if (tempans.size() > ans.size()){
                ans = tempans;
            }
            }
        }

        return ans;
    }

*/

/*

28. Find the Index of the First Occurrence in a String
(https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

Method 1
int strStr(string haystack, string needle) {
        // int ans = -1;
        int index = haystack.find(needle);
        if (index != -1 ){
            return index;
        }

        return -1;
    }


Method 2
int strStr(string haystack, string needle) {

        if (needle.length() > haystack.length()){
            return -1;
        }
        int ans = -1;

        int i = 0;
        int j = 0;

        while(i < haystack.length()){

            if(haystack[i] == needle[j]){
                ans = i;
                int temp = i+1;
                int count = 1;
                while(count < needle.length()){
                    if (haystack[temp]!=needle[count]){
                        temp = -1;
                        break;
                    }else{
                        count++;
                        temp++;
                    }
                }
                if (temp == ans + count){
                    return ans;
                }
            }
            i++;
        }

        return -1;
    }

*/

/*

Tricky Question
443. String Compression (https://leetcode.com/problems/string-compression/)

class Solution {
public:

    string convertDigit(int n){
        string ans;
        while(n > 0){
            int digit = n % 10;
            string t = to_string(digit);
            char const *n_char = t.c_str();
            ans.push_back(*n_char);
            n = n/10;
        }

        int i = 0;
        int j = ans.length()-1;
        while(i < j){
            swap(ans[i], ans[j]);
            i++;
            j--;

        }
        cout << " Num is " << ans << endl;
        return ans;
    }


    int compress(vector<char>& chars) {

        vector<char> ans ;
        unordered_map<char, int> table;

        for(int i = 0; i < chars.size();i++){

            if(table.empty()){
                table[chars[i]] += 1;
            }else if(table.count(chars[i])>0){
                table[chars[i]] += 1;

            }else {

                auto firstElement = table.begin();
                ans.push_back(firstElement->first);
                string value = convertDigit(firstElement->second);
                string t = to_string(1);
                char const *t_char = t.c_str();
                char const *p_char = value.c_str();
                if (value.length()==1 && *t_char == *p_char){
                    cout<<endl;
                }else{
                for(auto var:value){
                    ans.push_back(var);
                }
                }

                table.clear();
                table[chars[i]] += 1;

            }

            if (i == chars.size()-1){

                auto firstElement = table.begin();
                ans.push_back(firstElement->first);
                string value = convertDigit(firstElement->second);
                string t = to_string(1);
                char const *t_char = t.c_str();
                char const *p_char = value.c_str();
                if (value.length()==1 && *t_char == *p_char){
                    cout<<endl;
                }else{
                for(auto var:value){
                    ans.push_back(var);
                }
                }

                table.clear();
            }
        }

       for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
       }

        chars.clear();


       for(int i = 0; i < ans.size();i++){
                chars.push_back(ans[i]);

       }
        return chars.size();
    }
};


*/