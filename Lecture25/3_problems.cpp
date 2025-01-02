/*
    Array Subset
    (https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1)

    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int m = a.size();
        int n = b.size();
        
        unordered_map<int, int> valMap;
        
        for(auto val:a){
            valMap[val]++;
        }
        
        for(auto val:b){
            valMap[val]++;
        }
        
        if(m < n){
            for(auto val:a){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }else{
            for(auto val:b){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }
        
        return true;
    }

*/

/*
    Union of Two Linked Lists
    (https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1)

    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        map<int, int> valMap;
        
        while(head1){
            valMap[head1->data]++;
            head1 = head1->next;
        }
        
        while(head2){
            valMap[head2->data]++;
            head2 = head2->next;
        }
        
        Node* front = NULL;
        Node* back = NULL;
        for(auto val:valMap){
            Node* newNode = new Node(val.first);
            if(front == NULL){
                front = newNode;
                back = newNode;
            }else{
                back->next = newNode;
                back = back->next;
            }
            
        }
        return front;
    }

*/

/*
    Sum equals to Sum
    (https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1)

    bool findPairs(vector<int>& arr) {
        // code here.
        
        unordered_map<int, int> mapVal;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                mapVal[arr[i] + arr[j]]++;
                
                if(mapVal[arr[i] + arr[j]] > 1){
                    return true;
                }
            }
        }
        return false;
    }

*/


/*
    Largest subarray with 0 sum (Good QUestion, DO it Again)
    (https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int, int> leftSum;
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i <arr.size(); i++){
            sum += arr[i];
            
            if(sum == 0){
                ans = max(ans, i+1);
            }else if(leftSum.find(sum) == leftSum.end()){
                leftSum[sum] = i;
            }else{
                ans = max(ans, i - leftSum[sum]);
            }
        }
        return ans;
    }
*/


/*
    Largest subarray of 0's and 1's (Similar Problem as Above), Good QUestion
    (https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1)

    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int> mapVal;
        
    // replace all 0 term with -1, now it is same as max subarray with sum 0
    
        int sum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                sum += -1;
            }else{
                sum +=  1;
            }
            
            
            if(sum == 0){
                maxSum = max(maxSum, i + 1);
            }else if(mapVal.find(sum) == mapVal.end()){
                mapVal[sum] = i;
            }else{
                maxSum = max(maxSum, i - mapVal[sum]);
            }
        }
        
        return maxSum;
        
    }


*/


/*
    648. Replace Words
    (https://leetcode.com/problems/replace-words/description/)


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


        bool searchPrefixNode(TrieNode* root, string prefix, string &dictWord){
            if(root->isTerminal){
                dictWord = root->endword;
                return true;
            }

            TrieNode* child;
            char ch = prefix[0];
            if(root->childNode.find(ch) != root->childNode.end()){
                child = root->childNode[ch];
            }else{
                return false;
            }

            return searchPrefixNode(child, prefix.substr(1), dictWord);
        }
        


};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        TrieNode* root = new TrieNode('-');
        for(auto each_word:dictionary){
            root->insert(root, each_word, each_word);
        }

        string prefix = "";
        string ans = "";
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                cout << prefix << endl;
                string replaceword = "";
                bool present = root->searchPrefixNode(root, prefix, replaceword);
                if(present){
                    ans += replaceword;
                }else{
                    ans += prefix;
                }
                ans = ans + " ";
                prefix = "";
            }else{
                prefix = prefix + sentence[i];
            }
            

        }

        // for last word
        string replaceword = "";
        bool present = root->searchPrefixNode(root, prefix, replaceword);
        if(present){
            ans += replaceword;
        }else{
            ans += prefix;
        }

        return ans;
    }
};


*/