/*  
    Problem 16
    23. Merge k Sorted Lists
    (https://leetcode.com/problems/merge-k-sorted-lists/)

    ListNode* mergeNodes(ListNode* &list1, ListNode* &list2){

        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* ansHead = new ListNode(99999999);
        ListNode* ansptr = ansHead;

        while(l1 && l2){
            ListNode* nextl1 = l1->next;
            ListNode* nextl2 = l2->next;

            ListNode* node1 = l1;
            ListNode* node2 = l2;

            if(l1->val < l2->val){
                ansptr->next = node1;
                ansptr = ansptr->next;
                l1 = nextl1;
            }else if(l1->val > l2->val){
                ansptr->next = node2;
                ansptr = ansptr->next;
                l2 = nextl2;
            }else{
                ansptr->next = node1;
                ansptr = ansptr->next;
                ansptr->next = node2;
                ansptr = ansptr->next;
                l1 = nextl1;
                l2 = nextl2;
            }

        }

        if(l1){
            ansptr->next = l1;
        }
        if(l2){
            ansptr->next = l2;
        }

        return ansHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }

        int j = 1;

        ListNode* ansHead = lists[0];

        while(j < lists.size()){
            ListNode* curr = lists[j];
            ansHead = mergeNodes(ansHead, curr);
            j++;
        }

        return ansHead;
    }
*/

/*
    Problem 17
    152. Maximum Product Subarray
    (https://leetcode.com/problems/maximum-product-subarray/)

    void productMax(vector<int> &nums, int i, int product, int &maxProduct, map<pair<int, int>, int> &dpMap){
        if(i >= nums.size()){
            maxProduct = max(maxProduct, product);
            return ;
        }

        if(dpMap.find({i, product}) != dpMap.end()){
            // maxProduct = max(dpMap[{i, product}], maxProduct);
            return ;
        }

        // include nums[i]
        maxProduct = max(maxProduct, nums[i] * product);
        productMax(nums, i + 1, nums[i] * product, maxProduct, dpMap);

        // exclude nums[i]
        if(i + 1 < nums.size()){
            productMax(nums, i + 1, 1, maxProduct, dpMap);
        }else{
            productMax(nums, i + 1, nums[i], maxProduct, dpMap);
        }

        dpMap[{i, product}] = maxProduct;

    }

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        map<pair<int, int>, int> dpMap;
        int ans = 1;
        int maxAns = INT_MIN;
        
        productMax(nums, 0, 1, maxAns, dpMap);
        return maxAns;
    }

*/

/*
    Problem 18
    153. Find Minimum in Rotated Sorted Array
    (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

    int findMin(vector<int>& nums) {
        
        int n = nums.size();

        int start = 0;
        int end = n -1;
        int mid = (start + end)/2;
        int ans = -1;

        while(start <= end){

            if(mid + 1 < n && nums[mid] > nums[mid+1]){
                return nums[mid + 1];
            }else if(mid + 1 < n && mid - 1 >= 0 && nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid]){
                return nums[mid];
            }

            if(nums[mid] > nums[0]){
                // ans = nums[start];
                start = mid + 1;
            }else{
                ans = nums[start];
                end = mid - 1;
            }

            mid = (start + end)/2;
        }

        if(ans == -1){
            return nums[0];
        }

        return nums[mid];

    }
        
*/