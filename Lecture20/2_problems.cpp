/*

    Good Question 
    Count the Reversals
    (https://www.geeksforgeeks.org/problems/count-the-reversals0401/1)

    int countRev (string s)
    {
    // your code here
    stack<char> st;
    
    
    if(s.length()%2 != 0){
        return -1;
    }
    int ans = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{'){
            st.push(s[i]);

        }else{
            
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
            
        }
    }
    
    while(!st.empty()){
        char elem1 = st.top();
        st.pop();
        char elem2 = st.top();
        st.pop();
        
        if(elem1 == elem2){
            ans += 1;
        }else{
            ans += 2;
        }
        
    }
    
    return ans;
    
    }

*/