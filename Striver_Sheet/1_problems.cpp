/* 
    Problem 1
    1. Two Sum
    (https://leetcode.com/problems/two-sum/)

    struct comp{
        bool operator()(pair<int, int> &A, pair<int, int> &B){
            return A.second < B.second;
        }
    };

    int binarySearch(int n, vector<pair<int, int>> &dataPair, int key, int i){
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(dataPair[mid].second == key){
                if(dataPair[mid].first == i){
                    if(mid - 1 >= 0 && dataPair[mid-1].second == key){
                        return dataPair[mid-1].first;
                    }
                    if(mid + 1 < n && dataPair[mid+1].second == key){
                        return dataPair[mid+1].first;
                    }
                }

                return dataPair[mid].first;
            }else if(key > dataPair[mid].second){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> dataPair;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            dataPair.push_back({i, nums[i]});
        }

        sort(dataPair.begin(), dataPair.end(), comp());

        for(auto v: dataPair){
            int key = target - v.second;
            int i = v.first;
            int j = binarySearch(n, dataPair, key, i);
            if(j != -1){
                return {i, j};
            }
        }

        return {-1, -1};

    }
*/

/*

    Probelm 2
    2. Add Two Numbers
    (https://leetcode.com/problems/add-two-numbers/submissions/)

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansptr = ansHead;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while(temp1 || temp2){
            int a = 0;
            int b = 0;
            if(temp1 != NULL){
                a = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                b = temp2->val;
                temp2 = temp2->next;
            }

            int sum = a + b + carry;
            carry = sum / 10;
            int value = sum % 10;

            ListNode* newNode = new ListNode(value);
            ansptr->next = newNode;
            ansptr = ansptr->next;
        }

        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            ansptr->next = newNode;
            ansptr = ansptr->next;
        }

        return ansHead->next;
    }
*/

/*
    Probelm 3
    3. Longest Substring Without Repeating Characters
    (https://leetcode.com/problems/longest-substring-without-repeating-characters/)

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }

        int i = 0;
        int j = 0;
        unordered_map<char, bool> presentChar;
        string temp;
        int maxAns = 0;

        while(i < n && j < n){

            if(presentChar[s[j]] == false){
                presentChar[s[j]] = true;
                temp += s[j];
                int k = temp.length();
                maxAns = max(maxAns, k);
                j++;
            }else{
                i++;
                j = i;
                temp = "";
                presentChar.clear();
            }
        }

        return maxAns;
    }

*/

/*
    Problem 4
    5. Longest Palindromic Substring
    (https://leetcode.com/problems/longest-palindromic-substring/)

    pair<int, string> getPalindromicCount(int i, int j, string &s, int n){
        int count = 0;
        string ans;
        if(i == j && s[i] == s[j]){
            ans += s[i];
            i--;
            j++;
            count = 1;
        }

        while(i >= 0 && j < n && s[i] == s[j]){
            ans = s[i] + ans;
            ans = ans + s[j];
            count += 2;
            i--;
            j++;
        }

        return {count, ans};
    }

    string longestPalindrome(string s) {
        
        int n = s.length();
        string ans;
        int maxCount = 0;
        
        for(int centre = 0; centre < n; centre++){

            // odd
            pair<int, string> valStr = getPalindromicCount(centre, centre, s, n);
            if(maxCount < valStr.first){
                ans = valStr.second;
                maxCount = valStr.first;
            }
            // even
            if(centre+1 < n){
                valStr = getPalindromicCount(centre, centre+1, s, n);
                if(maxCount < valStr.first){
                    ans = valStr.second;
                    maxCount = valStr.first;
                }
            }
        }

        return ans;
    }
*/

