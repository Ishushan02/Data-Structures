#include<iostream>

/*

NOTE WHENEVER WE GET A SORTING OPERATION IN SLIDING WINDOW IT WILL BE DONE  BY HEAP
PLEASE DO ALL HEAP QUESTIONS AGAIN AFTER LEARNING THE CONCEPT PROPERLY

*/


/*

    DO IT GOOD QUESTION 
    2653. Sliding Subarray Beauty - Time limit Exceeded
    (https://leetcode.com/problems/sliding-subarray-beauty/)

    Great method, 
        - keep count of the values coming as the nums bound is just -50 -> 50
        - maintain the same procedure of k Window, but in addition to that add a counter of each element
        - while storing the answer just take -ve numbers and little trick that's it

    void storeAns(map<int, int> &valNum, vector<int> &ans, int x){
        bool check = true;
        // x = x - 1;
        for(auto &[key, val]: valNum){
            int temp = val;
            if(key < 0 && temp > 0){
                if(x > temp){
                    x = x - temp;
                }else if(temp >= x){
                    ans.push_back(key);
                    return ;
                }
            }
        }
        ans.push_back(0);
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        deque<int> que;
        map<int, int> valNum;

        vector<int> ans;

        for(int i = 0; i < k; i++){
            valNum[nums[i]] += 1;
            que.push_back(i);
        }

        for(int i = k; i < nums.size(); i++){
            
            storeAns(valNum, ans, x);

            while(!que.empty() && i - que.front() >= k){
                valNum[nums[que.front()]]--;
                que.pop_front();
            }

            valNum[nums[i]] += 1;
            que.push_back(i);
        }

        storeAns(valNum, ans, x);

        return ans;

    }

*/

/*

IMPLEMENT K QUEUES IN AN ARRAY 

    - Very Important Question based on Interviews Perspective

Method 1 Brute Force Approach

    let's array of size (N)4 and k with (K)2 hence there will be (N / K) total queses possible
    here in this case 2 queues will be possible, (for this example both are of size 4 each)
    - We create Q1(0 -> 3) and Q2(4 -> 8) 
    let's say Q1 is filled copletely with 4 elemets and next elemet is to be filled, what it will do is 
    while inserting Q1 it will throw error saying Q1 is fully filled
    - but array is still not completely filled, hence this is not an optimal Use of Space
    - This is known as Fragmentation Problem (even though space is available we are not able to insert elements in the queue)
    - So, this method is discarded


Method 2 OPTIMAL APPROACH

    - front[k] an Array storing starting indexes of Kth Array [0, 1, ... k-1] front Indices of all queues
    - rear[k] an Array storing rear indexes of Kth Array [0, 1, ... k-1] rear Indices of all queues
    - next[N] store indices of next item for all item in an array 
        {Ex : let's say we have 2 queue in an Arr and elements are like this, Q0 and Q1 representing any element of that subscript
         {Q0, Q1, Q1, Q0, Q0, Q1, Q0, Q1, Q1}
        so as Q0 is in 0th position the next arr will have the pointer of Q0th next elem which here is 3, and so on }
    - freespot[k] current available free spot of k in main array (initalize with 0) 

        PUSH ALGORITHM
            - check overflow
                if freespot == - return false
            - find first free Idx, 
                int index = freespot
            - update freespot by next[index]
            - if first elem of Qith 
                if(front [qn] == -1) then fron[qn] = 0
                else:
                    // link new element to that queue's rearest element
                    next[rear[qn]] = index
                    // update next
                    next[index] = -1
                    // update rear
                    rear[qn] = index; arr[index] = x;
        
        POP ALGORITHM
            - check underFlow
                if(front[qn] == -1) return -1
            - find index to pop
                int index = front[qn]
            - update front
                front[qn] = next[index]
            - manage free spot
                next[index] = freespot
            
            


*/

using namespace std;

class KQueue{

    public:
        int n, k, freespot;
        int *arr, *front, *rear, *next;

