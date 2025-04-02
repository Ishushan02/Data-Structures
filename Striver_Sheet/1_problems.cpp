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