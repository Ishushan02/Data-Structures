/*  
    Problem 16
    23. Merge k Sorted Lists
    (https://leetcode.com/problems/merge-k-sorted-lists/)

    ListNode* mergeNodes(ListNode* &list1, ListNode* &list2){

        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* ansHead = new ListNode(99999999);
        ListNode* ansptr = ansHead;

        while(l1 && l2){
            ListNode* nextl1 = l1->next;
            ListNode* nextl2 = l2->next;

            ListNode* node1 = l1;
            ListNode* node2 = l2;

            if(l1->val < l2->val){
                ansptr->next = node1;
                ansptr = ansptr->next;
                l1 = nextl1;
            }else if(l1->val > l2->val){
                ansptr->next = node2;
                ansptr = ansptr->next;
                l2 = nextl2;
            }else{
                ansptr->next = node1;
                ansptr = ansptr->next;
                ansptr->next = node2;
                ansptr = ansptr->next;
                l1 = nextl1;
                l2 = nextl2;
            }

        }

        if(l1){
            ansptr->next = l1;
        }
        if(l2){
            ansptr->next = l2;
        }

        return ansHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }

        int j = 1;

        ListNode* ansHead = lists[0];

        while(j < lists.size()){
            ListNode* curr = lists[j];
            ansHead = mergeNodes(ansHead, curr);
            j++;
        }

        return ansHead;
    }
*/

/*
    Problem 17
    152. Maximum Product Subarray
    (https://leetcode.com/problems/maximum-product-subarray/)

    void productMax(vector<int> &nums, int i, int product, int &maxProduct, map<pair<int, int>, int> &dpMap){
        if(i >= nums.size()){
            maxProduct = max(maxProduct, product);
            return ;
        }

        if(dpMap.find({i, product}) != dpMap.end()){
            // maxProduct = max(dpMap[{i, product}], maxProduct);
            return ;
        }

        // include nums[i]
        maxProduct = max(maxProduct, nums[i] * product);
        productMax(nums, i + 1, nums[i] * product, maxProduct, dpMap);

        // exclude nums[i]
        if(i + 1 < nums.size()){
            productMax(nums, i + 1, 1, maxProduct, dpMap);
        }else{
            productMax(nums, i + 1, nums[i], maxProduct, dpMap);
        }

        dpMap[{i, product}] = maxProduct;

    }

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        map<pair<int, int>, int> dpMap;
        int ans = 1;
        int maxAns = INT_MIN;
        
        productMax(nums, 0, 1, maxAns, dpMap);
        return maxAns;
    }

*/

/*
    Problem 18
    153. Find Minimum in Rotated Sorted Array
    (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

    int findMin(vector<int>& nums) {
        
        int n = nums.size();

        int start = 0;
        int end = n -1;
        int mid = (start + end)/2;
        int ans = -1;

        while(start <= end){

            if(mid + 1 < n && nums[mid] > nums[mid+1]){
                return nums[mid + 1];
            }else if(mid + 1 < n && mid - 1 >= 0 && nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid]){
                return nums[mid];
            }

            if(nums[mid] > nums[0]){
                // ans = nums[start];
                start = mid + 1;
            }else{
                ans = nums[start];
                end = mid - 1;
            }

            mid = (start + end)/2;
        }

        if(ans == -1){
            return nums[0];
        }

        return nums[mid];

    }

*/

/*
    Problem 19
    33. Search in Rotated Sorted Array
    (https://leetcode.com/problems/search-in-rotated-sorted-array/)

    int pivot(vector<int>& nums, int n){
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){

            if(mid + 1 < n && nums[mid] > nums[mid+1]){
                return mid + 1;
            }else if(mid - 1>= 0 && mid + 1 < n && nums[mid] < nums[mid + 1] && nums[mid] < nums[mid-1]){
                return mid;
            }else if(nums[mid] > nums[0]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        if(start >= n){
            return 0;
        }

        return start;

    }

    int binarySearch(vector<int>& nums, int start, int end, int key){
        int mid = (start + end)/2;

        while(start <= end){

            if(nums[mid] == key){
                return mid;
            }else if(key > nums[mid]){
                start = mid + 1;
            }else{
                end = mid -1;
            }
            mid = (start + end)/2;
        }

        return -1;
    }

    int search(vector<int>& nums, int target){

        int n = nums.size();
        int pivotidx = pivot(nums, n);

        int ansidx = binarySearch(nums, 0, pivotidx-1, target);
        if(ansidx == -1){
            ansidx = binarySearch(nums, pivotidx, n-1, target);
        }
        return ansidx;
    }

*/