        KQueue(int _n, int _k):n(_n), k(_k), freespot(0){
            
            arr = new int[n];
            front = new int[k];
            rear = new int[k];
            next = new int[n];

            // initialize front and rear with -1
            for(int i = 0; i <k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            // initialize next with sequential flow and last elemt with -1
            for(int i = 0; i < n; i++){
                next[i] = i + 1;
                next[n-1] = -1;
            }
        }

        bool push(int x, int qi){

            // overflow
            if(freespot == -1){
                return false;
            }

            // get first free item and update it
            int index = freespot;
            freespot = next[index];

            // first elemt in q1
            if(front[qi] == -1){
                front[qi] = index;  
            }else{
                // link new element to that queue's rearest element
                next[rear[qi]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qi] = index;
            arr[index] = x;

            return true;

        }


        int pop(int qi){
            // underflow
            if(front[qi] == -1){
                return -1;
            }

            int index = front[qi];

            // front update
            front[qi] = next[index];

            // update freespot
            next[index] = freespot;
            freespot = index;

            return arr[index];
        }


        ~KQueue(){
            delete [] arr;
            delete [] front;
            delete [] rear;
            delete [] next;
        }

};



class QueueUsingStack{

    public:
        stack<int> s1, s2;

        QueueUsingStack(){
        }

        void push(int value){
            s1.push(value);
            
            if(s2.empty()){
                
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

            }else{
                
                stack<int> s3;
                
                while(!s2.empty()){
                    s3.push(s2.top());
                    s2.pop();
                }

                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

                while(!s3.empty()){
                    s2.push(s3.top());
                    s3.pop();
                }


            }



        }

        void pop(){
            s2.pop();
        }

        int top(){
            return s2.top();
        }

};

int main(){

        KQueue kq(8, 3);

        cout << kq.push(1, 0) << endl;
        cout << kq.push(2, 0) << endl;
        cout << kq.push(5, 2) << endl;
        cout << kq.push(-5, 1) << endl;
        cout << kq.push(7, 0) << endl;
        cout << kq.push(-9, 1) << endl;
        cout << kq.push(15, 2) << endl;

        // Q0 --> 1, 2, 7
        // Q1 --> -5, -9
        // Q2 --> 5, 15
        cout << "Popping Elements " << endl;
        cout << kq.pop(0) << endl;
        cout << kq.pop(1) << endl;
        cout << kq.pop(2) << endl;
        cout << kq.pop(0) << endl;
        cout << kq.pop(1) << endl;
        cout << kq.pop(1) << endl;



        cout << "All Operations are using Stacks Implemented Via Queue " << endl;

        QueueUsingStack que;

        // que --> 10, 11, -9, 1, 2, 7, 3
        que.push(10);
        que.push(11);
        que.push(-9);
        que.push(1);
        que.push(2);
        que.push(7);
        que.push(3);

        cout << que.top() << endl;

        // que -9, 1, 2, 7, 3
        que.pop();
        que.pop();

        cout << que.top() << endl;

        // que  7, 3
        que.pop();
        que.pop();
        que.pop();
        cout << que.top() << endl;


        return 0;

}

/*

    QUEUE USING STACKS
    (https://leetcode.com/problems/implement-queue-using-stacks/description/)

    class MyQueue {
public:

    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);

        if(s2.empty()){
                
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

            }else{
                
                stack<int> s3;
                
                while(!s2.empty()){
                    s3.push(s2.top());
                    s2.pop();
                }

                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

                while(!s3.empty()){
                    s2.push(s3.top());
                    s3.pop();
                }


            }

    }
    
    int pop() {
        int elem = s2.top();
        s2.pop();
        return elem;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
    }
};


*/


/*

    225. Implement Stack using Queues
    (https://leetcode.com/problems/implement-stack-using-queues/description/)

        class MyStack {
public:
    deque<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push_back(x);
    }
    
    int pop() {
        int val = que.back();
        que.pop_back();
        return val;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};


*/

/*
    K Sized Subarray Maximum
    (https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

    Method 1 (TLE)
    void rearrange(deque<int>& que, vector<int>& arr, int elem){
        // Max ...... Min
        
        if(que.empty()){
            que.push_front(elem);
            return ;
        }
        
        int topidx = que.front();
        if(arr[elem] >= arr[topidx]){
            que.push_front(elem);
        }else{
            
            que.pop_front();
            rearrange(que, arr, elem);
            que.push_front(topidx);
            
        }
        
        return;
        
    }
  
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        // first window
        int maxelem = INT_MIN;
        vector<int> ans;
        deque<int> que;
        for(int i = 0; i < k; i++){
            if(que.empty()){
                que.push_front(i);
            }else{
                rearrange(que, arr, i);
            }
            
        }
        
        for(int i = k; i < arr.size(); i++){
            
            // store ans
            ans.push_back(arr[que.front()]);
            
            // remove elem which is not in the front
            while(!que.empty() && i - que.front() >= k){
                que.pop_front();
            }
            
            if(que.empty()){
                que.push_front(i);
            }else{
                rearrange(que, arr, i);
            }
            
        }
        ans.push_back(arr[que.front()]);
        
        return ans;
    }


    Method 2 (Efficient Method)
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        // first window
        int maxelem = INT_MIN;
        vector<int> ans;
        deque<int> que;
        for(int i = 0; i < k; i++){
            
            // remove all smaller elem which is less than curr elem
            while(!que.empty() && arr[que.back()] <= arr[i]){
                que.pop_back();
            }
            que.push_back(i);
            
        }
        
        for(int i = k; i < arr.size(); i++){
            
            // store ans
            ans.push_back(arr[que.front()]);
            
            // remove elem which is not in the window
            while(!que.empty() && i - que.front() >= k){
                que.pop_front();
            }
            
            // remove all smaller elem which is less than curr elem
            while(!que.empty() && arr[que.back()] <= arr[i]){
                que.pop_back();
            }
            
            que.push_back(i);
            
        }
        ans.push_back(arr[que.front()]);
        
        return ans;
    }


*/

/*
    Sum of minimum and maximum elements of all subarrays of size k.
    (https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/)

    vector<int> sumOfmaxminSubarrays(vector<int>& arr, int k) {
        // code here
        
        // first window
        int sum;
        deque<int> greaterque; // contains max elems at the top
        deque<int> lesserque; // contains min elems at the top

        for(int i = 0; i < k; i++){
            
            // remove all smaller elem which is less than curr elem
            while(!greaterque.empty() && arr[greaterque.back()] <= arr[i]){
                greaterque.pop_back();
            }
            
            // remove all greater elem which is more than curr elem
            while(!lesserque.empty() && arr[lesserque.back()] >= arr[i]){
                lesserque.pop_back();
            }

            greaterque.push_back(i);
            lesserque.push_back(i);
            
        }
        
        for(int i = k; i < arr.size(); i++){
            
            // store ans
            sum = sum + arr[greaterque.front()] + arr[lesserque.front()];
            
            // remove elem which is not in the window
            while(!greaterque.empty() && i - greaterque.front() >= k){
                greaterque.pop_front();
            }
            
            while(!lesserque.empty() && i - lesserque.front() >= k){
                lesserque.pop_front();
            }
            
            // remove all smaller elem which is less than curr elem
            while(!greaterque.empty() && arr[greaterque.back()] <= arr[i]){
                greaterque.pop_back();
            }
            
            // remove all greater elem which is more than curr elem
            while(!lesserque.empty() && arr[lesserque.back()] >= arr[i]){
                lesserque.pop_back();
            }
            greaterque.push_back(i);
            lesserque.push_back(i);
            
        }
        sum = sum + arr[greaterque.front()] + arr[lesserque.front()];
                
        return ans;
    }



*/

/*
    933. Number of Recent Calls
    (https://leetcode.com/problems/number-of-recent-calls/description/)

    class RecentCounter {
public:

    vector<int> requests;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        int count = 1;
        if(requests.empty()){
            requests.push_back(t);
            // return count;
        }else{
            
            for(int i = 0; i < requests.size(); i++){
                int req = requests[i];
                if(req >= t - 3000 && req <= t){
                    count += 1;
                }
            }
            requests.push_back(t);
        }

        return count;
    }
};
*/


/*

    2327. Number of People Aware of a Secret
    (https://leetcode.com/problems/number-of-people-aware-of-a-secret/)


    Method 1 (TLE) - Brute Force Approach
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<bool> available ;
        vector<int> born ;

        // 1st day
        available.push_back(true);
        born.push_back(1);

        for (int each_day = 1; each_day < n; each_day++){

            for(int memb = 0; memb < available.size(); memb++){
                bool curravail = available[memb];
                int bv = born[memb];

                // forgets
                if( each_day + 1 - bv == forget){
                    available[memb] = false;
                }

                // create
                if((each_day + 1 - bv >= delay) && (available[memb])){
                    available.push_back(true);
                    // delayVal.push_back(delay);
                    born.push_back(each_day + 1);
                }
                }

        }
    
        long long int ans = 0;
        for(auto i:available){
            if(i){
                ans += 1;
            }
        }
        // cout << ans << endl;
        return ans % (1000000007);
    }


    Method 2 - Efficient Method
    Good Explanation Video (https://www.youtube.com/watch?v=dalyTgkiH0s)

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<long long int> knownby(2*n + 10, 0);

        knownby[1] = 1;

        for(int day = 1; day <= n; day++){
            for(int j = delay + day; j < day + forget; j++){
                knownby[j] = (knownby[j] + knownby[day]) % 1000000007;
            }
        }

        long long int ans = 0;

        for(int k = n; k >= n - forget+1; k--){
            ans = (ans + knownby[k])% 1000000007 ;
        }

        return ans;
    }

*/

/*
    1823. Find the Winner of the Circular Game
    (https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

    int findTheWinner(int n, int k) {
        
        deque<int> que;

        for(int i = 1; i<=n; i++){
            que.push_back(i);
        }

        while(que.size() > 1){

            int count = 1;
            while(count<k){
                que.push_back(que.front());
                que.pop_front();
                count = count + 1;
            }
            que.pop_front();

        }

        return que.front();
    }


    Method 2. Good O(n) time complexity
    int winner(int n, int k){

        if(n == 1){
            return 1;
        }
        int val = (winner(n -1, k) + k-1) % n + 1;
        return  val;

        // return ans;
    }

    int findTheWinner(int n, int k) {
        return winner(n ,k);
    }  

    Method 3
    int findTheWinner(int n, int k) {
        
        queue<int> que;
        for(int i = 1; i <= n; i++){
            que.push(i);
        }

        int c = 1;
        while(que.size()> 1){

            if(c == k){
                que.pop();
                c = 1;
            }else{
                que.push(que.front());
                que.pop();
                c++;
            }
        }

        return que.front();
    }

*/

/*
        950. Reveal Cards In Increasing Order (EASY YET TRICKY- DO IT AGAIN)
        (https://leetcode.com/problems/reveal-cards-in-increasing-order/)

        vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        deque<int> que;

        sort(deck.begin(), deck.end());

        for(int i = 0; i < n; i++){
            que.push_back(i);
        }

        // reverse simulation

        for(int i = 0; i < n; i++){

            // reveal
            ans[que.front()] = deck[i];
            que.pop_front();

            // push
            if(!que.empty()){
                que.push_back(que.front());
                que.pop_front();
            }
        }
        
        return ans;
    }

    Method 2

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> que;
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            que.push(deck[i]);
        }
            int i = 0;
            char oper = 'R';
            while(que.size()>1){
                // reveal
                if(oper == 'R'){
                    int front = que.front();
                    while(ans[i%n] != -1){
                        i++;
                    }
                    ans[i%n] = front;
                    que.pop();
                    i++;
                    oper = 'P';
                }

                if(oper == 'P'){
                    // push
                    while(ans[i%n] != -1){
                        i++;
                    }
                    // current is empty
                    i++;
                    oper = 'R';
                }  
            }
            
        for(int i = 0; i < n; i++){
            if(ans[i] == -1){
                ans[i] = que.front();
                que.pop();
                break;
            }
        }
        

        return ans;
    }
*/

/*
    480. Sliding Window Median
    (https://leetcode.com/problems/sliding-window-median/)

    Method 1 - TLE
    void storeAnswers(deque<int> que, vector<int>& nums, vector<double>& ans, int k){
        vector<int> temp2;

        while(!que.empty()){
            int num = nums[que.front()];
            temp2.push_back(num);
            que.pop_front();
        }

        sort(temp2.begin(), temp2.end());
        int n = temp2.size();

        if(k %2 != 0){
            // odd
            int id =  n/2;
            ans.push_back(temp2[id]);
        }else{
            // even
            int id1 =  n/2 -1;
            int id2 =  n/2;
            double as = (temp2[id1] + (double)temp2[id2]) / 2;
            ans.push_back(as);
        }


    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        deque<int> que;

        // 1st window
        for(int i =0; i < k; i++){
            que.push_back(i);
        }


        for(int i = k; i < nums.size(); i++){
            // cout << que.front() << endl;
            // get answer
            storeAnswers(que, nums, ans, k);

            // eliminate not in windows
            while(!que.empty() && (i - que.front() >= k)){
                que.pop_front();
            }

            // store answer
            que.push_back(i);
        }
        storeAnswers(que, nums, ans, k);

        return ans;
    }
*/