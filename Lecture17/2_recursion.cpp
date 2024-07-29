#include <iostream>
#include <vector>

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

/*

void subsequence(string mainstring, string outputstring, int index, vector<string> &op)
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

    for (auto ch : op)
    {
        cout << ch << " ";
    }
}

*/

/*

Important QUestion

Include Exclude Pattern Simple but yet tricky

198. House Robber
(https://leetcode.com/problems/house-robber/description/)

void MaxSum(vector<int> &nums, int currentIndex, int &maxSum, int sum){
        if(currentIndex >= (int)nums.size()){
            // cout << sum  << endl;
            maxSum = max(sum, maxSum);
            return ;
        }

        //include if current home is robbed go to i+2 home
        MaxSum(nums, currentIndex+2, maxSum, sum+nums[currentIndex]);

        //exclude if current home isnt robbed go to i+1 hoome
        MaxSum(nums, currentIndex+1, maxSum, sum);
    }

    int rob(vector<int>& nums) {
        int ans = 0;
        MaxSum(nums, 0, ans, 0);
        return ans;
    }

// In Leetcode it will give TLE, so we will solve this later using DP,
// this sol is just for practise

*/

/*

VVI Question Type 2 of Include Exclude Recursion

This is extremly important type2 of include/exclude Recursion type
322. Coin Change
(https://leetcode.com/problems/coin-change/submissions/1336146341/)

int Coins(vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = 0; i < coins.size();i++){
            int coin = coins[i];

            if (coin <= amount){
                int recursionAns = Coins(coins, amount - coin);

                if (recursionAns != INT_MAX){
                    ans = min(ans, 1+recursionAns);
                }

            }
        }


        return ans;

    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = Coins(coins, amount);

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }

// In Leetcode it will give TLE, so we will solve this later using DP,
// this sol is just for practise


*/

/*

213. House Robber II
(https://leetcode.com/problems/house-robber-ii/description/)

void MaxSum(vector<int> &nums, int currentIndex, int endIndex, int &maxSum, int sum){
        if(currentIndex >= endIndex + 1){
            maxSum = max(sum, maxSum);
            return ;
        }

        //include if current home is robbed go to i+2 home
        if(currentIndex <= endIndex){
            MaxSum(nums, currentIndex+2, endIndex, maxSum, sum+nums[currentIndex]);
        }

        //exclude if current home isnt robbed go to i+1 hoome
        MaxSum(nums, currentIndex+1, endIndex, maxSum, sum);
    }

    int rob(vector<int>& nums) {
        // int maxSum = INT_MIN;
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int sum = 0;
        int currentIndex = 0;
        int ans1 = 0;
        int ans2 = 0;
        // itterating from 0 -> n-2
        MaxSum(nums, 0, n-2, ans1, sum);

        // itterating from 1 -> n-1
        MaxSum(nums, 1, n-1, ans2, sum);
        return max(ans1, ans2);
    }

// In Leetcode it will give TLE, so we will solve this later using DP,
// this sol is just for practise

*/

/*

Geeks for Geeks Topic
(Count Derangements (Permutation such that no element appears in its original position))
(https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/)


- A Derangement is a permutation of n elements, such that no element appears
in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.

let's solve for 1 case, rest the recursion will take care of
let there be n elements
let elements be {1, 2, 3, ........, i, .......n-2, n-1}

let's switch 1 and ithe place elements

for 1 to place in any available places we have n-1 available positions

{i, 2, 3, .......1, .......n-2, n-1} // once i and 1 are swapped we have total (n-2) elements
to switch positions

{_, 2, 3, ...... 1, .....n - 2, n-1} // similarily for i it has (n-1) places
// to switch positions


hence for total number of 1 can be placed in
        (n-1) * [f(n-2) + f(n-1)]






int allDearrangements(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 2;

    return (n - 1) * (allDearrangements(n - 2) + allDearrangements(n - 1));
}

*/