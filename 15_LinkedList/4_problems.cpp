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


    Method 2
    // Procedure is that first create a function to reverse K nodes, and return 
        the reverse nodes head only if all the count of k is completed, else reverse initial head 

    ListNode* reverse(ListNode* start, int count){

        ListNode* curr = start;
        ListNode* prev = NULL;

        while(count && start){
            ListNode* temp = new ListNode(start->val);
            temp->next = prev ;
            prev = temp;
            start = start->next;
            count--;
        }

        if(count == 0){
            return prev;
        }else{
        // all nodes are not reversed, hence sending startigh result
            return curr;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* ansHead = NULL; // to return this
        ListNode* ans = ansHead; // ans List such that whenever reversed list comes, connect it.


        while(temp){
                ListNode* reverseNodes = reverse(temp, k);
                if(ansHead == NULL){
                    ansHead = reverseNodes;
                    ans = ansHead;
                }else{
                    while(ans->next){
                        ans = ans->next;
                    }
                    ans->next = reverseNodes;
                }

            //  shift temp to that part untill the List is reversed
            int tempCount = k-1;
            while(temp->next && tempCount){
                temp = temp->next;
                tempCount--;
            }

            temp = temp->next;
        }

        

        return ansHead;
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

    Method 2 (Simple and Easy)
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* evenList = NULL;
        ListNode* evenListHead = NULL;
        ListNode* oddList = NULL;
        ListNode* oddListHead = NULL;


        int i = 0;
        ListNode* temp = head;

        while(temp){
            ListNode* node = new ListNode(temp->val);
            if(i&1){
                if(oddList == NULL){
                    oddList = node;
                    oddListHead = node;
                }else{
                    oddList->next = node;
                    oddList = oddList->next;
                }
            }else{
                if(evenList == NULL){
                    evenList = node;
                    evenListHead = node;
                }else{
                    evenList->next = node;
                    evenList = evenList->next;
                }
            }
            i++;
            temp = temp->next;
        }

        evenList->next = oddListHead;
        evenList = evenList->next;

        return evenListHead;
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

    Method 2
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> indexMap;


        ListNode* temp = head;
        int idx = 0;

        while(temp){
            if(indexMap.find(temp) != indexMap.end()){
                return temp;
            }
            
            indexMap[temp] = idx;
            idx++;
            temp = temp->next;
        }

        return NULL;
    }
*/

/*

    // Note the additional addition of temp in the LinkedList (the condition in For Loop)

    NOTE N REMEMBER THIS TIP

    // Seee the 2nd Method
    // If there are N nodes in the list, and k parts, then every part has N/k elements, 
    // except the first N%k parts have an extra one.

    725. Split Linked List in Parts
    (https://leetcode.com/problems/split-linked-list-in-parts/)
    
    // removed 1st method

    Method 2

    ListNode* getList(ListNode* start, int count, vector<ListNode*> &ans){

        ListNode* temp = start;
        ListNode* tempHead = NULL;
        ListNode* tail = NULL;

        while(temp  && count){
            ListNode* newNode = new ListNode(temp->val);
            if(tempHead == NULL){
                tempHead = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }

            temp = temp->next;
            count--;
        }

        ans.push_back(tempHead);
        
        return temp;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ans;

        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        int partA = n / k;
        int partB = n % k;

        ListNode* start = head;

        for(int i = 1; i <= k; i++){

            if(i <= partB){
                
                int count = partA + 1;
                start = getList(start, count, ans);

            }else{
                int count = partA ;
                start = getList(start, count, ans);
            }
            
            
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


    Method 2 (Something Similar)

    pair<Node*, Node*> flattenNodes(Node* head){

        Node* headNode = head;
        Node* tailNode = head;

        while(headNode){
            
            if(headNode->child){
                Node* futureNodes = headNode->next;
                pair<Node*, Node*> nodes = flattenNodes(headNode->child);
                headNode->child = NULL;
                
                Node* flatHead = nodes.first;
                Node* flatTail = nodes.second;
                // cout << headNode->val << ": " << flatHead->val << " " << flatTail->val << endl;

                headNode->next = flatHead;
                flatHead->prev = headNode;

                flatTail->next = futureNodes;
                if(futureNodes){
                    futureNodes->prev = flatTail;
                }
                
            }
            // cout << headNode->val << endl;

            tailNode = headNode;
            headNode = headNode->next;
        }


        return {head, tailNode};

    }

    Node* flatten(Node* head) {
        
        pair<Node*, Node*> nodes = flattenNodes(head);
        Node* flatHead = nodes.first;
        Node* flatTail = nodes.second;

        // cout << flatHead->val << " " << flatTail->val << endl;

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

    Method 2

    Node* linkdelete(Node* head, int n, int m) {
        // code here
        
        int count = 1;
        Node* temp = head;
        
        while(temp){
            
            
            if(count == m){
                Node* todelete = temp->next;
                temp->next = NULL;
                
                int c = n;
                while(c && todelete){
                    todelete = todelete->next;
                    c--;
                }
                
                count = 0;
                if(todelete){
                    temp->next = todelete;
                }else{
                    temp = temp->next;
                }
                
            }else{
                count++;
                temp = temp->next;
            }
            
            
        }
        
        return head;
        
    }

*/


/*
    21. Merge Two Sorted Lists
    (https://leetcode.com/problems/merge-two-sorted-lists/)

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


/*

    160. Intersection of Two Linked Lists
    (https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }

        ListNode* temp1 = headA;
        ListNode* temp3 = headA;
        ListNode* temp2 = headB;
        ListNode* ans = NULL;

        while(temp1){
            temp1->val = -1 * temp1->val;

            temp1 = temp1->next;
        }

        while(temp2){
            if(temp2->val < 0){
                temp2->val = temp2->val;
                 ans = temp2;
                break;
            }

            temp2 = temp2->next;
        }

        while(temp3){
            temp3->val = -1 * temp3->val;

            temp3 = temp3->next;
        }

        return ans;
    }

*/


/*

    Flattening a Linked List
    (https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        int elem;
        if(list1->data <= list2->data){
            elem = list1->data;
            list1 = list1->bottom;
        }else{
            elem = list2->data;
            list2 = list2->bottom;
        }

        Node* temp1 = list1;
        Node* temp2 = list2;
        
        Node* ans = new Node(elem);

        Node* ansptr = ans;

        while(temp1 && temp2){

            if(temp1->data < temp2->data){
                Node* newelem = new Node(temp1->data);
                ansptr->bottom = newelem;
                ansptr = ansptr->bottom;
                temp1 = temp1->bottom;
            }else if(temp1->data > temp2->data){
                Node* newelem = new Node(temp2->data);
                ansptr->bottom = newelem;
                ansptr = ansptr->bottom;
                temp2 = temp2->bottom;
            }else{
                Node* newelem2 = new Node(temp2->data);
                Node* newelem1 = new Node(temp1->data);
                ansptr->bottom = newelem1;
                ansptr = ansptr->bottom;
                ansptr->bottom = newelem2;
                ansptr = ansptr->bottom;
                temp2 = temp2->bottom;
                temp1 = temp1->bottom;
            }
        }

        while(temp1){
            Node* newelem = new Node(temp1->data);
            ansptr->bottom = newelem;
            ansptr = ansptr->bottom;
            temp1 = temp1->bottom;
        }

        while(temp2){
            Node* newelem = new Node(temp2->data);
            ansptr->bottom = newelem;
            ansptr = ansptr->bottom;
            temp2 = temp2->bottom;
        }
        
        // print(ans);
        // cout << "******" << endl;
        return ans;
    }
    
    Node* insertNode(Node* &head, Node* elem){
        if(head == NULL){
            head = elem;
            head->next = NULL;
            return head;
        }
        Node* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = elem;
        elem->next = NULL;

        return head;
    }
    
     
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        
        Node* temp = root;
        Node* list1 = temp;
        temp = temp->next;
        
        while(temp){
            Node* list2 = temp;
            list1 = mergeTwoLists(list1, list2);
            temp = temp->next;
        }
        
        return list1;
        
    }




    // ---------------------------------------------------------------------------------------

    // VVVVVI Method 2, Focus on the method -- 

    Node* mergeNode(Node* a, Node* b){
        if(a == NULL){
            return b;
        }
        
        if(b == NULL){
            return a;
        }
        
        Node* ans = 0; // This is same sa initializing it to NULL
        
        if(a->data < b->data){
            ans = a;
            a->bottom = mergeNode(a->bottom, b);
        }else{
            ans = b;
            b->bottom = mergeNode(a, b->bottom);
        }
        
        return ans;
        
        
    }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root == NULL){
            return NULL;
        }
        Node* ans = mergeNode(root, flatten(root->next));
        
        return ans;
    }

*/