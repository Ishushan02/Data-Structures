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
    
*/