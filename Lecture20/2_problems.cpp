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

/*
    1047. Remove All Adjacent Duplicates In String
    (https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/)

    string removeDuplicates(string s) {
        
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        string ans;
        if(st.empty()){
            return ans;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
        
    }

*/


/*

Celebrity Problem
(https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

    Method 1 O(n^2)

    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        int zerorow = 0;
        for(int row = 0; row < mat.size(); row++){
            bool flag = false;
            for(int col = 0; col < mat.size(); col++){
                // all row elemets are 0 and for that all col elements are 1 
                if(mat[row][col] == 0){
                    flag = true;
                }else if(mat[row][col] ==1 && row == col){
                    flag = true;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                zerorow = row;
                break;
            }
        }
        // int ans = -1
        for(int col = 0; col < mat.size(); col++){
            if(col!= zerorow && mat[col][zerorow] != 1){
                return -1;
            }
        }
        
        return zerorow;
        
        
    }



    // The 2nd method O(n) is very very important and frequently asked in Interviews
    // Very Very Very Important method ( Stack Implementation)

    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        // Method 2
        stack <int> st;
        
        //input all mat index in stack
        for(int i = 0; i<mat.size(); i++){
            st.push(i);
        }
        
        int celeb = -1;
        while(st.size() != 1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
            if(mat[A][B] == 1){
                // A is not celebrity, A knows B and B is celebrity
                st.push(B);
            }else if(mat[B][A] == 1){
                // B is not celebrity, B knows A and A is celebrity
                st.push(A);
            }
            
            if(st.empty()){
                return -1;
            }
        }
        
        celeb = st.top();
        // cout << "Celeb Value is " << celeb << endl;
        
        // check all row elem of celeb is 0 disregard it's same row value
        // celebrity might know himself or not doesn't effect our answer
        
        for(int col = 0; col < mat.size(); col++){
            if(celeb != col && mat[celeb][col] != 0){
                return -1;
            }
        }
        
        // check all col elem of celeb is 1 disregard it's same row value
        // celebrity might know himself or not doesn't effect our answer
        
        for(int row = 0; row < mat.size(); row++){
            if(celeb != row && mat[row][celeb] != 1){
                return -1;
            }
        }
        
        return celeb;

    }
    

*/


/*


    1019. Next Greater Node In Linked List
    (https://leetcode.com/problems/next-greater-node-in-linked-list/description/)
    
    
    // Method 1, Time Limit Exceeded by 1 test case
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* temp = head;
        vector<int> ans;

        st.push(temp);
        while(temp != NULL && !st.empty()){
            ListNode* topNode = st.top();
            // cout << topNode->val << " - curr temp val " << temp->val << endl;
            if(temp->val > topNode->val){
                ans.push_back(temp->val);
                st.pop();

                ListNode* newNode = topNode->next;
                if(newNode != NULL){
                    st.push(newNode);
                }
                temp = newNode;
            }else{        
                // no element greater than that element
                if(temp->next == NULL){
                    ans.push_back(0);
                    st.pop();

                    ListNode* newNode = topNode->next;
                    if(newNode != NULL){
                        st.push(newNode);
                    }
                    temp = newNode;
                }else{
                    temp = temp->next;
                }

                
            }

        }

        // always last element will not have any next greater
        // ans.push_back(0);

        return ans;
    }


    // Method 2 (Good Approach)
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans;
        vector<int> llemelements;

        ListNode* temp = head;

        while(temp){
            llemelements.push_back(temp->val);
            ans.push_back(0);
            temp = temp->next;
        }

        stack<int> st;
        // st.push(0);

        for(int i = 0; i < llemelements.size(); i++){
            while(!st.empty() && llemelements[i] > llemelements[st.top()]){
                int idx = st.top();
                ans[idx] = llemelements[i];
                st.pop();
            }
            st.push(i);

        }

        return ans;

    }


*/

/*

COMPLETE THE N STACKS IN AN ARRAY - 

 */

/*

    901. Online Stock Span
    (https://leetcode.com/problems/online-stock-span/)


    public :
        stack <pair <int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {


        int count = 1;
        cout << " Price: " << price << endl;
        while(!st.empty() ){
            pair<int, int> val = st.top();
            // cout << " Price: " << val.first << ", Count: " << val.second << endl;
            if(price >= val.first){
                count = count + val.second;
            }else{
                break;
            }
            st.pop();
        }

        pair<int, int> newPr;
        newPr.first = price;
        newPr.second = count;
        st.push(newPr);

        


        return count;
        // st.push(price);


    }

*/