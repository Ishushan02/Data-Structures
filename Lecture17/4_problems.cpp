#include <iostream>
#include <vector>

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

bool palindromeCheck(string word, int idx1, int idx2)
{
    if (idx1 < 0 && idx2 >= word.length())
    {
        return true;
    }

    if (word[idx1] != word[idx2])
    {
        return false;
    }

    bool ans = palindromeCheck(word, idx1 - 1, idx2 + 1);
    return ans;
}

void subarray(vector<int> &array, int i, int j)
{
    if ((i == (int)array.size()-1) && (j == (int)array.size()))
    {
        return;
    }

    if ( j == (int)array.size())
    {
        i += 1;
        j = i;
    }

    // printing subarray
    for (int var = i; var <= j; var++)
    {
        cout << array[var] << " ";
    }
    cout << endl;

    subarray(array, i, j+1);
}

int main()
{

    // string word = "abcddedgp";
    // char c = 'd';
    // int ans = lastoccurence(word, 0, -1, c);
    // cout << " Last Occurence of the char " << c << " is " << ans << endl;

    // string word = "abcddedgp";
    // reverseString(word, 0, word.length() - 1);
    // cout << " Reverse of a String abcddedgp" << " is " << word << endl;

    // string word = "MALAYALAM"; //"ROAAOR";
    // int n = word.length();
    // // check length
    // int idx1 = 0;
    // int idx2 = 0;
    // if (n % 2 == 0)
    // {
    //     idx1 = n / 2 - 1;
    //     idx2 = n / 2;
    // }
    // else
    // {
    //     idx1 = n / 2;
    //     idx2 = n / 2;
    // }
    // bool palicheck = palindromeCheck(word, idx1, idx2);
    // cout << " Word " << word << " is Palindrome " << palicheck << endl;

    vector<int> array = {1, 2, 3, 4, 5};
    int i = 0;
    int j = 0;
    subarray(array, i, j);
}

/*

415. Add Strings
(https://leetcode.com/problems/add-strings/description/)

Solve it using Recursion

    void addStr(string& num1, int idx1, string& num2, int idx2, int carry, string& sumval){

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
                sumval += (carry + '0');
            }
            return ;
        }

        int val = carry + n1 + n2;

        carry = val/10;
        int v = val%10;
        sumval += (v +'0');

        addStr(num1, idx1 - 1, num2, idx2 - 1, carry, sumval);

    }

    string addStrings(string num1, string num2) {

        int idx1 = num1.length()-1;
        int idx2 = num2.length()-1;
        int carry = 0;
        string sumval;
        addStr(num1, idx1, num2, idx2, carry, sumval);
        reverse(sumval.begin(), sumval.end());
        return sumval;
    }

*/

/*

121. Best Time to Buy and Sell Stock
(https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)


METHOD 1 (TLE)

    int solve(vector<int>& prices, int minindex, int maxindex, int& maxdiff, int n){
        
            
        if(maxindex == n && minindex == n-1){
            return maxdiff;
        }

        // cout << prices[minindex] << " - " << prices[maxindex] << " - " << maxdiff << endl;

        int diff = prices[maxindex] - prices[minindex];
        if(diff > maxdiff){
            maxdiff = diff;
        }

        if(maxindex == n-1 ){
            minindex = minindex + 1;
            maxindex = minindex;
        }

        int ans = solve(prices, minindex, maxindex+1, maxdiff, n);        
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==1){
            return 0;
        }
        int minindex = 0;
        int maxindex = 1;
        int maxdiff = -1;

        int ans = solve(prices, minindex, maxindex, maxdiff, n);
        // ans = if(ans > 0) ? ans:0;
        return ans < 0 ? 0:ans;

    }


METHOD 2 (ACCEPTED)

    void solve(vector<int>& prices, int i, int minPrice, int& maxProfit, int n){
        if (i == n){
            return ;
        }
        if (prices[i] < minPrice){
            minPrice = prices[i];
        }
        if (prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }

        solve(prices,i+1, minPrice, maxProfit, n);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1){
            return 0;
        }
        int i = 0;
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        solve(prices, i, minPrice, maxProfit, n);

        return maxProfit < 0 ? 0:maxProfit;
    }

*/


/*
    115. Distinct Subsequences (Memory Limit Exceeded)
    (https://leetcode.com/problems/distinct-subsequences/description/)

    void getSubseq(string &s, string &temp, string &t, int &ans, int index){
        if(index >= s.length()){
            if(temp == t){
                ans += 1;
                // cout << temp << " " ;
            }
            return ;
        }

        temp = temp + s[index];
        getSubseq(s, temp, t, ans, index + 1);
        temp.pop_back();
        getSubseq(s, temp, t, ans, index + 1);

    }

    int numDistinct(string s, string t) {
        string temp = "";
        int ans = 0;
        getSubseq(s, temp, t, ans, 0);

        return ans;
    }

*/

/*  
    494. Target Sum
    (https://leetcode.com/problems/target-sum/description/)

    void getSum(vector<int>& nums, int target, int tempSum,int index, int &count){
        if(index >= nums.size()){
            if(target == tempSum){
                count += 1;
            }
            return ;
        }


        getSum(nums, target, tempSum + nums[index], index + 1, count);
        getSum(nums, target, tempSum - nums[index], index + 1, count);


    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        getSum(nums, target, 0, 0, count);

        return count;
    }
    
*/


/*
    567. Permutation in String
    (https://leetcode.com/problems/permutation-in-string/description/)

    bool getPerm(string s1, int index, string s2){
        if(index >= s1.length()){
            cout << s1 << endl;
            if (s2.find(s1) != std::string::npos) {
                return true; 
            }
            return false;
        }

        for(int i = index; i < s1.length(); i++){
            swap(s1[i], s1[index]);
            bool tempAns = getPerm(s1, index + 1, s2);
            if(tempAns){
                return true;
            }
            swap(s1[i], s1[index]);

        }

        return false;
    }

    bool checkInclusion(string s1, string s2) {
        return getPerm(s1, 0, s2);
    }

*/