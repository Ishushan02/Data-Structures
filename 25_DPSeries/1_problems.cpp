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