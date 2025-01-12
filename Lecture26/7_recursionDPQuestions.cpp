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

    // Do it using Bottom Up Approach
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