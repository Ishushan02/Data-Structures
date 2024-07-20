#include <iostream>

using namespace std;

/*

6. Zigzag Conversion (https://leetcode.com/problems/zigzag-conversion/description/)

    string convert(string s, int numRows) {
        if (numRows==1){
            return s;
        }
        string ans;

        vector<vector<string> > vec(numRows, vector<string>(s.size()));
        int col = 0;
        bool colVal = true;
        int wordcount = 0;
        int row = 0; // fill each col
        while (wordcount <= s.length()-1){

            // cout << " Filling each Col " << endl;
            while(row < numRows){
                // cout << " Rows " << row << " Col " << col << " Word COunt " << wordcount << " WOrd is " << s[wordcount]<< endl;
                if (wordcount >= s.length()){
                    break;
                }
                vec[row][col] = s[wordcount];
                row++;
                wordcount++;
            }
            row--;

            if (wordcount >= s.length()){
                    break;
                }

            // cout << " Filling up Diaog " << endl;
            // go up diagonally
            row = row - 1;
            col = col + 1;
            // vec.resize(numRows, vector<int> (col+1, -1));
            while(row >= 0){
                // cout << " Rows " << row << " Col " << col << " Word COunt " << wordcount << " WOrd is " << s[wordcount]<< endl;
                if (wordcount >= s.length()){
                    break;
                }
                // vec.resize(numRows, vector<int> (col+1, -1));

                vec[row][col] = s[wordcount];
                wordcount++;
                if (row == 0){
                    break;
                }
                col += 1;
                row -= 1;

            }
            // cout << "Coming here " << endl;

            // col = col - 1;
            row = row + 1;


        }

        // vec[row][col] = s[s.length()-1];

        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                ans+=vec[i][j];
                // cout << vec[i][j] << " ";
            }
            // cout << endl;
        }
        return ans;
    }
*/

/*

179. Largest Number   https://leetcode.com/problems/largest-number/description/
VVI Question

static bool comprator(string a, string b){
        string t1 = a + b;
        string t2 = b + a;

        return t1>t2; // think of 303 & 330so we must return 330 when {3, 30} are given.
    }

    string largestNumber(vector<int>& nums) {
        vector<string>  sortedstr;

        for(int i = 0; i < nums.size();i++){
            sortedstr.push_back(to_string(nums[i]));
        }
        sort(sortedstr.begin(), sortedstr.end(), comprator);// custom comprator use in sort function

        string ans;
        for(int i = 0; i < nums.size();i++){
            ans += sortedstr[i];
        }

        // edge case of 0
        if (sortedstr[0] == "0") {
            return "0";
        }

        return ans;
    }

*/

/*
2125. Number of Laser Beams in a Bank
(https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

int numberOfBeams(vector<string>& bank) {
        vector<int> totallaser;
        for(int i = 0; i < bank.size();i++){
            string data = bank[i];
            int sum = 0;
            for(int j = 0; j < data.length();j++){
                if (data[j]=='1'){
                    sum+=1;
                }
            }
            cout << sum << endl;
            if (sum != 0){
                totallaser.push_back(sum);
            }
        }

        int ans = 0;
        for(int i = 0; i < totallaser.size();i++){
            int j = i + 1;
            if (j < totallaser.size()){
                if(totallaser[i] == 0 || totallaser[j] == 0){
                    ans = ans + 0;
                }else{
                    ans = ans + totallaser[i] * totallaser[j];
                }

            }
        }
        return ans;
    }

*/

/*

1209. Remove All Adjacent Duplicates in String II
(https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

Method1 - Time Limit Exceeded
class Solution {
public:

    string deletestr(string s, int k){

        map<char, int> data;
        char previous = s[0];
        data[previous] = 1;

        int i = 1;
        while(i < s.length()){
            char current = s[i];

            if (current != previous){
                data.erase(previous);
                data[current] += 1;
                previous = current;
            }else{
                data[current] += 1;
            }


            if (data[current] == k){
                s.erase(i-k+1, k);
                if(s.length() < k ){
                    return s;
                    }
                data.erase(current);
                previous = s[0];
                data[previous] = 1;
                i = 1;
                current = s[i];
                continue;

            }
            i++;
        }
        return s;

    }

    string removeDuplicates(string s, int k) {
        string val = deletestr(s, k);
        // val = deletestr(s, k);
        // cout << val << endl;

        return val;
    }
};


Method 2 (VVI Question)

// 2 Pointer Approach, we ar just inplacing everything.
string removeDuplicates(string s, int k) {
        vector<int> countchar(s.length());

        int i = 0;
        int j = 0;

        while(j < s.length()){
            s[i] = s[j]; // placing jth value at i
            countchar[i] = 1;

            if (i > 0 && s[i-1]==s[i]){
                countchar[i] += countchar[i-1];
            }

            if (countchar[i] == k){
                i = i - k;
            }
            i++;
            j++;

        }

        return s.substr(0, i);
    }

*/