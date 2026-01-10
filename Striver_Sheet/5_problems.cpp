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

/*

    Problem 108
    (https://leetcode.com/problems/find-the-duplicate-number/)
    287. Find the Duplicate Number

    with Array Modification
    int findDuplicate(vector<int>& nums) {
        int n = 0;

        for(int i = 0; i < n; i++){
            int index = abs(nums[i]);
            if(arr[index] < 0) return index;

            arr[index] = -1 * arr[index];
        }
        
        return -1;
    }

    without Array Modification
    int findDuplicate(vector<int>& nums) {
        int tor = nums[0];
        int rab = nums[0];
        bool first =  true;
        while(first || tor != rab){
            tor = nums[tor];
            rab = nums[nums[rab]];
            first = false;
        }

        tor = nums[0];
        while(tor != rab){
            tor = nums[tor];
            rab = nums[rab];
        }

        return tor;
    }
        
*/

/*

    Problem 109
    (https://leetcode.com/problems/lru-cache/)
    146. LRU Cache

    class DLL{
    public:
        int val;
        int key;
        DLL* next;
        DLL* prev;
        DLL(int key, int value){
            this->key = key;
            this->val = value;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    class LRUCache {
    public:

        int n;
        DLL* head = NULL;
        DLL* tail = NULL;
        unordered_map<int, DLL*> cacheMap;

        LRUCache(int capacity) {
            this->n = capacity;
        }

        void removeNode(DLL* node){
            DLL* prevN = node->prev;
            DLL* nextN = node->next;

            if(node == head){
                node = node->next;
                head = node;
            }else if(prevN == NULL){
                nextN->prev = NULL;
                head = nextN;
            }else if(nextN == NULL){
                prevN->next = NULL;
                tail = prevN;
            }else{
                prevN->next = nextN;
                nextN->prev = prevN;
            }

        }
        
        DLL* addNode(int key, int val){
            DLL* newNode = new DLL(key, val);
            if(head == NULL || tail == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            return newNode;
        }

        int deleteHead(){
            int v = head->key;
            head = head->next;
            return v;
        }

        int get(int key) {
            if(cacheMap.find(key) != cacheMap.end()){
                auto node = cacheMap[key];
                removeNode(cacheMap[key]);
                DLL* newNode = addNode(key, node->val);
                cacheMap[key] = newNode;
                return node->val;
            }

            return -1;
        }
        
        void put(int key, int value) {
            if(cacheMap.find(key) != cacheMap.end()){
                removeNode(cacheMap[key]);
                DLL* newNode = addNode(key, value);
                cacheMap[key] = newNode;
                return ;
            }

            if(cacheMap.size() == n){
                int k = deleteHead();
                cacheMap.erase(k);
                DLL* newNode = addNode(key, value);
                cacheMap[key] = newNode;
            }else{
                DLL* newNode = addNode(key, value);
                cacheMap[key] = newNode;
            }
        }
    };
*/

