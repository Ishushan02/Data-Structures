/*
    739. Daily Temperatures (Good Question )
    (https://leetcode.com/problems/daily-temperatures/description/)

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){

            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }

*/



/*

    402. Remove K Digits (Good No. of Companies asked this questions)
    (https://leetcode.com/problems/remove-k-digits/description/)

    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i = 0; i < num.length(); i++){

            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() && k != 0){
            st.pop();
            k--;
        }

        if(st.empty()){
            return "0";
        }

        // reverse the stack
        stack<char> reversedst;

        while(!st.empty()){
            reversedst.push(st.top());
            st.pop();
        }

        // removing all leading 0's
        while(!reversedst.empty() && reversedst.top() == '0'){
            reversedst.pop();
        }

        if(reversedst.empty()){
            return "0";
        }

        // storing ans;
        string ans;
        while(!reversedst.empty()){
            ans += reversedst.top();
            reversedst.pop();
        }

        return ans;
    }
*/


/*
    921. Minimum Add to Make Parentheses Valid
    (https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

    int minAddToMakeValid(string s) {
        
        stack<char> val;
        int k = 0;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                val.push(s[i]);
            }else if(s[i] == ')' && !val.empty()){
                val.pop();
            }else{
                k++;
            }

        }
        cout << "k: " << k << " val: " << val.size() << endl;
        return val.size() + k ;
        // return k || val.size() ;
    }

*/

/*
    32. Longest Valid Parentheses // This is a Very Good Question
    (https://leetcode.com/problems/longest-valid-parentheses/)
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(-1); // for starting case
        bool continuous = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop(); // elements are popped

                if(st.empty()){
                    st.push(i); // such that last elem index is stored to count len
                                // this also means that it's invalid parenthesis
                }else{
                    int totLen = i - st.top(); // not doing + 1(for indexing) because prev-1 elem is being subtracted
                    ans = max(ans, totLen);
                }
            }
        }

        return ans;
    }
*/

/*  
        735. Asteroid Collision
        (https://leetcode.com/problems/asteroid-collision/)

        vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        vector<int> ans;

        for(auto ast:asteroids){
            bool destroy = false;
            if(ast > 0){
                // cout << ast << endl;
                st.push(ast);
            }else{
                if(st.empty() || st.top() < 0 ){
                    st.push(ast);
                }else{
                    // bombard
                    while(!st.empty() && st.top() > 0){
                        if(abs(ast) == st.top()){
                            destroy = true;
                            st.pop();
                            break;
                        }else if(abs(ast) > st.top()){
                            st.pop();
                        }else{
                            destroy = true;
                            break;
                        }
                    }

                    if(!destroy){
                        st.push(ast);
                    }

                }
            }
        }
        
        while(!st.empty()){
            // cout << st.top() << endl;
            ans.insert(ans.begin(), st.top());
            st.pop();
        }

        return ans;

    }
*/

/*
    1472. Design Browser History
    (https://leetcode.com/problems/design-browser-history/)

        class BrowserHistory {
    public:
    stack<string> browserstck;
    stack<string> forwardstck;
    BrowserHistory(string homepage) {
        browserstck.push(homepage);
    }
    
    void visit(string url) {
        browserstck.push(url);

        //given condition to clear forwstck
        while(!forwardstck.empty()){
            forwardstck.pop();
        }
    }
    
    string back(int steps) {
        int i = 0;
        // homepage will always be there in the browser stack so that 1 condition
        while(i < steps && browserstck.size()>1){
            forwardstck.push(browserstck.top());
            browserstck.pop();
            i = i + 1;
        }
        return browserstck.top();
    }
    
    string forward(int steps) {
        int i = 0;
        while(i < steps && !forwardstck.empty()){
            browserstck.push(forwardstck.top());
            forwardstck.pop();
            i = i + 1;
        }
        return browserstck.top();

    }
    };


*/