/*
    Problem 5
    987. Vertical Order Traversal of a Binary Tree
    (https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

    struct comp{
        bool operator()(pair<int, pair<int, TreeNode*>> &A, pair<int, pair<int, TreeNode*>>&B){
            if(A.first < B.first){
                return true;
            }else if(A.first == B.first){
                if(A.second.first < B.second.first){
                    return true;
                }else if(A.second.first == B.second.first){
                    return A.second.second->val < B.second.second->val;
                }else{
                    return false;
                }
            }else{
                return false;
            }
            
        }
    };

    void traversal(TreeNode* root, int height, int breadth, vector<pair<int, pair<int, TreeNode*>>> &dataValue){
        if(root == NULL){
            return ;
        }

        // cout <<  root->val<< " , "<< breadth << endl;
        dataValue.push_back({height, {breadth, root}});
        traversal(root->left, height - 1, breadth+1, dataValue);
        traversal(root->right, height + 1, breadth+1, dataValue);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<pair<int, pair<int, TreeNode*>>> dataValue;
        traversal(root, 0, 0, dataValue);
        map<int, vector<int>> dataMap;
        sort(dataValue.begin(), dataValue.end(), comp());

        for(auto v:dataValue){
            dataMap[v.first].push_back(v.second.second->val);
            // cout << v.second.second->val << " ";
        }

        for(auto &[key, val]: dataMap){
            ans.push_back(val);
        }

        return ans;
    }
*/

/*
    Problem 6
    8. String to Integer (atoi)
    (https://leetcode.com/problems/string-to-integer-atoi/)

    int myAtoi(string s) {

        bool isNegative = false;
        long long int n = 0;
        bool numStarted = false;

        int i = 0;
        bool signPres = false;
        while(i < s.length()){
            if(s[i] != ' '){
                if(s[i] == '-'){
                    isNegative = true;
                    i++;
                    break;
                }else if(s[i] == '+'){
                    i++;
                    break;
                }else if(s[i] >= '0' && s[i] <= '9'){
                    break;
                }else{
                    return 0;
                }
            }
            i++;
        }

        // i = 0;
        while(i < s.length()){
            char c = s[i];
            if(c >= '0' && c <= '9'){
                int j = i;
                c = s[j];
                while(j < s.length() && s[j] >= '0' && s[j] <= '9'){
                    // cout << " * " << s[j] << " , " << n << endl;
                    n = n * 10 + (s[j] - '0');
                    j++;
                    
                    if(n >= INT_MAX || n < INT_MIN){
                        break;
                    }
                }
                
                
                break;
            }else{
                return 0;
            }
            i++;
        }

        if(isNegative){
            n = n * -1;
        }

        if(n > INT_MAX - 1 ){
            return INT_MAX;
        }
        if(n < INT_MIN){
            return INT_MIN;
        }
        return n;
    }

*/

/*
    Problem 7
    994. Rotting Oranges
    (https://leetcode.com/problems/rotting-oranges/)

    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh = 0;
        queue<pair<int, int>> que;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;
        if(fresh == 0){
            return time;
        }
        while(!que.empty()){
            int qSize = que.size();

            for(int k = 0; k < qSize; k++){
                pair<int, int> idx = que.front();
                que.pop();
                int i = idx.first;
                int j = idx.second;

                if(i + 1 < m && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    fresh--;
                    que.push({i+1, j});
                }

                if(j + 1 < n && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    fresh--;
                    que.push({i, j+1});
                }
                if(i - 1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    fresh--;
                    que.push({i-1, j});
                }
                if(j - 1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    fresh--;
                    que.push({i, j-1});
                }

            }
            time++;
        }

        if(fresh == 0){
            return time-1;
        }

        return -1;
    }

*/

/*

    Problem 8
    13. Roman to Integer
    (https://leetcode.com/problems/roman-to-integer/)

    int romanToInt(string s) {
        unordered_map<string, int> romanNum{
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"VX", 40},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000},
        };

        int i = 0;
        int num = 0;

        int n = s.length();

        while(i < n){

            string temp;
            temp +=  s[i];
            string curr;
            curr += s[i];
            int j = i + 1;
            bool rev = false;
            while(j < n ){
                string t;
                t += s[j];
                if(romanNum[t] > romanNum[curr]){
                    rev = true;
                    temp += s[j];
                    curr = s[j];
                    j++;
                }else{
                    break;
                }
                
            }
            // cout << romanNum[temp] << endl;
            num += romanNum[temp];

            i = j;
        }


        return num;
    }

*/

