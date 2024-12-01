#include<iostream>
#include<queue>

using namespace std;

/*
    It follows FIFO (First in First Out)
    Normal Queue
    Circular Queue
    DeQueue ( Doubly Ended Queue)

    Just Like Stack we can only access the Top element similiarily in
    Queue we can only access first element of the Queue. (Normal queue we can only pop from front, and push from back)


    Dequeue In Doubly Ended Queue we can push and pop from front and back both way

    Circular Queue as the name suggests it means the same
*/


// Not Implementing Queue and Dequeue, see Circular Queue



class CircularQueue{

    public:
        int *arr;
        int n;
        int front ;
        int rear;
    
    CircularQueue(int size){
        this->n = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int val){

        if((front == 0 && rear == n - 1) || (rear == front - 1)){
            // it is compltely filled
            cout << " Queue is Filled, OverFlow" << endl;
        }else if(front == -1 && rear == -1){  // first element
            rear++;
            front++;
            arr[rear] = val;
        }else if(rear == n -1 && front != 0 ){ // circular flow rear will move from back to front
            rear = 0;
            arr[rear] = val;
        }else{ // normal flow
            rear++;
            arr[rear] = val;
        }

    }

    void pop(){
        // no element is there
        if(front == -1 && rear == -1 ){
            cout << " Queue is Empty, UnderFlow" << endl;
        }else if(front == rear) { // 1 element is present
            arr[front] = -1;
            front = -1;
            rear = -1;
        }else if(front == n -1){ // circular nature
            arr[front] = -1;
            front = 0;
        }else{
            arr[front] = -1;
            front++;
        }
    }
    

    int getSize(){
        // cout << rear << "--"<<front << endl;
        if(rear == -1 and front == -1){
            return 0;
        }else if(front > rear){
            return (n - front ) + rear + 1;
        }else{
            return abs(rear - front) + 1;
        }
        // return abs(rear - front) + 1;
    }

    int getFront(){
        if(front == -1){
            cout << " Queue is Empty, nothing to reutrn "<< endl;
            return 0;
        }
        return arr[front];
    }

    bool isEmpty(){
        if(rear == -1 and front == -1){
            return true;
        }
        return false;
    }

    void print(){
        cout << " Printing all elements of Circular Queue " << endl;
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }


};

void reverseQueue(queue<int>& que){
    stack<int> st;
    while(!que.empty()){
        st.push(que.front());
        que.pop();
    }

    while(!st.empty()){
        que.push(st.top());
        st.pop();
    }

}

void recurseReverse(queue<int> &que){
    if(que.empty()){
        return;
    }

    int elem = que.front();
    que.pop();
    recurseReverse(que);
    que.push(elem);

}


// reverse in the group of k 
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} k = 3
// OP: {3, 2, 1, 6, 5, 4, 9, 8, 7, 10}

// if we have to not use the extra space, we will keep a counter of the elements processed in queue
// and push in back of the queue, when counter comes to an end just original queue will have reversed kGroups

void reverseKGroup(queue<int>& que, int k, queue<int>& ansque){
    if(int(que.size()) < k){
        while(!que.empty()){
            ansque.push(que.front());
            que.pop();
        }
        return;
    }

    stack<int> st;
    int it = k;
    while(it){
        st.push(que.front());
        que.pop();
        it--;
    }

    it = k;
    while(it){
        ansque.push(st.top());
        st.pop();
        it--;
    }

    reverseKGroup(que, k, ansque);




}

