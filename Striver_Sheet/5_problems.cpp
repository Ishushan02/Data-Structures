/*

    Problem 101
    (https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)
    1373. Maximum Sum BST in Binary Tree

    struct NodeBlock{
        // int TreeNode* node;
        int sum = 0;
        bool isBST = false;
        int min = 500000;
        int max = -500000;
    };  

    class Solution {
    public:

        NodeBlock traverseNodes(TreeNode* root, int &maxSum){
            if(root == NULL){
                NodeBlock nb;
                nb.isBST = true;
                return nb;
            }

            NodeBlock leftNodes = traverseNodes(root->left, maxSum);
            NodeBlock rightNodes = traverseNodes(root->right, maxSum);
            NodeBlock currentNode;
            if(
            leftNodes.isBST && 
            rightNodes.isBST && 
            root->val > leftNodes.max && 
            root->val < rightNodes.min){
            currentNode.isBST = true;
            currentNode.sum = root->val + leftNodes.sum + rightNodes.sum;
                maxSum = max(maxSum, currentNode.sum);
                currentNode.min = min(root->val, leftNodes.min);
                currentNode.max = max(root->val, rightNodes.max);
                return currentNode;
            }
            
            currentNode.isBST = false;
            return currentNode;
        }


        int maxSumBST(TreeNode* root) {
            int maxSum = 0;
            auto n = traverseNodes(root, maxSum);

            return maxSum;
        }
    };
*/

/*

    Problem 102
    (https://leetcode.com/problems/max-consecutive-ones/)
    485. Max Consecutive Ones

    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0;
        int maxcnt = 0;

        for(auto i: nums){
            if(i == 1){
                cnt += 1;
                maxcnt = max(maxcnt, cnt);
            }else{
                cnt = 0;
            }
        }
        return maxcnt;
    }

*/

/*
    Problem 103
    (https://leetcode.com/problems/next-greater-element-i/)
    496. Next Greater Element I
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nextGreater;
        for(int i = 0; i < nums2.size(); i++){
            int num = nums2[i];
            int nextNum = -1;
            for(int j = i + 1; j < nums2.size(); j++){
                if(nums2[j] > num){
                    nextNum = nums2[j];
                    break;
                }
            }
            nextGreater.push_back(nextNum);
        }

        
        unordered_map<int, int> idxMap2;
        for(int i = 0; i < nums2.size();i++ ){
            idxMap2[nums2[i]] = i;
        }

        vector<int> ans;
        unordered_map<int, int> idxMap1;
        for(int i = 0; i < nums1.size();i++ ){
            int idx = idxMap2[nums1[i]];
            ans.push_back(nextGreater[idx]);
        }
        return ans;
    }
*/

/*

    Problem 104
    (https://leetcode.com/problems/reverse-pairs/description/)
    493. Reverse Pairs

    void merge(vector<int>& nums, int start, int mid, int end, int &count){

        int i = start;
        int j = mid+1;
        while(i <= mid){
            while(j <= end && nums[i] > 2 * (long long int) nums[j]){
                j++;
            }
            count += (j - (mid + 1));
            i++;
        }
        

        i = start;
        int end1 = mid;
        j = mid+1;
        int end2 = end;
        vector<int> ans;

        while(i <= end1 && j <= end2){
            if(nums[i] < nums[j]){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }

        while(i <= end1){
            ans.push_back(nums[i]);
            i++;
        }

        while(j <= end2){
            ans.push_back(nums[j]);
            j++;
        }

        for(int k = start; k <= end; k++){
            nums[k] = ans[k-start];
        }
    }

    void divide(vector<int>& nums, int start, int end, int &count){
        if(start >= end){
            return ;
        }
        int mid = (start + end)/2;
        divide(nums, start, mid, count);
        divide(nums, mid+1, end, count);

        merge(nums, start, mid, end, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        divide(nums, 0, nums.size()-1, count);
        return count;
    }
*/

