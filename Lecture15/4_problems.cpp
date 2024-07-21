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


Method 2 (VVI Method)

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

/*

VVI Question

767. Reorganize String (https://leetcode.com/problems/reorganize-string/description/)

// It can be done by priority Queue very easily we will see it later

string reorganizeString(string s) {

        // storing in letters 0 -> 26
        int hash[26] = {0};

        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a']++;
        }
        // string ans;


        char maxfreqchar;
        int maxfreq = -1;

        for(int i = 0; i < 26; i++){
            if(hash[i] > maxfreq){
                maxfreq = hash[i];
                maxfreqchar = i + 'a';
            }
        }

        int index = 0; // placing all characters in even places
        while(index < s.length() && maxfreq > 0){
            s[index] = maxfreqchar;
            index += 2;
            maxfreq--;

        }

        // no places left now so it's not possible to put same characters in diff place
        if(maxfreq > 0 ){
            return "";
        }

        hash[maxfreqchar-'a'] = 0;

        for(int i = 0; i < 26; i++){
            cout << i + 'a' << " - " << hash[i] << endl;
            while(hash[i] > 0){
                if (index >= s.length()){
                    index = 1;
                }
                s[index] = i + 'a';
                hash[i]--;
                index+=2;
            }
        }

        //checking end char value
        for(int i = 0; i < 26; i++){
            if (hash[i] > 0){
                return "";
            }
        }

        return s;
    }

*/

/*

8. String to Integer (atoi)
(https://leetcode.com/problems/string-to-integer-atoi/description/)

int myAtoi(string s) {
        string ans;
        int i = 0;
        while(i < s.length()){
            if (s[i] == ' '){
                i++;
            }else{
                break;
            }

        }

        ans = s.substr(i);
        cout << " Ans " << ans << " i is " << i << endl;

        // determining sign
        int sign = 1;
        if(ans[0] == '-'){
            sign = -1;
            ans = ans.substr(1);
        }else if(ans[0] == '+'){
            sign = 1;
            ans = ans.substr(1);
        }

        // removing leading 0
        if(ans[0] == '0'){
            ans = ans.substr(1);
        }



        string tempans;
        int finalans = 0;
        for(int i = 0; i< ans.length();i++){
            if (ans[i] >= '0' && ans[i]<= '9'){
                cout << finalans << " ";
                int val = ans[i] - '0';
                if(finalans > INT_MAX/10 || (finalans == INT_MAX/10 && ans[i]>'7')) { // 2nd condition if for "2147483646" just 1 less than INT_MAX
                    return sign==-1 ? INT_MIN:INT_MAX;
                }

                finalans = finalans * 10 + (ans[i] - '0');
            }else{
                break;
            }
        }



        return finalans * sign;

    }

*/

/*

VVI Question
539. Minimum Time Difference
(https://leetcode.com/problems/minimum-time-difference/)

int convertMinutes(string time){
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));

        return hh * 60 + mm ;
    }

    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;

        for(int i = 0; i < timePoints.size();i++){

            int min = convertMinutes(timePoints[i]);
            minutes.push_back(min);
        }


        sort(minutes.begin(), minutes.end());

        for(int i = 0; i < timePoints.size();i++){
            cout << minutes[i] << " " ;
        }

        int ans = INT_MAX;
        for (int i = 0;i < minutes.size();i++){
            if(i+1 < minutes.size()){
                ans = min(ans, minutes[i+1]-minutes[i]);
            }
        }

        //considering the last case also
        // Making night 00:00 --> 1440

        ans = min(ans, (1440 + minutes[0])- minutes[minutes.size()-1]);

       return ans;
    }


*/