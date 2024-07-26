#include <iostream>

using namespace std;

/*

1781. Sum of Beauty of All Substrings
(https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/)

// The main idea of this solution is not to store all substring in a list and then
// evaluate each substring... rather than do the count of char while getting the substring
// that will be much more efficient.


int beautySum(string s) {
        vector<string> substring;
        int ans = 0;
        for(int i = 0; i<s.length();i++){ // Time Complexity O(n)
            map<char, int> val;
            for(int j = i;j<s.length();j++){ // Time Complexity O(n)
                char ch = s[j];
                val[ch]++;

                int max_ = INT_MIN;
                int min_ = INT_MAX;

                for(auto each:val){ // Time Complexity O(26)
                    max_ = max(max_, each.second);
                    min_ = min(min_, each.second);

                }

                ans += (max_ - min_);

            }
        }
        return ans;
    }

Time Complexity is O(n * n * 26) -> O(n^2)
*/

/*

VVI Question
(https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)


    int ncr(int n){ //(nC2 - n(n-1)/2)
        int ans = 1;
        ans = n * (n-1) / 2;
        return ans;
    }

    int sherlockAndAnagrams(string s) {
        map<string, int> data;
        int sbs = 0;
        for(int i = 0; i < s.length();i++){
            for(int j = i; j < s.length();j++){
                sbs+=1;
                string subst = s.substr(i, j-i+1);
                sort(subst.begin(), subst.end());
                data[subst]++;
            }
        }

        // cout << " Substr " << sbs << endl;
        int ans = 0;

        for(auto each:data){
            if(each.second >= 2){
                ans += ncr(each.second);
            }
        }

        return ans;

    }

*/

/*
VVVVI Question

151. Reverse Words in a String
(https://leetcode.com/problems/reverse-words-in-a-string/description/)

string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int start = 0;
        int end = 0;
        int i = 0;

        while (i < s.length()){

            // remove all leading spaces
            while(s[i] == ' '){
                i++;
            }


            if (i >= s.length()){
                break; // such that end is at correct position hence we can trim end part
            }

            // copy all the words to starting position
            while(s[i] != ' ' && i < s.length()){
                s[end] = s[i];
                end++;
                i++;
            }

            //reverse the first word
            reverse(s.begin()+start, s.begin()+end);

            // add 1 space in between
            s[end] = ' ';
            end++;

            cout << s.substr(start, end-start+1) <<endl;
            start = end;

        }


        s= s.substr(0, end-1); // use resize it doesn't take extra space)
        cout << s << endl;
        return s;
    }

*/