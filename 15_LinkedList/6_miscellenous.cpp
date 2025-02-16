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

/*  
    705. Design HashSet
    (https://leetcode.com/problems/design-hashset/description/)

    class LinkedList{
    public:
        int val;
        LinkedList* next;

        LinkedList(int value){
            this->val = value;
            this->next = NULL;
        }
};

class MyHashSet {
public:

    LinkedList* ll ;
    LinkedList* head;

    MyHashSet() {
        ll = NULL;
        head = ll;
    }
    
    void add(int key) {
        if(contains(key)){
            return ;
        }

        LinkedList* node = new LinkedList(key);
        if(head == NULL){
            head = node;
        }else{
            
            LinkedList* temp = head;

            while(temp->next){
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    
    void remove(int val) {

        if(head == NULL){
            return ;
        }

        if(head->next == NULL){
            if(head->val == val){
                return ;
            }
            return ;
        }

        LinkedList* begin = head;
        LinkedList* end = head->next;

        while(end){

            if(end->val == val){
                LinkedList* temp = end;
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
            head = head->next;
        }        

    }
    
    bool contains(int key) {
        
        LinkedList* temp = head;

        while(temp){
            // cout << temp->val << " ";
            if(temp->val == key){
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
};

*/

/*
    19. Remove Nth Node From End of List
    (https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

    ListNode* reverse(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* head = temp;
        while(head){
            ListNode* forw = head->next;
            head->next = prev;
            prev = head;
            head = forw;

        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* reverseList = reverse(head);

        ListNode* temp = reverseList;
        if(n == 1){
            temp = temp->next;
            return reverse(temp);
        }
        int count = 1;
        while(temp){

            if(count == n-1){
                // cout << " Here "<< endl;
                if(temp->next && temp->next->next){
                    ListNode* fut = temp->next->next;
                    temp->next = fut;
                    temp = temp->next;
                }else{
                    temp->next = NULL;
                    // temp = temp->next;
                }
                break;
                
            }
            count++;
            temp = temp->next;
        }

        ListNode* v = reverseList;

        // while(v){
        //     cout << v->val << endl;
        //     v = v->next;
        // }


        
        return reverse(reverseList);

    }

*/

/*
    24. Swap Nodes in Pairs
    (https://leetcode.com/problems/swap-nodes-in-pairs/description/)

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        while(firstNode->next){
            swap(firstNode->val, secondNode->val);
            if(firstNode->next){
                firstNode = firstNode->next->next;
            }else{
                break;
            }
            if(secondNode->next){
                secondNode = secondNode->next->next;
            }else{
                break;
            }
            
            // break;
        }

        return head;
    }
*/

/*
    82. Remove Duplicates from Sorted List II
    (https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)

    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }

        map<int, int> mapVal;

        ListNode* temp = head;
        while(temp){
            mapVal[temp->val]++;
            temp = temp->next;
        }

        ListNode* anslist = NULL;
        ListNode* ansHead = NULL;

        for(auto &[key, val]:mapVal){
            if(val == 1){
                ListNode* newNode = new ListNode(key);

                if(anslist == NULL){
                    anslist = newNode;
                    ansHead = newNode;
                }else{
                    anslist->next = newNode;
                    anslist = anslist->next;
                }
            }
        }

        return ansHead;

    }

    
*/