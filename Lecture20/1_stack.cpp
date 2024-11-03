#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
    Follows LIFO Ordering(Last In First Out)
    Stack can only be accessible from TOP and no other way to access it

*/


// insert atBottom
// get MiddleElement

/*
    So, the biggest advantage is that, we can use recursion for stack oeration as it also follows STACK operation in backend
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

    sortedInsert(s, 40);
    printstack(s);

    return 0;
}
