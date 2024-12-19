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

int main(){

    int arr[] = {100, 50, 200, 70, 20, 250, 150, -1};
    Node* root = NULL;
    for(auto i : arr){
        if (i == -1){
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
}