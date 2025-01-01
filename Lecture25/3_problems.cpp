/*
    Array Subset
    (https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1)

    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int m = a.size();
        int n = b.size();
        
        unordered_map<int, int> valMap;
        
        for(auto val:a){
            valMap[val]++;
        }
        
        for(auto val:b){
            valMap[val]++;
        }
        
        if(m < n){
            for(auto val:a){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }else{
            for(auto val:b){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }
        
        return true;
    }

*/

/*
    Union of Two Linked Lists
    (https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1)

    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        map<int, int> valMap;
        
        while(head1){
            valMap[head1->data]++;
            head1 = head1->next;
        }
        
        while(head2){
            valMap[head2->data]++;
            head2 = head2->next;
        }
        
        Node* front = NULL;
        Node* back = NULL;
        for(auto val:valMap){
            Node* newNode = new Node(val.first);
            if(front == NULL){
                front = newNode;
                back = newNode;
            }else{
                back->next = newNode;
                back = back->next;
            }
            
        }
        return front;
    }
    
*/