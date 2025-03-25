/*
    BLIND 75
    The Notebook Questions
    (https://leetcode.com/problem-list/oizxjoit/)
*/

/*
    Problem 1
    128. Longest Consecutive Sequence
    (https://leetcode.com/problems/longest-consecutive-sequence/description/)

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        map<int, bool> mapVal;
        for(auto v:nums){
            mapVal[v] = true;
        }

        int maxConsecutive = 0;
        int valCount = 0;
        long long int prev = -100000000000;
        for(auto &[key, val]: mapVal){
            if(prev == 100000000000){
                valCount = 1;
                maxConsecutive = max(maxConsecutive, valCount);
            }else if(prev + 1 == key){
                valCount += 1;
                maxConsecutive = max(maxConsecutive, valCount);
            }else{
                valCount = 0;
            }
            prev = key;
        }

        return maxConsecutive+1;
    }
*/

/*
    Problem 2
    1. Two Sum
    (https://leetcode.com/problems/two-sum/description/)

    struct valueSort{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> valuePair;
        for(int i = 0; i < nums.size(); i++){
            valuePair.push_back({nums[i], i});
        }

        sort(valuePair.begin(), valuePair.end(), valueSort());

        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){  
            pair<int, int> num1 = valuePair[i];
            pair<int, int> num2 = valuePair[j];
            int sumVal = num1.first + num2.first;

            if(sumVal == target){
                return {num1.second, num2.second};
            }

            if(sumVal > target){
                j--;
            }else{
                i++;
            }

        }

        return {0, 1};

    }

*/

/*
    Problem 3
    3. Longest Substring Without Repeating Characters
    (https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

    int lengthOfLongestSubstring(string s) {
        int uniqueMax = 0;
        int i = 0;
        unordered_map<char, bool> charCount;
        while(i < s.length()){
            int curridx = i;
            int j = i;
            int count = 0;
            while(j < s.length() && !(charCount[s[j]])){
                charCount[s[j]] = true;
                count++;
                j++;
            }
            charCount.clear();
            uniqueMax = max(uniqueMax, count);
            i = curridx + 1;
        }        

        return uniqueMax;
    }

*/

/*
    Problem 4
    5. Longest Palindromic Substring
    (https://leetcode.com/problems/longest-palindromic-substring/description/)

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
    133. Clone Graph
    (https://leetcode.com/problems/clone-graph/description/)

    void buildMap(Node* node, map<int, vector<int>> &nodeMap){
        if(node == NULL || nodeMap.find(node->val) != nodeMap.end()){
            return ;
        }

        nodeMap[node->val] = {};
        for(auto v: node->neighbors){
            nodeMap[node->val].push_back(v->val);
            buildMap(v, nodeMap);
        }
        
    }

    Node* cloneGraph(Node* node) {
        map<int, vector<int>> nodeMap;
        buildMap(node, nodeMap);

        Node* ansNode = NULL;
        unordered_map<int, Node*> allNodes;

        for(auto &[key, value]:nodeMap){
            // cout << key << ": ";
            Node* newNode = NULL;
            if(allNodes.find(key) == allNodes.end()){
                newNode = new Node(key);
                allNodes[key] = newNode;
            }else{
                newNode = allNodes[key];
            }

            if(ansNode == NULL){
                ansNode = newNode;
            }

            for(auto v:value){
                if(allNodes.find(v) == allNodes.end()){
                    Node* tempNode = new Node(v);
                    allNodes[v] = tempNode;
                    newNode->neighbors.push_back(tempNode);
                }else{
                    Node* tempNode = allNodes[v];
                    newNode->neighbors.push_back(tempNode);
                }

            }
        }

        
        return ansNode;
    }
*/

/*
    Problem 6
    647. Palindromic Substrings
    (https://leetcode.com/problems/palindromic-substrings/)

    int substrings(string s, int i, int j, int count){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
        
    }

    int countSubstrings(string s) {
        
        int count = 0;
        for(int centre = 0; centre < s.length(); centre++){
            // odd substr
            count += substrings(s, centre, centre, 0);

            //even substr
            count += substrings(s, centre, centre+1, 0);

        }

        return count;

    }
*/

/*

    Problem 7
    141. Linked List Cycle
    (https://leetcode.com/problems/linked-list-cycle/submissions/)

    bool hasCycle(ListNode *head) {
        
        while(head){
            if(head->val == -1000000){
                return true;
            }
            head->val = -1000000;

            head = head->next;
        }

        return false;
    }

*/

/*
    Problem 8
    268. Missing Number
    (https://leetcode.com/problems/missing-number/submissions/)

    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = n * (n+1)/2;
        int totalSum = 0;
        for(auto v:nums){
            totalSum += v;
        }

        return sum - totalSum;
    }
        
*/

/*
    Problem 9
    11. Container With Most Water
    (https://leetcode.com/problems/container-with-most-water/)
    // the idea is we move from min because we expect the next one will have higher length, hence higher Area

    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int maxArea = 0;
        int i = 0;
        int j = n - 1;

        while(i < j){
            int l1 = height[i];
            int l2 = height[j];
            maxArea = max(maxArea, min(l1, l2) * (j - i));
            if(l1 < l2){
                i++;
            }else{
                j--;
            }

        }

        return maxArea;
    }

*/

/*
    Problem 10
    139. Word Break
    (https://leetcode.com/problems/word-break/)

    bool checkPresence(string &s, int i, unordered_map<string, bool> &wordMap, vector<int> &dpArr){
        if(i >= s.length()){
            return true;
        }

        if(dpArr[i] != -1){
            return dpArr[i];
        }

        bool flag = false;
        for(int j = i; j < s.length(); j++){
            string substring = s.substr(i, j - i +1);
            if(wordMap[substring] && checkPresence(s, j+1, wordMap, dpArr)){
                flag = true;
            }
        }

        dpArr[i] = flag;
        return dpArr[i];
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> wordMap;
        vector<int> dpArr(s.length(), -1);

        for(auto word:wordDict){
            wordMap[word] = true;
        }

        return checkPresence(s, 0, wordMap, dpArr);
    }
*/