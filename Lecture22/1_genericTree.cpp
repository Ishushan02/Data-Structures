#include<iostream>

using namespace std;

/*

    Trees is a Non Linear Data Structure
                                    10                                            Level0


                    20                             30                             Level1
 
                      
            40               50           60                      70              Level2


            - Adjacent Nodes are known as Siblings if they are from same parent Node.
            - Root Node is the top Node from which all nodes are generated
            - Nod which has no child at all is known as leaf Node
            - Binary tree is a tree in which a Node will have either 1 or 2 Node as it's child 
            - Nodes above the parent Node is known as Ancestor Node
    
    All Traversal of a Tree Data Structure
    - Preorder Traversal -  (N, L, R)  {10, 20, 40, 50, 30, 60, 70}
    - Inorder Traversal - (L, N, R) {40, 20, 50, 10, 60, 30, 70}
    - Post Order Traversal - (L, R, N) {40, 50, 20, 60, 70, 30, 10}
    - Level Order Traversal - (Leve0, Level1, Level2, ...)  {10, 20, 30, 40, 50, 60, 70}
    - Morris Order Traversal (In Google Interview it's generally asked) {40, 20, 50, 10, 60, 30, 70}
      (Inorder Traversal without Recursion or Stack)

*/

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    Node* createTree(){

        int value;
        cout << "Enter Value of Node " << endl;
        cin >> value;

        if(value == -1){
            return  NULL;
        }else{

            Node* rootNode = new Node(value);
            cout << "Adding Left Child for " << value << endl;
            rootNode->left = createTree();
            cout << "Adding Right Child for " << value << endl;
            rootNode->right = createTree();

            return rootNode;
        }

    }


};

int main(){

    Node* root = NULL; // just initializing 
    root = root->createTree();
    return 0;
}