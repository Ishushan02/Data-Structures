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