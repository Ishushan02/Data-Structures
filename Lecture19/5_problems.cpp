#include <iostream>

using namespace std;


int main(){

    return 0;
}


/*

    VVI and Tricky Question - Practise it.

    138. Copy List with Random Pointer
    (https://leetcode.com/problems/copy-list-with-random-pointer/submissions/1432943259/)


    Node* recursemap(Node* head, unordered_map<Node*, Node*> & mp){

        if(head == NULL){
            return head;
        }

        Node* newHead = new Node(head->val);
        mp[head] = newHead;

        newHead->next = recursemap(head->next, mp);

        if(head->random){
            newHead->random = mp[head->random];
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return recursemap(head, mp);
    }
*/


