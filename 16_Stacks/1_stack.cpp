#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
    Follows LIFO Ordering(Last In First Out)
    Stack can only be accessible from TOP and no other way to access it

    Do, N Stack in an Array Question --

*/


// insert atBottom
// get MiddleElement

/*
    So, the biggest advantage is that, we can use recursion for stack operation as it also follows STACK operation in backend
*/

void printstack(stack<int>& stck){
    if(stck.empty()){
        return;
    }
    cout << stck.top() << " ";
    stck.pop();
    printstack(stck);
}

void printMiddleElem(stack<int> &stck, int n, int i){
    if(stck.empty()){
        return ;
    }
    if(n/2 == i){
        cout <<" Middle Element is " <<stck.top() << endl;
        return;
    }
    int elem = stck.top();
    stck.pop();
    i= i + 1;
    printMiddleElem(stck, n, i);
    stck.push(elem);
}



void insertAtBottom(stack<int>& stck, int val){
    if(stck.empty()){
        stck.push(val);
        return;
    }

    int elem = stck.top();
    stck.pop();
    insertAtBottom(stck, val);

    // Back Tracking
    stck.push(elem);
}

void reverse(stack<int>& stck){

    if(stck.empty()){
        
        return;
    }

    int val = stck.top();

    stck.pop();

    reverse(stck);
    insertAtBottom(stck, val);


}

// let's say in decreasing order
bool checkSorted(stack<int>& stck, int element, bool &ans){
    if(stck.size()==0){
        return true;
    }

    int topelem = stck.top();

    if(element < topelem){
        return false;
    }
    stck.pop();
    ans = ans && checkSorted(stck, topelem, ans);
    stck.push(topelem);

    return ans;
}


void sortedInsert(stack<int>& stck, int value){

    int topelem = stck.top();
    if(topelem < value){
        stck.push(value);
        return;
    }

    stck.pop();
    sortedInsert(stck, value);
    stck.push(topelem);
}

int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);

    cout << s.size() << endl;
    cout << " Stack s is empty " << s.empty() << endl;
    cout << " Top Element " << s.top() << endl;

    // As we know that Stack is used in Recursion operation so, we  take advantage of that.

    // printMiddleElem(s, s.size(), 0);

    // insertAtBottom(s, 1000);
    // printstack(s);

    // reverse(s);
    // printstack(s);

    bool ans = true;
    checkSorted(s, INT_MAX, ans); // decreasing order check
    if(ans){
        cout << "Stack is Sorted " << endl;
    }else{
        cout << "Stack is not Sorted " << endl;
    }
    // sortedInsert(s, 40);
    // printstack(s);

    return 0;
}

/*
    Valid Parantheses IMP question, do it.

    20. Valid Parentheses
    (https://leetcode.com/problems/valid-parentheses/description/)

    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{

                if(s[i] == ')' && !st.empty() && st.top()=='('){
                    st.pop();
                }else if(s[i] == ']' && !st.empty() && st.top()=='['){
                    st.pop();
                }else if(s[i] == '}' && !st.empty() && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }

        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }

    }
*/


/*

    Expression contains redundant bracket or not
    (https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/0)

        int checkRedundancy(string s) {
        // code here
        
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    return 1;
                }
                
                while(!st.empty() && st.top() != '('){
                    st.pop();
                }
                
                //pop '('
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
            }
        }
        
        return 0;
    }


*/

/*

    // Important Question, Do it Again bsdk
    // (Similar will be the smallest on Right Question try that)
    Smaller on Left
    (https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1)

    vector<int> leftSmaller(int n, int a[]){
        // code here
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            
            while(st.top()>=a[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(a[i]);
            
        }
        
        return ans;
    }

*/

/*
    // VVIII Question, do it later..(Class 3 Last question)
    84. Largest Rectangle in Histogram

    Procedure:
        So the thought process is that, get the shortest number to it left and right wards,
        that would be the max area covered by it, hence calculate the area and also store the maximum
        possible solution. 


    (https://leetcode.com/problems/largest-rectangle-in-histogram/)


    vector<int> nextSmaller(vector<int>&heights){
        vector<int> ans;
        stack<int> st;
        st.push(-1);

        for(int i = heights.size()-1; i>=0; i--){

            while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }

        // it's from backwards
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> prevSmaller(vector<int>&heights){
        vector<int> ans;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < heights.size(); i++){

            while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }


        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> backsmall = prevSmaller(heights);
        vector<int> frontsmall = nextSmaller(heights);
        int maxArea = -1;
        for(int i = 0; i < heights.size(); i++){
            if(frontsmall[i] == -1){
                frontsmall[i] = heights.size();
            }
            int width = frontsmall[i] - backsmall[i] - 1;
            int height = heights[i];

            maxArea = max(maxArea, width * height);
        }

        return maxArea;
    }


    Efficient Solution (VVIIMMPPP)
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;

        int maxRect = 0;
        for(int i = 0; i <= n; i++){

            while((!st.empty()) &&  (i == n || heights[st.top()] > heights[i])){
                int ht = heights[st.top()];
                st.pop();
                int wt = i;
                if(!st.empty()){
                    wt = i - st.top() - 1;
                }

                maxRect = max(maxRect, ht * wt);
            }
            st.push(i);

        }
        return maxRect;

    }
    
*/

/*

COMPLETE THE N STACKS IN AN ARRAY - 

*/