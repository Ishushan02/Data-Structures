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