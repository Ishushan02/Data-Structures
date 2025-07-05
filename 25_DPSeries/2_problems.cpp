
/*

    SUBSET/SUBSEQUENCES DP PROBLEMS ONLY ----

*/

/*
     Subset Sum Equal To K
    (https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM)

    bool subsetSum(vector<int> &arr, int i, int k, vector<vector<int>> &dpArrary){
        if(k == 0){
            dpArrary[i][k] = 1;
            return dpArrary[i][k];
        }

        if(i >= arr.size()){
            return false;
        }

        if(dpArrary[i][k] != -1){
            return dpArrary[i][k];
        }

        bool ans = false;
        if(k - arr[i] >= 0){
            ans = ans || subsetSum(arr, i+1, k - arr[i], dpArrary);
        }
        
        ans = ans || subsetSum(arr, i+1, k, dpArrary);
        dpArrary[i][k] = ans;
        return dpArrary[i][k];

    }

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.    
        vector<vector<int>> dpArrary(n+1, vector<int>(k+1, -1));
        return subsetSum(arr, 0, k, dpArrary);

    }
*/