/*

    Partition DP's VVIII and it's Tough

*/

/*
    Matrix Chain Multiplication
    (https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

    int minMatMulCost(vector<int> &arr, int i, int j, vector<vector<int>> &dpArray){
        if(i == j){
            return 0;
        }
        
        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }
        
        int minSteps = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + minMatMulCost(arr, i, k, dpArray) + minMatMulCost(arr, k+1, j, dpArray);
            minSteps = min(minSteps, steps);
        }
        
        dpArray[i][j] = minSteps;
        
        return dpArray[i][j];
        
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, -1));
        return minMatMulCost(arr, 1, n-1, dpArray);
    }

    // Tabulation Method

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, 0));
        
        for(int i = 0; i < n + 1; i++){
            dpArray[i][i] = 0;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int minSteps = 1e9;
                for(int k = i; k < j; k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dpArray[i][k] + dpArray[k+1][j];
                    minSteps = min(minSteps, steps);
                }
                dpArray[i][j] = minSteps;
            }
        }
        
        return dpArray[1][n-1];
    }

    METHOD 2
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, 0));
        
        for(int len = 2; len < n; len++){
            for(int i = 1; i < n - len + 1; i++){
                int j = i + len - 1;
                int minCounts = INT_MAX;
                for(int k = i; k < j; k++){
                    int cnt = arr[i-1] * arr[k] * arr[j] + 
                    dpArray[i][k] + 
                    dpArray[k+1][j];
                    minCounts = min(minCounts, cnt);
                }
                dpArray[i][j] = minCounts;
            }
        }
        
        return dpArray[1][n-1];
        
    }
*/

/*
    1547. Minimum Cost to Cut a Stick
    (https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        // int n = cuts.size();

        int m = cuts.size();
        vector<vector<int>> dpArray(m+1, vector<int>(m + 1, 0));

        for(int len = 2; len < m; len++){
            for(int i = 0; i + len < m; i++){
                int j = i + len;
                int minCuts = 1e9;
                for(int k = i + 1; k < j; k++){
                    int cutCost = (cuts[j] - cuts[i]) + dpArray[i][k] + dpArray[k][j];
                    minCuts = min(minCuts, cutCost);
                }
            dpArray[i][j] = minCuts;   
            }
        }

        return dpArray[0][m-1];

    }
*/

/*
    312. Burst Balloons
    (https://leetcode.com/problems/burst-balloons/description/)

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // return getMaxBurst(nums, 1, nums.size()-2);
        int n = nums.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n + 1, 0));

        for(int start = n-1; start >= 1; start--){
            for(int end = 1; end <= n - 2; end++){
                if(start > end){
                    continue;
                }
                int maxBurst = 0;
                for(int k = start; k <= end; k++){
                    int burst = nums[start - 1] * nums[k] * nums[end + 1] + getMaxBurst(nums, start, k-1) + getMaxBurst(nums, k+1, end);
                    dpArray[start][end] = max(dpArray[start][end], burst);
                }
            }
        }

        return dpArray[1][n-2];

    }


    2nd Metod
    (There are 2 Methods, check recursion and Bottom Up )

    int getMaxCoins(vector<int> &nums, int i, int j){
        if(i > j){
            return 0;
        }

        int maxCoins = 0;
        for(int k = i; k <= j; k++){
            cout << i-1 << " , " << k << " , " << j << endl;
            int coins = nums[i-1] * nums[k] * nums[j+1] +
                    getMaxCoins(nums, i, k - 1) +
                    getMaxCoins(nums, k+1, j);
            maxCoins = max(coins, maxCoins); 
        }

        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        // return getMaxCoins(nums, 1, n-2);
        vector<vector<int>> dpArray(n + 1, vector<int>(n+1, 0));

        for(int len = 1; len < n; len++){
            for(int i = 1; i + len < n; i++){
                int j = i + len - 1;
                int maxCoins = 0;
                for(int k = i; k <= j; k++){
                    int coins = nums[i-1] * nums[k] * nums[j+1] +
                            dpArray[i][k-1]+
                            dpArray[k+1][j];
                    maxCoins = max(coins, maxCoins); 
                }
                dpArray[i][j] = maxCoins;
            }
        }

        return dpArray[1][n-2];

    }
        
*/

