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

    class MyCircularQueue {
    public:

    queue<int> que;
    int rearElem = -1;
    int K = 0;

    MyCircularQueue(int k) {
        K = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }

        que.push(value);
        rearElem = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        que.pop();
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return que.front();
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return rearElem;
    }
    
    bool isEmpty() {
        return que.size() == 0;
    }
    
    bool isFull() {
        return  que.size() == K;
    }
    };

*/