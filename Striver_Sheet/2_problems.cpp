/*
    Problem 26
    50. Pow(x, n)
    (https://leetcode.com/problems/powx-n/)

    double pow(double x, long long int n){
        double ans = 1;
        while(n){

            if(n & 1){
                ans = ans * x;
            }

            x = x * x;
            n = n >> 1;
        }

        return ans;
    }

    double myPow(double x, long long int n) {

        if(n < 0){
            double ans = pow(x, abs(n));
            return 1/ans;
        }

        return pow(x, n);
    }
*/