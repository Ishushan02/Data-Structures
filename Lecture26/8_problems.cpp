/*
    // It is also given in previous file the one above see that as well

    279. Perfect Squares
    (https://leetcode.com/problems/perfect-squares/)

    int allPossibility(int n, int tempSum, vector<int> &dpArr){

        if(tempSum <= 0){
            return 0;
        }

        if(dpArr[tempSum] != -1){
            return dpArr[tempSum];
        }

        int minCount = INT_MAX;
        for(int i = 1; i <= n; i++){
            int includeans = 0;
            if(tempSum >= i * i){
                includeans = allPossibility(n, tempSum - i * i, dpArr);

                if(includeans != -1){
                    minCount = min(minCount, includeans + 1);
                    dpArr[tempSum] = minCount;
                }
            }

        }


        

        return dpArr[tempSum];
    }

    int numSquares(int n) {

        vector<int> dpArr(n + 1, -1);
        
        return allPossibility(n, n, dpArr);
    }   

*/