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
        sort(sortedstr.begin(), sortedstr.end(), comprator);

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