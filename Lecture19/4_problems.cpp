#include <iostream>

using namespace std;

int main(){

    return 0;
}


/*

    VVVIII Question - Microsoft Interview

    25. Reverse Nodes in k-Group
    (https://leetcode.com/problems/reverse-nodes-in-k-group/)

    int getLength(ListNode* head){
        ListNode* temp = head;
        int l = 0;

        while(temp){
            l++;
            temp = temp->next;
        }

        return l;
    }

    ListNode* reverseLL(ListNode* head, int k){
        if(head == NULL){
            return head;
            // 0 elements
        }

        if(head->next == NULL){
            return head;
            // 1 elements
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;

        int l = getLength(head);
        if(l < k){
            return head;
        }

        while(position < k){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            position++;
        }

        if(curr != NULL){
            head->next = reverseLL(curr, k);
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* ans = reverseLL(head, k);

        return ans;
    }

*/