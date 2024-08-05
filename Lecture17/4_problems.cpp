#include <iostream>

using namespace std;

/*

Last Occurence of a Char

We Can also  do this using strrchr() function of string
*/

int lastoccurence(string &word, int index, int ans, char c)
{

    if (index == (int)word.length())
    {
        return ans;
    }

    if (c == word[index])
    {
        ans = index;
    }

    lastoccurence(word, index + 1, ans, c);
}

void reverseString(string &word, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
    {
        return;
    }

    swap(word[startIndex], word[endIndex]);

    reverseString(word, startIndex + 1, endIndex - 1);
}

int main()
{

    string word = "abcddedgp";
    // char c = 'd';
    // int ans = lastoccurence(word, 0, -1, c);
    // cout << " Last Occurence of the char " << c << " is " << ans << endl;

    reverseString(word, 0, word.length() - 1);
    cout << " Reverse of a String abcddedgp" << " is " << word << endl;
}

/*

415. Add Strings
(https://leetcode.com/problems/add-strings/description/)

Solve it using Recursion

string addStr(string& num1, int idx1, string& num2, int idx2, int carry, string sumval){

        int n1 = 0;
        int n2 = 0;

        // cout << " Val " << sumval << " Carry " << carry << endl;
        if(idx1 < 0 && idx2 >= 0){
            n1 = 0;
            n2 = num2[idx2] - '0';
        }else if(idx1 >= 0 && idx2 < 0){
            n2 = 0;
            n1 = num1[idx1] - '0';
        }else if (idx1 >= 0 && idx2 >= 0){
            n1 = num1[idx1] - '0';
            n2 = num2[idx2] - '0';
        }

        if(idx1 < 0 && idx2 < 0){
            if(carry != 0){
                sumval += to_string(carry);
            }
            return sumval;
        }

        int val = carry + n1 + n2;

        carry = val/10;
        int v = val%10;
        sumval += to_string(v);

        string ans = addStr(num1, idx1 - 1, num2, idx2 - 1, carry, sumval);
        return ans;
    }

    string addStrings(string num1, string num2) {

        int idx1 = num1.length()-1;
        int idx2 = num2.length()-1;
        int carry = 0;
        string sumval;
        string ans = addStr(num1, idx1, num2, idx2, carry, sumval);
        reverse(ans.begin(), ans.end());
        return ans;
    }

*/