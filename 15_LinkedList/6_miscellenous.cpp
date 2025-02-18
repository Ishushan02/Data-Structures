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

/*
    3217. Delete Nodes From Linked List Present in Array
    (https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/)

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* anshead =NULL;
        ListNode* anslist =NULL;

        unordered_map<int, bool> valMap;
        for(auto v:nums){
            valMap[v] = true;
        }

        ListNode* temp = head;

        while(temp){
            int value = temp->val;

            if(valMap[value] == 0){
                ListNode* newNode = new ListNode(value);
                if(anslist == NULL){
                    anslist = newNode;
                    anshead = newNode;
                }else{
                    anslist->next = newNode;
                    anslist = anslist->next;
                }
            }

            temp = temp->next;
        }

        return anshead;

    }

*/

/*
    2807. Insert Greatest Common Divisors in Linked List
    (https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/)

    int getGCD(int a, int b){
        if(a == 0){
            return b;
        }else if(b == 0){
            return a;
        }

        while(a > 0 && b > 0){
            if(a > b){
                a = a - b;
            }else{
                b = b - a;
            }
        }

        if(a == 0){
            return b;
        }

        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* anslist = NULL;
        ListNode* anshead = NULL;

        ListNode* temp = head;

        while(temp->next){

            int a = temp->val;
            int b = temp->next->val;

            int gcd = getGCD(a, b);

            ListNode* newa = new ListNode(a);
            ListNode* newb = new ListNode(b);
            ListNode* newgcd = new ListNode(gcd);


            if(anslist == NULL){
                anshead = newa;
                anslist = newa;
                anslist->next = newgcd;
                anslist = anslist->next;
                anslist->next = newb;
                anslist = anslist->next;
            }else{
                anslist->next = newgcd;
                anslist = anslist->next;
                anslist->next = newb;
                anslist = anslist->next;
            }

            temp = temp->next;

        }

        return anshead;

    }


*/

/*
    2487. Remove Nodes From Linked List
    (https://leetcode.com/problems/remove-nodes-from-linked-list/description/)

    ListNode* reverseNodes(ListNode* head){
        ListNode* prev = NULL;

        ListNode* temp = head;

        while(temp){
            ListNode* future = temp->next;
            temp->next = prev;
            prev = temp;
            temp = future;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        
        ListNode* reversedNodes = reverseNodes(head);

        int maxNum = -1;
        ListNode* temp = reversedNodes;
        ListNode* anslist = NULL;
        ListNode* ansHead = NULL;

        while(temp){
            int val = temp->val;
            if(val >= maxNum){
                maxNum = val;
                ListNode* newNode = new ListNode(val);
                if(anslist== NULL){
                    anslist = newNode;
                    ansHead = newNode;
                }else{
                    anslist->next = newNode;
                    anslist = anslist->next;
                }
            }

            temp = temp->next;
        }
        return reverseNodes(ansHead);
    }
        
*/

/*
    2326. Spiral Matrix IV
    (https://leetcode.com/problems/spiral-matrix-iv/)

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int row = m;
        int col = n;
        int startRow = 0;
        int endRow = row - 1;
        int startCol = 0;
        int endCol = col - 1;

        ListNode* temp = head;

        while(temp){
            for(int i = startCol; temp && i <= endCol; i++){
                ans[startRow][i] = temp->val;
                temp = temp->next;
            }
            startRow++;


            for(int i = startRow; temp && i <= endRow; i++){
                ans[i][endCol] = temp->val;
                temp = temp->next;
            }
            endCol--;

            for(int i = endCol; temp && i >= startCol; i--){
                ans[endRow][i] = temp->val;
                temp = temp->next;
            }
            cout << endl;
            endRow--;

            for(int i = endRow; temp && i >= startRow; i--){
                ans[i][startCol] = temp->val;
                temp = temp->next;
            }
            startCol++;

        }

        return ans;


    }

*/

/*
    116. Populating Next Right Pointers in Each Node
    (https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)

    and

    117. Populating Next Right Pointers in Each Node II
    (https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)

    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        Node* temp = root;
        queue<Node*> que;
        que.push(temp);
        temp->next = NULL;

        
        while(!que.empty()){

            int size = que.size();
            Node* prevright = NULL;

            for(int i = 0; i < size; i++){
                Node* front = que.front();
                que.pop();
                if(front->right){
                    front->right->next = prevright;
                    prevright = front->right;
                    que.push(front->right);
                }
                if(front->left){
                    front->left->next = prevright;
                    prevright = front->left;
                    que.push(front->left);
                }
                // que.pop();
            }

        }

        return root;
        

    }

*/

/*
    445. Add Two Numbers II
    (https://leetcode.com/problems/add-two-numbers-ii/description/)

    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;

        while(head){

            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* num1 = reverse(l1);
        ListNode* num2 = reverse(l2);
        ListNode* ans = NULL;
        ListNode* ansHead = NULL;
        int prevSum = 0;

        while(num1 || num2){

            if(num1 != NULL && num2 == NULL){
                int sum = num1->val + prevSum;
                int digit = sum % 10;
                prevSum = sum / 10 ;

                ListNode* newNode = new ListNode(digit);
                if(ans == NULL){
                    ans = newNode;
                    ansHead = ans;
                }else{
                    ans->next = newNode;
                    ans = ans->next;
                }

                num1 = num1->next;
            }else if(num1 == NULL && num2 != NULL){
                int sum = num2->val + prevSum;
                int digit = sum % 10;
                prevSum = sum / 10 ;

                ListNode* newNode = new ListNode(digit);
                if(ans == NULL){
                    ans = newNode;
                    ansHead = ans;
                }else{
                    ans->next = newNode;
                    ans = ans->next;
                }

                num2 = num2->next;
            }else{

                int sum = num1->val + num2->val + prevSum;
                int digit = sum % 10;
                prevSum = sum / 10 ;

                ListNode* newNode = new ListNode(digit);
                if(ans == NULL){
                    ans = newNode;
                    ansHead = ans;
                }else{
                    ans->next = newNode;
                    ans = ans->next;
                }

                num1 = num1->next;
                num2 = num2->next;


            }
        }

        if(prevSum > 0){
            ListNode* newNode = new ListNode(prevSum);
            ans->next = newNode;
            ans = ans->next;
                
        }
        return reverse(ansHead);

    

    }


*/

/*
    86. Partition List
    (https://leetcode.com/problems/partition-list/description/)

    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lowerNodes = NULL;
        ListNode* greaterNodes = NULL;
        ListNode* lowerhead = NULL;
        ListNode* greaterhead = NULL;

        ListNode* temp = head;

        while(temp){
            ListNode* newNode = new ListNode(temp->val);

            if(newNode->val < x){
                if(lowerNodes == NULL){
                    lowerNodes = newNode;
                    lowerhead = newNode;
                }else{
                    lowerNodes->next = newNode;
                    lowerNodes = lowerNodes->next;
                }
            }else if(newNode->val >= x){
                if(greaterNodes == NULL){
                    greaterNodes = newNode;
                    greaterhead = newNode;
                }else{
                    greaterNodes->next = newNode;
                    greaterNodes = greaterNodes->next;
                }
            }
            temp = temp->next;
        }

        if(lowerNodes){
            lowerNodes->next = greaterhead;
            lowerNodes = lowerNodes->next;
            return lowerhead;
        }

        return greaterhead;

    }
        
*/