/*
    Problem 20
    39. Combination Sum
    (https://leetcode.com/problems/combination-sum/)

    void allPossibilities(vector<int>& candidates, int j, int target, vector<int> temp, int sum, vector<vector<int>> &ans){

        if(sum == target){

            ans.push_back(temp);
            return;
        }

        for(int i = j; i < candidates.size(); i++){
            if(sum + candidates[i] <= target){
                temp.push_back(candidates[i]);
                allPossibilities(candidates, i, target, temp, sum + candidates[i], ans);
                temp.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        allPossibilities(candidates, 0, target, temp, 0, ans);

        return ans;
    }

*/

/*
    Problem 21
    295. Find Median from Data Stream
    (https://leetcode.com/problems/find-median-from-data-stream/)

    class MedianFinder {
    public:

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        double median = 0.0;

        MedianFinder(){

        }
        
        void addNum(int num){
            if(maxHeap.size() < minHeap.size()){
                if(maxHeap.size() == 0){
                    if(num > minHeap.top()){
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(num);
                    }else{
                        maxHeap.push(num);
                    }
                    
                }else{
                    if(num > minHeap.top()){
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(num);
                    }else{
                        maxHeap.push(num);
                    }
                }
            }else if(maxHeap.size() > minHeap.size()){
                if(minHeap.size() == 0){
                    if(num < maxHeap.top()){
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(num);
                    }else{
                        minHeap.push(num);
                    }
                }else{
                    if(num < maxHeap.top()){
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(num);
                    }else{
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(num);
                    }
                }
            }else{
                // initialCase
                if(maxHeap.size()==0 || minHeap.size()==0 ){
                    maxHeap.push(num);
                }else{
                    if(num < maxHeap.top()){
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(num);
                    }else{
                        minHeap.push(num);
                    }
                }
            }

            int maxSize = maxHeap.size();
            int minSize = minHeap.size();
            // cout << num << " , MaxSize: " << maxSize << " , MinSize: "<< minSize << endl;

            if(maxSize > minSize){
                median = maxHeap.top();
            }else if(maxSize == minSize){
                median = ((double)maxHeap.top() + minHeap.top()) / 2;
            }else{
                if(minHeap.size() == 0){
                    median = maxHeap.top();
                }else{
                    median = minHeap.top();
                }       
                
            }
            // cout << num << " : " << median << endl;
        }
        
        double findMedian() {
            return median;
        }
    };
*/

/*
    Problem 22
    (297. Serialize and Deserialize Binary Tree)
    (https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        return max(l, r) + 1;
    }

    vector<TreeNode*> traverseSerialize(TreeNode* root){

        queue<TreeNode*> que;
        que.push(root);
        vector<TreeNode*> serializedData;
        serializedData.push_back(root);
        int h = height(root);

        while(!que.empty() && h > 0){

            // TreeNode* top = que.front();
            // serializedData.push_back(top);
            int size = que.size();
            // que.pop();

            for(int i = 0; i < size; i++){
                TreeNode* top = que.front();
                if(top->left != NULL){
                    que.push(top->left);
                    serializedData.push_back(top->left);
                }else{
                    serializedData.push_back(NULL);
                }

                if(top->right != NULL){
                    que.push(top->right);
                    serializedData.push_back(top->right);
                }else{
                    serializedData.push_back(NULL);
                }

                que.pop();
            }
            h--;
        }   
        
        return serializedData;
    }

    TreeNode* traverseDeseralize(vector<int> data){
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(data[0]);
        que.push(root);
        int i = 1;

        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            // cout << curr->val << " : " << data[i] << " , " << data[i+1] << endl;

            // left
            // TreeNode* leftNode = NULL;
            if(i < data.size() && data[i] != 9999){
                TreeNode* leftNode = new TreeNode(data[i]);
                curr->left = leftNode;
                que.push(leftNode);
            }
            i++;
            // right
            // TreeNode* rightNode = NULL;
            if(i < data.size() && data[i] != 9999){
                TreeNode* rightNode = new TreeNode(data[i]);
                curr->right = rightNode;
                que.push(rightNode);
            }
            i++;

        }

        return root;

    }

    vector<int> getNodeValue(string &data){
        vector<int> values;
        // values.push_back(9999);
        string elem;
        int i = 0;
        while(i < data.length()){
            if(data[i] == ' '){
                int val = stoi(elem);
                values.push_back(val);
                elem = "";
            }else{
                elem += data[i];
            }
            i++;
        }
        return values;
    }

    class Codec {
    public:
        vector<TreeNode*> serialized;
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(root == NULL){
                return "";
            }
            
            int h = height(root);
            serialized = traverseSerialize(root);
            int size = serialized.size();

            string ans;
            for(int i = 0; i < size; i++){
                TreeNode* v = serialized[i];
                if(v == NULL){
                    ans += "9999 ";
                    // cout << "-1" << " ";
                }else{
                    ans += to_string(v->val) + " ";
                    // cout << v->val << " ";
                }
            }
            // cout << endl;

            return ans;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if(data == ""){
                return NULL;
            }

            vector<int> elementValues = getNodeValue(data);
            // for(auto v: elementValues){
            //     cout << v << " ";
            // }
            int index = 0;
            TreeNode* root = traverseDeseralize(elementValues);

            // for(auto v: elementValues){
            //     cout << v << " ";
            // }
            return root;
        }
    };


*/

