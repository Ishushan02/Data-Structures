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