/* 
    Problem 1
    1. Two Sum
    (https://leetcode.com/problems/two-sum/)

    struct comp{
        bool operator()(pair<int, int> &A, pair<int, int> &B){
            return A.second < B.second;
        }
    };

    int binarySearch(int n, vector<pair<int, int>> &dataPair, int key, int i){
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(dataPair[mid].second == key){
                if(dataPair[mid].first == i){
                    if(mid - 1 >= 0 && dataPair[mid-1].second == key){
                        return dataPair[mid-1].first;
                    }
                    if(mid + 1 < n && dataPair[mid+1].second == key){
                        return dataPair[mid+1].first;
                    }
                }

                return dataPair[mid].first;
            }else if(key > dataPair[mid].second){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> dataPair;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            dataPair.push_back({i, nums[i]});
        }

        sort(dataPair.begin(), dataPair.end(), comp());

        for(auto v: dataPair){
            int key = target - v.second;
            int i = v.first;
            int j = binarySearch(n, dataPair, key, i);
            if(j != -1){
                return {i, j};
            }
        }

        return {-1, -1};

    }
*/

/*

    Probelm 2
    2. Add Two Numbers
    (https://leetcode.com/problems/add-two-numbers/submissions/)

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansptr = ansHead;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while(temp1 || temp2){
            int a = 0;
            int b = 0;
            if(temp1 != NULL){
                a = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                b = temp2->val;
                temp2 = temp2->next;
            }

            int sum = a + b + carry;
            carry = sum / 10;
            int value = sum % 10;

            ListNode* newNode = new ListNode(value);
            ansptr->next = newNode;
            ansptr = ansptr->next;
        }

        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            ansptr->next = newNode;
            ansptr = ansptr->next;
        }

        return ansHead->next;
    }
*/