/*

    Boolean Parenthesization
    (https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)

    int totalTrueWays(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dpArray){
        if(i > j){
            return 0;
        }
        if(i == j){
            if(isTrue){
                return s[i] =='T';
            }else{
                return s[i] == 'F';
            }
        }
        
        if(dpArray[i][j][isTrue] != -1){
            return dpArray[i][j][isTrue];
        }
        
        int allWays = 0;
        for(int k = i+1; k <= j; k += 2){
            int leftTrue = totalTrueWays(s, i, k-1, true, dpArray);
            int leftFalse = totalTrueWays(s, i, k-1, false, dpArray);
            int rightTrue = totalTrueWays(s, k+1, j, true, dpArray);
            int rightFalse = totalTrueWays(s, k+1, j, false, dpArray);
            
            if(s[k] == '&'){
                if(isTrue){
                    allWays += ((  leftTrue * rightTrue ) ) ;
                }else{
                    allWays += (((  leftTrue * rightFalse)  + (  leftFalse * rightTrue) 
                    + (  rightFalse * leftFalse) ))  ;
                }
            }else if(s[k] == '|'){
                if(isTrue){
                    allWays += ( (  leftTrue * rightTrue ) + (  leftFalse * rightTrue )  +
                    (  leftTrue * rightFalse) ) ;
                }else{
                    allWays += ((  leftFalse * rightFalse)  ) ;
                }
            }else{
                if(isTrue){
                    allWays += ((  leftTrue*rightFalse)  + (  leftFalse * rightTrue) ) ;
                }else{
                    allWays += ((  leftTrue*rightTrue)  + (  leftFalse * rightFalse) ) ;
                }
            }

        }
        
        dpArray[i][j][isTrue] = allWays ;
        
        return dpArray[i][j][isTrue];
    }
  
    int countWays(string &s) {
        // code here
        int n = s.length();
        vector<vector<vector<int>>> dpArray(n + 1, vector<vector<int>>(n + 1,
        vector<int>(2, -1)));
        return totalTrueWays(s, 0, n-1, 1, dpArray);
    }
*/

/*
    132. Palindrome Partitioning II
    (https://leetcode.com/problems/palindrome-partitioning-ii/description/)

    bool isPalindrome(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int getMinPartCut(string &s, int idx, vector<int> &dpArray){
        if(idx >= s.length()){
            return 0;
        }

        if(dpArray[idx] != -1){
            return dpArray[idx];
        }

        string temp;
        int cut = 0;
        int minCut = INT_MAX;
        for(int i = idx; i < s.length(); i++){
            temp += s[i];
            if(isPalindrome(temp)){
                int cut = getMinPartCut(s, i+1, dpArray);
                if(cut != INT_MAX){
                    cut = cut + 1;
                }
                minCut = min(minCut, cut);
            }
        }

        dpArray[idx] = minCut;

        return dpArray[idx];
    }

    int minCut(string s) {
        if(isPalindrome(s)){
            return 0;
        }

        int minCutAns = INT_MAX;
        vector<int> dpArray(s.length() + 1, -1);
        return getMinPartCut(s, 0, dpArray) - 1;
    }

    Bottom UP Approach
    int minCut(string s) {

        int minCutAns = INT_MAX;
        int n = s.length();
        vector<int> dpArray(n + 2, 0);
        // return getMinPartCut(s, 0, dpArray) - 1;

        for(int idx = n-1; idx >= 0; idx--){
            string temp;
            int minCut = INT_MAX;
            for(int i = idx; i < s.length(); i++){
                temp += s[i];
                if(isPalindrome(temp)){
                    int cut = dpArray[i+1];
                    if(cut != INT_MAX){
                        cut = cut + 1;
                    }
                    minCut = min(minCut, cut);
                }
            }

            dpArray[idx] = minCut;
        }

        return dpArray[0]-1;
    }

*/

/*

    1745. Palindrome Partitioning IV
    (https://leetcode.com/problems/palindrome-partitioning-iv/description/)

    OPTIMIZE IT
    bool isPalindrome(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void getMinPartCut(string &s, int idx, int cut, bool &ans, vector<vector<int>> &dpArray){
        if(idx >= s.length()){
            if(cut == 3){
                ans = true;
            }
            return ;
        }

        if(dpArray[idx][cut] != -1){
            return ;
        }

        string temp;
        for(int i = idx; i < s.length(); i++){
            temp += s[i];
            if(isPalindrome(temp)){
                getMinPartCut(s, i+1, cut + 1, ans, dpArray);
            }
        }

        dpArray[idx][cut] = ans;

    }

    bool checkPartitioning(string s) {
        
        int n = s.length();

        // int minCutAns = INT_MAX;
        bool ans = false;
        vector<vector<int>> dpArray(n + 1, vector<int>(n + 1, -1));
        getMinPartCut(s, 0, 0, ans, dpArray);
       
        return ans;
    }

*/


/*

    1043. Partition Array for Maximum Sum
    (https://leetcode.com/problems/partition-array-for-maximum-sum/)

    int getMaxParSum(vector<int> &arr, int idx, int k, vector<int> &dpArray){

        int maxSum = 0;
        int maxVal = 0;
        int len = 0;

        if(dpArray[idx] != -1){
            return dpArray[idx];
        }
        
        for(int i = idx; i < arr.size() && i < idx + k; i++){
            len += 1;
            maxVal = max(maxVal, arr[i]);

            int sum = maxVal * len + getMaxParSum(arr, i + 1, k, dpArray);
            maxSum = max(maxSum, sum);
        }

        dpArray[idx] = maxSum;

        return dpArray[idx];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dpArray(arr.size()+1, -1);
        return getMaxParSum(arr, 0, k, dpArray);
    }
        
*/