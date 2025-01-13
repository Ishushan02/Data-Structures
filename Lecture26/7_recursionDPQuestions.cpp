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