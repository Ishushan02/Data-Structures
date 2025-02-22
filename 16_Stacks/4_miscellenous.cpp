/*
    3174. Clear Digits
    (https://leetcode.com/problems/clear-digits/description/)

    string clearDigits(string s) {
        
        stack<char> st;
        int i = 0;

        while(i < s.length()){

            if(isdigit(s[i])){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
            i++;
        }

        string ans;

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

*/

/*
    2696. Minimum String Length After Removing Substrings
    (https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/)

    int minLength(string s) {
        
        stack<char> st;
        int i = 0;

        while(i < s.length()){
            
            if(s[i] == 'B' && !st.empty() && st.top() == 'A'){
                st.pop(); // AB
            }else if(s[i] == 'D' && !st.empty() && st.top() == 'C'){
                st.pop(); // CD
            }else{
                st.push(s[i]);
            }
            i++;
            
        }

        

        return st.size();
    }

*/

/*
    1614. Maximum Nesting Depth of the Parentheses
    (https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/)

    int maxDepth(string s) {
        int maxSize = 0;
        stack<char> st;

        int i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                st.push(s[i]);
                int n = st.size();
                maxSize = max(n, maxSize);
            }else{
                if(s[i] == ')'){
                    st.pop();
                }
            }
            i++;
        }

        return maxSize;
    }

*/

/*
    2000. Reverse Prefix of Word
    (https://leetcode.com/problems/reverse-prefix-of-word/description/)

    string reversePrefix(string word, char ch) {
        
        int i = 0;
        stack<char> st;
        bool isPresent = false;

        while(i < word.length()){
            st.push(word[i]);
            if(word[i] == ch){
                isPresent = true;
                break;
            }
            i++;
        }

        if(!isPresent){
            return word;
        }

        string ans;

        while(!st.empty()){
            // cout << st.top() << " : " << ans<< endl;
            ans += st.top();
            st.pop();
        }

        i++;
        while(i < word.length()){
            ans += word[i];
            i++;
        }

        return ans;
    }

*/

/*
    1598. Crawler Log Folder
    (https://leetcode.com/problems/crawler-log-folder/description/)

    int minOperations(vector<string>& logs) {
        
        stack<string> st;
        int i = 0;

        while(i < logs.size()){
            if(logs[i] == "../"){
                if(!st.empty()){
                    st.pop();
                }
            }else if(logs[i] != "./"){
                st.push(logs[i]);
            }
            i++;
        }

        return st.size();
    }

*/

/*
    1544. Make The String Great
    (https://leetcode.com/problems/make-the-string-great/)

    string makeGood(string s) {
        
        stack<char> st;
        int i = 0;

        while(i < s.length()){
            char c = s[i];
            // cout << i << endl;
            char topchar;
            if(st.size() > 0){
                topchar = st.top();
            }
            
            int a = (topchar - '0') - (c - '0');
            // 32 because the difference between same char small and large is 32
            if((a == 32 || a == -32) && !st.empty()){
                st.pop();
            }else{
                st.push(c);
            }            
        
            i++;
        }

        string ans;

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

*/

/*
    1021. Remove Outermost Parentheses
    (https://leetcode.com/problems/remove-outermost-parentheses/description/)

    string removeOuterParentheses(string s) {
        
        int open = 0;
        int close = 0;

        int i = 0;
        string mid;
        vector<string> partitions;

        while(i < s.length()){

            if(s[i] == '('){
                open++;
            }

            if(s[i] == ')'){
                close++;
            }
            mid += s[i];

            if(open != 0 && (open == close)){
                partitions.push_back(mid);
                open = 0;
                close = 0;
                mid = "";
            }

            i++;
        }

        string ans;
        for(int i = 0; i < partitions.size(); i++){
            string curr = partitions[i];
            curr.erase(0, 1);
            curr.erase(curr.length()-1, 1);
            // cout << curr << endl;
            ans += curr;
        }

        return ans;
    }

*/

/*
    897. Increasing Order Search Tree
    (https://leetcode.com/problems/increasing-order-search-tree/description/)

    void inOrderedTraversal(TreeNode* root, TreeNode* &ansNode, TreeNode* &ansHead){
        if(root == NULL){
            return ;
        }

        
        inOrderedTraversal(root->left, ansNode, ansHead);
        TreeNode* newNode = new TreeNode(root->val);
        if(ansNode == NULL){
            ansNode = newNode;
            ansHead = newNode;
        }else{
            ansNode->right = newNode;
            ansNode = ansNode->right;
        }
        
        inOrderedTraversal(root->right, ansNode, ansHead);

    }

    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* ansNode = NULL;
        TreeNode* ansHead = NULL;

        inOrderedTraversal(root, ansNode, ansHead);

        return ansHead;
    }

*/

/*
    844. Backspace String Compare
    (https://leetcode.com/problems/backspace-string-compare/description/)

    string procedure(string s){
        int i = 0;
        stack<char> st1;
        
        while(i < s.length()){
            if(s[i] == '#'){
                if(st1.size()>0){
                    st1.pop();
                }
            }else{
                st1.push(s[i]);
            }
            i++;
        }

        string s1;

        while(!st1.empty()){
            s1 = st1.top() + s1;
            st1.pop();
        }

        return s1;
    }

    bool backspaceCompare(string s, string t) {
        
        stack<char> st1;
        stack<char> st2;
        
        string s1 = procedure(s);
        string s2 = procedure(t);
        
        return s1 == s2;
    }
        
*/