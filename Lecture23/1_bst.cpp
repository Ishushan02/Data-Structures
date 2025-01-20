#include<iostream>
#include<vector>
using namespace std;

/*

    It is a Binary tree wherein the 
    - left child is strictly smaller than the root Node and 
    - right child is strictly greater then the root Node.

*/

class Node{

    public :
     int data;
     Node* left;
     Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};


Node* BST(int val, Node* root){

    if(root == NULL){
        root = new Node(val);
        return root;
    }else{
        if(val < root->data){
            root->left = BST(val, root->left);
        }else{
            root->right = BST(val, root->right);
        }
    }
    return root ;
}

void preOrder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

bool search(int val, Node* root){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }

    bool ans1 = false;
    bool ans2 = false;
    if(val < root->data ){
        ans1 = search(val, root->left);
    }else{
        ans2 = search(val, root->right);
    }
    return ans1 || ans2;    
}


/*

`Delete Node {All Cases}
    if the Node has 2 child
    if the Node has 1 left child
    if the node has 1 right child
    if the node doesn't have any child

*/


int getMax(Node* root){
    if(root == NULL){
        return -1;
    }
    while(root->right){
        root = root->right;
    }

    return root->data;
}

Node* deleteNode(Node* root, int val){

    if(root == NULL){
        return NULL;
    }

    // search the node first
    if(root->data == val){
        // delete karna hai

        if(root->left == NULL && root->right == NULL){ // no children
            root = NULL;
            delete root;
            return NULL;
        }else if(root->left != NULL && root->right == NULL){ // only left node is present
            Node* leftchild = root->left;
            root->left = NULL;
            delete root;
            return leftchild;
        }else if(root->right != NULL && root->left == NULL){ // only right node is present
            Node* rightchild = root->right;
            root->right = NULL;
            delete root;
            return rightchild;
        }else{ // both Nodes are present

            // get next smallest element, which is max in the left of it
            int maxVal = getMax(root->left);
            root->data = maxVal; // replace root by that elemt

            // delete the max left from left tree;
            root->left = deleteNode(root->left, maxVal);
            return root;

        }
        
    }else{
        if(val < root->data){
            root->left = deleteNode(root->left, val);
        }else{
            root->right = deleteNode(root->right, val);
        }
    }
    return root;
    
}

int main(){

    int arr[] = {100, 50, 200, 70, 20, 250, 150, -1};
    Node* root = NULL;
    for(auto i : arr){
        if(i == -1){
            break;
        }else{
            root = BST(i, root);
        }
    }

    preOrder(root);
    cout << endl;
    cout << "Search eleemnt 250 is " << search(250, root) <<  endl;
    cout << "Search eleemnt -1 is " << search(-1, root) <<  endl;

    // The Min value of BST will be at the left->left->left.....
    // The Max value of BST will be at the right->right->right.......

    cout << "Max element in Left Tree is " << getMax(root->left) << endl;
    cout << "Max element in Right Tree is " << getMax(root->right) << endl;


    // delete Node 
    // deleteNode(root, 250);
    // deleteNode(root, 200);
    Node* val = deleteNode(root, 50);
    cout << val->data << endl;
    preOrder(root);

}