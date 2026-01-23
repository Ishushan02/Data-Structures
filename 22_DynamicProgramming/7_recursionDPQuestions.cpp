/*
        213. House Robber II
        (https://leetcode.com/problems/house-robber-ii/)

        int totalVal(vector<int>& nums, int start, int end, vector<vector<int>> &dpArr){
        
        if(start > end){
            return 0;
        }
        
        if(dpArr[start][end]!= -1){
            return dpArr[start][end];
        }

        int includeans = nums[start] + totalVal(nums, start + 2, end, dpArr);
        int excludeans = 0 + totalVal(nums, start + 1, end, dpArr);

        int ans = max(includeans, excludeans);

        dpArr[start][end] = ans;

        return dpArr[start][end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        return max(totalVal(nums, 0, n-2, dpArr), totalVal(nums, 1, n-1, dpArr));
    }
*/


/*
    Painting the Fence
    (https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

    int totalWays(int n, int k, vector<int> &dpArr){
        if(n == 1){
            return k;
        }
        
        if(n ==2){
            return k + (k * (k-1)) ;
        }
        
        if(dpArr[n]!= -1){
            return dpArr[n];
        }
        
        int sameans = (k -1) * (totalWays(n -2, k, dpArr));
        int diffans = (k -1) * (totalWays(n -1, k, dpArr));
        
        dpArr[n] = sameans + diffans;
        return dpArr[n];
    }
    
    int countWays(int n, int k) {
        // code here
        vector<int> dpArr(n+1, -1);
        return totalWays(n, k, dpArr);
    }

*/

/*
    72. Edit Distance
    (https://leetcode.com/problems/edit-distance/description/)

    int getminOperation(string &word1, string &word2, int i, int j, vector<vector<int>> &dpArr){
        if(i >= word1.length() && j >= word2.length()){
            return 0;
        }else if(i >= word1.length()){
            return word2.length()-j;
        }else if(j >= word2.length()){
            return word1.length()-i;
        }

        if(dpArr[i][j]!= -1){
            return dpArr[i][j];
        }

        int minOp = 0;
        if(word1[i]==word2[j]){
            minOp = 0 + getminOperation(word1, word2, i+1, j+1, dpArr);
        }else{
            int insop = 1 + getminOperation(word1, word2, i, j+1, dpArr);
            int delop = 1 + getminOperation(word1, word2, i+1, j, dpArr);
            int swaop = 1 + getminOperation(word1, word2, i+1, j+1, dpArr);

            minOp = min(insop, min(delop, swaop));
        }
        dpArr[i][j] = minOp;
        return dpArr[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dpArr(m+1, vector<int>(n+1, -1));
        return getminOperation(word1, word2, 0, 0, dpArr);
    }

*/

/*
    221. Maximal Square
    (https://leetcode.com/problems/maximal-square/)

    // Do it using DP Bottom Up Approach - TLE
*/


/*
    416. Partition Equal Subset Sum
    (https://leetcode.com/problems/partition-equal-subset-sum/description/)

    bool ifPossilble(vector<int>& nums, int sum, int index, vector<vector<int>> &dpArr){
        if(sum == 0){
            return true;
        }

        if(index >= nums.size()){
            return false;
        }

        if(dpArr[index][sum] !=  -1){
            return dpArr[index][sum];
        }

        bool ans = false;
        if(sum >= nums[index]){
            ans = ans || ifPossilble(nums, sum-nums[index], index+1, dpArr);
        }

        ans = ans || ifPossilble(nums, sum, index+1, dpArr);

        dpArr[index][sum] = ans;
        return dpArr[index][sum];
    }


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(auto val:nums){
            sum += val;
        }

        if(sum & 1){
            return false;
        }

        sum = sum / 2;
        vector<vector<int>> dpArr(n+1, vector<int>(sum + 1, -1));
        return ifPossilble(nums, sum, 0, dpArr);
    }
*/


