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