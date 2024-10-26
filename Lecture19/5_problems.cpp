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

    //------------------------------------------------------------------------------------------------

    // Method 2 Takes O(n) times as map isn't created in it and no extra O(n) space is required
    void print(Node* head){
        Node* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    Node* copyRandomList(Node* head) {
        
        if (head == NULL){
            return NULL;
        }

        // Step 1, Clone A (7->13->11->10->1 : 7->7->13->13->11->11->10->10->1->1)

        Node* it = head;
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;

        }

        it = head;
        // print(it);
        // Step 2, create the connections between new Node and there random values

        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next:nullptr;
            it = it->next->next;
        }

        // Step 3, remove the links between old and new Nodes
        it = head;
        Node* clonedHead = it->next;
        while(it){
            Node* clonedNode = it->next;
            it->next = clonedNode->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;

        }

        return clonedHead;


    }


*/


