/*
    1700. Number of Students Unable to Eat Lunch
    (https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = students.size();
        queue<int> que;
        stack<int> st;
        int sqcount = 0;
        int circcount = 0;
        reverse(sandwiches.begin(), sandwiches.end());
        for(auto v:sandwiches){
            st.push(v);
        }
        for(auto v:students){
            if(v == 1){
                sqcount++;
            }else{
                circcount++;
            }
            que.push(v);
        }

        while(!st.empty()){

            int sandwich = st.top();
            // cout << que.size() <<  " - " << sqcount <<  " - " << circcount << endl;

        
            if(sandwich == 1){
                // sqr
                if(sqcount == 0){
                    return n;
                }
            }else{
                // circ
                if(circcount == 0){
                    return n;
                }
            }

            if(sandwich == que.front()){
                if(sandwich == 1){
                    sqcount--;
                }else{
                    circcount--;
                }
                st.pop();
                n--;
            }else{
                que.push(que.front());
            }
            que.pop();

        }

        return n;


    }
*/

/*
    2073. Time Needed to Buy Tickets
    (https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        // idx, val
        queue<pair<int, int>> que;

        for(int i = 0; i < tickets.size(); i++){
            que.push({i, tickets[i]});
        }

        int time = 0;
        while(!que.empty()){
            pair<int, int> front = que.front();

            if(front.first == k && front.second == 1){
                time += 1;
                return time;
            }

            if(front.second == 1){
                que.pop();
            }else{
                que.pop();
                que.push({front.first, front.second - 1});
            }

            time++;
            
        }

        return 0;
    }


*/

/*
    622. Design Circular Queue
    (https://leetcode.com/problems/design-circular-queue/)

    #include<vector>
using namespace std;
class MyCircularQueue {
public:

    int K;
    int start = -1;
    int end = -1;
    vector<int> arr;

    MyCircularQueue(int k) {
        K = k;
        arr = vector<int>(k, -1);  // Proper initialization
    }

    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            start = 0;
            end = 0;
            arr[end] = value;
            return true;
        }
        end++;
        arr[end] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(start == 0 && end == 0){
            arr[start] = -1;
            start = -1;
            end = -1;
            return true;
        }

        arr[start] = -1;
        int temp = start;
        for(int i = 1; i <= end; i++){
            arr[temp] = arr[i];
            temp++;
        }
        end--;

        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[start];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[end];
    }
    
    bool isEmpty() {
        if(start == -1 && end == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(start == -1 && end == -1){
            return false;
        }
        if(end - start + 1 == K){
            return true;
        }
        return false;
    }
};

*/


/*

// See this Procedure again it is good..

    641. Design Circular Deque
    (https://leetcode.com/problems/design-circular-deque/description/)

class MyCircularDeque {
public:

    vector<int> arr;
    int start = -1;
    int end = -1;
    int size = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        capacity = k;
        arr = vector<int>(k, -1);
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }

        if(isEmpty()){
            start = 0;
            end = 0;
        }else{
            start =( start - 1 + capacity) % capacity;
        }

        arr[start] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        if(isEmpty()){
            start = 0;
            end = 0;
        }else{
            end = (end + 1) % capacity;
        }

        arr[end] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }

        if(start == end){
            start = -1;
            end = -1;
        }else{
            start = (start + 1) % capacity;
        }
        size--;

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }

        if(start == end){
            start = -1;
            end = -1;
        }else{
            end = (end - 1 + capacity) % capacity;
        }
        size--;

        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }

        return arr[start];
        
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }

        return arr[end];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

*/