/*
    Problem 23
    424. Longest Repeating Character Replacement
    (https://leetcode.com/problems/longest-repeating-character-replacement/)

    TLE (Method 1)
    void replaceChars(string &s, char prev, int i, int k, int ans, int &maxAns){
        if(i >= s.length()){
            return ;
        }

        // cout << i << " : " << s << endl;

        if(s[i] == prev){
            ans++;
            maxAns = max(maxAns, ans);
            replaceChars(s, s[i], i+1, k, ans, maxAns);
        }else{

            // 2 options
            // replace
            char curr = s[i];
            if(k > 0){
                // replace curr
                s[i] = prev;
                replaceChars(s, s[i], i, k-1, ans, maxAns);
                s[i] = curr;

                // replace prev
                // ans++;
                replaceChars(s, s[i], i, k-1, 1, maxAns);
            }
            
            // don't replace
            s[i] = curr;
            if(prev == curr){
                ans++;
                maxAns = max(maxAns, ans);
                replaceChars(s, curr, i+1, k, ans, maxAns);
            }else{

                // change prev
                replaceChars(s, curr, i+1, k, 1, maxAns);
            }
            

        }
    }

    int characterReplacement(string s, int k) {
        
        if(s.length() == 1){
            return 1;
        }

        int maxAns = 1;
        replaceChars(s, s[0], 1, k, 1, maxAns);

        return maxAns;
    }

*/

/*
    Problem 24
    300. Longest Increasing Subsequence
    (https://leetcode.com/problems/longest-increasing-subsequence/)

    int getLongestIncrSubs(vector<int>& nums, int i, int prev, vector<vector<int>> &dpArray){
        if(i >= nums.size()){
            return 0;
        }

        if(dpArray[i][prev + 1] != -1){
            return dpArray[i][prev+1];
        }

        int include = 0;
        int exclude = 0;

        if(prev == -1 || nums[i] > nums[prev]){
            include = 1 + getLongestIncrSubs(nums, i+1, i, dpArray);
        }

        exclude = getLongestIncrSubs(nums, i+1, prev, dpArray);

        dpArray[i][prev+1] = max(include, exclude);
        return max(include, exclude);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dpArray(n+1, vector<int>(n+1, -1));
        return getLongestIncrSubs(nums, 0, -1, dpArray);

    }
*/

/*
    Problem 25
    48. Rotate Image
    (https://leetcode.com/problems/rotate-image/)

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int i = 0;
        int j = n - 1;
        while(i < j){

            for(int row = 0; row < n; row++){
                swap(matrix[row][i], matrix[row][j]);
            }
            i++;
            j--;
        }
    }
*/

/*
    Problem 25
    49. Group Anagrams
    (https://leetcode.com/problems/group-anagrams/)

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> temp(strs.begin(), strs.end());
        unordered_map<string, vector<int>> valAns;
        int i = 0;
        for(auto s:temp){
            sort(s.begin(), s.end());
            valAns[s].push_back(i);
            i++;
        }

        vector<vector<string>> ans;
        for(auto &[key, vals]:valAns){
            vector<string> val;
            for(auto v:vals){
                val.push_back(strs[v]);
            }
            ans.push_back(val);
        }

        return ans;
    }
*/

/*
    Problem 26
    53. Maximum Subarray
    (https://leetcode.com/problems/maximum-subarray/)

    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxSum = INT_MIN;

        for(auto v: nums){

            sum += v;
            maxSum = max(maxSum, sum);

            if(sum < 0){
                sum = 0;
            }

        }

        return maxSum;
    }

*/

