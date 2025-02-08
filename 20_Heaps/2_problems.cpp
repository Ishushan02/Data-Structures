/*
    Important pattern
    - Top K Patterns
    - Merge K Sorted pattern
    - Two Heaps Pattern
    - Minimum Number pattern

*/

/*
    215. Kth Largest Element in an Array
    (https://leetcode.com/problems/kth-large st-element-in-an-array/)

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // pushed k elements into min Heap
        for(int i = 0; i < k; i++){
            minHeap.push(nums[i]);
        }

        // now check if element is larger than that, push it

        for(int i = k; i < nums.size(); i++){
            if(minHeap.top() < nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top(); // kth Largest Element

        // similarily we can also find kth Smallest element.
    }

    // Try Solving it using MaxHeap
*/

/*

    Is Binary Tree Heap
    (https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)

    bool isHeap(struct Node* tree) {
        // code here
        
        queue<Node*> que;
        que.push(tree);
        bool frontNull = false;
        
        while(!que.empty()){
            Node* front = que.front();
            que.pop();
            
            if(front == NULL){
                frontNull = true;
            }else{
                if(frontNull){
                    return false; // completeness
                }else{
                    // check child should be less or equal
                    if(front->left && front->left->data > front->data){
                        return false;
                    }
                    if(front->right && front->right->data > front->data){
                        return false;
                    }
                    
                    que.push(front->left);
                    que.push(front->right);
                }
            }
        }
        
        return true;
    }
*/

/*
    Minimum Cost of ropes
    (https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

        int minCost(vector<int>& arr) {
        // code here
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i< arr.size(); i++){
            minHeap.push(arr[i]);
        }
        
        int totalCost = 0;
        
        while(!minHeap.empty()){
            // cout << "TotalCost: " <<totalCost << endl;
            if(minHeap.size() > 1){
                int n1 = minHeap.top();
                minHeap.pop();
                int n2 = minHeap.top();
                minHeap.pop();
                totalCost += n1 + n2;
                // cout << n1 + n2 << endl;
                minHeap.push(n1 + n2);
            }else{
                // int n1 = minHeap.top();
                minHeap.pop();
                // totalCost += n1 ;
            }
        }
        return totalCost;
    }

*/

/*
    Merge k Sorted Arrays (Very Very Good Question, Standard Question - Merge K sorted pattern)
    (https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

    class Info{
    public:
    int data;
    int rowIdx;
    int colIdx;
    
    Info(int a, int b, int c){
        data = a;
        rowIdx = b;
        colIdx = c;
    }
};

class Solution
{
    public:
    
    struct comparator{
      bool operator()(Info* a, Info* b){
          return a->data > b->data; // always think opposite(min Heap and max Heap)
      }  
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<Info*, vector<Info*>, comparator> minHeap;
        vector<int> ans;
        // insert k elements
        
        for(int row = 0; row < K; row++){
            // Info* temp;
            Info* temp = new Info(arr[row][0], row, 0);
            // temp->rowIdx = row;
            // temp->colIdx = 0;
            minHeap.push(temp);
        }
        
        // Now do the same process of like level order
        int col = arr[0].size();
        int row = arr.size();
        while(!minHeap.empty()){
            Info* front = minHeap.top();
            minHeap.pop();
            
            int currRow = front->rowIdx;
            int currCol = front->colIdx;
            ans.push_back(front->data);
            
            if(currCol + 1 < col){
                Info* newElem = new Info(arr[currRow][currCol+1], currRow, currCol+1);
                minHeap.push(newElem);
            }
        }
        
        return ans;
        
        
        
        
    }
};
*/

/*
    // similar Question as above example

    23. Merge k Sorted Lists
    (https://leetcode.com/problems/merge-k-sorted-lists/description/)

    struct comparator{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        if(lists.size() == 0){
            return ansHead;
        }

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            if(temp != NULL){
                minHeap.push(temp);
                // cout << temp->val << endl;
            }
        }

        while(!minHeap.empty()){

            ListNode* front = minHeap.top();
            minHeap.pop();

            cout << front->val << " ";
            
            if(ansHead == NULL && ansTail == NULL){
                ansHead = front;
                ansTail = front;
            }else{
                ansTail->next = front;
                ansTail = front;
            }
            

            if(front->next){
                ListNode* newNode = front->next;
                minHeap.push(newNode);
            }
        }

        return ansHead;
        
    }

*/


/*
    // similar question based on Top K Patterns

    632. Smallest Range Covering Elements from K Lists
    (https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

    struct comparator{
        bool operator()(Info* a, Info*b){
            return a->val > b->val;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info*, vector<Info*>, comparator> minHeap;
        int minRange = INT_MAX;
        int maxRange = INT_MIN;
        
        // get k elements
        for(int i = 0; i<nums.size(); i++){
            Info* temp = new Info(nums[i][0], i, 0);
            minHeap.push(temp);
            minRange = min(minRange, nums[i][0]);
            maxRange = max(maxRange, nums[i][0]);

        }
        
        int ansStart = minRange;
        int ansEnd = maxRange;
        while(!minHeap.empty()){
            Info* front = minHeap.top();
            minHeap.pop();

            // this will be min elem in that window
            minRange = front->val;

            // cout << minRange << " -> " << maxRange << endl;
            if((maxRange - minRange) < (ansEnd - ansStart)){
                ansEnd = maxRange;
                ansStart = minRange;
            }

            
                                // col dim of that data
            if(front->col + 1 < nums[front->row].size()){
                Info* temp = new Info(nums[front->row][front->col + 1], front->row, front->col + 1);
                minHeap.push(temp);
                maxRange = max(nums[front->row][front->col + 1], maxRange);
            }else{
                // because that row won't be common to the other rows
                break;
            }

            
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
*/


/*  
    // Very Very Very Good Question, intution is aise mid eleme nikalne ke liye left mai MaxHeap and right mai MinHeap laga dena
    // pura logic isupon insertion.. so check that out

    // if incoming number > median.. push it on the right(minHeap) else push it on lef(maxHeap)

    295. Find Median from Data Stream
    (https://leetcode.com/problems/find-median-from-data-stream/)


    class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;
    MedianFinder() {
        
    }
    // left is maxheap && right is minHeap
    void addNum(int num){
        if(maxHeap.size() == minHeap.size()){
            if(num > median){
                // insert in right(minHeap), then minheap will have extra elem which will be median
                minHeap.push(num);
                median = minHeap.top();
            }else{
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }else if(maxHeap.size() == minHeap.size() + 1){ // maxHeap is greater by 1
            if(num > median){
                
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }else{
                int top = maxHeap.top();
                minHeap.push(top);
                maxHeap.pop();
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }

        }else if(minHeap.size() == maxHeap.size() + 1){
            if(num > median){
    // we have to insert in (right)minHeap, but first overload minHeap top elem(as MaxHeap size is larger) to maxHeap
                int top = minHeap.top();
                maxHeap.push(top);
                minHeap.pop();
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }else{
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top())/ 2.0;
            }

        }
    }


   
    
    double findMedian() {
        return median;
        
    }
};

*/