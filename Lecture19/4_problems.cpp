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