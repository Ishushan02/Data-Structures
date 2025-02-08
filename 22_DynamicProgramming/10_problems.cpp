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


    // method 3
    int solveIncExc(vector<int>& stones, int sum, int i){
        if(i >= stones.size()){

            // there are 2 possibilities here
            // for include case return sum
            // for excluded case return totalSum - sum
            int incSum = sum;
            int excSum = totalSum - sum;

            return abs(incSum - excSum);


    }

    int lastStoneWeightII(vector<int>& stones) {
        
        // vector<vector<int>> &dpArr()

        // return solveWeights(stones, 0, 0);

        // DP 
        totalSum = accumulate(stones.begin(), stones.end(), 0);
        // vector<vector<int>> dpArr(stones.size()+1, vector<int>((2 * totalSum + 1), -1));
        // return solveWeightsDP(stones, 0, 0, dpArr);

        return solveIncExc(stones, 0, 0); // can uptimize it using DP
    
    }


*/


/*

    Great Question and almost easy ... first 3D DP Question --

    97. Interleaving String
    (https://leetcode.com/problems/interleaving-string/description/)

    // The catch is if there are at a situation when both s1 and s2 character are same as s3 character
    // then explore both the options in this
    // 2nd catch is if k is greater than it's length which means that some of the s1 or s2 characters are unused
    // 3rd catch is at the time when all the pointers are as same as it's length then only they have truly matched



    Time Complexity - > O(2 ^ N) for all positions there are 2 possibilities
    bool compareCharacters(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i == s1.length() && j == s2.length() && k == s3.length()){
            return true;
        }

        if(k >= s3.length()){
            return false;
        }

        bool ans = false;
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            ans = ans || compareCharacters(s1, s2, s3, i+1, j, k+1) || compareCharacters(s1, s2, s3, i, j+1, k+1);;
        }else if(s1[i] == s3[k]){
            ans = ans || compareCharacters(s1, s2, s3, i+1, j, k+1);
        }else if(s2[j] == s3[k]){
            ans = ans || compareCharacters(s1, s2, s3, i, j+1, k+1);
        }

        return ans;
    }

    Time Complexity - > O(m * n * N)
    bool compareCharactersDP(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dpArr){
        if(i == s1.length() && j == s2.length() && k == s3.length()){
            return true;
        }

        if(k >= s3.length()){
            // any of the other string isn't consumed completely
            return false;
        }

        cout << i << " " << j << " " << k << endl;
        if(dpArr[i][j][k] != -1){
            return dpArr[i][j][k];
        }

        bool ans = false;
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            ans = ans || compareCharactersDP(s1, s2, s3, i+1, j, k+1, dpArr) || compareCharactersDP(s1, s2, s3, i, j+1, k+1, dpArr);;
        }else if(s1[i] == s3[k]){
            ans = ans || compareCharactersDP(s1, s2, s3, i+1, j, k+1, dpArr);
        }else if(s2[j] == s3[k]){
            ans = ans || compareCharactersDP(s1, s2, s3, i, j+1, k+1, dpArr);
        }

        dpArr[i][j][k] = ans;
        return dpArr[i][j][k];
    }

    // Time Complexity - > O(m * n )
    // Method 3 remove k, the logic is i + j will always be k.. simple thought
    bool compareCharactersDP1(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dpArr){
        if(i == s1.length() && j == s2.length() && i+j == s3.length()){
            return true;
        }

        if(i+j >= s3.length()){
            // any of the other string isn't consumed completely
            return false;
        }

        // cout << i << " " << j << " " << k << endl;
        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }

        bool ans = false;
        if(s1[i] == s3[i+j] && s2[j] == s3[i+j]){
            ans = ans || compareCharactersDP1(s1, s2, s3, i+1, j, dpArr) || compareCharactersDP1(s1, s2, s3, i, j+1, dpArr);;
        }else if(s1[i] == s3[i+j]){
            ans = ans || compareCharactersDP1(s1, s2, s3, i+1, j, dpArr);
        }else if(s2[j] == s3[i+j]){
            ans = ans || compareCharactersDP1(s1, s2, s3, i, j+1, dpArr);
        }

        dpArr[i][j]= ans;
        return dpArr[i][j];
    }


    bool isInterleave(string s1, string s2, string s3) {
        // vector<vector<vector<int>>> dpArr(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1)));

        // return compareCharacters(s1, s2, s3, 0, 0, 0);
        // return compareCharactersDP(s1, s2, s3, 0, 0, 0, dpArr);

        vector<vector<int>> dpArr(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return compareCharactersDP1(s1, s2, s3, 0, 0, dpArr);
    }


*/


/*

    // So, the idea is that first we store all ones and zeros early so that later on we don't get into complications.
    // Ones they are stored, the max zeros can be m and maz ones can be n hence
    // use include and exclude operation  wherein include and exclude only if m - zeros >= 0 and n - ones >= 0

    // and get the max one..

    // better draw the tree structure, it will be helpful.

    474. Ones and Zeroes
    (https://leetcode.com/problems/ones-and-zeroes/description/)


    int getMaxSize(vector<pair<int, int>> &values, int m, int n, int idx){
        if(idx >= values.size()){
            return 0;
        }


        int zeros = values[idx].first;
        int ones = values[idx].second;

        int includeans = 0;
        int excludeans = 0;
        if(m - zeros >= 0 && n - ones >= 0){
            includeans = 1 + getMaxSize(values, m - zeros, n - ones, idx + 1);
        }
        

        excludeans = getMaxSize(values, m, n, idx + 1);

        return max(includeans, excludeans);


    }
    

    int getMaxSizeDP(vector<pair<int, int>> &values, int m, int n, int idx, vector<vector<vector<int>>> &dpArr){
        if(idx >= values.size()){
            return 0;
        }

        if(dpArr[m][n][idx] != -1){
            return dpArr[m][n][idx];
        }
        
        int zeros = values[idx].first;
        int ones = values[idx].second;

        int includeans = 0;
        int excludeans = 0;
        if(m - zeros >= 0 && n - ones >= 0){
            includeans = 1 + getMaxSizeDP(values, m - zeros, n - ones, idx + 1, dpArr);
        }
        

        excludeans = getMaxSizeDP(values, m, n, idx + 1, dpArr);

        dpArr[m][n][idx] = max(includeans, excludeans);

        return dpArr[m][n][idx];


    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int, int>> values;

        for(auto eachStr: strs){
            int zeros = 0;
            int ones = 0;
            for(auto each_char: eachStr){
                if(each_char == '0'){
                    zeros += 1;
                }else{
                    ones += 1;
                }
            }
            values.push_back({zeros, ones});
        }

        // return getMaxSize(values, m, n, 0);

        vector<vector<vector<int>>> dpArr(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size()+1, -1)));
        return getMaxSizeDP(values, m, n, 0, dpArr);

    }
*/