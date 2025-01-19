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