#include <iostream>

using namespace std;


int main(){

    return 0;
}


/*

    VVI and Tricky Question - Practise it.

    138. Copy List with Random Pointer
    (https://leetcode.com/problems/copy-list-with-random-pointer/)


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


/*

    61. Rotate List
    (https://leetcode.com/problems/rotate-list/description/)


    long length(ListNode* head){
        long len = 0;
        ListNode* temp = head;

        while(temp){
            len += 1;
            temp = temp->next;
        }

        return len;
    }


    ListNode* rotateList(ListNode* head){
        if (head == NULL){
            return NULL;
        }

        // 1, 2, 3, 4, 5
        ListNode* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        // temp as 4

        ListNode* rotatedHead = temp->next;
        rotatedHead->next = head;
        temp->next = nullptr;

        return rotatedHead;

    }

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }else if(head->next == NULL){
            return head;
        }

        long L = length(head);
        k = k % L;

        if(k == 0){
            return head;
        }

        ListNode* rotatedHead = rotateList(head);

        while(k-1){
            rotatedHead = rotateList(rotatedHead);
            k--;
        }

        return rotatedHead;
    }

    Method 2 // Easy Method

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* temp = head;
        int n = 0;

        while(temp){
            temp = temp->next;
            n++;
        }

        int stop = 0;

        k = k % n;
        stop = n - k;

        if(stop == 0 || k == 0){
            return head;
        }



        ListNode* ansList = NULL;
        ListNode* ansHead = NULL;

        temp = head;
        // cout << stop << endl;
        int count = 1;
        while(count && temp){
            if(count == stop){
                cout << temp->val << endl;
                ansList = temp->next;
                ansHead = temp->next;
                temp->next = NULL;
                break;
            }
            count++;
            temp = temp->next;
        }

        while(ansList->next){
            ansList = ansList->next;
        }

        ansList->next = head;
        ansList = ansList->next;

        return ansHead;
    }

*/

/*

    VVI Question - It's a Good Question

    2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
    (https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)


    Method 1 (TLE)
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* prev = head;
        ListNode* forw = head;
        ListNode* itr = head;
        int i = 1;
        vector<int> criticalPoints;

        while(itr->next){
            ListNode* curr = itr;
            forw = itr->next;

            if(curr->val < prev->val && curr->val < forw->val){
                criticalPoints.push_back(i);
                // cout << "Local Minima " << curr->val << " at " << i << endl;
            }
            if(curr->val > prev->val && curr->val > forw->val){
                criticalPoints.push_back(i);
                // cout << "Local Maxima " << curr->val << " at " << i << endl;
            }
            
            prev = curr;
            itr = itr->next;
            i++;
        }

        int n = criticalPoints.size();
        if(n == 0 || n == 1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int min_dist = INT_MAX;
        int max_dist = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                min_dist = min(min_dist, abs(criticalPoints[i] - criticalPoints[j]));
                max_dist = max(max_dist, abs(criticalPoints[i] - criticalPoints[j]));
            }
        }

        ans.push_back(min_dist);
        ans.push_back(max_dist);


        return ans;
    }


    Method 2

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* prev = head;
        ListNode* forw = head;
        ListNode* itr = head;
        int i = 1;
        // vector<int> criticalPoints;
        int prevcriticalPoint = -1; // to calculate minDistance at each iteration
        int firstcriticalPoint = -1; // store the first cPoint
        int lastcriticalPoint = -1; // store the last cPoint
        int minDist = INT_MAX; // store minimum dist between CPoint
        bool cPoint = false; // check at each iteration Cpoint is there or not and store that in prevCpoint


        while(itr->next){
            ListNode* curr = itr;
            forw = itr->next;

            if(curr->val < prev->val && curr->val < forw->val){
                cPoint = true;
                if(firstcriticalPoint == -1){
                    firstcriticalPoint = i;
                }

                lastcriticalPoint = i;

                if(lastcriticalPoint != firstcriticalPoint && prevcriticalPoint != -1){
                    minDist = min(minDist, abs(lastcriticalPoint - prevcriticalPoint));
                }

            }
            if(curr->val > prev->val && curr->val > forw->val){
                cPoint = true;
                if(firstcriticalPoint == -1){
                    firstcriticalPoint = i;
                }

                lastcriticalPoint = i;

                if(lastcriticalPoint != firstcriticalPoint && prevcriticalPoint != -1){
                    minDist = min(minDist, abs(lastcriticalPoint - prevcriticalPoint));
                }
            }

            if(cPoint){
                prevcriticalPoint = i;
                cPoint = false;
            }
            
            prev = curr;
            itr = itr->next;
            i++;
        }
        
        if (minDist == INT_MAX){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ans.push_back(minDist);
        ans.push_back(lastcriticalPoint - firstcriticalPoint);
        
        
        return ans;
    }

    Method 3  - (Same Logic as Method 2 but different way)

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* prevNode = head;
        if (prevNode == NULL){
            return ans;
        }
        ListNode* currNode = prevNode->next;
        if (currNode == NULL){
            return ans;
        }
        ListNode* futureNode = currNode->next;
        if (futureNode == NULL){
            return ans;
        }

        int MinDist = INT_MAX;
        int i = 1;
        int FNode = -1;
        int LNode = -1;

        while(currNode->next){

            futureNode = currNode->next;

            bool isCPoint = (currNode->val > futureNode->val && currNode->val > prevNode->val) || (currNode->val < futureNode->val && currNode->val < prevNode->val);
 
            if (isCPoint){
                if(FNode && LNode == -1){
                    FNode = i;
                    LNode = i;
                }else{
                    MinDist = min(MinDist, i - LNode);
                    LNode = i;
                }

            }
            i++;
            prevNode = currNode;
            currNode = currNode->next;
        }

        if(FNode == -1 || MinDist == INT_MAX){
            return ans;
        }

        ans[0] = MinDist;
        ans[1] = abs(LNode - FNode);

        return ans;

    }

*/