/*
    Problem 9
    14. Longest Common Prefix
    (https://leetcode.com/problems/longest-common-prefix/)

    string longestCommonPrefix(vector<string>& strs) {
        
        string ans;
        ans = strs[0];
        int n = strs.size();
        int i = 0;
        while(i < n){
            string temp = strs[i];
            int j = 0;
            int k = 0;
            string tempAns = "";
            while(j < temp.length() && k < ans.length() && ans[k] == temp[j]){
                tempAns += temp[j];
                j++;
                k++;
            }
            ans = tempAns;
            if(tempAns == ""){
                return "";
            }
            i++;
        }

        return ans;

    }

*/


/*
    Problem 10
    15. 3Sum
    (https://leetcode.com/problems/3sum/)

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tempVec(nums.begin(), nums.end());
        // vector<vector<int>> res;
        set<vector<int>> ans;

        for(int i = 0; i<nums.size(); i++){
            int val = nums[i];
            tempVec.erase(tempVec.begin() + i);
            int j = 0;
            int k = tempVec.size()-1;

            while(j < k){
                int sum = nums[i] + tempVec[j] + tempVec[k];
                if(sum == 0){
                    if(nums[i] <= tempVec[j]){
                        ans.insert({nums[i], tempVec[j], tempVec[k]});
                    }else if(nums[i] > tempVec[k]){
                        ans.insert({tempVec[j], tempVec[k], nums[i]});
                    }else{
                        ans.insert({tempVec[j], nums[i], tempVec[k]});
                    }
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
            tempVec.insert(tempVec.begin() + i, val);
        }

        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }

*/

/*
    Problem 11
    18. 4Sum
    (https://leetcode.com/problems/4sum/)

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){
            return {};
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;

        for(int a = 0; a < n; a++){
            if(a > 0 && nums[a] == nums[a-1]){
                continue;
            }
            for(int b = a + 1; b < n; b++){
                int c = b + 1;
                int d = n - 1;
                while(c < d){
                    // cout << c << " , " << d << endl;
                    long long int sum = (long long int)nums[a] + (long long int)nums[b] + (long long int)nums[c] + (long long int)nums[d];

                    if(sum == target){
                        ans.insert({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                    }else if(sum > target){
                        d--;
                    }else{
                        c++;
                    }
                }

            }
        }

        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }

*/

/*
    Problem 12
    19. Remove Nth Node From End of List
    (https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;

        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }
        int todelete = len - n;
        if(todelete <= 0){
            return head->next;
        }

        temp = head;
        while(temp && todelete-1){
            temp = temp->next;
            todelete--;
        }

        if(temp != NULL){
            if(temp->next){
                if(temp->next->next){
                    temp->next = temp->next->next;
                }else{
                    temp->next = NULL;
                }
            }
        }else{
            head->next;
        }

        return head;
    }

*/

/*
    Problem 13
    20. Valid Parentheses
    (https://leetcode.com/problems/valid-parentheses/)

    bool isValid(string s) {
        
        int i = 0;
        stack<char> st;

        while(i < s.length()){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                if(s[i] == '}' && st.top() == '{'){
                    st.pop();
                }else if(s[i] == ')' && st.top() == '('){
                    st.pop();
                }else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }
            i++;
        }

        if(!st.empty()){
            return false;
        }

        return true;

    }

*/

