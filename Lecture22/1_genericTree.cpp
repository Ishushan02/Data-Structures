#include<iostream>

using namespace std;

/*

    ALWAYS SOLVE THE TREE QUESTION BY MAKING DIAGRAM FIRST -- VERY VERY IMPORTANT

    Trees is a Non Linear Data Structure
                                    10                                            Level 0


                    20                             30                             Level 1
 
                      
            40               50           60                      70              Level 2


            - Adjacent Nodes are known as Siblings if they are from same parent Node.
            - Root Node is the top Node from which all nodes are generated
            - Node which has no child at all is known as leaf Node
            - Binary tree is a tree in which a Node will have either 1 or 2 Node as it's child 
            - Nodes above the parent Node is known as Ancestor Node
    
    All Traversal of a Tree Data Structure
    - Preorder Traversal -  (N, L, R)  {10, 20, 40, 50, 30, 60, 70}
    - Inorder Traversal - (L, N, R) {40, 20, 50, 10, 60, 30, 70}
    - Post Order Traversal - (L, R, N) {40, 50, 20, 60, 70, 30, 10}
    - Level Order Traversal - (Leve0, Level1, Level2, ...)  {10, 20, 30, 40, 50, 60, 70}
    - Morris Order Traversal (In Google Interview it's generally asked) {40, 20, 50, 10, 60, 30, 70}
      (Inorder Traversal without Recursion or Stack)

    - Skew Tree all Nodes are only on the left part of the tree

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

    void preOrderTraversal(Node* node){

        if(node == NULL){
            return ;
        }

        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);

    }

    void inOrderTraversal(Node* node){
        if(node == NULL){
            return ;
        }

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node){
        if(node == NULL){
            return ;
        }

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void levelOrderTraversal(Node* node){
        if(node == NULL){
            return;
        }

        if(node->left){
            cout << node->left->data << " ";
        }
        if(node->right){
            cout << node->right->data << " ";
        }

        levelOrderTraversal(node->left);
        levelOrderTraversal(node->right);

    }


};

void levelrightOrderTraversal(Node* node){
     if(node == NULL){
            return;
        }

    if(node->right){
        cout << node->right->data << " ";
    }
    if(node->left){
        cout << node->left->data << " ";
    }
    levelrightOrderTraversal(node->right);
    levelrightOrderTraversal(node->left);

}

int main(){

    Node* root = NULL; // just initializing 
    root = root->createTree();

    // created the above tree given in the comment
    // {10, 20, 40, -1, -1, 50, -1, -1, 30, 60, -1, -1, 70, -1, -1}
    cout << "Preorder Traversal of the Tree "<< endl;
    root->preOrderTraversal(root);
    cout << endl;


    cout << "Inorder Traversal of the Tree "<< endl;
    root->inOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal of the Tree "<< endl;
    root->postOrderTraversal(root);
    cout << endl;

    cout << "LevelOrder Traversal of the Tree "<< endl;
    cout << root->data << " ";
    root->levelOrderTraversal(root);
    cout << endl;

    cout << "Level Right Order Traversal of the Tree "<< endl;
    cout << root->data << " ";
    levelrightOrderTraversal(root);
    cout << endl;
    


    return 0;
}