/*
    Problem 27
    54. Spiral Matrix
    (https://leetcode.com/problems/spiral-matrix/description/)

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int startRow = 0;
        int endRow = row - 1;
        int startCol = 0;
        int endCol = col - 1;

        int count = 0;
        int totalElem = row * col;
        vector<int> ans;

        while(count < totalElem){
            cout << count << " - "<< startRow << ", " << endRow << ", "<< startCol << ", " << endCol << endl;
            // row left to right
            for(int i = startCol; count < totalElem && i <= endCol; i++){
                cout << matrix[startRow][i] << " ";
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            cout <<endl;
            startRow++;


            // col top to bottom
            for(int i = startRow; count < totalElem && i <= endRow; i++){
                cout << matrix[i][endCol] << " ";
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            cout << endl;
            endCol--;

            // row right to left
            for(int i = endCol; count < totalElem && i >= startCol; i--){
                cout << matrix[endRow][i] << " ";
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            cout << endl;
            endRow--;

            // col bottom to top
            for(int i = endRow; count < totalElem && i >= startRow; i--){
                cout << matrix[i][startCol] << " ";
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            cout << endl;
            startCol++;

        }

        return ans;

    }

*/

/*
    Problem 28
    55. Jump Game
    (https://leetcode.com/problems/jump-game/)

    bool ifPossible(vector<int> &nums, int i, vector<int> &dpArray){
        // cout << i << endl;
        if(i >= nums.size()){
            return false;
        }

        if(dpArray[i] != -1){
            return dpArray[i];
        }

        if(i == nums.size() - 1){
            return true;
        }

        if(nums[i] == 0){
            return false;
        }

        bool ans = false;
        for(int j = 1; j <= nums[i]; j++ ){
            ans = ans || ifPossible(nums, i + j, dpArray);
            if(ans){
                dpArray[i] = 1;
                return true;
            }
            
            
        }

        dpArray[i] = ans;
        return ans;

    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpArray(n+1, -1);
        return ifPossible(nums, 0, dpArray);
    }
*/

/*
    Problem 29
    572. Subtree of Another Tree
    (https://leetcode.com/problems/subtree-of-another-tree/)

    void subRootNode(TreeNode* root, TreeNode* subRoot, vector<TreeNode*> &nodes){
        if(root== NULL){
            return ;
        }

        if(root->val == subRoot->val){
            nodes.push_back(root);
        }

        subRootNode(root->left, subRoot, nodes);
        subRootNode(root->right, subRoot, nodes);

    }

    bool checkSimilarity(TreeNode* rootA, TreeNode* rootB){
        if((rootA == NULL && rootB != NULL) || (rootA != NULL && rootB == NULL)){
            return false;
        }
        if(rootA == NULL && rootB == NULL){
            return true;
        }

        if(rootA->val != rootB->val){
            return false;
        }

        return checkSimilarity(rootA->left, rootB->left) && checkSimilarity(rootA->right, rootB->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        vector<TreeNode*> nodes;
        subRootNode(root, subRoot, nodes);
        
        if(nodes.size() == 0){
            return false;
        }
        // cout << node->val << endl;

        for(auto v: nodes){
            if(checkSimilarity(v, subRoot)){
                return true;
            }
        }

        return false;
    }

*/

/*
    Problem 30
    62. Unique Paths
    (https://leetcode.com/problems/unique-paths/)

    int allPossiblePaths(int i, int j, int m, int n, vector<vector<int>> dpArr){
        if(i > m || j > n){
            return 0;
        }
        if(i == m && j == n ){
            return 1;
        }
        // cout << i << " , " << j << endl;
        if(dpArr[i][j] != -1){
            return dpArr[i][j];
        }
        int allPaths = 0;
        allPaths += allPossiblePaths(i + 1, j, m, n, dpArr) + allPossiblePaths(i, j+1, m, n, dpArr);
        dpArr[i][j] = allPaths;
        

        return allPaths;
    }

    int topDownApproach(int m, int n){

        vector<vector<int>> dpArr(m+2, vector<int>(n+2, 0));
        dpArr[m][n] = 1;
        for(int i = 1; i <= m+1 ; i++){
            dpArr[i][n] = 1;
        }

        for(int i = 1; i <= n+1 ; i++){
            dpArr[m][i] = 1;
        }

        for(int i = m-1; i >= 1; i--){
            for(int j = n-1; j >= 1; j--){
                // cout << i<<j << " , " << i+1<<j << " and " << i<<j+1 << endl;
                // cout << dpArr[i][j] << " , " << dpArr[i+1][j] << " and " << dpArr[i][j+1] << endl;
                dpArr[i][j] += dpArr[i+1][j] + dpArr[i][j+1];
                // cout << dpArr[i][j] << endl;
            }
        }

        return dpArr[1][1];
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dpArr(m+2, vector<int>(n+2, -1));
        return topDownApproach(m, n);
        // return 1;
    }

*/