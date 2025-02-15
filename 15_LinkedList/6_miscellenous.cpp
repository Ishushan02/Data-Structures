/*
    203. Remove Linked List Elements
    (https://leetcode.com/problems/remove-linked-list-elements/description/)

    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            if(head->val == val){
                return NULL;
            }
            return head;
        }

        ListNode* begin = head;
        ListNode* end = head->next;

        while(end){

            if(end->val == val){
                ListNode* temp = end;
                while(temp){
                    if(temp->val == val){
                        temp = temp->next;
                    }else{
                        break;
                    }
                }

                if(temp){
                    begin->next = temp;
                    begin = begin->next;
                    end = begin->next;
                }else{
                    end = NULL;
                    begin->next = NULL;
                }

            }else{
                begin = begin->next;
                end = end->next;
            }
        }

        if(head->val == val){
            return head->next;
        }

        return head;
    }

*/

/*
    1290. Convert Binary Number in a Linked List to Integer
    (https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/)

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        
        ListNode* ll = reverseList(head);

        int sum = 0;
        int i = 0;
        while(ll){
            int val = ll->val;

            sum = sum + val * pow(2, i);
            i++;
            ll = ll->next;
        }

        return sum;

    }
*/