/*
    Problem 14
    21. Merge Two Sorted Lists
    (https://leetcode.com/problems/merge-two-sorted-lists/)

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* ansHead = new ListNode(0);
        ListNode* ansptr = ansHead;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                ListNode* nexNode = temp1->next;
                ansptr->next = temp1;
                ansptr = ansptr->next;
                temp1 = nexNode;
            }else if(temp2->val < temp1->val){
                ListNode* nexNode = temp2->next;
                ansptr->next = temp2;
                ansptr = ansptr->next;
                temp2 = nexNode;
            }else{
                ListNode* nexNode1 = temp1->next;
                ListNode* nexNode2 = temp2->next;
                ansptr->next = temp1;
                ansptr = ansptr->next;
                ansptr->next = temp2;
                ansptr = ansptr->next;

                temp1 = nexNode1;
                temp2 = nexNode2;
            }
        }

        while(temp1){
            ansptr->next = temp1;
            ansptr = ansptr->next;
            temp1 = temp1->next;
        }

        while(temp2){
            ansptr->next = temp2;
            ansptr = ansptr->next;
            temp2 = temp2->next;
        }

        return ansHead->next;

    }
        
*/

/*
    Problem 15
    25. Reverse Nodes in k-Group
    (https://leetcode.com/problems/reverse-nodes-in-k-group/)

    ListNode* reverseList(ListNode* head, ListNode* tail){
        ListNode* reverse = NULL;
        ListNode* temp = head;

        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = reverse;
            reverse = temp;
            if(temp == tail){
                break;
            }
            temp = nextNode; 
        }

        return reverse;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len += 1;
            temp = temp->next;
        }

        // cout << " Len: " << len << endl;
        if(k > len){
            return head;
        }
        
        ListNode* ansHead = new ListNode(0);
        ListNode* ansptr = ansHead;
        temp = head;
        int i = 1;
        ListNode* start = head;
        ListNode* end = NULL;
        int itr = 0;

        while(temp){
            // cout << temp->val << endl;
            ListNode* nextNode = temp->next;

            

            if(i == k){
                end = temp;
                ListNode* reversed = reverseList(start, end);
                ansptr->next = reversed;
                while(ansptr->next){
                    ansptr = ansptr->next;
                }
                
                start = nextNode;
                i = 1;
            }else{
                i++;
            }

            itr++;
            temp = nextNode;
        }

        ansptr->next = start;

        return ansHead->next;

    }

*/

/*
    Problem 16
    26. Remove Duplicates from Sorted Array
    (https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        while(j < n){

            if(nums[i] == nums[j]){
                j++;
            }else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        

        return i+1;
    }
*/

/*
    Problem 17
    1008. Construct Binary Search Tree from Preorder Traversal
    (https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

    TreeNode* constructTree(int n, vector<int>& preorder, int start, int end){
        if(start > end){
            return NULL;
        }

        // cout << preorder[start] << " , " << preorder[end] << endl;

        TreeNode* root = new TreeNode(preorder[start]);

        int rptr = start;
        while(rptr <= end){
            if(preorder[rptr] > preorder[start]){
                break;
            }
            rptr++;
        }

    
        root->left = constructTree(n, preorder, start + 1, rptr - 1);
        root->right = constructTree(n, preorder, rptr, end);
            
        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        // int
        return constructTree(n, preorder, 0, n-1);

    }

*/

/*
    Problem 18
    28. Find the Index of the First Occurrence in a String
    (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

    int strStr(string haystack, string needle) {
        
        int i = 0;
        int j = 0;

        while(i < haystack.length()){

            int j = i;
            int k = 0;
            while(k < needle.length() && j < haystack.length() && haystack[j] == needle[k]){
                j++;
                k++;
            }

            if(k >= needle.length()){
                return i;
            }

            i++;
        }

        return -1;
    }

*/

/*  
    Problem 19
    543. Diameter of Binary Tree
    (https://leetcode.com/problems/diameter-of-binary-tree/)

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh, rh) + 1;
    }

    void diameter(TreeNode* root, int &ans){
        if(root == NULL){
            return ;
        }
        
        int diam = height(root->left) + height(root->right);
        ans = max(ans, diam);

        diameter(root->left, ans);
        diameter(root->right, ans);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }

*/

