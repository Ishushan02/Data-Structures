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

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> wordMap;

        for(auto word:wordDict){
            wordMap[word] = true;
        }

        return matchPossibleWords(s, wordMap, 0);
    }

*/