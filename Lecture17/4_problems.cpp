#include <iostream>

using namespace std;

/*

Last Occurence of a Char


*/

int lastoccurence(string &word, int index, int ans, char c)
{

    if (index == word.length())
    {
        return ans;
    }

    if (c == word[index])
    {
        ans = index;
    }

    int val = lastoccurence(word, index + 1, ans, c);

    return val;
}

int main()
{

    string word = "abcddedg";
    char c = 'd';
    int ans = lastoccurence(word, 0, -1, c);

    cout << " Last Occurence of the char " << c << " is " << ans << endl;
}