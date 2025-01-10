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



    Approach 2. (Bottom Up, ->  Iterative Approach)
        - find out problem is 1D/2D/3D --> accordingly create DP Array 
        - Analyse Base Cases
        - check parameter, Reverse it and Copy Paste Logic(from Recursion procedure)

        Generally  in Bottom Up APproach what we do is we create base cases and based on this base cases 
        we try to find the rest of the solutions


            int iterativeDP(int n){
                vector<int> dpArr(n+1, -1); // step 1, find dpArray dimension
                dpArr[0] = 0; // step 2 store base case
                dpArr[1] = 1; // step 2 store base case

                // revering and copy pasting
                // as 0, and 1 are already given so starting with 2
                for(int i = 2; i <= n; i++){
                    dpArr[i] = dpArr[i-1] + dpArr[i-2];
                }

                return dpArr[n];
            }

            int fib(int n) {
                if(n == 0){
                    return 0;
                }
                if(n ==1){
                    return 1;
                }
                return iterativeDP(n);
            }


    Approach 3. Optmize if possible (If possible, not necessary we can optimize it further based on Problems)

            int iterativeDP(int n){
                
                if(n == 0){
                    return 0;
                }
                if(n == 1){
                    return 1;
                }
                
                int prev = 0;
                int curr = 1;
                for(int i = 2; i <= n; i++){
                    int temp = prev + curr;
                    prev = curr;
                    curr = temp;
                }

                return curr;
            }

            int fib(int n) {
                return iterativeDP(n);
            }

*/

