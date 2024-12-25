/*
    Important pattern
    - Top K Patterns
    - Merge K Sorted pattern
    - Two Heaps Pattern
    - Minimum Number pattern

*/

/*
    215. Kth Largest Element in an Array
    (https://leetcode.com/problems/kth-largest-element-in-an-array/)

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