/*

    Test 1
    
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev = 0;
        int curr = 1;
        int i = 2;
        while(i <= n){
            int val = curr + prev;
            prev = curr;
            curr = val;
            i += 1;
        }

        return curr;
    }
*/


/*
    70. Climbing Stairs
    (https://leetcode.com/problems/climbing-stairs/description/)

    Tabular DP
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        vector<int>Fn(n+1, 0);
        Fn[0] = 1;
        Fn[1] = 1;

        for(int i = 2; i <= n; i++){
            Fn[i] = Fn[i-2] + Fn[i-1];
        }
        
        return Fn[n];
    }

    Space Optimization
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        int prev = 1;
        int curr = 1;

        for(int i = 2; i <= n; i++){
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        
        return curr;
    }

*/

/*
    Frog Jump(GFG)
    (https://www.geeksforgeeks.org/problems/geek-jump/1)

    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> minCosts(height.size(), INT_MAX);
        
        minCosts[0] = 0;
        minCosts[1] = abs(height[0] - height[1]);
        for(int i = 0; i < height.size(); i++){
            if(i+1 < n){
                int energy = minCosts[i] +  abs(height[i] - height[i+1]);
                minCosts[i+1] = min(minCosts[i+1], energy);
            }
            if(i+2 < n){
                int energy = abs(height[i] - height[i+2]);
                minCosts[i+2] = minCosts[i] + min(minCosts[i+2], energy);
            }
        }
        
        return minCosts[n-1];
    }
        
*/