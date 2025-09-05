/*
    The Celebrity Problem
    (https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

    The one using Stacks
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> st;
        int n = mat.size();
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(i != j && mat[i][j] == 1){
                st.push(j);
            }else if(i != j && mat[j][i] == 1){
                st.push(i);
            }
            
            if(st.empty()) return -1;
        }
        
        int celeb = st.top();
        for(int i = 0; i < n; i++){
            if(i != celeb && mat[i][celeb] == 0){
                return -1;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i != celeb && mat[celeb][i] == 1){
                return -1;
            }
        }
        
        return celeb;
    }
        
*/