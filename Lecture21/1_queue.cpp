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
        if(rear == -1 and front == -1){
            return 0;
        }
        return abs(rear - front) + 1;
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
    cout << "Size of Queue: "<<cque.getSize()<< endl;
    cout << "Front of Queue: "<<cque.getFront()<< endl;
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



}