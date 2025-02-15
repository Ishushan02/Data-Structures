#include<iostream>
#include<vector>

using namespace std;

/*

    ADOBDE and MICROSOFT asks lots of LinkeList Questions

*/

int main(){


}

/*

206. Reverse Linked List
(https://leetcode.com/problems/reverse-linked-list/)

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
(https://leetcode.com/problems/middle-of-the-linked-list/)

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

    // Method 2 of doing Tortoise Approach
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slowptr = head;
        ListNode* fastptr = head;

        while(fastptr){
            // cout << "Slow: " << slowptr->val << " , Fast: " << fastptr->val << endl;
            
            if(fastptr->next == NULL){
                break;
            }

            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        return slowptr;
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

    Method 2 (easier step, when we go and refer middle Node, that time only delete it)
    ListNode* getMiddleNode(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        while(fast){

            if(fast->next == NULL){
                break;
            }

            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
            
        }

        prev->next = slow->next;
        
        return head;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }

        ListNode* middleNode = getMiddleNode(head);

        return head;

    }
*/

/*

234. Palindrome Linked List
(https://leetcode.com/problems/palindrome-linked-list/description/)

    ListNode* MiddleNode(ListNode* &temp){
        ListNode* tor = temp;
        ListNode* rab = temp;

        while(rab){
            rab = rab->next;
            if(rab){
                rab = rab->next;
            }else{
                return tor;
            }
            tor = tor->next;
        }
        return tor;
    }

    int Length(ListNode* temp){
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

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

    bool isPalindrome(ListNode* head) {
        int len = Length(head);
        ListNode* midl = MiddleNode(head);
        cout << midl->val << " length is " << len << endl;
        ListNode* start = NULL;
        if(len%2 == 0){
            start = reverseList(midl);
        }else{
            start = reverseList(midl->next);
        }

        int temp = 0;
        while(temp<len/2){
            if(start->val != head->val){
                return false;
            }
            start = start->next;
            head = head->next;
            temp++;
        }
        return true;
    }
*/

/*

141. Linked List Cycle
(https://leetcode.com/problems/linked-list-cycle/submissions/1418112537/)

    Method 1
    bool hasCycle(ListNode *head) {
        int temp = 99999999;
        // cout << head->pos << endl;
        if(head == NULL || head->next == NULL){
            cout << " Here " << endl;
            return false;
        }
        while(head){
            if(head->val == 99999999){
                return true;
            }else{
                head->val = 99999999;
            }
            head = head->next;
        }

        return false;;
    }


    Method 2

// Fast pointer and slow pointer approach, if they meet at same pointer location then cycle approach. (rabbit and tortoise)

    bool hasCycle(ListNode *head) {
        if (!head || !head->next){
            return false;
        }

        ListNode* tor = head;
        ListNode* rab = head->next;
        
        while(rab && rab->next){
            if(tor == rab){
                return true;
            }

            tor = tor->next;
            rab = rab->next->next;
        }

        return false;
    }

/*

83. Remove Duplicates from Sorted List
(https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)

    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL){
            return head;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){
            if(prev->val == curr->val){
                ListNode* forw = curr->next;
                prev->next = forw;
                //. delete
                curr = curr->next;
            }else{
                curr = curr->next;
                prev = prev->next;
            }
        }


        return head;
    }

*/

