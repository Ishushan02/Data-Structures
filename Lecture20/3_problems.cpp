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

    void reversest(stack<char>& st, stack<char>& ansst){
        if(st.empty()){
            return;
        }
        char topelem = st.top();
        st.pop();
        ansst.push(topelem);
        reversest(st, ansst);
        
    }

    string removeKdigits(string num, int k) {

        // if(num.length() ==1 and k == 1){
        //     return "0";
        // }
        string ans;
        stack <char> st;

        int i = 0;
        while(i < num.length()){
            char curr = num[i];

            while(!st.empty() && st.top() > curr && k > 0){
                st.pop();
                k--;
            }

            st.push(curr);
            i++;
        }

        // for remaining k's
        while(!st.empty() && k != 0){
            st.pop();
            k--;
        }

        stack<char> ansst;
        reversest(st, ansst);

        // removing all leading 0's

        while(!ansst.empty() && ansst.top() == '0'){
            ansst.pop();
        }

        if(ansst.empty()){
            return "0";
        }
        
        while(!ansst.empty()){
            ans += ansst.top();
            ansst.pop();

        }

        return ans;
    }
*/