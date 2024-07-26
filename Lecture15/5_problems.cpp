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
        for(int i = 0; i<s.length();i++){
            map<char, int> val;
            for(int j = i;j<s.length();j++){
                char ch = s[j];
                val[ch]++;

                int max_ = INT_MIN;
                int min_ = INT_MAX;

                for(auto each:val){
                    max_ = max(max_, each.second);
                    min_ = min(min_, each.second);

                }

                ans += (max_ - min_);

            }
        }
        return ans;
    }
    
*/