/*
    1981. Minimize the Difference Between Target and Chosen Elements
    (https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/)

    // DO it unable to do it via DP Method (Top Down Approach - TLE)

    (Solved )
    void absMinDiff(vector<vector<int>>& mat, int target, int sum, int rowIdx, int &minDiff, vector<vector<int>> &dpArray){
        if(rowIdx >= mat.size()){
            minDiff = min(minDiff, abs(target - sum));
            return ;
        }
        if(dpArray[rowIdx][sum] != -1) return ;

        for(int col = 0; col < mat[0].size(); col++){
            absMinDiff(mat, target, sum + mat[rowIdx][col], rowIdx+1, minDiff, dpArray);
        }
        
        dpArray[rowIdx][sum] = minDiff;
    }


    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        int minDiff = INT_MAX;
        int totSum = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                totSum += mat[i][j];
            }
        }
        vector<vector<int>> dpArray(mat.size() + 2, vector<int>(target + totSum, -1));
        absMinDiff(mat, target, 0, 0, minDiff, dpArray);

        return minDiff;
    }
        
*/


/*
    55. Jump Game
    (https://leetcode.com/problems/jump-game/description/)

    bool reachEnd(vector<int>& nums, int index, vector<int> &dpArr){
        // cout << index << endl;
        if(index == nums.size() -1){
            return true;
        }

        if(index > nums.size()){
            return false;
        }

        if(dpArr[index] != -1){
            return 0;
        }

        bool tempAns = false; 
        int maxStep = nums[index];
        for(int i = 1; i <= maxStep; i++){
            tempAns = tempAns || reachEnd(nums, index+i, dpArr);
            if(tempAns){
                dpArr[index] = true;
                return true;
            }
        }
        dpArr[index] = tempAns;
        return dpArr[index];
    }

    bool canJump(vector<int>& nums) {
        vector<int> dpArr(nums.size()+1, -1);
        return reachEnd(nums, 0, dpArr);
    }
    
*/


/*  
    45. Jump Game II
    (https://leetcode.com/problems/jump-game-ii/)

    // DO it unable to do it via DP Method (Top Down Approach - TLE)

*/

/*
    120. Triangle
    (https://leetcode.com/problems/triangle/description/)

    int getMinPath(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dpArr){
        if(row >= triangle.size()){
            return INT_MAX;;
        }

        if(dpArr[row][col]!= -1){
            return dpArr[row][col];
        }

        int currelem = triangle[row][col];
        int minSum = currelem;
        int minelem = min(getMinPath(triangle, row + 1, col, dpArr), getMinPath(triangle, row + 1, col+1, dpArr));
        if(minelem != INT_MAX){
            minSum = minSum + minelem;
        }

        dpArr[row][col] = minSum;
        return dpArr[row][col];
       
    }

    int minimumTotal(vector<vector<int>>& triangle) {


        int n = triangle.size();

        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        return getMinPath(triangle, 0, 0, dpArr);
    }


*/

/*
    (It is easy question, but this idea would be hard to think, just watch the procedure carefully)

    121. Best Time to Buy and Sell Stock 
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n ==1){
            return 0;
        }
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;

    }

*/


