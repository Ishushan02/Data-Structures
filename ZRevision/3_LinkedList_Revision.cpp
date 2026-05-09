/*
    Find length of Loop
    (https://www.geeksforgeeks.org/problems/find-length-of-loop/1)

    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head->next == NULL) return 0;
        Node* rab = head;
        Node* tor = head;
        
        while(rab && rab->next){
            tor = tor->next;
            rab = rab->next->next;
            if(tor == rab){
                int count = 1;
                Node* temp = tor->next;
                while (temp != tor) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }
        
        return 0;
    }
        
*/