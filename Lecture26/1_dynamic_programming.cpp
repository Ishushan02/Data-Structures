/*

    DYNAMIC PROGRAMMING IS A PROBLEM SOLVING TECHNIQUE 

    - How do we know that I can use DP in a given Problem
        Cond1 -> Overlapping Subproblem
        Cond2 -> Optimal Substructure
    
        If these both exist then we can say that we can use DP in the given problem

    Overlapping SUbproblem means : We are solving for same(entity) thing multiple number of times
    Optimal Substructure : Using 2 optimal solution of sub structure we are able to get optimal solution of big Structure


    So, what DP does is what we have solved for 1 value, we won't solve it again, because we store the value


    Now there are 3 standard ways to solve DP
        - Top Down Approach  (Use Recurssion + Memoisation{this means just storing sub answers somwhere})
        - Bottom Up Approach (We use Loop + some Data Structure)

        {and then we see if we can do space optimization or not}
    

    Approach 1. (Recursion + Memoisation)

    Top Down Approach (VVVVVVVImportant, just remeber this, and use it everywhere in DP Problems)
        - find out problem is 1D/2D/3D --> accordingly create DP Array 
        - store answers in it
        - if ans already exists in DP Array -> return the ans don't do further procedures

    Let's solve  Fibonacci Series by all these methods

    Method 1 (Recursion method - without DP)
    int usingRec(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        return usingRec(n-1) + usingRec(n-2);
    }

    int fib(int n) {
        return usingRec(n);
    }


    Method 2 (with DP, - Approach 1 Top Down with Memoisation)
    - How do we find the order of DP problem such that we create that order DP Array(1D, 2D, 3D)
     : What we have to do is, check how many variables are being modified at each recursion call, that is the number of order
        your DP array should be.

    int usingRec(int n, vector<int> &dpArray){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        if(dpArray[n] != -1){
            return dpArray[n];
        }

        dpArray[n] = usingRec(n-1, dpArray) + usingRec(n-2, dpArray);

        return dpArray[n];
    }

    int fib(int n) {

        vector<int> dpArray(n+1, -1);
        return usingRec(n, dpArray);
    }



*/

