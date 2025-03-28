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