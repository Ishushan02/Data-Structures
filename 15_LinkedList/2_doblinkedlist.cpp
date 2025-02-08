#include<iostream>
#include<vector>

using namespace std;

class Node{

     public:
       int data;
       Node* next;
       Node* prev;

     Node(int value){
          this->data = value;
          this->next = NULL;
          this->prev = NULL;
     }
};

Node* insertAtHead(int value, Node* &head, Node* &tail){

     if(head == NULL && tail == NULL ){ // no node exists
          Node* newNode = new Node(value);
          head = newNode;
          tail = newNode;

     }else{ // elemt already exists
          Node* newNode = new Node(value);
          head->prev = newNode;
          newNode->next = head;
          head = newNode;
     }

     return head;
}

Node* insertAtIndex(int value, int index, Node* &head, Node* &tail){

     Node* temp = head;
     int i = 0;

     while(temp){

          if (i == index - 1){

               Node* newNode = new Node(value);
               Node* nextelem = temp->next;

               if(nextelem == NULL){                
                    tail = newNode;
                    newNode->prev = temp;
                    newNode->next = NULL;
                    temp->next = newNode;
               }else{
                    newNode->prev = temp;
                    newNode->next = nextelem;

                    temp->next = newNode;
                    nextelem->prev = newNode;
               }
               break;

          }

          temp = temp->next;
          i++;
     }


     return head;
}


Node* deleteAtIndex(int index, Node* &head, Node* &tail){
     if(index == 0){
          Node* nextelem = head->next;
          nextelem->prev = NULL;
          head = nextelem;
          return head;
     }

     Node* temp = head;
     Node* prevs;
     int i = 0;

     while(temp){
          prevs = temp->prev;
          if(i == index-1){
               Node* nextNode = temp->next;
               prevs->next = nextNode;
               nextNode->prev = prevs;
               if(prevs->next == NULL){
                  tail = prevs;
               }

          }

          i++;
          temp = temp->next;
     }

     return head;
}

void printForwards(Node* &head){
     Node* i = head;
     cout << " Printing Forwards: "<< " ";
     while(i != NULL){
          cout << i->data << " ";
          i = i->next;
     }
    cout << endl;
}

void printBackwards(Node* &tail){
     Node* i = tail;
     cout << " Printing Backwards: "<< " ";
    while(i != NULL){
        cout << i->data << " ";
        i = i->prev;
    }
    cout << endl;
}

int main(){
     Node* head = NULL;
     Node* tail = NULL;
     head = insertAtHead(10, head, tail);
     head = insertAtHead(20, head, tail);
     head = insertAtHead(30, head, tail);

     printForwards(head);
     printBackwards(tail);

     head = insertAtIndex(40, 2, head, tail);
     printForwards(head);

     head = insertAtIndex(50, 4, head, tail);
     printForwards(head);

     head = insertAtIndex(70, 5, head, tail);
     printForwards(head);
     printBackwards(tail);

     head = deleteAtIndex(0, head, tail);
     printForwards(head);
     printBackwards(tail);

     // write search algo also


}