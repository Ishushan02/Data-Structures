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


Time Complexity - O(n)
*/

/*
VVI Question - HARD Level
68. Text Justification - (https://leetcode.com/problems/text-justification/description/)

string justifyspaces(vector<string> words, int start, int end, int evenlyspaces, int remainderspaces, int maxWidth){

        string tempans;
        int totalchar = 0;
        for(int i = start; i < end-1; i++){
            tempans += words[i];
            totalchar += words[i].length();
            for(int j = 0; j < evenlyspaces;j++){
                tempans += " ";
                totalchar+=1;
            }

            if(remainderspaces){
                tempans += " ";
                totalchar+=1;
                remainderspaces--;
            }
        }
        totalchar+=words[end-1].length();
        tempans += words[end-1];

        while(totalchar < maxWidth){
            tempans += " ";
            totalchar++;
        }

        return tempans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        string tempans;
        int start = 0;
        int totalchars = 0;
        int wordcount = 0;
        for(int i = 0; i < words.size();i++){

            if(tempans.length() + words[i].length() <= maxWidth){
                tempans += words[i];
                tempans += ' ';
                totalchars += words[i].length();
                wordcount += 1;
            }else{
                int totalspaces = maxWidth - totalchars;
                int evenlyspaces = totalspaces/max(1, (wordcount-1));
                int remainderspaces = totalspaces % max(1, (wordcount-1));

                string data = justifyspaces(words, start, i, evenlyspaces, remainderspaces, maxWidth);
                ans.push_back(data);
                wordcount = 1;
                totalchars = 0;
                totalchars += words[i].length();
                start = i;
                tempans = "";
                tempans += words[i];
                tempans += ' ';
            }
        }
        if(tempans.length() > maxWidth){
            tempans = tempans.substr(0, maxWidth);
        }

        while(tempans.length() < maxWidth){
            tempans += " ";
        }
        // string data = justifyspaces(words, start, i, evenlyspaces, remainderspaces, maxWidth);
        ans.push_back(tempans);
        // cout << tempans << endl;



        return ans;
    }


*/

/*

// A format to create total Binary numbers that's the main concept of this question, 
// recursively how to create all Binary digits of length n
// Simple trick   start include exclude method but only change is include 0 on left and include 1 on right

1980. Find Unique Binary String
(https://leetcode.com/problems/find-unique-binary-string/)

    string createString(vector<string>& nums, int n, int index, string temp){
        if(index == n ){
            if(find(nums.begin(), nums.end(), temp) == nums.end()){
                return temp;
            }
            return "";
        }

        string ans1 = createString(nums, n, index+1, temp+"1");
        if(ans1 != ""){
            return ans1;
        }

        string ans2 = createString(nums, n, index+1, temp+"0");
        if(ans2 != ""){
            return ans2;
        }

        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        return createString(nums, n, 0, "");
    }

*/

/*

    Important yet Tricky Question

2405. Optimal Partition of String
(https://leetcode.com/problems/optimal-partition-of-string/description/)

    int partitionString(string s) {
        
        vector<bool> isPresent(26, false);

        int count = 0;

        for(auto c:s){
            if(isPresent[c-'a']){
                count++;
                isPresent = vector<bool> (26, false);
            }
            isPresent[c-'a'] = true;
        }

        return count+1; // as last count will be excluded
    }

*/