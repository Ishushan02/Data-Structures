#include<iostream>
#include<map>

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
    

    Trie 
    It is a Multiway Tree Data Structure
        - stores mostly char
        - It is used to store strings
        - child map<int, trieNode* >
        - bool terminal
*/


class Trie{

    public:
    char value;
    unordered_map<int, Trie*> child;
    bool isTreminal = false;

    Trie(char charval){
        value = charval;
        isTreminal = false;
    }

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
};



/*
    (Very Very Important Question)
    30. Substring with Concatenation of All Words
    (https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        unordered_map<string, int> wordFreq;

        for(auto each_word:words){
            wordFreq[each_word]++;
        }

        int wordlen = words[0].length();
        int windowlen = wordlen * words.size();

        for(int i = 0; i + windowlen <= s.length(); i = i + 1){
            string substring = s.substr(i, windowlen);
            // cout << "Each Substr: " << substring << endl;

            // store all temp substring in tempMap
            unordered_map<string, int> tempwordFreq;
            for(int j = i; j <  i + windowlen; j = j + wordlen){
                string eachstr = s.substr(j, wordlen);
                if(wordFreq.find(eachstr) == wordFreq.end()){
                    break;
                }else{
                    tempwordFreq[eachstr]++;
                }
                
            }

            // compare both the maps
            bool val = true;
            for(auto each_substr:wordFreq){
                if(tempwordFreq[each_substr.first] != each_substr.second){
                    val = false;
                    break;
                }else{
                    val = true;
                }
            }

            if(val){
                ans.push_back(i);
            }
            
        }
        
        return ans;
    }

*/


