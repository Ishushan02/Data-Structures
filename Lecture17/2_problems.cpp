#include <iostream>
#include <vector>

/*

ALL Questions of Recursion are really Important they are DP questions so just
solving them for practise

Solve all the 2_problems.cpp and 3_problems.cpp using DP after DP Class.

*/

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

Important QUestion (DP)

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
(https://leetcode.com/problems/coin-change/)

    void allPossibilities(vector<int>& coins, int tempAmount, int steps, int &ans){
    

        if(tempAmount == 0){
            ans = min(ans, steps);
            return ;
        }

        for(int i = 0; i < coins.size(); i++){

            if(tempAmount >= coins[i]){
                allPossibilities(coins, tempAmount - coins[i], steps+1, ans);

            }

        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        allPossibilities(coins, amount, 0, ans);

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


Method 1. (Better Formatting )

    void traverseHouses(vector<int>& nums, int tempSum, int startIndex, int endIndex, int &maxSum){
        if(startIndex > endIndex){
            maxSum = max(maxSum, tempSum);
            return;
        }

        traverseHouses(nums, tempSum + nums[startIndex], startIndex + 2, endIndex, maxSum);
        traverseHouses(nums, tempSum, startIndex + 1, endIndex, maxSum);


    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        int maxSum = 0;
        traverseHouses(nums, 0, 0, n-2, maxSum);
        traverseHouses(nums, 0, 1, n-1, maxSum);

        return maxSum;
    }

Method 2 (previous one)
    
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
        return 1;

    return (n - 1) * (allDearrangements(n - 2) + allDearrangements(n - 1));
}

*/

/*
------------------------------------------------------------------------------------------------------------
Dry Run 
    - The concept is based on (last 2 colors to be same and last 2 colors to be different)

for n ==1 (R)-->  R

for n == 2, k = 3 (R, G, B)

    Same Patterns -> RR, GG, BB                      - total K * (n -1) ways
    Diff Patterns -> RG, RB, BR, BG, GR, GB          - total k * (k -1) ways

    Tota Patterns -> 3 + 6 = 9

for n == 3, k = 3 (R, G, B)
    
    Same Patterns - > Take all diff patterns of top and add same to it
                        RGG, RBB, BRR, BGG, GRR, GBB                    - total prev only diff ways

    Diff Patterns -> Take total patterns of prev and add diff col in it
                        RRG, RRB, GGR, GGB, BBR, BBG, RGR, RGB, RBG, RBR, BRG, BRB, BGR, BGB, GRB, GRG, GBG, GBR
                                                                        - total prev all comb * (K - 1) 

    Tota Patterns -> 6 + 9 * 2 = 24   -> K * 1 + prev * (k - 1)
                    -> k + k * (k - 1)


for n == 4 k = 3 (R, G, B)

    Same Pattern
        (from above)      RRG, RRB, GGR, GGB, BBR, BBG, RGR, RGB, RBG, RBR, BRG, BRB, BGR, BGB, GRB, GRG, GBG, GBR
    add same color ot it  RRGG, RRBB, GGRR, .............. GBRR        
                        - total prev only diff ways (18)

    Diff Pattern 
            total prev all comb *  k - 1 -> 24 * 2 = 48

    Total Patterns -> 24 * 2 + 18




Hence for n = 1 -> total k ways
      for n = 2 -> total k - 1 ways

      for n  = 3
                same = total(n-2) ways * (k-1) ways
                diff = total(n-1) ways * (k -1) ways
            total :=  k-1 * totalof(n-2) + k - 1 * totalof(n-1)





Painting the Fence (Practise Well it won't be done by intutive)
(https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

See the video Again, it's imp

    int ways(int n, int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return k + ((k)*(k-1));
        }

        return (k-1) * ways(n-2, k) + (k-1) * ways(n-1, k);
    }

    long long countWays(int n, int k){
        // code here

        long long ans = (long long) ways(n, k);

        return ans % 1000000007;
    }

*/

/*

72. Edit Distance
(https://leetcode.com/problems/edit-distance/)

int minOperation(string &word1, string &word2, int i, int j){
        if(i >= word1.length()){
            return word2.length()-j;
        }
        if(j >= word2.length()){
            return word1.length()-i;
        }

        int ans = 0;

        if(word1[i]==word2[j]){
            // no operation
            ans = 0 + minOperation(word1, word2, i+1, j+1);
        }else{
            // perform operation

            // insert
            int insop = 1 + minOperation(word1, word2, i, j+1);
            // delete
            int delop = 1 + minOperation(word1, word2, i+1, j);
            // replace
            int replop = 1 + minOperation(word1, word2, i+1, j+1);

            ans = min(insop, min(delop, replop));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {

        int ans = minOperation(word1, word2, 0, 0);

        return ans;
    }

*/

/*

221. Maximal Square
(https://leetcode.com/problems/maximal-square/description/)

int square(int i, int j, vector<vector<char>>& matrix, int& maxi){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
            // row || col out of index
        }

        int rightmove = square(i, j+1, matrix, maxi);
        int diagonalmove = square(i+1, j+1, matrix, maxi);
        int downmove = square(i+1, j, matrix, maxi);

        if(matrix[i][j]=='1'){
            cout << " i " << i << " j " << j << endl;
            int ans = 1 + min(rightmove, min(downmove, diagonalmove));
            maxi = max(maxi, ans);
            return ans;
        }else{
            // standing on 0
            return 0;
        }

    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int maxSqr = 0;
        int temp =  square(0, 0, matrix,  maxSqr);
        return maxSqr*maxSqr; // returning area
    }
*/