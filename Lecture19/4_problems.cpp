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


/*

    328. Odd Even Linked List
    (https://leetcode.com/problems/odd-even-linked-list/description/)

    void print(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ListNode* insertNode(ListNode* toInsert, ListNode* &evenNode, ListNode* &oddNode, bool flag){



        if (flag == false){
            // even
            if(evenNode == NULL){
                evenNode = toInsert;
                evenNode->next = NULL;

            }else{
                ListNode* temp = evenNode;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = toInsert;
                toInsert->next = NULL;

                return evenNode;
            }
        }else{
            // odd
            if(oddNode == NULL){
                oddNode = toInsert;
                oddNode->next = NULL;

            }else{
                ListNode* temp = oddNode;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = toInsert;
                toInsert->next = NULL;

                return oddNode;
            }
        }

        return toInsert;
    }

    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL){
            return head;
        }
        
        
        ListNode* odd = NULL;
        ListNode* even = NULL;

        ListNode* temp = head;
        bool flag = true;

        while(temp){

            ListNode* newNode = new ListNode(temp->val);
            
            if(flag){
                // cout << temp->val << " odd " << endl;
                odd = insertNode(newNode, even, odd, flag);
                flag = false;
            }else{
                // cout << temp->val << " even " << endl;
                even = insertNode(newNode, even, odd, flag);
                flag = true;
            }


            temp = temp->next;
        }

        print(odd);
        print(even);

        ListNode* p = odd;

        while(p->next){
            p = p->next;
        }

        p->next = even;

        return odd;

    }


*/

/*

    142. Linked List Cycle II
    (https://leetcode.com/problems/linked-list-cycle-ii/description/)

    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next){
            return NULL;
        }

        ListNode* tor = head;
        ListNode* rab = head;

        // Just to check cycle
        while(rab && rab->next){
            // cout << tor->val <<"****" << rab->val << endl;
            tor = tor->next;
            if (rab->next->next){
                rab = rab->next->next;
            }else{
                return NULL;
            }
            
            if(rab==tor){
                break;
            }
        }


        // if it's null then no cycle
        if(rab->next == NULL || rab == NULL){
            return NULL;
        }

        // Once cycle is confirmed return the node where both meets
        rab = head;

        while(tor != rab){
            tor = tor->next;
            rab = rab->next;
        }
        return rab;
    }
*/

/*

    // Note the additional addition of temp in the LinkedList (the condition in For Loop)

    725. Split Linked List in Parts
    (https://leetcode.com/problems/split-linked-list-in-parts/)

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> buckets;

        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        int totalequalelements = n / k;
        int remainingelements = n % k;

        for(int i = 0; i < k; i++){
            buckets.push_back(totalequalelements);
        }

        
        while(remainingelements){
            for(int i = 0; i < k; i++){
                if(remainingelements <= 0){
                    break;
                }
                buckets[i] = buckets[i] + 1;
                remainingelements--;
            }
        }

        temp = head;
        vector<ListNode*> ans(k, nullptr);
        for(int i = 0; i < k && temp; i++){    // Important thing of adding condition in For Loop
            ans[i] = temp;
            int totalelements =  buckets[i];
            for(int j = 0; j < totalelements-1; j++){
                temp = temp->next;
            }

            ListNode* newelem = temp->next;
            temp->next = nullptr;
            temp = newelem;

        }

        

        return ans;

    }

*/


/*

VVVIIII Question

    430. Flatten a Multilevel Doubly Linked List
    (https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/)

    Node* flattenNode(Node* head){

        Node* curr = head;
        Node* tail = head;

        while(curr){

            if(curr->child){
                Node* childTail = flattenNode(curr->child);
                Node* temp = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                childTail->next = temp;
                if(temp){
                    temp->prev = childTail;
                }
                curr->child = NULL;
            }

            tail = curr;
            curr = curr->next;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if (head == NULL){
            return NULL;
        }
        flattenNode(head);
        return head;
    }


*/


/*

Important QUestion, took many times to solve please focus on variable traversal

    Delete N nodes after M nodes of a linked list
    (https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1)

    void deleteNode(Node* head, int n, int m){
        
        if(head == NULL){
            return;
        }
        
        Node* temp = head;
        
        for(int i = 0; i < m-1; i++){
            if(temp == NULL){
                return;
            }
            temp = temp->next;
        }
        if(temp == NULL){
                return;
            }
        Node* MthNode = temp;
        temp = MthNode->next;
        
        for(int i = 0; i < n; i++){
            if(temp == NULL){
                break;
            }
            Node* nextTodelete = temp->next;
            delete temp;
            temp = nextTodelete;
        }
        
        MthNode->next = temp;
        
        deleteNode(temp, n, m);
    }
  
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        deleteNode(head, n, m);
        return head;
        
    }

*/


