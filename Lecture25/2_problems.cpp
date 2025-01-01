
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


/*
    208. Implement Trie (Prefix Tree) {Good Question}
    (https://leetcode.com/problems/implement-trie-prefix-tree/description/)

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> childNode;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }

        void insert(TrieNode* root, string word) {
            if(word.length() == 0){
                root->isTerminal = true;
                return ;
            }

            TrieNode* child;
            char ch = word[0];
            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                child = new TrieNode(ch);
                root->childNode[ch] = child;
            }
            insert(child, word.substr(1));

        }

        bool search(TrieNode* root, string word) {
            if(word.length() == 0){
                return root->isTerminal;
            }

            char ch = word[0];
            TrieNode* child;

            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                return false;
            }
            return search(child, word.substr(1));
        }

        bool startsWith(TrieNode* root, string prefix) {
            if(prefix.length() == 0){
                return true;
            }

            char ch = prefix[0];
            TrieNode* child;

            cout << ch << endl;

            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                return false;
            }
            return startsWith(child, prefix.substr(1));
        }

};

    class Trie {
    public:
        // 
        TrieNode* root;

        Trie() {
            root = new TrieNode('-');
        }
        
        void insert(string word) {
            root->insert(root, word);
        }
        
        bool search(string word) {
            return root->search(root, word);
        }
        
        bool startsWith(string prefix) {
            return root->startsWith(root, prefix);
        }
    };

*/



/*

    14. Longest Common Prefix (2nd Method, we already did it by strings, now doing it by Trie)
    (https://leetcode.com/problems/longest-common-prefix/description/)

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> childNode;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }

        void insert(TrieNode* root, string word) {
            if(word.length() == 0){
                root->isTerminal = true;
                return ;
            }

            TrieNode* child;
            char ch = word[0];
            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                child = new TrieNode(ch);
                root->childNode[ch] = child;
            }
            insert(child, word.substr(1));

        }

        bool search(TrieNode* root, string word) {
            if(word.length() == 0){
                return root->isTerminal;
            }

            char ch = word[0];
            TrieNode* child;

            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                return false;
            }
            return search(child, word.substr(1));
        }

        bool startsWith(TrieNode* root, string prefix) {
            if(prefix.length() == 0){
                return true;
            }

            char ch = prefix[0];
            TrieNode* child;

            cout << ch << endl;

            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                return false;
            }
            return startsWith(child, prefix.substr(1));
        }
        
        // if it has single child include it, in ans or else that's not common
            //          root
            //          /
            //         F
            //        /
            //        L
            //    /   \   \
            //  WER. OW.  IGHT. 
        
};



class Solution {
public:

    void longestCommon(TrieNode* root, string &ans){
        if(root->isTerminal){
            return ;
        }
        
        if(root->childNode.size() == 1){
            auto val = root->childNode.begin()->first;
            ans += val;
            cout << val << endl;
            root = root->childNode[val];
            longestCommon(root, ans);
        }else{
            return ;
        }

        

    }

    string longestCommonPrefix(vector<string>& strs) {
        
        TrieNode* root = new TrieNode('-');

        for(auto val:strs){
            root->insert(root, val);
        }
        string ans ;
        longestCommon(root, ans);

        return ans;

    }
};
*/

/*

We can do get suggestions from given prefix string.

*/

/*
    187. Repeated DNA Sequences
    (https://leetcode.com/problems/repeated-dna-sequences/description/)

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freqMap;

        for(int i = 0; i + 10 <= s.length(); i++){
            string st = s.substr(i, 10);
            freqMap[st]++;
        }

        vector<string> ans;

        for(auto val:freqMap){
            // cout << 
            if(val.second > 1){
                ans.push_back(val.first);
            }
        }

        return ans;
    }
    
*/