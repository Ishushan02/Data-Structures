/*
    1046. Last Stone Weight
    (https://leetcode.com/problems/last-stone-weight/)



    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()> 1){
            sort(stones.rbegin(), stones.rend());
            
            int wt1 = stones[0];
            int wt2 = stones[1];

            stones.erase(stones.begin() + 0);
            stones.erase(stones.begin() + 0);

            if(wt2 > wt1){
                stones.push_back(wt2 - wt1);
            }else if(wt1 > wt2){
                stones.push_back(wt1 - wt2);
            }

        }

        if(stones.size() == 0){
            return 0;
        }

        return stones[0];
    }

*/


/*
    1049. Last Stone Weight II
    (https://leetcode.com/problems/last-stone-weight-ii/)

    // The difference between top and this question is that in top we 
    // have to pick only the 2 heaviest element whereas in this we can pick any element
    // hence remember this chart

        Ex: [2,7,4,1,8,1]

                    2
        subtr 2              add 2

           7                    7
    subtr 7   add 7     subtr 7   add 7
    .......
    ...

    We cannot take if the sum is negative, hence we are returning INT_MAX at eddge case 
    ans if sum>= 0 return that..

    and at the end get the minimum of overall and return that as answer

    while making dpArrary the column might varry from it's +ve sum to its -ve sum
    hence we are summing it over and 2* sum + 1 ; 1 because we have to include 0

    now while accessing the sum can be negative, so adding the totalSum to index to keep it positive and index 
    doesn't go into negative.

    -----------------------------------------------------------------------

    int solveWeights(vector<int>& stones, int sum, int i){
        if(i >= stones.size()){

            if(sum < 0){
                return INT_MAX;
            }

            return sum;
        }

        int posSum = solveWeights(stones, sum + stones[i], i + 1);
        int negSum = solveWeights(stones, sum - stones[i], i + 1);

        return min(posSum, negSum);

    }
    
    int totalSum = 0;
    int solveWeightsDP(vector<int>& stones, int sum, int i, vector<vector<int>> &dpArr){
        if(i >= stones.size()){
            if(sum < 0){
                return INT_MAX;
            }
            return sum;
        }

        if(dpArr[i][sum + totalSum] != -1){
            return dpArr[i][sum + totalSum];
        }

        int posSum = solveWeightsDP(stones, sum + stones[i], i + 1, dpArr);
        int negSum = solveWeightsDP(stones, sum - stones[i], i + 1, dpArr);

        dpArr[i][sum + totalSum] = min(posSum, negSum);
        return dpArr[i][sum + totalSum];

    }

    int lastStoneWeightII(vector<int>& stones) {
        
        // vector<vector<int>> &dpArr()

        // return solveWeights(stones, 0, 0);
        totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dpArr(stones.size()+1, vector<int>((2 * totalSum + 1), -1));
        return solveWeightsDP(stones, 0, 0, dpArr);

    }


*/