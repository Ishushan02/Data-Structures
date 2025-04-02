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