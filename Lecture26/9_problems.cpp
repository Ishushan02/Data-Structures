/*
    140. Word Break II
    (https://leetcode.com/problems/word-break-ii/description/)

    vector<string> matchPossibleWords(string &s, unordered_map<string,bool> &wordMap, int idx){

        if(idx == s.length()){
            return {""};
        }
        vector<string> ans;
        
        string validword = "";
        for(int i = idx; i < s.length(); i++){
            validword += s[i];
            if(wordMap.find(validword) != wordMap.end()){
                vector<string> remainingWord = matchPossibleWords(s, wordMap, i + 1);
                for(auto each_word: remainingWord){
                    string endPart;
                    if(each_word.size() > 0){
                        endPart = " " + each_word;
                    }
                    ans.push_back(validword + endPart);
                }

            }
        }
        return ans;
    }


    unordered_map<int, vector<string>> dpArr;
    vector<string> matchPossibleWordsDP(string &s, unordered_map<string,bool> &wordMap, int idx){

        if(idx == s.length()){
            return {""};
        }
        vector<string> ans;

        if(dpArr.find(idx) != dpArr.end()){
            return dpArr[idx];
        }
        
        string validword = "";
        for(int i = idx; i < s.length(); i++){
            validword += s[i];
            if(wordMap.find(validword) != wordMap.end()){
                vector<string> remainingWord = matchPossibleWordsDP(s, wordMap, i + 1);
                for(auto each_word: remainingWord){
                    string endPart;
                    if(each_word.size() > 0){
                        endPart = " " + each_word;
                    }
                    ans.push_back(validword + endPart);
                }

            }
        }

        dpArr[idx] = ans;
        return dpArr[idx];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> wordMap;

        for(auto word:wordDict){
            wordMap[word] = true;
        }

        return matchPossibleWords(s, wordMap, 0);
    }

*/


/*
    96. Unique Binary Search Trees
    (https://leetcode.com/problems/unique-binary-search-trees/description/)

    int allPossibilities(int n, vector<int> &dpArr){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dpArr[n] != -1){
            return dpArr[n];
        }

        int sum = 0;
        for(int i = 1; i <= n; i++){

            int leftPart  = i - 1; 
            int rightPart = n - i;
            int lans = allPossibilities(leftPart, dpArr);
            int rans = allPossibilities(rightPart, dpArr);            
            sum += (lans * rans);

        }

        dpArr[n] = sum;
        return dpArr[n];

    }

    int numTrees(int n) {

        if(n == 1){
            return 1;
        }

        vector<int> dpArr(n + 1, -1);


        return allPossibilities(n, dpArr);
    }
*/


/*
    95. Unique Binary Search Trees II
    (https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

    vector<TreeNode*> allPossibleTrees(int start, int end){
        if(start > end){
            return {NULL};
        }

        if(end == start){
            TreeNode* node = new TreeNode(start);
            return {node};
        }

        vector<TreeNode*> allTree;
        for(int i = start; i <= end; i++){

            vector<TreeNode*> leftTrees = allPossibleTrees(start, i -1);
            vector<TreeNode*> rightTrees = allPossibleTrees(i+1, end);
            
            for(int j = 0; j < leftTrees.size(); j++){      
                for(int k = 0; k < rightTrees.size(); k++){
                    TreeNode* currNode = new TreeNode(i);
                    currNode->left = leftTrees[j];
                    currNode->right = rightTrees[k];
                    allTree.push_back(currNode);
                }
            }

        }

        return allTree;
    }

    vector<TreeNode*> allPossibleTreesDP(int start, int end, map<pair<int, int>, vector<TreeNode*>> &treeMap){
        if(start > end){
            return {NULL};
        }

        if(end == start){
            TreeNode* node = new TreeNode(start);
            return {node};
        }

        if(treeMap.find({start, end})!= treeMap.end()){
            return treeMap[{start, end}];
        }

        vector<TreeNode*> allTree;
        for(int i = start; i <= end; i++){

            vector<TreeNode*> leftTrees = allPossibleTreesDP(start, i -1, treeMap);
            vector<TreeNode*> rightTrees = allPossibleTreesDP(i+1, end, treeMap);
            
            for(int j = 0; j < leftTrees.size(); j++){      
                for(int k = 0; k < rightTrees.size(); k++){
                    TreeNode* currNode = new TreeNode(i);
                    currNode->left = leftTrees[j];
                    currNode->right = rightTrees[k];
                    allTree.push_back(currNode);
                }
            }

        }

        treeMap[{start, end}] = allTree;

        return treeMap[{start, end}];
    }


    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> treeMap;
        // vector<TreeNode*> ansTrees =  allPossibleTrees(1, n);
        vector<TreeNode*> ansTrees =  allPossibleTreesDP(1, n, treeMap);
        return ansTrees;

    }
*/