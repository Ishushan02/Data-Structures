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

/*

    So, the Idea is that, if you have a later occurence of a char, and if curre char is larger than top char
    then pop it out, also mark visited and not visited, if you are popping it mark it unvisited


    316. Remove Duplicate Letters
    (https://leetcode.com/problems/remove-duplicate-letters/)

    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOccurence;
        unordered_map<char, bool> present;
        for(int i = 0; i < s.length(); i++){
            lastOccurence[s[i]] = i;
        }

        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            if(present[s[i]] != 1){
                while(!st.empty() && lastOccurence[s[st.top()]] > i && s[i] < s[st.top()]){
                    present[s[st.top()]] = 0;
                    st.pop();
                }
                present[s[i]] = 1;
                st.push(i);
            }
        }

        string ans;

        while(!st.empty()){
            ans = s[st.top()] + ans;
            st.pop();
        }

        return ans;
    }

*/

/*
    227. Basic Calculator II
    (https://leetcode.com/problems/basic-calculator-ii/)

    int calculate(string s) {
        
        int i = 0;
        int n = s.length(); 
        string temp;
        while(i < n){
            if(s[i] == ' '){
                i += 1;
                continue;
            }else{
                temp += s[i];
                i += 1;
            }
        }
        

        s = temp;
        n = s.length();
        i = 0;
        // cout << s << endl;
        stack<int> st;
        while(i < n){

            if(s[i] == '/' || s[i] == '*'){
                int a = 0;
                char c = s[i];
                i += 1;
                while(i < n && isdigit(s[i])){
                    cout << s[i] << endl;
                    a = a * 10 + (s[i] - '0');
                    i += 1;
                }
                int top = st.top();
                st.pop();
                
                if(c == '*'){
                    st.push(top*a);
                }else{
                    st.push(top/a);
                }

            }else if(s[i] == '+' || s[i] == '-'){
                int a = 0;
                char c = s[i];
                i += 1;
                while(i < n && isdigit(s[i])){
                    a = a * 10 + (s[i] - '0');
                    i += 1;
                }
                
                if(c == '-'){
                    st.push(-1*a);
                }else{
                    st.push(a);
                }


            }else{
                int a = 0;

                while(i < n && isdigit(s[i])){
                    a = a * 10 + (s[i] - '0');
                    i += 1;
                }
                st.push(a);
            }

        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
        
*/

/*
    Very VERY Good Question
    907. Sum of Subarray Minimums (TLE)
    (https://leetcode.com/problems/sum-of-subarray-minimums/)

    // SIMILAR Question can be Sum Of SUbarray Maximums

    Efficient Method (Stacks)
    Procedure is, get the counts of each numbers in array that will contribute to the min sum of all Subarrays
    Ex: 
    [3, 1, 2, 4]

    SUbArr : 
    [3], [3, 1], [3, 1, 2], [3, 1, 2, 4]
    min are:  3.    1.       1.           1

    [1], [1, 2], [1, 2, 4]
    1.     1.       1.    

    [2], [2, 4]
    2.     2.   

    [4]
    4.  

    3 counts -> 1; 
    1 counts -> 6;
    2 counts -> 2;
    4 counts -> 1;

    total Sum = 3 * 1 + 2 * 6 + 2 * 2 + 4 * 1 = 17

    hence we can get the range of each possible number by getting its min on left and right and get it's count

    make sure you include the (equal to)== num either in left small calculation or right small calculation not both
    because that will result in duplicates.. 


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> leftSmallestRange(n, -1);
        vector<int> rightSmallestRange(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()) leftSmallestRange[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop();
            }

            if(!st2.empty()) rightSmallestRange[i] = st2.top();
            st2.push(i);
        }

        // for(auto v: leftSmallestRange){
        //     cout << v << " ";
        // }cout<<endl;

        // for(auto v: rightSmallestRange){
        //     cout << v << " ";
        // }

        int ans = 0;
        for(int i = 0; i < n; i++){
            long long int leftRange = i - leftSmallestRange[i];
            long long int rightRange = rightSmallestRange[i] - i;
            long long int num = (arr[i] * leftRange * rightRange) % mod;
            ans += num;
            ans = ans % mod;
        }

        return ans;
    }

*/


/*

    2104. Sum of Subarray Ranges
    (https://leetcode.com/problems/sum-of-subarray-ranges/)

    Same as above, but you have to find max Ranges also
    and to get all sum(max - min) --> maxSum - minSum


    long long int getMax(vector<int>& arr){
        int n = arr.size();
        vector<int> leftSmallestRange(n, -1);
        vector<int> rightSmallestRange(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            if(!st.empty()) leftSmallestRange[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] < arr[i]){
                st2.pop();
            }

            if(!st2.empty()) rightSmallestRange[i] = st2.top();
            st2.push(i);
        }

        long long int ans = 0;
        for(int i = 0; i < n; i++){
            long long int leftRange = i - leftSmallestRange[i];
            long long int rightRange = rightSmallestRange[i] - i;
            long long int num = (arr[i] * leftRange * rightRange);
            ans += num;
        }

        return ans;
    }

    long long int getMin(vector<int>& arr){
        int n = arr.size();
        vector<int> leftSmallestRange(n, -1);
        vector<int> rightSmallestRange(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()) leftSmallestRange[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop();
            }

            if(!st2.empty()) rightSmallestRange[i] = st2.top();
            st2.push(i);
        }

        long long int ans = 0;
        for(int i = 0; i < n; i++){
            long long int leftRange = i - leftSmallestRange[i];
            long long int rightRange = rightSmallestRange[i] - i;
            long long int num = (arr[i] * leftRange * rightRange);
            ans += num;
        }

        return ans;
    }


    long long subArrayRanges(vector<int>& arr) {
        long long int ans = getMax(arr) - getMin(arr);
        return ans;
    }

*/