/*
    Problem 20
    37. Sudoku Solver
    (https://leetcode.com/problems/sudoku-solver/)

    bool checkPlace(vector<vector<char>>& board, char num, int i, int j){

        for(int row = 0; row < 9; row++){
            if(board[row][j] == num){
                return false;
            }
        }

        for(int col = 0; col < 9; col++){
            if(board[i][col] == num){
                return false;
            }
        }

        int rrow = 0;
        int ccol = 0;

        if(i >= 0 && i < 3)rrow = 0;
        if(i >= 3 && i < 6)rrow = 3;
        if(i >= 6 && i < 9)rrow = 6;
        if(j >= 0 && j < 3)ccol = 0;
        if(j >= 3 && j < 6)ccol = 3;
        if(j >= 6 && j < 9)ccol = 6;

        for(int p = rrow; p < rrow+3; p++){
            for(int q = ccol; q < ccol+3; q++){
                if(board[p][q] == num){
                    return false;
                }
            }
        }

        return true;

    }


    bool placeChar(vector<vector<char>>& board){

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.'){

                    for(int k = '1'; k <= '9'; k++){
                        if(checkPlace(board, k, i, j)){

                            board[i][j] = k;
                            bool tempAns = placeChar(board);
                            if(tempAns){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        placeChar(board);
    }
        
*/

/*
    Problem 21
    38. Count and Say
    (https://leetcode.com/problems/count-and-say/)

    string compression(string &s){
        string ans;
        int i = 0;
        int j = 0;

        int tempCount = 0;
        while(j < s.length()){
            if(s[i]==s[j]){
                tempCount++;
            }else{
                ans += to_string(tempCount) + s[i];
                i = j;
                tempCount = 1;
            }
            j++;
        }

        ans += to_string(tempCount) + s[i];

        return ans;
    }

    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string ans = countAndSay(n - 1);
        return compression(ans);
    }
*/

/*
    Problem 22
    39. Combination Sum
    (https://leetcode.com/problems/combination-sum/description/)

    void allPossibleSum(vector<int>& candidates, int j, vector<int> temp, int target, int tempSum, vector<vector<int>>& res){
        if(tempSum == target){
            res.push_back(temp);
            return ;
        }

        int prev = -1;
        for(int i = j; i < candidates.size(); i++){
            if(tempSum + candidates[i] <= target){
                temp.push_back(candidates[i]);
                allPossibleSum(candidates, i, temp, target, tempSum + candidates[i], res);
                temp.pop_back();
            }

            prev = i;
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        allPossibleSum(candidates, 0, temp, target, 0, ans);
        return ans;
    }
*/


/*
    Problem 23
    40. Combination Sum II
    (https://leetcode.com/problems/combination-sum-ii/)

    void allPossibilities(vector<int>& candidates, int j, int target, int tempSum, vector<int> &temp, vector<vector<int>> &ans){
        if(tempSum == target){
            ans.push_back(temp);
            return ;
        }

        for(int i = j; i < candidates.size(); i++){
            if (i > j && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if(tempSum + candidates[i] <= target){
                temp.push_back(candidates[i]);
                allPossibilities(candidates, i+1, target, tempSum + candidates[i], temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int j = 0;
        sort(candidates.begin(), candidates.end());
        allPossibilities(candidates, 0, target, 0, temp, ans);

        return ans;

    }
*/

/*
    Problem 24
    46. Permutations
    (https://leetcode.com/problems/permutations/)

    void permutations(vector<int>& nums, int j, vector<vector<int>> &ans){
        if(j >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = j; i < nums.size(); i++){
            swap(nums[i], nums[j]);
            permutations(nums, j+1, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        permutations(nums, 0, ans);

        return ans;
    }
        
*/