/*

    Problme 110
    (https://leetcode.com/problems/lfu-cache/description/)
    460. LFU Cache

    class DLL{
    public:
        int key;
        int val;
        int freq;
        DLL* next;
        DLL* prev;
        DLL(int key, int val, int count = 1){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
            this->freq = count;
        }
    };

    class LFUCache {
    public:
        int n;
        unordered_map<int, DLL*> cacheMap;
        DLL* startptr = NULL;
        DLL* endptr = NULL;

        DLL* addNode(int key, int val, int count = 1){
            DLL* newNode = new DLL(key, val, count);
            if(startptr == NULL || endptr == NULL){
                startptr = newNode;
                endptr = newNode;
            }else{
                endptr->next = newNode;
                newNode->prev = endptr;
                endptr = newNode;
            }
            return newNode;
        }

        void deleteSpecificNode(DLL* node){

            DLL* nextNode = node->next;
            DLL* prevNode = node->prev;

            if(prevNode == NULL && nextNode == NULL){
                startptr = NULL;
                endptr = NULL;
            }else if(prevNode != NULL && nextNode == NULL){
                prevNode->next = NULL;
                endptr = prevNode;
            }else if(prevNode == NULL && nextNode != NULL){
                nextNode->prev = NULL;
                startptr = nextNode;
            }else{
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }

        }

        int deleteNode(){
            // int key;
            int minCount = INT_MAX;
            DLL* minCountKey;
            DLL* temp = endptr;

            while(temp){
                if(temp->freq <= minCount){
                    minCount = temp->freq;
                    minCountKey = temp;
                }
                temp = temp->prev;
            }

            DLL* nextNode = minCountKey->next;
            DLL* prevNode = minCountKey->prev;

            if(prevNode == NULL && nextNode == NULL){
                startptr = NULL;
                endptr = NULL;
            }else if(prevNode != NULL && nextNode == NULL){
                prevNode->next = NULL;
                endptr = prevNode;
            }else if(prevNode == NULL && nextNode != NULL){
                nextNode->prev = NULL;
                startptr = nextNode;
            }else{
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }
            return minCountKey->key;

        }   

        LFUCache(int capacity) {
            this->n = capacity;
        }
        
        int get(int key) {
            // cout << " For Key : " << key << endl;
            // for(auto &[k, v]:cacheMap){
            //     cout << k << ": " << v->val << endl;
            // }cout << endl;
            
            if(cacheMap.find(key) != cacheMap.end()){
                
                DLL* oldNode = cacheMap[key];
                int ans = oldNode->val;
                deleteSpecificNode(oldNode);
                DLL* newNode = addNode(key, ans, oldNode->freq + 1);
                cacheMap[key] = newNode;
                return ans;
            }
            return -1;
        }
        
        void put(int key, int value) {
            // cout << " For PUT Key : " << key << " , val "<< value << endl;
            // for(auto &[k, v]:cacheMap){
            //     cout << k << ": " << v->val<< ", "<< v->freq << endl;
            // }cout << endl;
            if(cacheMap.find(key) != cacheMap.end()){
                DLL* oldNode = cacheMap[key];
                int ans = oldNode->val;
                deleteSpecificNode(oldNode);
                DLL* newNode = addNode(key, value, oldNode->freq + 1);
                cacheMap[key] = newNode;
                return ;
            }

            if(cacheMap.size() >= n){
                int k = deleteNode();
                // cout << " Exceeded Size and delete "<< k << endl;
                cacheMap.erase(k);
                DLL* newNode = addNode(key, value, 1);
                cacheMap[key] = newNode;

            }else{
                DLL* newNode = addNode(key, value, 1);
                cacheMap[key] = newNode;
            }

        }
    };

    Method 2 (better method)

    class DoublyLinkedList{
    public:
        int key;
        int val;
        int freq;
        DoublyLinkedList* next;

        DoublyLinkedList(int key, int val, int freq = 1){
            this->key = key;
            this->val = val;
            this->freq = freq;
            this->next = NULL;
        }
    };

    class LFUCache {
    public:
        unordered_map<int,DoublyLinkedList* > nodeMap;
        map<int, DoublyLinkedList* > freqMap;
        int lfuSize;

        LFUCache(int capacity) {
            this->lfuSize = capacity;
        }

        void addNodeFreqMap(int freq, DoublyLinkedList* newNode, map<int, DoublyLinkedList* >& freqMap){
            // cout << " To Add " << newNode->key << " , " << newNode->val << " and freq is "<< freq << endl;
            if(freqMap.find(freq) == freqMap.end()){
                freqMap[freq] = newNode;
            }else{
                DoublyLinkedList* temp = freqMap[freq];
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newNode;

            }

        }

        void removeNode(int freq, DoublyLinkedList* node, map<int, DoublyLinkedList* >& freqMap){

            DoublyLinkedList* temp = freqMap[freq];
            DoublyLinkedList* prevNode = temp;
            if(temp->key == node->key){
                temp = temp->next;
                if(temp != NULL){
                    freqMap[freq] = temp;
                }else{
                    freqMap.erase(freq);
                }
                
                return ;
            }

            while(temp){
                if(temp->key == node->key){
                    break;
                }
                prevNode = temp;
                temp = temp->next;
            }

            if(temp->next){
                prevNode->next = temp->next;
                return ;
            }

            prevNode->next = NULL;

        }

        int removeleastFreqNode(map<int, DoublyLinkedList* >& freqMap){
        
            auto it = freqMap.begin();
            DoublyLinkedList* temp = freqMap[it->first];
            int key = temp->key;
            temp = temp->next;
            if(temp != NULL){
                freqMap[it->first] = temp;
            }else{
                freqMap.erase(it->first);
            }

            return key;
        }
        
        int get(int key) {
            if(nodeMap.find(key) != nodeMap.end()){
                auto node = nodeMap[key];
                int value = node->val;
                int currentFreq = node->freq;
                removeNode(currentFreq, node, freqMap);

                DoublyLinkedList* newNode = new DoublyLinkedList(key, value, currentFreq + 1);
                addNodeFreqMap(currentFreq + 1, newNode, freqMap);
                nodeMap[key] = newNode;
                return value;
            }

            return -1;
        }
        
        void put(int key, int value) {
            
            if(nodeMap.find(key) != nodeMap.end()){
                auto node = nodeMap[key];
                int currentFreq = node->freq;
                removeNode(currentFreq, node, freqMap);

                DoublyLinkedList* newNode = new DoublyLinkedList(key, value, currentFreq + 1);
                addNodeFreqMap(currentFreq + 1, newNode, freqMap);
                nodeMap[key] = newNode;
                return ;
            }

            if(nodeMap.size() == lfuSize){
                int k = removeleastFreqNode(freqMap);
                nodeMap.erase(k);
                DoublyLinkedList* newNode = new DoublyLinkedList(key, value, 1);
                addNodeFreqMap(1, newNode, freqMap);
                nodeMap[key] = newNode;
            }else{
                DoublyLinkedList* newNode = new DoublyLinkedList(key, value, 1);
                addNodeFreqMap(1, newNode, freqMap);
                nodeMap[key] = newNode;
            }
            
        }
    };


*/

/*
    Problem 111
    56. Merge Intervals (VVII Question)
    (https://leetcode.com/problems/merge-intervals/)

    void checkvector(vector<vector<int>>& intervals, int i, int j){
        if(j >= intervals.size()){
            return ;
        }
        if(intervals[i][1] >= intervals[j][0]){
            intervals[i][1] = max(intervals[i][1], intervals[j][1]);
            intervals.erase(intervals.begin()+j);
            checkvector(intervals, i, j);
        }else{
            checkvector(intervals, i + 1, j + 1);
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), sortFn());
        checkvector(intervals, 0, 1);
        return intervals;
    }
*/