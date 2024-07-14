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