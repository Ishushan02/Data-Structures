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


/*

876. Middle of the Linked List
(https://leetcode.com/problems/middle-of-the-linked-list/submissions/1416594390/)

    ListNode* middleNode(ListNode* head) {
        vector<int> value;

        ListNode* tempNode = head;
        int count = 0;
        while(head){
            value.push_back(head->val);
            count++;
            head = head->next;
        }

        
            //odd
            int temp = 0;
            while(tempNode){
                if(temp == count/2){
                    return tempNode;
                }
                temp++;
                tempNode = tempNode->next;
            }
        
        return head;

        
    }


    VVI Approach - Tortoise Approach

    ListNode* middleNode(ListNode* head) {
        
        // Tortoise Approach
        // While Rabbit takes 2 steps tortoise takes 1 step
        ListNode* step1 = head;
        ListNode* step2 = head;

        while(step2){
            
            step2 = step2->next;
            if (step2){
                step2 = step2->next;
            }else{
                return step1;
            }
            step1 = step1->next;
            
        }
        return step1;
    }
*/

/*

2095. Delete the Middle Node of a Linked List
(https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

    ListNode* middleNode(ListNode* head){
        ListNode* step1 = head;
        ListNode* step2 = head;

        while(step2){
            
            step2 = step2->next;
            if (step2){
                step2 = step2->next;
            }else{
                return step1;
            }
            step1 = step1->next;
            
        }
        return step1;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        int n = 0;
        ListNode* midlNode = middleNode(head);
        ListNode* temp = head;
        ListNode* prev = head;

        
        while(temp){

            if(temp->next == midlNode){
                prev = temp;
                cout << temp->val << endl;
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                
                
            }else{
                temp = temp->next;
            }
            
            
        }

        return head;
    }
*/