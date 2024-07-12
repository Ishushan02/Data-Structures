#include <iostream>
using namespace std;

/*

Get All Sub String Out of a String

// Procedure

Now from a string the substring can be of different lengths
(the length can be either even or odd)

to find odd length substrings start with 2 pointers at same index
    - increase the pointers throughout the length both sides from each pointer

to find even length substrings start with 2 pointers at adjacent indices
    - increase the pointers throughout the length both sides from each pointer

int getsubstring(string s, int i, int j){


        while(i >= 0 && j < s.length()){
            string temp = s.substr(i, j);
            cout << temp << " ";
            i--;
            j++;
        }
        return 0;

    }

int main(){
    for(int centre = 0; centre < s.length(); centre++){

                // odd substring
                int i = centre;
                int j = centre;
                int p = getsubstring( s, i, j);

                // even substring
                i = centre;
                j = centre + 1;
                if (j < s.length()){
                    p = getsubstring( s, i, j);
                }
            }

 }


*/

/*
Very Important Question

// 647. Palindromic Substrings (https://leetcode.com/problems/palindromic-substrings/description/)

int getsubstring(string s, int i, int j){

        int count = 0;
        while(i >= 0 && j < s.length() && s[i]==s[j]){
            string temp = s.substr(i, j);
            count++;
            // cout << temp << " ";
            i--;
            j++;
        }
        return count;

    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int centre = 0; centre < s.length(); centre++){

            // odd substring
            int i = centre;
            int j = centre;
            ans += getsubstring( s, i, j);

            // even substring
            i = centre;
            j = centre + 1;
            if (j < s.length()){
                ans += getsubstring( s, i, j);
            }
        }



        return ans;
    }

*/

/*
2325. Decode the Message
(https://leetcode.com/problems/decode-the-message/submissions/1316123973/)


class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, string> convert ;
        char alphabet = 'a';

        for (int i = 0; i < key.length();i++){
                                    // we couldhave also used count of key if it is 0
            if ((key[i] != ' ') && (convert.find(key[i]) == convert.end())){
                convert[key[i]] = alphabet;
                alphabet++;
                // cout << key[i] << " ";
            }
        }

        string ans ;
        for(int i = 0; i<message.length();i++){
            if (message[i] != ' '){
            ans = ans + convert[message[i]];
            }else{
                ans = ans + ' ';
            }

        }

    return ans;
    }
};


*/

/*

2391. Minimum Amount of Time to Collect Garbage
(https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int pickuptime = 0;

        for(int i = 0;i<garbage.size();i++){
            string var = garbage[i];
            pickuptime += var.length();
        }

        cout << " Pickup Time " << pickuptime << endl;

        // Metal travel time
        int variabletime = 0;
        int mtraveltime = 0;
        for(int i = 1;i<garbage.size();i++){
            variabletime = variabletime + travel[i-1];
            string var = garbage[i];
            if (var.find("M")!=string::npos){
                mtraveltime =  variabletime;
            }
        }
        cout << " M Time " << mtraveltime << endl;

        variabletime = 0;
        int ptraveltime = 0;
        for(int i = 1;i<garbage.size();i++){
            variabletime = variabletime + travel[i-1];
            string var = garbage[i];
            if (var.find("P")!=string::npos){
                ptraveltime =  variabletime;
            }
        }
        cout << " P Time " << ptraveltime << endl;

        variabletime = 0;
        int gtraveltime = 0;
        for(int i = 1;i<garbage.size();i++){
            variabletime = variabletime + travel[i-1];
            // cout << gtraveltime << " - " << variabletime << " ";
            string var = garbage[i];
            if (var.find("G")!=string::npos){
                // cout << " ** " ;
                gtraveltime =  variabletime;
            }

        }
        cout << " G Time " << gtraveltime << endl;


        return mtraveltime + ptraveltime + gtraveltime + pickuptime;

    }
};


*/

/*

791. Custom Sort String
(https://leetcode.com/problems/custom-sort-string/description/)

Method 1
class Solution {
public:
    string customSortString(string order, string s) {
        string ans ;
        string notpresent;
        for(int i = 0;i<order.size();i++){
            int cnt = count(s.begin(),s.end(),order[i]);
            if(cnt > 0){
                while(cnt){
                ans += order[i];
                cnt--;
                }
            }
        }

        for(int i = 0;i<s.size();i++){
            if(ans.find(s[i]) == string::npos){
                int cnt = count(s.begin(),s.end(),s[i]);
                if(cnt > 0){
                    while(cnt){
                    ans += s[i];
                    cnt--;
                    }
                }


            }
        }



        return ans + notpresent;
    }
};


Method 2

string ordercopy;
class Solution {
public:

    static bool cmp(char a, char b){
        return (ordercopy.find(a) < ordercopy.find(b));
    }

    string customSortString(string order, string s) {
        ordercopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

*/

/*
IMP Question
890. Find and Replace Pattern
(https://leetcode.com/problems/find-and-replace-pattern/description/)

class Solution {
public:

    string normalize(string key){
        unordered_map<char, char> convert ;
        char alphabet = 'a';

        for (int i = 0; i < key.length();i++){
            if (convert.find(key[i]) == convert.end()){
                convert[key[i]] = alphabet;
                alphabet++;
            }
        }

        for(int i = 0; i < key.length();i++){
            key[i] = convert[key[i]];
        }

        return key;


    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans ;

        string match_pattern = normalize(pattern);

        for(int i = 0; i < words.size();i++){
            string temp = normalize(words[i]);
            if(temp == match_pattern){
                ans.push_back(words[i]);
            }
        }

        return ans;


    }
};

*/

/*

242. Valid Anagram (https://leetcode.com/problems/valid-anagram/description/)

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> maps;
        map<char, int> mapt;

        for(int i = 0; i < s.length();i++){
            maps[s[i]] += 1;
        }


        for(int i = 0; i < t.length();i++){
            mapt[t[i]] += 1;
        }

        if (maps==mapt){
            return true;
        }

        return false;
    }
};
*/