/*

    Very VERY IMPORTANT Please focus on Procedure, little different then rest of them

    115. Distinct Subsequences
    (https://leetcode.com/problems/distinct-subsequences/description/)

    int getSubseqCount(string& s, string& t, int i, int j){
        
        if(j >= t.length()){
            return 1;
        }
        if(i >= s.length()){
            return 0;
        }

        int maxCount = 0;
        if(s[i] == t[j]){
            int includeans = getSubseqCount(s, t, i+1, j+1);
            int excludeans = getSubseqCount(s, t, i+1, j);
            maxCount = max(maxCount, includeans + excludeans);
        }else{
            int tempCount = getSubseqCount(s, t, i+1, j);
            maxCount = max(maxCount, tempCount);
        }

        return maxCount;
    }

    int getSubseqCountDP(string& s, string& t, int i, int j, vector<vector<int>> &dpArr){
        
        if(j >= t.length()){
            return 1;
        }
        if(i >= s.length()){
            return 0;
        }

        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }

        int maxCount = 0;
        if(s[i] == t[j]){
            int includeans = getSubseqCountDP(s, t, i+1, j+1, dpArr);
            int excludeans = getSubseqCountDP(s, t, i+1, j, dpArr);
            maxCount = max(maxCount, includeans + excludeans);
        }else{
            int tempCount = getSubseqCountDP(s, t, i+1, j, dpArr);
            maxCount = max(maxCount, tempCount);
        }

        dpArr[i][j] = maxCount;
        return dpArr[i][j];
    }

    int numDistinct(string &s, string &t) {
        string tempString ;
        vector<vector<int>> dpArr(s.length()+1, vector<int>(t.length()+ 1, -1));
        // return getSubseqCount(s, t, 0, 0);
        return getSubseqCountDP(s, t, 0, 0, dpArr);
    }

*/

/*
    516. Longest Palindromic Subsequence
    (https://leetcode.com/problems/longest-palindromic-subsequence/description/)

    Do it using other DP Method

*/


/*
    VVVIIIII Question

    983. Minimum Cost For Tickets
    (https://leetcode.com/problems/minimum-cost-for-tickets/description/)

    int minDollars(vector<int>& days, vector<int>& costs, int idx, vector<int> &dpArr){

        cout << idx << endl;
        if(idx >= days.size()){
            return 0;
        }

        if(dpArr[idx] != -1){
            return dpArr[idx];
        }

        // 1 day pass
        int ans1 = costs[0] + minDollars(days, costs, idx + 1, dpArr);

        // 7 day pass
        int i = idx;
        for(i = idx; i < days.size() && days[i] < days[idx] + 7; i++);
        int ans2 = costs[1] + minDollars(days, costs, i, dpArr);

        i = idx;
        for(i = idx; i < days.size() && days[i] < days[idx] + 30; i++);
        int ans3 = costs[2] + minDollars(days, costs, i, dpArr);

        dpArr[idx] =  min(ans1, min(ans2, ans3));
        return dpArr[idx];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dpArr(days.size() + 1, -1);
        return minDollars(days, costs, 0, dpArr);
    }


 */

/*
    279. Perfect Squares
    (https://leetcode.com/problems/perfect-squares/description/)


    int totalMinNumbers(int n, int tempSum){
        if(tempSum == n){
            return 0;
        }

        int totPossib = INT_MAX;
        for(int i = 1; i < n; i++){
            int count  = 0;
            int currSum = tempSum + pow(i, 2);
            if(currSum <= n){
                int temp = totalMinNumbers(n, currSum);
                if(temp != INT_MAX){
                    count = 1 + temp;
                    totPossib = min(count, totPossib);
                }
            }

    
        }

        return totPossib;
    }

    int totalMinNumbersDP(int n, int tempSum, vector<int> &dpArr){
        if(tempSum == n){
            return 0;
        }

        if(dpArr[tempSum] != -1){
            return dpArr[tempSum];
        }

        int totPossib = INT_MAX;
        for(int i = 1; i < n; i++){
            int count  = 0;
            int currSum = tempSum + pow(i, 2);
            if(currSum <= n){
                int temp = totalMinNumbersDP(n, currSum, dpArr);
                if(temp != INT_MAX){
                    count = 1 + temp;
                    totPossib = min(count, totPossib);
                }
            }

    
        }
        dpArr[tempSum] = totPossib;

        return dpArr[tempSum];
    }

    int numSquares(int n) {
        if(n == 1){
            return 1;
        }
        int tempSum = 0;

        vector<int> dpArr(n+1, -1);
        // return totalMinNumbers(n, tempSum);
        return totalMinNumbersDP(n, tempSum, dpArr);

    }

    
*/