int main(){

    queue<int> que;

    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);

    cout << "Front of Queue " << que.front() << endl;
    cout << "Size of Queue " << que.size() << endl;
    cout << "Rear Element of Queue " << que.back() << endl;

    cout << "Printing all elements of Queue " << endl;
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop(); // it will pop from front
    }
    cout << endl;


    // Doubly Ended Queue (Dqueue), 

    deque<int> dqq;
    dqq.push_front(10);
    dqq.push_back(20);
    dqq.push_back(30);
    dqq.push_front(40);
    dqq.push_back(50);
    dqq.push_front(60);


    cout << "Front of DeQueue " << dqq.front() << endl;
    cout << "Size of DeQueue " << dqq.size() << endl;
    cout << "Rear Element of DeQueue " << dqq.back() << endl;

    cout << "Printing all elements of Queue " << endl;
    while(!dqq.empty()){
        cout << dqq.front() << " ";
        dqq.pop_front(); // it will pop from front
    }
    cout << endl;

    // Circular Queue
    cout << " Circular Queue " << endl;
    CircularQueue cque(5);

    cque.push(1);
    cque.push(2);
    cque.print();
    cout << "Size of Circular Queue: "<<cque.getSize()<< endl;
    cout << "Front of Circular Queue: "<<cque.getFront()<< endl;
    cque.push(3);
    cque.push(4);
    cque.push(5);
    cque.print();

    cque.pop();
    cque.print();
     cque.push(11);
    cque.print();

    cque.pop();
    cque.print();
     cque.push(20);
    cque.print();

    cout << "Size of Circular Queue "<< cque.getSize() << endl;;


    // Reversing the Queue
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    cout << "Revering the QUeue" << endl;
    reverseQueue(que);
    cout << "Printing all elements of Reversed Queue " << endl;
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop(); // it will pop from front
    }
    cout << endl;

    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    recurseReverse(que);
    cout << "Printing all elements of Recursed Reversed Queue " << endl;
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop(); // it will pop from front
    }
    cout <<endl;


    // Reverse in Groups of K
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    que.push(60);
    que.push(70);
    que.push(80);
    que.push(90);
    que.push(100);

    queue<int> ansqueue;
    reverseKGroup(que, 4, ansqueue);
    cout << "Reversing in Groups of K " << endl;
    while(!ansqueue.empty()){
        cout << ansqueue.front() << " ";
        ansqueue.pop(); // it will pop from front
    }
    cout <<endl;

}



/*  
    Interleave the First Half of the Queue with Second Half
    (https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/0)

    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> ans;
        
        int k = q.size()/2;
        queue<int> strq;
        while(k){
            strq.push(q.front());
            q.pop();
            k--;
        }
        
        while(!q.empty()&& !strq.empty()){
            ans.push_back(strq.front());
            ans.push_back(q.front());
            q.pop();
            strq.pop();
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        while(!strq.empty()){
            ans.push_back(strq.front());
            strq.pop();
        }
        
        return ans;
    }

*/

/*

VVIIIII AlGORITHM

Sliding Window Applications
     - Find Subarray ....
     - Find Substring ....
     - Find Window ....

Procedure is (let's say window size is K)
    - first do the process for k window
    - store all the ans's in a queue

    - start from k to N //(all current window will always be in K-index+1 to index)
        // store the answer, process whatever is required
        // this is actually storing answer for previous case

        // now time is to move the window, so include next element and remove previous element from que
        // if(!q.empty() && index - q.front() >= k ) -->remove it q.pop()

        //store next eleme
        nexnew elem = arr[i]
        //according to method do the procedure and q.push(arr[i])

*/


/*
    // SLIDING WINDOW APPLICATION

    First negative in every window of size k
    (https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        
        vector<int> ans;
        queue<int> que;
        
        // for first window
        for(int i = 0; i < k; i++){
            if(arr[i] < 0){
                que.push(i);
                // cout << i << endl;
            }
        }
        // cout << "---" << endl;
        
        
        // for next windows
        for(int index = k; index < arr.size(); index++){
            
            // store prev window ans
            if(que.empty()){
                ans.push_back(0); // no negative element
            }else{
                ans.push_back(arr[que.front()]);// as queue has indexes
            }
            
            // remove 1 elemt from prev window
            if((!que.empty()) && (index - que.front() >= k)){
                // cout << que.front() << endl;
                que.pop();
            }
            
            // add new elem
            int elem = arr[index];
            if(elem < 0){
                que.push(index); // store index
            }
            
        }
        
        // the last window is left to push into answer
        if(que.empty()){
            ans.push_back(0); // no negative element
        }else{
            ans.push_back(arr[que.front()]);// as queue has indexes
        }
        
        return ans;
        
    }

*/


/*

    239. Sliding Window Maximum (VVIII Question)
    (https://leetcode.com/problems/sliding-window-maximum/description/)

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // always try using deque as we can perform back operation on it
        deque<int> que;
        vector<int> ans;

        for(int i = 0; i< k; i++){

            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }

        for(int i = k; i < nums.size(); i++){

            // store answer for prev window
            ans.push_back(nums[que.front()]);

            // remove if prev window idx exist
            if(!que.empty() && i - que.front() >= k){
                que.pop_front();
            }

            // remove any smaller elem's from the window from back
            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);

        }
        ans.push_back(nums[que.front()]);

        return ans;
    }

*/