/*

    Problme 105
    (https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
    297. Serialize and Deserialize Binary Tree

    class Codec {
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(root == NULL){
                return "";
            }
            queue<TreeNode*> que;
            string ans;
            que.push(root);
            ans += to_string(root->val)+ "=";

            while(!que.empty()){
                auto topNode = que.front();
                que.pop();
                
                if(topNode->left){
                    ans += to_string(topNode->left->val) + "=";
                    que.push(topNode->left);
                }else{
                    ans += "n=";
                }
                if(topNode->right){
                    ans += to_string(topNode->right->val)+ "=";
                    que.push(topNode->right);
                }else{
                    ans += "n=";
                }
            }
            // cout << ans << endl;
            return ans;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if(data == ""){
                return NULL;
            }
            vector<int> nodes;
            int i = 0;
            while(i < data.length() ){
                int j = i;
                string temp;
                while(j < data.length()){
                    if(data[j] == '='){
                        break;
                    }else{
                        temp += data[j];
                    }
                    j++;
                }
                i = j+1;
                // cout << temp << endl;
                if(temp == "n"){
                    nodes.push_back(-100000);
                }else{
                    nodes.push_back(stoi(temp));
                }
                
            }
            // data[0]
            TreeNode* root = new TreeNode(nodes[0]);
            // nodeMap[root->val]
            queue<TreeNode*> que;
            que.push(root);

            i = 1;
            while(!que.empty()){
                auto topNode = que.front();
                que.pop();

                if(i < nodes.size()){
                    if(nodes[i] != -100000){
                        TreeNode* node = new TreeNode(nodes[i]);
                        topNode->left = node;
                        que.push(node);
                    }
                }
                if(i+1 < nodes.size()){
                    if(nodes[i+1] != -100000){
                        TreeNode* node = new TreeNode(nodes[i+1]);
                        topNode->right = node;
                        que.push(node);
                    }
                }
                i += 2;

            }
            return root;
        }
    };
*/

/*

    Problem 106
    (https://leetcode.com/problems/find-median-from-data-stream/)
    295. Find Median from Data Stream

    class MedianFinder {
    public:

        priority_queue<int> leftQueue;
        priority_queue<int, vector<int>, greater<int>> rightQueue;
        double MEDIAN ;


        MedianFinder() {
        }
        
        void addNum(int num) {
            
            if(leftQueue.empty()){
                leftQueue.push(num);
                MEDIAN = (double)leftQueue.top();
                return ;
            }else{
                if(num <= leftQueue.top()){
                    leftQueue.push(num);
                }else{
                    rightQueue.push(num);
                }
            }

            int a = leftQueue.size();
            int b = rightQueue.size();

            if(a == b){
                MEDIAN = ((double)leftQueue.top() + (double)rightQueue.top())/2;
                return ;
            }else{
                if(a > b){
                    while(leftQueue.size() - rightQueue.size() > 1){
                        rightQueue.push(leftQueue.top());
                        leftQueue.pop();
                    }

                }else{
                    while(rightQueue.size() > leftQueue.size()){
                        leftQueue.push(rightQueue.top());
                        rightQueue.pop();
                    }
                }
                if(leftQueue.size() == rightQueue.size()){
                    MEDIAN = ((double)leftQueue.top() + (double)rightQueue.top())/2;
                }else{
                    MEDIAN = (double)leftQueue.top();
                }
                
            }
        }
        
        double findMedian() {
            return MEDIAN;
        }
    };
*/

/*

    Problem 107
    (https://leetcode.com/problems/ones-and-zeroes/)
    474. Ones and Zeroes

    int maxCounts(vector<pair<int, int>> &values, int idx, int m, int n, vector<vector<vector<int>>> &dpArr){
        if(idx >= values.size()){
            return 0;
        }

        if(dpArr[m][n][idx] != -1){
            return dpArr[m][n][idx];
        }

        int zer0Count = values[idx].first;
        int oneCount = values[idx].second;

        int includeAns = 0;
        int excludeAns = 0;

        if(m - zer0Count >= 0 && n - oneCount >= 0){
            includeAns = 1 + maxCounts(values, idx+1, m-zer0Count, n-oneCount, dpArr);
        }
        excludeAns = maxCounts(values, idx+1, m, n, dpArr);
        
        dpArr[m][n][idx] = max(includeAns, excludeAns);
        return dpArr[m][n][idx];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>values;

        for(int i = 0; i < strs.size(); i++){
            int zer = count(strs[i].begin(), strs[i].end(), '0');
            int one = count(strs[i].begin(), strs[i].end(), '1');
            values.push_back({zer, one});
        }
        vector<vector<vector<int>>> dpArr(m+1, vector<vector<int>>(n +1, vector<int>(strs.size() + 1, -1)));
        return maxCounts(values, 0, m, n, dpArr);
    }
*/