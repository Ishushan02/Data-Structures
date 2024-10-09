#include<iostream>
#include<vector>

using namespace std;

int main(){


}

/*

206. Reverse Linked List
(https://leetcode.com/problems/reverse-linked-list/submissions/1416561388/)

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
*/