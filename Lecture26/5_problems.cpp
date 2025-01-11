/*

PATTERN - MERGE INTERVALS

*/

/*
    375. Guess Number Higher or Lower II
    (https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

    SO, the idea is, get the maximum cost of getting wrong answer.. out of which return the minimum one which is 
    the min of all max Costs.

    int computeCost(int start, int end){
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = start; i<end; i++){
            int lcost = i + computeCost(start, i - 1);
            int rcost = i + computeCost(i + 1, end);

            int maxCost = max(lcost, rcost);
            ans = min(ans, maxCost);
        }

        return ans;
    }

    int computeCostDP(int start, int end, vector<vector<int>> &dpArr){
        if(start >= end){
            return 0;
        }

        if(dpArr[start][end] != -1){
            return dpArr[start][end];
        }

        int ans = INT_MAX;
        for(int i = start; i<end; i++){
            int lcost = i + computeCostDP(start, i - 1, dpArr);
            int rcost = i + computeCostDP(i + 1, end, dpArr);

            int maxCost = max(lcost, rcost);
            ans = min(ans, maxCost);
        }

        dpArr[start][end] = ans;

        return dpArr[start][end];
    }

    int getMoneyAmount(int n) {
        
        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        // return computeCost(1, n);
        return computeCostDP(1, n, dpArr);
    }

*/