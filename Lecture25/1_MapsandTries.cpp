#include<iostream>
#include<map>
#include <string>
#include <unordered_map>

/*

    NEW METHOD OF LOPPING MAP

    unordered_map<string, int> myMap;

    for(auto &[key, val]:myMap){
        cout << key << " , " << val << endl;
    }

    // without address also it will work fine with copy of key and val in the variable
    // but then with address it's copy won't be created
    // and directed there address are accessed

*/

using namespace std;
/*

Maps - 
    Ordered Map - Acess(O(logn)), Insert(O(logn)), Delete(O(logn)) -  It is implemented using Balance BST
    Unordered Map - Acess(O(1)), Insert(O(1)), Delete(O(1)) - 
        For Unordered map, it works like array, so whenever we give it a key,
        there will be a hash function which converts the string value into desired integer value
        and then that value will be stored int that index of Array.

        Hash FUnction is combined of hash Code and Compression Function
        fo whenever an unordered map is declared, it will assign a fix size of array,
        next once you give any key value too it the Code part of hash function will 
        conver the key into integer value and upon which the integer value is then
        comressed to the range of that array size, after which on that index the 
        value is stored.

    map.find(key)

    - Linear Probing
    - Quadratic Probing
    - Collision wala {}
    - Load Factor {If load Factor is < 0.7, then it is said that we are using efficient Hash Function}
    - 
    

Trie - {It is also said as Prefix Tree} 
    It is a Multiway Tree Data Structure
        - stores mostly char
        - It is used to store strings
        - child map<int, trieNode* >
        - bool terminal
     - Search in Trie O(len of word for search)
     - Insert in Trie O(len of word for search)

*/

/*
    // Comparator Example in MAP

    struct MyComparator {
        bool operator()(const int a, const int b) const{
            return a > b; // Reverse the order
        }
    };
    
    void main(vector<int>& nums) {
        
        map<int, int, MyComparator> numsMap;

        for(auto &[key, val]:numsMap){
            cout << val << endl;
        }


    }


*/

class Trie{

    public:
        char value;
        unordered_map<char, Trie*> child;
        bool isTreminal;

    Trie(char charval){
        value = charval;
        isTreminal = false;
    }
};

void insert(Trie* root, string word){
        // base case
        if(word.length() == 0){
            root->isTreminal = true;
            return ;
        }

        // insert char
        char ch = word[0];
        Trie* newNode;

        // if char is present, link it
        if(root->child.count(ch) == 1){
            newNode = root->child[ch];
        }else{
            // create one and link it
            newNode = new Trie(ch);
            root->child[ch] = newNode;
        }

        insert(newNode, word.substr(1));


    }

bool search(Trie* root, string word){
    if(word.length() == 0){// last character in root
        if(root->isTreminal == true){ // last word is terminal Node
            return true;
        }else{
            return false;
        }
    }

    char ch = word[0];
    Trie* child;

    if(root->child.find(ch) != root->child.end()){
        // present;
        child = root->child[ch];
    }else{
        // not present
        return false;
    }

    return search(child, word.substr(1));

}


/*
    To delete, if we mark the terminal node of that word to be False, then it will be same 
    as the word in not present in the Trie, so deleting the trie is like just marking the terminal 
    node as false.

    We should not delete the entire Node, as deleting the entire node it will not only effect 
    the current Node it will effect all the related nodes. So don;t delete all the nodes, just
    mark the terminal node as false.

*/


void deleteNode(Trie* root, string word){
    // base case
    if(word.length() == 0){
        // end case
        if(root->isTreminal == true){
            root->isTreminal = false;
            return ;
        }else{
            // nothing to delete as that word won't be present
            return ;
        }
    }

    char ch = word[0];
    Trie* childNode;

    if(root->child.find(ch) != root->child.end()){
        childNode = root->child[ch];
    }else{
        // the char is not present so nothing to delete
        return ;

    }

    deleteNode(childNode, word.substr(1));

}


int main(){

    Trie* root = new Trie('-');

    insert(root, "ishan");
    insert(root, "ishu");
    insert(root, "ishananand");
    insert(root, "iloveyou");

    cout << search(root, "ishan") << endl;
    cout << search(root, "ish") << endl;
    cout << search(root, "ishu") << endl;
    cout << search(root, "ishunan") << endl;
    cout << search(root, "ishunanand") << endl;

    deleteNode(root, "ishan");
    cout << "Deleted ishan: " << endl;
    cout << search(root, "ishan") << endl;
    insert(root, "ishan");

}