/*


    2181. Merge Nodes in Between Zeros
    (https://leetcode.com/problems/merge-nodes-in-between-zeros/submissions/1435719601/)

    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* ansptr = ans;

        ListNode* temp = head;

        while(temp){

            if(temp->val == 0 && sum != 0){
                ListNode* newNode = new ListNode(sum);
                ansptr->next = newNode;
                newNode = ansptr;
                ansptr = ansptr->next;                
                sum = 0;
            }else{
                sum = sum + temp->val;
            }

            temp = temp->next;
        }


        return ans->next; // the first element contains -1
    }

*/

/*

    2816. Double a Number Represented as a Linked List
    (https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/)

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* itr = head;

        while(itr){
            ListNode* newNode = new ListNode(itr->val);
            newNode->next = prev;
            prev = newNode;
            itr = itr->next;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        ListNode* temp = head;
        ListNode* reversedNode = reverse(temp);

        ListNode* itr = reversedNode;
        ListNode* prev = reversedNode;
        int carry = 0;
        while(itr){
            int value = itr->val * 2 + carry;
            itr->val = value%10;
            carry = value/10;
            prev = itr;
            itr = itr->next;
        }

        ListNode* ans = reverse(reversedNode);

        // instead of adding carry in rever, first reverse it and then add it on head
        if(carry != 0){
            ListNode* data = new ListNode(carry);
            data->next = ans;
            ans = data;
        }


        return ans;
    }
    
*/

/*

    // VVI Question, often Interview Question focus on it
    1171. Remove Zero Sum Consecutive Nodes from Linked List
    (https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/)

    void sanitizeMap(unordered_map<int, ListNode*>& sumvalues, ListNode* fromNode, int currSum){
        // DELETE THOSE MAP ENTERIES WHICH HAS TO BE REMOVED FROM LL
        int tempsum = currSum;

        while(true){
            tempsum += fromNode->val;
            if(tempsum == currSum){
                break;
            }
            sumvalues.erase(tempsum);
            fromNode = fromNode->next;
        }

       
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* it = head;
        if(head == NULL){
            return NULL;
        }

        unordered_map<int, ListNode*> sumvalues;

        int sum = 0;
        while(it){
            sum = sum + it->val;
            if(sum == 0){
                head = it->next;
                sumvalues.clear();
            }else if(sumvalues.find(sum) != sumvalues.end()){
                // to delete 
                sanitizeMap(sumvalues, sumvalues[sum]->next, sum); 
                sumvalues[sum]->next = it->next;
            }else{
                // ListNode* newNode = it;
                sumvalues[sum] = it;
            }

            it = it->next;
        }

        return head;
    }

*/

/*

    1721. Swapping Nodes in a Linked List
    (https://leetcode.com/problems/swapping-nodes-in-a-linked-list/submissions/1438207425/)

    int length(ListNode* head){

        int n = 0;

        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }

        return n;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n = length(head);
        ListNode* firstptr = NULL;
        ListNode* secondptr = NULL;


        ListNode* temp = head;
        int i = 1;
        while(temp){

            if(i == k){
                ListNode* nn = temp;
                firstptr = nn;
            }
            if(i == n-k+1){
                ListNode* nn = temp;
                secondptr = nn;
            }
            i++;
            temp = temp->next;
        }

        int p = firstptr->val;
        firstptr->val = secondptr->val;
        secondptr->val = p;

        return head;
    }

*/


/*
VVVVIIIIII Question--
// Sort LinkedList using Merge Sort

    148. Sort List
    (https://leetcode.com/problems/sort-list/description/)


    ListNode* getMid(ListNode* head){

        ListNode* sloptr = head;
        ListNode* fastptr = head->next;


        while(fastptr && fastptr->next){
            
            sloptr = sloptr->next;
            fastptr = fastptr->next->next; 
        }
        cout << sloptr->val << endl;
        return sloptr;

    }

    // fromquestion 21
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
        // print(ans);
        
       
        return ans;
    }

    ListNode* Divide(ListNode* head){

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* mid = getMid(head);
        
        ListNode* leftNode = head;
        ListNode* rightNode = mid->next;
        mid->next = NULL;

        leftNode = Divide(leftNode);
        rightNode = Divide(rightNode);

        ListNode* mergedList = mergeTwoLists(leftNode, rightNode);
        return mergedList;

    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* mergedLL = Divide(head);

        return mergedLL;
    }

*/