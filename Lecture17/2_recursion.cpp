#include <iostream>

using namespace std;

bool checkSorted(int arr[], int n, int index)
{
    if (index == n)
    {
        return true;
    }

    if ((index + 1 < n) && (arr[index] > arr[index + 1]))
    {
        return false;
    }

    return checkSorted(arr, n, index + 1);
}

/*
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 9, 6, 7};
    // cout << " arr is sorted or not " << checkSorted(arr, 8, 0) << endl;
}
*/

/*

    VVI Importamt Pattern for Recursion
    Include/Exclude Pattern

    With this approach the pattern takes in consideration of 1 condition,
    it checks it's advantage and disadvantage of that condition and followups
    with further proceedings.

    Subsequence -> Any string is said a subsequence of other string, if
        - you can include/exclude any characters of it
        - it can be continuous or non continuous
        - but the order should be maintained

        Ex - string -> abc
        All subsequences of above string
        a, b, c, ab, ac, bc, abc, " "

    Total Number of subsequence of a string of length n is 2^n (V V I)
    Substring is continous and it's different from subsequence

    Let's try to get subsequence of "abc" using recursion

                                "abc"| "" {input string and output initially}
                                 /         \
                                /           \
                        include "a"        exclude "a"
                               /               \
                        "abc", "a"            "abc", ""
                         /   \
                include "b" exclude "b"
                        /     \
              "abc", "ab"  "abc", "a"
                ...................
                .........

                "abc", "ab", "ac", "a", "bc", "b", "c", ""


*/
#include <vector>
void subsequence(string mainstring, string outputstring, int index, vector<string>& op)
{
    if (index == (int)mainstring.length())
    {
        op.push_back(outputstring);
        cout << outputstring << " ";
        return;
    }

    char currentchar = mainstring[index];

    // include part
    subsequence(mainstring, outputstring + currentchar, index + 1, op);

    // exclude part
    subsequence(mainstring, outputstring, index + 1, op);
}

int main()
{

    // example of include exclude pattern
    vector<string> op;
    subsequence("abc", "", 0, op);

    for(auto ch:op){
        cout << ch << " ";
    }
}