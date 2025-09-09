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

/*
    1776. Car Fleet II
    (https://leetcode.com/problems/car-fleet-ii/)

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<int> timereq(n, -1);
        stack<int> st;
        vector<double> ans(n, -1.000);

        for(int i=n-1; i >= 0; i-- ){
            int pos = cars[i][0];
            int spd = cars[i][1];
            // double time = (double)pos/(double)spd;
            while(!st.empty() && cars[st.top()][1] >= spd){
                st.pop();
            }
            
            while(!st.empty()){
                int idx = st.top();
                int dist = cars[idx][0] - cars[i][0];
                int v = abs(cars[idx][1] - cars[i][1]);
                double t = dist/(double)v;

                if(ans[idx] == -1 || t < ans[idx]){
                    ans[i] = t;
                    break;
                }
                st.pop();
            }

            st.push(i);
        }


        return ans;
    }
*/

/*
    402. Remove K Digits
    (https://leetcode.com/problems/remove-k-digits/)

    string removeKdigits(string &num, int k) {

        stack<char> st;

        for(int i = 0; i < num.length(); i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k -= 1;
            }
            st.push(num[i]);
        }

        while(!st.empty() && k != 0){
            st.pop();
            k -= 1;
        }

        string tempans;
        while(!st.empty()){
            tempans += st.top();  
            st.pop();
        }

        reverse(tempans.begin(), tempans.end());
    
        int i = 0;
        while(i < tempans.length() && tempans[i] == '0'){
            i += 1;
        }

        string ans = tempans.substr(i);
        if(ans == "") ans = "0";
        return ans;
    }
*/

/*

    int longestValidParentheses(string s) {
        stack<int> st;
        int maxCount = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }else{
                    maxCount = max(maxCount, i - st.top());
                }
                
            }
        }

        return maxCount;
    }
*/


/*
    456. 132 Pattern
    (https://leetcode.com/problems/132-pattern/)

    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int third = -1e9;
        for(int i =  nums.size() -1 ; i >= 0; i--){
            
            if(third > nums[i]) return true;

            while(!st.empty() && st.top() < nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
        
*/