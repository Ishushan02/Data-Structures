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