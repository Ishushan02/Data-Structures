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
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

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


    // Method 1 (Good Approach)
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


    Method 2 // Good APproach (Remember prev question of next smaller, and histogram area, same logic)
    ListNode* reverseLL(ListNode* head){

        ListNode* prev = NULL;
        
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode* reversedElem = reverseLL(head);

        vector<int> ans;
        stack<int> st;

        while(reversedElem){
            int elem = reversedElem->val;
            while(!st.empty() && st.top() <= elem){
                st.pop();
            }

            if(st.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(st.top());
            }
            st.push(elem);
            reversedElem = reversedElem->next;
        }

        reverse(ans.begin(), ans.end());
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


/*

    1003. Check If Word Is Valid After Substitutions
    (https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/)


    bool isValid(string s) {

        while(true){
            auto k = s.find("abc");
            if(k == -1){
                break;
            }
            s = s.erase(k, 3);

            // cout << s << endl;
            // break;
        }

        if(s == ""){
            return true;
        }else{
            return false;
        }


        
        return true;
    }


*/


/*
    394. Decode String
    (https://leetcode.com/problems/decode-string/)

    string decodeString(string s) {
        
        stack<string> st;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == ']'){

                string tempstr;
                while(!st.empty() && st.top() != "["){
                    tempstr += st.top();
                    st.pop();
                }
                st.pop(); // popping "["

                string numstr;
                while(!st.empty() && isdigit(st.top()[0])){
                    numstr += st.top();
                    st.pop();
                }

                reverse(numstr.begin(), numstr.end());
                int n = stoi(numstr);

                string value;
                for(int j = 0; j < n; j++){
                    value += tempstr;
                }
                // cout << value << endl;
                st.push(value);

            }else{

                string temp(1, s[i]);
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            // cout << st.top() << endl;
            st.pop();
        }
        reverse(ans.begin(), ans.end());


        return ans;
    }

*/

/*  
        pos = [10, 8, 0, 5, 3]; time = [2, 4, 1, 1, 3]
        Approach is get sort each of them wrt position

        now after sorting  w.r.t position
        [{0, 1}, {3, 3}, {5, 1}, {8, 4}, {10, 2}]

        so time is also on basis of position
        time = [12, 4, 7, 1, 1]

        so, now for car 1 with time 12 there is no bigger time than 12 it will reach alone
        for car 2, t = 4, it will catch up 7 so they both will reach together
        for car (3 gone with 2 already)

        for car 4, t = 1, (car 4 and car 5 will go together)

        hence the logic is if fron cars time is larger than the current car will go along with it.

        calculate each time for each car (target-currpos)/time



    853. Car Fleet (VVIII and Good Question )
    (https://leetcode.com/problems/car-fleet/description/)

    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 1){
            return 1;
        }
       

        // doing it for sorting, in py we can do it easily via lambda
        vector<pair<int, int>> data;
        for(int i = 0; i < position.size(); i++){
            pair<int, int> val;
            val.first = position[i];
            val.second = speed[i];
            data.push_back(val);
        }

        sort(data.begin(), data.end(), comp);
        // sorted based on position

        // for(auto a:data){
        //     cout << a.first << "--"<< a.second << " ";
        // }
        // cout << endl;

        stack<float> st;
        for(int i = 0; i < data.size(); i++){
            float time = (target - data[i].first)/(float)(data[i].second);
            while(!st.empty() && (time >= st.top())){
                st.pop();
            }
            st.push(time);
        }
        return st.size();

    }

*/

/*  

    It is a HARD level question and quite confusing, so please see it again and again
    Just check it out, and get the gist.

    1776. Car Fleet II
    (https://leetcode.com/problems/car-fleet-ii/submissions/1457236171/)

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(), -1);

        stack<int> st;
        for(int i = cars.size()-1; i >= 0; i--){

            // check curr car is faster than st.top
            while(!st.empty() &&  cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            // check speed, and collision time
            while(!st.empty()){
                double collisionTime = (double)(cars[st.top()][0] - cars[i][0])/(cars[i][1] - cars[st.top()][1] );

                if(ans[st.top()] == -1 || collisionTime <= ans[st.top()]){
                    ans[i] = collisionTime;
                    break; // get only the first collision
                }
                st.pop();
                

            }
            st.push(i);

        }
        return ans;
    }

*/

/*

    71. Simplify Path (Good and Important Question)
    (https://leetcode.com/problems/simplify-path/)


    void reverse(stack<string>& stck, string& ans){
        if(stck.empty()){
            return;
        }

        string topelem = stck.top();
        stck.pop();
        reverse(stck, ans);
        ans += topelem;
    }

    string simplifyPath(string path) {
        
        string ans;
        stack <string> st;

        int i = 0;
        while(i < path.length()){

            int j = i;
            string next;
            next += path[i];
            j += 1;
            while(j < path.length()){
                if(path[j] == '/'){
                    break;
                }
                next += path[j];
                j++;
            }
            i = j;

            if(!st.empty() && next == "/.."){
                st.pop();
            }else if(next == "/" || next == "/."){
                // do nothing
                continue;
            }else if(next != "/.."){
                st.push(next);
            }


            // cout << next << endl;
            // i++;
        }

        
        if(st.empty()){
            // root directory
            return "/";
        }

        // reverse the stack or else add that string there itself
        reverse(st, ans);

        // ans
        // while(!newstck.empty()){
        //     ans += newstck.top();
        //     newstck.pop();
        // }
        cout << "Ans " << ans << endl;

        return ans;

    }
*/