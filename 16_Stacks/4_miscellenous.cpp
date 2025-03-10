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

/*
    589. N-ary Tree Preorder Traversal
    (https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)

    void preOrderNArr(Node* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        Node* curr = root;
        ans.push_back(curr->val);
        for(Node* child:curr->children){
            // cout << child->val << endl;
            preOrderNArr(child, ans);
        }
        
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;        
        preOrderNArr(root, ans);

        return ans;
    }

*/

/*
    590. N-ary Tree Postorder Traversal
    (https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/)

    void postOrderNArr(Node* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        Node* curr = root;
        
        for(Node* child:curr->children){
            postOrderNArr(child, ans);
        }

        ans.push_back(curr->val);
        
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;        
        postOrderNArr(root, ans);

        return ans;
    }

*/

/*
    682. Baseball Game
    (https://leetcode.com/problems/baseball-game/description/)

    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        int i = 0;
        while(i < operations.size()){

            string currop = operations[i];

            if(currop == "C"){
                // cout << "C: " << st.top() << endl;
                st.pop();
            }else if(currop == "D"){
                    // cout << "D: " << 2 * st.top() << endl;
                    // int a = st.top();
                    st.push(2 * st.top());

            }else if(currop == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();

                    // cout << "+: " << a << " and " << b << " is "<< a + b << endl;
                    st.push(b);
                    st.push(a);
                    st.push(b + a);
            }else{
                // cout << "Num: " << currop << endl;
                st.push(stoi(currop));
            }
            i++;
        }

        int ans = 0;

        while(!st.empty()){
            // cout << st.top() << endl;
            ans += st.top();
            st.pop();
        }

        return ans;

    }
        
*/


/*
    150. Evaluate Reverse Polish Notation
    (https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){

            if(tokens[i] == "+"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 + n1);
            }else if(tokens[i] == "-"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 - n1);
            }else if(tokens[i] == "*"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 * n1);
            }else if(tokens[i] == "/"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 / n1);
            }else{
                int v = stoi(tokens[i]);
                st.push(v);
            }
        }

        return st.top();
    }

*/

/*  
    946. Validate Stack Sequences
    (https://leetcode.com/problems/validate-stack-sequences/description/)

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i = 0;
        int j = 0;
        int n = pushed.size();
        stack<int> st;
        while(i < n && j < n){

            while(i < n && pushed[i] != popped[j]){
                st.push(pushed[i]);
                i++;
            }
            if(i >= n){
                break;
            }
            st.push(pushed[i]);
            i++;
            
            while(!st.empty() && (st.top() == popped[j])){
                st.pop();
                j++;
            }
        }

        if(st.empty()){
            return true;
        }

        return false;
    }
*/

/*

// Method 2 is better, but Method 1 gives better details

    316. Remove Duplicate Letters
    (https://leetcode.com/problems/remove-duplicate-letters/description/)

    && 

    1081. Smallest Subsequence of Distinct Characters
    (https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/)

    
    string removeDuplicateLetters(string s) {
        
        unordered_map<char, int> charMap;
        unordered_map<char, int> charVisited;

        int count = 0;
        for(auto v: s){
            charMap[v]++;
            charVisited[v] = true;
        }

        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            char curr = s[i];
            if(st.empty()){
                st.push(curr);
                charMap[curr]--;
                charVisited[curr] = false;
            }else{
                char top = st.top();
                if(!st.empty() && charMap[top] > 0 && curr < top &&  charVisited[curr]){
                    while(!st.empty() && charMap[st.top()] > 0 && curr < st.top()){
                        charVisited[st.top()] = true;
                        st.pop();
                    }

                    st.push(curr);
                    charMap[curr]--;
                    charVisited[curr] = false;
                }else if(charMap[curr] > 0 && charVisited[curr]){
                    st.push(curr);
                    charMap[curr]--;
                    charVisited[curr] = false;
                }else{
                    charMap[curr]--;
                }
            }
        }   

        string ans;

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }




    Method 2

    string removeDuplicateLetters(string s) {
        
        unordered_map<char, int> charMap;
        unordered_map<char, int> charVisited;

        int count = 0;
        for(int i = 0; i < s.length(); i++){
            charMap[s[i]] = i;
            charVisited[s[i]] = false;
        }

        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            
            char currChar = s[i];
            if(st.empty() && !charVisited[currChar]){
                st.push(s[i]);
                charVisited[s[i]] = true;
            }else{
                char tos = st.top();
                
                if(currChar < tos && charMap[tos] > i && !charVisited[currChar]){

                    while(!st.empty() && currChar < st.top() && !charVisited[currChar] && charMap[st.top()] > i){
                        charVisited[st.top()] = false;
                        st.pop();
                    }
                    st.push(currChar);
                    charVisited[currChar] = true;
                }else if(!charVisited[currChar]){
                    st.push(currChar);
                    charVisited[currChar] = true;
                }
            }
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
    227. Basic Calculator II
    (https://leetcode.com/problems/basic-calculator-ii/)

    int calculate(string s) {
        
        stack<int> st;
        int i = 0;

        int j = 0;
        string t;
        while(j < s.length()){
            if(s[j] != ' '){
                t += s[j];
            }
            j++;
        }
        s = t;


        while(i < s.length()){

            if(s[i] == '+'|| s[i] == '-'){
                char op = s[i];
                i++;
                // int a = getDigit(s, i);
                int a = 0;
                while(isdigit(s[i])){
                    a = a * 10 + (s[i] - '0');
                    i++;
                }
                if(op == '-'){
                    st.push(-1 * a);
                }else{
                    st.push(a);
                }
            }else if(s[i] == '*' || s[i] == '/'){
                char op = s[i];
                i++;
                int tos = st.top();
                st.pop();
                int a = 0;
                while(isdigit(s[i])){
                    a = a * 10 + (s[i] - '0');
                    i++;
                }
                if(op == '*'){
                    st.push(tos * a);
                }else{
                    st.push(tos / a);
                }

            }else{
                int a = getDigit(s, i);
                st.push(a);
            }

        }

        int ans = 0;
        while(!st.empty()){
            // cout << st.top() << endl;
            ans += st.top();
            st.pop();
        }


        return ans;
    }

*/


/*
    1006. Clumsy Factorial
    (https://leetcode.com/problems/clumsy-factorial/description/)

    int clumsy(int n) {
        
        if(n == 1 || n == 2){
            return n;
        }
        int a = n;
        int b = n -1;

        stack<int> st;
        st.push(a * b);
        char op = '/';
        b--;
        while(b >= 1){
            
            // cout << tos << " , " << b << endl;
            if(op == '*'){
                int tos = st.top();
                st.pop();
                st.push(tos * b);
                op = '/';
            }else if(op == '/'){
                int tos = st.top();
                st.pop();
                st.push(tos / b);
                op = '+';
            }else if(op == '+'){
                st.push(b);
                op = '-';
            }else{
                st.push(-b);
                op = '*';
            }
            b--;
        }

        int ans = 0;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
        
*/