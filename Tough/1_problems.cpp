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
                same = total(n-2) ways * (k-1) ways
                diff = total(n-1) ways * (k -1) ways
            total :=  k-1 * totalof(n-2) + k - 1 * totalof(n-1)

------------------------------------------------------------------------------------------------------------



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