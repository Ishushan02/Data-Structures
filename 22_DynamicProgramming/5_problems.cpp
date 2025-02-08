/*

PATTERN - MERGE INTERVALS

*/

/*
    375. Guess Number Higher or Lower II
    (https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

    SO, the idea is, get the maximum cost of getting wrong answer.. out of which return the minimum one which is 
    the min of all max Costs.

    int computeCost(int start, int end){
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = start; i<end; i++){
            int lcost = i + computeCost(start, i - 1);
            int rcost = i + computeCost(i + 1, end);

            int maxCost = max(lcost, rcost);
            ans = min(ans, maxCost);
        }

        return ans;
    }

    int computeCostDP(int start, int end, vector<vector<int>> &dpArr){
        if(start >= end){
            return 0;
        }

        if(dpArr[start][end] != -1){
            return dpArr[start][end];
        }

        int ans = INT_MAX;
        for(int i = start; i<end; i++){
            int lcost = i + computeCostDP(start, i - 1, dpArr);
            int rcost = i + computeCostDP(i + 1, end, dpArr);

            int maxCost = max(lcost, rcost);
            ans = min(ans, maxCost);
        }

        dpArr[start][end] = ans;

        return dpArr[start][end];
    }

    int getMoneyAmount(int n) {
        
        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        // return computeCost(1, n);
        return computeCostDP(1, n, dpArr);
    }

*/

/*

    1130. Minimum Cost Tree From Leaf Values
    (https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

    int solveMinCost(vector<int>& arr, map<pair<int, int>, int>& partitionMap, int start, int end){
        // base
        if(start >= end){
            return 0;
        }


        int ans = INT_MAX;
        // do the partition and get produ and get element
        for(int i = start; i < end; i++){
            int leftrangeMax = partitionMap[{start, i}];
            int rightrangeMax = partitionMap[{i+1, end}];

            int currMaxVal = leftrangeMax * rightrangeMax;

            int leftSubtreeMax = solveMinCost(arr, partitionMap, start, i);
            int rightSubtreeMax = solveMinCost(arr, partitionMap, i+1, end);

            ans = min(ans, currMaxVal + leftSubtreeMax + rightSubtreeMax);

        }
        return ans;
    }

    int solveMinCostDP(vector<int>& arr, map<pair<int, int>, int>& partitionMap, int start, int end, vector<vector<int>>& dpArr){
        // base
        if(start >= end){
            return 0;
        }

        if(dpArr[start][end] != -1){
            return dpArr[start][end];
        }

        int ans = INT_MAX;
        // do the partition and get produ and get element
        for(int i = start; i < end; i++){
            int leftrangeMax = partitionMap[{start, i}];
            int rightrangeMax = partitionMap[{i+1, end}];

            int currMaxVal = leftrangeMax * rightrangeMax;

            int leftSubtreeMax = solveMinCostDP(arr, partitionMap, start, i, dpArr);
            int rightSubtreeMax = solveMinCostDP(arr, partitionMap, i+1, end, dpArr);

            ans = min(ans, currMaxVal + leftSubtreeMax + rightSubtreeMax);

        }

        dpArr[start][end] = ans;
        return dpArr[start][end];
    }

    int mctFromLeafValues(vector<int>& arr) {
        
        //  store the max Values of leaf Nodes
        map<pair<int, int>, int> partitionMap;

        for(int i = 0; i < arr.size();  i++){
            for(int j = 0; j < arr.size(); j++){
                if(i == j){
                    partitionMap[{i, j}] = arr[j];
                }else{
                    // compare the max between prev element and current element
                    partitionMap[{i, j}] = max(partitionMap[{i, j-1}], arr[j]);
                }
            }
        }
        int n = arr.size();
        int start =0;
        int end = arr.size() - 1;
        vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));

        // return solveMinCost(arr, partitionMap, start, end);
        return solveMinCostDP(arr, partitionMap, start, end, dpArr);

        // return 5;
    }
*/