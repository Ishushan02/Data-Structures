/*
    ALL THIS PROBLEMS I FOUND IT DIFFICULT PLEASE SEE THIS AGAIN ISHAN JI
*/


/*
    1482. Minimum Number of Days to Make m Bouquets
    (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

    bool totFlowers(vector<int>& bloomDay, int m, int k, int days){
        
        int count = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            
            // if currday is less than given day
            if(bloomDay[i] <= days){
                count+= 1;
            }

            // count
            if(count == k){
                m = m - 1;
                count = 0;
                if(m == 0){
                    break; // requirement completed
                }
            }

            // it's not adjacent
            if(bloomDay[i] > days){
                count = 0;
            }
        }

        if(m == 0){
            return true;
        }

        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = INT_MAX;
        int end = INT_MIN;

        for(int i = 0; i < bloomDay.size(); i++){
            start = min(start, bloomDay[i]);
            end = max(end, bloomDay[i]);
        }

        int mid = (start + end)/2;
        int ans = -1;
        while(start <= end){
            if(totFlowers(bloomDay, m, k, mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        return ans;
    }

*/

/*
    658. Find K Closest Elements
    (https://leetcode.com/problems/find-k-closest-elements/description/)

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        int start = 0; 
        int end = arr.size()-1;
        while(end - start >= k){
            int lowdiff = x - arr[start];
            int highdiff = arr[end] - x;
            
            if(lowdiff > highdiff){
                start = start + 1;
            }else{
                end = end - 1;
            }
        }

        for(int i = start; i <= end; i++){
            ans.push_back(arr[i]);
        }

        return ans;
        
    }

    
*/

/*
    Allocate Minimum Pages
    (https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

    bool ifPossible(vector<int> arr, int k, int pages){
        int studentCount = 1;
        int tempPages = 0;
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] > pages){
                return false;
            }
            if(arr[i] + tempPages > pages){
                studentCount++;
                tempPages= arr[i];
                if(studentCount > k){
                    return false;
                }
            }else{
                tempPages += arr[i];
            }
        }
        
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int start = 0;
        int end = 0;
        if(k > arr.size()){
            return -1;
        }
        
        for(int i = 0; i < arr.size(); i++){
            end += arr[i];
        }
        
        int mid = (start + end)/2;
        int ans = -1;
        
        while(start <= end){
            if(ifPossible(arr, k, mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }
        
        return ans;
    }

*/

/*

    Aggressive Cows
    (https://www.geeksforgeeks.org/problems/aggressive-cows/0)

    (bool ifPossible(vector<int> &stalls, int k, int dist){
        int pos = stalls[0];
        int count = 1;

        for(int i = 1;i < stalls.size() ; i++){
            if (stalls[i]-pos >= dist){
                pos = stalls[i];
                count++;
            }
            if (count==k){
                return true;
            }
        }

        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int end = stalls[stalls.size() -1] - stalls[0];
        
        int mid = (start + end)/2;
        
        int ans = -1;
        while(start <= end){
            
            if(ifPossible(stalls, k, mid)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        
        return ans;
        
        
    })
*/

/*
    // Proceure is
    // - starting root is currNode
    //     currNode
    //         - get predecessor of root Node
    //         - shift all currNode's left elements to right of predecessor
    //         - shift currNode's left element to currNode's right
    //         - nullify currNode's left branch
    //     - currNode -> currNode->right shift right

    
    114. Flatten Binary Tree to Linked List
    (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

    void flatten(TreeNode* root) {
        if(root == NULL){
            return ;
        }
        TreeNode* currNode = root;

        while(currNode){
            if(currNode->left){
                TreeNode* pred = currNode->left;

                while(pred->right){
                    pred = pred->right;
                }

                pred->right = currNode->right;
                currNode->right = currNode->left;
                currNode->left = nullptr;
            }
            currNode = currNode->right;
        }

    }
*/

