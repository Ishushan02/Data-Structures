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