/*
    21. Merge Two Sorted Lists
    (https://leetcode.com/problems/merge-two-sorted-lists/submissions/1431053260/)

    Method 1 

    void print(ListNode* head){
        ListNode* temp = head;
        // int count = 0;
        while(temp){
            cout << temp->val << endl;
            temp = temp->next;
        }

        // return count;
    }

    ListNode* insertNode(ListNode* &head, ListNode* elem){
        if(head == NULL){
            head = elem;
            head->next = NULL;
            return head;
        }
        ListNode* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = elem;
        elem->next = NULL;

        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // int count1 = getLength(list1);
        // int count2 = getLength(list2);
        if(list1 == NULL ){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* ans = NULL;
        while(temp1 && temp2){
            print(ans);
            cout << temp1->val << "--" << temp2->val << endl;
            if(temp1->val < temp2->val){
                ListNode* elem1 = new ListNode(temp1->val);
                ans = insertNode(ans, elem1);
                temp1 = temp1->next;
            }else if (temp1->val == temp2->val){
                ListNode* elem1 = new ListNode(temp1->val);
                ListNode* elem2 = new ListNode(temp2->val);
                ans = insertNode(ans, elem1);
                ans = insertNode(ans, elem2);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }else{
                ListNode* elem1 = new ListNode(temp2->val);
                ans = insertNode(ans, elem1);
                temp2 = temp2->next;
            }
        }

        while(temp1){
            ListNode* elem1 = new ListNode(temp1->val);
            ans = insertNode(ans, elem1);
            temp1 = temp1->next;
        }

        while(temp2){
            ListNode* elem1 = new ListNode(temp2->val);
            ans = insertNode(ans, elem1);
            temp2 = temp2->next;
        }

        return ans;

    }





    // ----------------------------------------------------------------------------------------------------


    Method 2

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        int elem;
        if(list1->val <= list2->val){
            elem = list1->val;
            list1 = list1->next;
        }else{
            elem = list2->val;
            list2 = list2->next;
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        ListNode* ans = new ListNode(elem);

        ListNode* ansptr = ans;

        while(temp1 && temp2){

            if(temp1->val < temp2->val){
                ListNode* newelem = new ListNode(temp1->val);
                ansptr->next = newelem;
                ansptr = ansptr->next;
                temp1 = temp1->next;
            }else if(temp1->val > temp2->val){
                ListNode* newelem = new ListNode(temp2->val);
                ansptr->next = newelem;
                ansptr = ansptr->next;
                temp2 = temp2->next;
            }else{
                ListNode* newelem2 = new ListNode(temp2->val);
                ListNode* newelem1 = new ListNode(temp1->val);
                ansptr->next = newelem1;
                ansptr = ansptr->next;
                ansptr->next = newelem2;
                ansptr = ansptr->next;
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }

        while(temp1){
            ListNode* newelem = new ListNode(temp1->val);
            ansptr->next = newelem;
            ansptr = ansptr->next;
            temp1 = temp1->next;
        }

        while(temp2){
            ListNode* newelem = new ListNode(temp2->val);
            ansptr->next = newelem;
            ansptr = ansptr->next;
            temp2 = temp2->next;
        }
        print(ans);
        
       
        return ans;
    }
*/


/*

    Print Kth Node from back (0 based index)
    (https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)

 
    SinglyLinkedListNode* reverse(SinglyLinkedListNode* head){
        SinglyLinkedListNode* prev = new SinglyLinkedListNode(head->data);
        SinglyLinkedListNode* temp = head;
        
        while(temp){
            SinglyLinkedListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }
        
        return prev;
    }

    void print(SinglyLinkedListNode* head){
        SinglyLinkedListNode* temp = head;
        
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
        if(llist == NULL){
            return -1;
        }
        SinglyLinkedListNode* newllist = reverse(llist);
        print(newllist);
        SinglyLinkedListNode* temp = newllist;
        int i = 0;
        while(temp){
            if(i == positionFromTail){
                return temp->data;
            }
            temp = temp->next;
            i = i + 1;
        }
        return -1;
    }



*/