/*

    Painting the Fence (Practise Well it won't be done by intutive)
    (https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

------------------------------------------------------------------------------------------------------------
Dry Run 
    - The concept is based on (last 2 colors to be same and last 2 colors to be different)

for n ==1 (R)-->  R

for n == 2, k = 3 (R, G, B)

    Same Patterns -> RR, GG, BB                      - total K * (n -1) ways
    Diff Patterns -> RG, RB, BR, BG, GR, GB          - total k * (k -1) ways

    Tota Patterns -> 3 + 6 = 9

for n == 3, k = 3 (R, G, B)
    
    Same Patterns - > Take all diff patterns of top and add same to it
                        RGG, RBB, BRR, BGG, GRR, GBB                    - total prev only diff ways

    Diff Patterns -> Take total patterns of prev and add diff col in it
                        RRG, RRB, GGR, GGB, BBR, BBG, RGR, RGB, RBG, RBR, BRG, BRB, BGR, BGB, GRB, GRG, GBG, GBR
                                                                        - total prev all comb * (K - 1) 

    Tota Patterns -> 6 + 9 * 2 = 24   -> K * 1 + prev * (k - 1)


for n == 4 k = 3 (R, G, B)

    Same Pattern
        (from above)      RRG, RRB, GGR, GGB, BBR, BBG, RGR, RGB, RBG, RBR, BRG, BRB, BGR, BGB, GRB, GRG, GBG, GBR
    add same color ot it  RRGG, RRBB, GGRR, .............. GBRR        
                        - total prev only diff ways (18)

    Diff Pattern 
            total prev all comb *  k - 1 -> 24 * 2 = 48

    Total Patterns -> 24 * 2 + 18




Hence for n = 1 -> total k ways
      for n = 2 -> total k - 1 ways

      for n  = 3
                same = prev(n-2) ways * (k-1) ways
                diff = prev(n-1) ways * (k -1) ways
            total :=  k-1 * totalof(n-2) + k - 1 * totalof(n-1)

    K  = 3

                        f(n=1) = 3 --> 1 ways
                        f(n = 2) --> 3 + 6 -> 9 ways
let's go by formula     f(n=3) := f(n-2) * (k -1) + f(n-1) * (k - 1) = (f(n=1) * k - 1) + (f(n=2) * k - 1)
                                                                     = 3 * 2 + 9 * 2 = 24

                        and so on ..



------------------------------------------------------------------------------------------------------------



    int countWays(int n, int k) {
        // code here
        if(n == 1){
            return k;
        }
        
        if(n == 2){
            return k + (k * (k - 1));
        }
        
        int same = (k - 1) * countWays(n -2, k); 
        int diff = (k -1) * countWays(n- 1, k);  
        
        return same + diff;
    }

*/



/*
    (take 1 and i elements)
        - swap i and 1 fix thos --> now total we have n - 2 ways
        - now fix only 1 at poisition i -> now we have n - 1 ways

        - in total - we have (n-1) elements left to be swapped 

        - so (n - 1) * (totways(n-2) + totways(n-1))


  Disarrangement of balls {Focus On Logic }
    (https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1)

    int allDearrangements(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
    
        return (n - 1) * (allDearrangements(n - 2) + allDearrangements(n - 1));
    }

    int countDer(int n) {
        return allDearrangements(n);
    }

*/


/*  
    72. Edit Distance
    (https://leetcode.com/problems/edit-distance/description/)

    int getminOper(string &word1, string &word2, int i, int j){
        if(i >= word1.length()){
            return word2.length()-j;
        }

        if(j >= word2.length()){
            return word1.length()-i;
        }

        int ans = 0;
        if(word1[i] == word2[j]){
            ans = 0 + getminOper(word1, word2, i+1, j+1);
        }else{

            // insert
            int insertop = 1 + getminOper(word1, word2, i , j + 1);

            // delete
            int deleteop = 1 + getminOper(word1, word2, i+ 1, j);

            // replace
            int replaceop = 1 + getminOper(word1, word2, i+1, j+1);

            ans = min(insertop, min(deleteop, replaceop));
        }

        return ans;
    }

    int minDistance(string word1, string word2) {
        return getminOper(word1, word2, 0, 0);
    }
*/


/*
    221. Maximal Square
    (https://leetcode.com/problems/maximal-square/)
    
    int traverseSqr(vector<vector<char>>& matrix, int i, int j, int &maxAns){
        if(j >= matrix[0].size() || i >= matrix.size()){
            return 0;
        }

        int rightans = traverseSqr(matrix, i, j+ 1, maxAns);
        int downans = traverseSqr(matrix, i+1, j, maxAns);
        int diagans = traverseSqr(matrix, i+1, j+ 1, maxAns);
        if(matrix[i][j] == '1'){
            
            int tempAns = 1 + min(rightans, min(downans, diagans));
            // cout << " i " << i << " j " << j << " TempAns: " << tempAns << " MAx: " << maxAns << endl;
            maxAns = max(maxAns, tempAns);
            return tempAns;
        }else{
            return 0;
        }

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxAns = 0;
        int temp = traverseSqr(matrix, 0, 0, maxAns);

        return maxAns * maxAns;
    }
*/

/*
    // STANDARD PARTITIONING OR CUT PROBLEMS ARE SOLVED IN THIS METHOD
    1547. Minimum Cost to Cut a Stick
    (https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)

    int getminCost(vector<int>& cuts, int start, int end, vector<vector<int>> &dpArr){
        if(end - start < 2){
            return 0;
        }

        if(dpArr[start][end] != -1){
            return dpArr[start][end];
        }
        int minCost = INT_MAX;
        for(int i = start+1; i <= end - 1; i++){
            int cost = (cuts[end] - cuts[start]) + getminCost(cuts, start, i, dpArr) + getminCost(cuts, i, end, dpArr);
            minCost = min(minCost, cost);
        }

        dpArr[start][end] = minCost;

        return minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dpArr(cuts.size()+1, vector<int>(cuts.size()+1, -1));

        return getminCost(cuts, 0, cuts.size()-1, dpArr);
    }
*/