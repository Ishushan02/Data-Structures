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

    402. Remove K Digits
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