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