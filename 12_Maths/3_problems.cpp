/*
    3765. Complete Prime Number
    (https://leetcode.com/problems/complete-prime-number/description/)
    Good Question

    bool checkPrime(int n){
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;

        for(int i = 5; i * i <= n; i += 6){
            if((n% i == 0) || (n % (i + 2) == 0)) return false;
        }

        return true;
    }

    bool completePrime(int num) {
        
        string numVal = to_string(num);

        long long int prefix = 0;
        for(int i = 0; i < numVal.length(); i++){
            prefix = prefix * 10 + (numVal[i] - '0');
            // cout << prefix << endl;
            if(!(checkPrime(prefix))) return false;
        }

        long long int suffix = 0;
        int j = 0;
        for(int i = numVal.length()-1; i>= 0; i--){
            suffix = pow(10, j)*(numVal[i] - '0') + suffix ;
            // cout << suffix << endl;
            if(!(checkPrime(suffix))) return false;
            j += 1;
        }

        return true;

    }

*/