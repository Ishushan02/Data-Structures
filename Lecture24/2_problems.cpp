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