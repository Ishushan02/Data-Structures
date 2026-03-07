/*

Knapsacks Problems
    There are 2 types, 0/1 knapsack and fractional(Greedy) problem,
    We will solve 0/1

    0 - 1 Knapsack Problem
    (https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)

    int getMaxCapacity(int capacity, vector<int> &val, vector<int> &wt, int index){
        if(index >= val.size()){
            return 0;
        }
        
        
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + getMaxCapacity(capacity - wt[index], val, wt, index+1);
        }
            
        int exclude = 0 + getMaxCapacity(capacity, val, wt, index+1);
        
        int ans = max(include, exclude);
        return ans;
        
        
    }
    
    int getMaxCapacityDP(int capacity, vector<int> &val, vector<int> &wt, int index, vector<vector<int>> &dpArr){
        if(index >= val.size()){
            return 0;
        }
        
        if(dpArr[index][capacity] != -1){
            return dpArr[index][capacity];
        }
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + getMaxCapacityDP(capacity - wt[index], val, wt, index+1, dpArr);
        }
            
        int exclude = 0 + getMaxCapacityDP(capacity, val, wt, index+1, dpArr);
        

        dpArr[index][capacity] = max(include, exclude);
        return dpArr[index][capacity];
    }
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dpArr(n+1, vector<int>(capacity+1, -1));
        // return getMaxCapacity(capacity, val, wt, 0);
        return getMaxCapacityDP(capacity, val, wt, 0, dpArr);
        // return maxSum;
           
    }


    // Tabulation Method

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dpArray(W + 2, vector<int>(val.size() + 2, 0));
        // return maxValSack(val, wt, W, 0, dpArray);
        int n = val.size();
        for(int w = 0; w <= W; w++){
            for(int i = n - 1; i >= 0; i--){
                auto inc = 0;
                if(wt[i] <= w){
                    inc = val[i] + dpArray[w-wt[i]][i+1];//maxValSack(val, wt, W - wt[i], i + 1, dpArray);
                }
                
                auto exc = dpArray[w][i+1];//maxValSack(val, wt, W, i+1, dpArray);
                dpArray[w][i] = max(inc, exc);
            }
        }
        
        return dpArray[W][0];
    }

*/


/*
    Painting the Fence (or LeetCode 276, - Premium)
    (https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

    int procedure(int n, long long int k, vector< int> &dpArr){

    
    if(n == 1){
        return k;
    }

    if(n == 2){
        return k + k * (k -1);
    }

    if(dpArr[n] != -1){
        return dpArr[n];
    }


    int same = ((k - 1) * procedure(n-2, k, dpArr)) %1000000007;
   int diff = ((k - 1) * procedure(n -1, k, dpArr)) %1000000007;

    dpArr[n] = (same + diff)%1000000007 ;
    return dpArr[n];

    
    }

    int numberOfWays(int n, int k) {
        // Write your code here.
        vector< int> dpArr(n + 1, -1);
        return procedure(n, k, dpArr);
    }

*/


/*
    416. Partition Equal Subset Sum
    (https://leetcode.com/problems/partition-equal-subset-sum/description/)

    bool checkSum(vector<int>& nums, int tempVal, int index, vector<vector<int>> &dpArr){
        if(index >= nums.size() || tempVal < 0){
            return false;
        }

        if(tempVal == 0){
            return true;
        }

        if(dpArr[index][tempVal] != -1){
            return dpArr[index][tempVal];
        }

        bool includeans =  checkSum(nums, tempVal - nums[index], index + 1, dpArr);
        bool excludeans =  checkSum(nums, tempVal, index + 1, dpArr) ;

        dpArr[index][tempVal] = includeans || excludeans;

        return dpArr[index][tempVal];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(auto val:nums){
            sum += val;
        }

        if(sum&1){
            return false;
        }

        int target = sum / 2;
        vector<vector<int>> dpArr(n+1, vector<int>(target+ 1, -1));

        return checkSum(nums, target, 0, dpArr);
    }


    // Efficient Approach
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for(auto v: nums){
            totSum += v;
        }

        int n = nums.size();
        if(totSum & 1) return false;
        int halfSum = totSum/2;

        vector<int> rowAns(halfSum + 1, 0);
        vector<int> currAns(halfSum + 1, 0);

        rowAns[0] = 1;
        currAns[0] = 1;
        for(int idx = n - 1; idx >= 0; idx--){
            for(int j = 1; j <= halfSum; j++){
                bool inc = false;
                if(j >= nums[idx]){
                    inc = rowAns[j - nums[idx]];
                }
                bool exc = rowAns[j];
                
                currAns[j] = inc || exc;
            }
            rowAns = currAns;
        }

        return rowAns[halfSum];
    }
*/

/*
    1155. Number of Dice Rolls With Target Sum
    (https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

    int totalways(int n, int k, int target, vector<vector<long long int>> &dpArr){
        if(n == 0 && target == 0){
            return 1;
        }
        if(target < 0 || n < 0){
            return 0;
        }

        if(dpArr[n][target] != -1){
            return dpArr[n][target];
        }
        
        long long int ways = 0;
        for(int i = 1; i <= k; i++){
            ways += totalways(n -1, k, target-i, dpArr);
            ways = ways % 1000000007;
        }

        dpArr[n][target] = ways % 1000000007;
        return dpArr[n][target];
    }


    int numRollsToTarget(int n, int k, int target) {

        vector<vector<long long int>> dpArr(n+1, vector<long long int>(target+1, -1));
        return totalways(n, k, target, dpArr);
    }


    // Tabulation Method
    int numRollsToTarget(int n, int k, int target) {

        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        vector<int> curr(target + 1, 0);

        for(int nVal = 1; nVal <= n; nVal++){
            for(int tar = 1; tar <= target; tar++){
                long long int totalPossibilities = 0;
                for(int i = 1; i <= k; i++){
                    if(tar >= i && prev[tar - i] > 0){
                        totalPossibilities += prev[tar - i];
                        totalPossibilities = totalPossibilities % 1000000007;
                    }
                }
                curr[tar] = totalPossibilities % 1000000007;
            }
            prev = curr;
        }
        
        return curr[target] % 1000000007;
    }
    

*/