/*

    Sort a linked list of 0s, 1s and 2s
    (https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

    void insertAtTail(Node* &tomove, Node* &head, Node* &tail){
        if(head == NULL && tail == NULL){
            head = tomove;
            tail = tomove;
        }else{
            tail->next = tomove;
            tail = tomove;
        }
    }
  
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node* onehead = NULL;
        Node* onetail = NULL;
        Node* twohead = NULL;
        Node* twotail = NULL;
        Node* zerohead = NULL;
        Node* zerotail = NULL;
        
        Node* temp = head;
        
        while(temp){
            
            Node* tomove = temp;
            temp = temp->next;
            tomove->next = NULL; // isolating it
            
            if(tomove->data == 0){
                insertAtTail(tomove, zerohead, zerotail);
            }else if(tomove->data == 1){
                insertAtTail(tomove, onehead, onetail);
            }else if(tomove->data = 2){
                insertAtTail(tomove, twohead, twotail);
            }
            
        }
        
        // merge all of them, don't forget empty list
        
        if(zerohead != NULL){
            if(onehead != NULL){
                zerotail->next = onehead;
                if(twohead != NULL){
                    onetail->next = twohead;
                }
                    //do nothing for else case
                
            }else{
                zerotail->next = twohead;
            }
            return zerohead;
            
        }else{
            if(onehead != NULL){
                onetail->next = twohead;
                    //do nothing for else case
            
                return onehead;
                
            }else{
                return twohead;
            }
        }
    }
    
    

*/

/*

    Add 1 to a Linked List Number
    (https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1)

    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;

        while(curr){
            Node* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;

        
    }
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* node = reverse(head);
        // print(node);
        
        Node* temp = node;
        
        int carry = 1;
        while(temp){
            // cout << temp->data << endl;
            int val = temp->data;
            int sum = val + carry;
            carry = sum / 10;
            int k = sum % 10;
            temp->data = k;
            
            // cout << newNode->data << endl;
            temp = temp->next;
        }
        
        if(carry != 0){
            Node* nn = new Node(carry);
            nn->next = node;
            node = nn;
            // node->next = NULL;
        }else{
            Node* ans = reverse(node);
            return ans;
        }
        // print(node);

        
        
        // print(node);
        
        return node;
    }
*/


/*
    IMP Question
    
    2. Add Two Numbers
    (https://leetcode.com/problems/add-two-numbers/)

    ListNode* reverseLL(ListNode* l){
        ListNode* temp = l;
        ListNode* prev = NULL;

        while(temp){
            ListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }

        return prev;
    }

    void print(ListNode* head){
        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count = count + 1;
            temp =temp->next;
        }

        return count;
    }

    ListNode* insertNode(ListNode* &head, ListNode* newNode){
        
        if(head == NULL){
            head = newNode;
            head->next = NULL;
            return head;
        }
        ListNode* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* listnum1 = l1;//reverseLL(l1);
        ListNode* listnum2 = l2;//reverseLL(l2);



        int n1 = getLength(listnum1);
        int n2 = getLength(listnum2);
        

        int count = n1 > n2 ? n1 : n2;
        
        // cout << count << " Count " << endl;
        int k = 0;
        int carry = 0;
        ListNode* ans = NULL;

        ListNode* temp = ans;
        while(k < count){
            
            int num1 = listnum1 ? listnum1->val : 0;
            int num2 = listnum2 ? listnum2->val : 0;

            int sum = num1 + num2 + carry;

            carry = sum / 10;
            int data = sum%10;

            ListNode* newNode = new ListNode(data);
            ans = insertNode(ans, newNode);
            k++;
            listnum1 = listnum1 ? listnum1->next: NULL;
            listnum2 = listnum2 ? listnum2->next: NULL;

        }

        if(carry != 0){
            ListNode* nn = new ListNode(carry);
            ans = insertNode(ans, nn);
            // return nn;
        }


        return ans;
    }




    // --------------------------------------------------------------------
    // Recursive Approach


    ListNode* recursiveAdd(ListNode* l1, ListNode* l2, int carry){

        if(!l1 && !l2 && !carry){return 0; }

        int a = l1 ? l1->val:0;
        int b = l2 ? l2->val:0;
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode* ans = new ListNode(digit);
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        ans->next = recursiveAdd(l1, l2, carry);

        return ans;


    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursiveAdd(l1, l2, 0);
    }

*/

/*

    Detect and Delete Loops

*/

/*

    Which Sorting Algo is best for LinkedList (QuickSort or MergeSort)

*/