#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node* next; 

        Node(int value){
            this->data = value;
            this->next = NULL;
        }

};


Node* insertHead(int value, Node* &head, Node* &tail){
    // if it is a new Node
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;

    }else{
        Node* newNode = new Node(value);
        newNode->next = head; // connecting to head 
        head = newNode;
    }

    return head;
}

Node* insertAtIndex(int index, Node* &head, Node* &tail, int value){
    int i = 0;

    Node* temp = head;

    while(temp){

        if(i == index-1){
            
            Node* newNode = new Node(value);
            Node* nextNode = temp->next;
            temp->next = newNode;
            
            if(nextNode == NULL){
                newNode->next = NULL;
                tail = newNode;
            }else{
                newNode->next = nextNode;
            }
            break;
            // temp->next = newNode;
            
            
        }
        i++;
        temp = temp->next;
    }
    return head;
}

Node* insertAtTail(int value, Node* &head, Node* &tail){
    Node* temp = head;

    while(temp != tail){
        temp = temp->next;
    }

    Node* newNode = new Node(value);
    temp->next = newNode;
    tail = newNode;
    newNode->next = NULL;

    return head;

}

void printLinkedList(Node* &head){
    Node* i = head;

    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
}

bool search(Node* &head, int value){
    Node* i = head;

    while(i != NULL){
        if(i->data == value){
            return true;
        }
       i= i->next;
    }
    return false;
}

Node* deleteatIndex(Node* &head, Node* &tail, int index){
    int i = 0;

    Node* temp = head;
    Node* prev = head;

    while(temp){

        if(i == index - 1){

            prev = temp;
            
            
            // Node* newNode = new Node(value);
            Node* nextNode = temp->next;
            temp->next = nextNode;
            
            prev->next = nextNode->next;
            if(prev->next == NULL){
                tail = prev;
            }
            // temp->next = newNode;
            
            
        }else{
            temp = temp->next;
        }
        i++;
        
    }
    return head;
}

int main(){
    /*
    // static memory allocation 
    Node first;
    */


    // dynamic memory allocation
    Node* head = NULL;
    Node* tail = NULL;
    head = insertHead(10, head, tail);
    head = insertHead(20, head, tail);
    head = insertHead(30, head, tail);
    head = insertHead(40, head, tail);
    head = insertHead(50, head, tail);

    printLinkedList(head);

    insertAtIndex(4, head, tail, 70);

    printLinkedList(head);
    head = insertAtTail(90, head, tail);
    head = insertAtTail(100, head, tail);
    printLinkedList(head);

    // cout << " Element is present 70 "<< search(head, 70) << endl;

    head = deleteatIndex(head, tail, 7);
    printLinkedList(head);


    return 0;

}