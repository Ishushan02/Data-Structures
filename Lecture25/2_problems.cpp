
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

/*
    211. Design Add and Search Words Data Structure (It is really Good question, search modification)
    (https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

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
            if(ch != '.'){
                if(root->childNode.find(ch) != root->childNode.end()){
                    child = root->childNode[ch];
                }else{
                    child = new TrieNode(ch);
                    root->childNode[ch] = child;
                }
            }
            insert(child, word.substr(1));

        }

        bool search(TrieNode* root, string word) {
            if(word.length() == 0){
                return root->isTerminal;
            }

            char ch = word[0];
            // cout << "Word: "<< word << endl;
            TrieNode* child;
            bool matchA = false;
            if(ch != '.'){
                if(root->childNode.find(ch) != root->childNode.end()){
                    child = root->childNode[ch];
                }else{
                    return false;
                }
                matchA = search(child, word.substr(1));
            }else{
                // for all nodes whenever . comes
                for(auto &[str, node]:root->childNode){
                    // cout << str << endl;
                    matchA = matchA || search(node, word.substr(1));
                }
                
            }
            return matchA;
        }

};



class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode('-');
    }
    
    void addWord(string word) {
        root->insert(root, word);
    }
    
    bool search(string word) {
        return root->search(root, word);
    }
};
*/


/*
    676. Implement Magic Dictionary (It is really Good question, search modification)
    (https://leetcode.com/problems/implement-magic-dictionary/description/)

class Trie{
    public:
    char data;
    bool isTerminal;
    map<char, Trie*> childNode;

    Trie(char ch){
        data = ch;
        isTerminal = false;
    }
    
    void insert(Trie* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        Trie* child;
        char ch = word[0];

        if(root->childNode.find(ch) != root->childNode.end()){
            child = root->childNode[ch];
        }else{
            child = new Trie(ch);
            root->childNode[ch] = child;
        }
        insert(child, word.substr(1));
    }

    bool search(Trie* root, string word, bool mismatch = false){
        if(word.length() == 0){
            return mismatch && root->isTerminal;
        }

        Trie* child;
        char ch = word[0];
        if(root->childNode.find(ch) != root->childNode.end()){
            child = root->childNode[ch];
            if(search(child, word.substr(1), mismatch)){
                return true;
            }
        }

        // mismatched
        // cout << word << endl;
        if(mismatch == false){
            for(auto &[key, node]:root->childNode){
                child = root->childNode[key];
                // ans = search(child, word.substr(1), diffCount);
                mismatch = true;
                if(ch != key && search(child, word.substr(1), mismatch)){
                    return true;
                }
            }
        }
        return false;
    }
};




class MagicDictionary {
public:
    Trie* root;
    MagicDictionary() {
        root = new Trie('-');
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto each_str:dictionary){
            root->insert(root, each_str);
        }
    }
    
    bool search(string searchWord) {
        bool mismatch = false;
        return root->search(root, searchWord, mismatch);
    }
};

*/

/*
    1268. Search Suggestions System (Good Question logic is k=store the entire word in terminal Node)
    (https://leetcode.com/problems/search-suggestions-system/description/)

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> childNode;
        string endword;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }

        void insert(TrieNode* root, string word, string &original) {
            if(word.length() == 0){
                root->isTerminal = true;
                root->endword = original; // storing corresponding words in terminal
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
            insert(child, word.substr(1), original);

        }

        void getStrings(TrieNode* root, vector<string> &allstring){
            if(root == NULL){
                return ;
            }

            if(root->isTerminal == true){
                allstring.push_back(root->endword);
            }

            for(auto &[key, node]:root->childNode){
                getStrings(node, allstring);
            }

        }

        TrieNode* searchPrefixNode(TrieNode* root, string prefix){
            if(prefix.length() == 0){
                return root;
            }

            TrieNode* child;
            char ch = prefix[0];
            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
                return searchPrefixNode(child, prefix.substr(1));
            }

            return NULL;
        }
        


};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ans;
        int n = searchWord.length();
        TrieNode* root = new TrieNode('-');

        for(auto val:products){ 
            root->insert(root, val, val);
        }


        string prefix = "";
        for(int i = 0; i < searchWord.length(); i++){
            // cout << searchWord.substr(0, i+1) << endl;
            prefix = prefix + searchWord[i];
            TrieNode* prefixNode = root->searchPrefixNode(root, prefix);
            vector<string> values;
            root->getStrings(prefixNode, values);
            sort(values.begin(), values.end());
            
            if(values.size()> 3){
                values.erase(values.begin() + 3, values.end());
            }
        
            ans.push_back(values);

        }

        return ans;
    }
};

*/


/*
    745. Prefix and Suffix Search (TRY IT)
    (https://leetcode.com/problems/prefix-and-suffix-search/description/)
*/