/*
    // It is also given in previous file the one above see that as well

    279. Perfect Squares
    (https://leetcode.com/problems/perfect-squares/)

    int allPossibility(int n, int tempSum, vector<int> &dpArr){

        if(tempSum <= 0){
            return 0;
        }

        if(dpArr[tempSum] != -1){
            return dpArr[tempSum];
        }

        int minCount = INT_MAX;
        for(int i = 1; i <= n; i++){
            int includeans = 0;
            if(tempSum >= i * i){
                includeans = allPossibility(n, tempSum - i * i, dpArr);

                if(includeans != -1){
                    minCount = min(minCount, includeans + 1);
                    dpArr[tempSum] = minCount;
                }
            }

        }


        

        return dpArr[tempSum];
    }

    int numSquares(int n) {

        vector<int> dpArr(n + 1, -1);
        
        return allPossibility(n, n, dpArr);
    }   

*/

/*
    712. Minimum ASCII Delete Sum for Two Strings
    (https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

    int getMinOperations(string s1, string s2, int i, int j){
        if(i >= s1.length() && j >= s2.length()){
            return 0;
        }else if(i >= s1.length() && j != s2.length()){
            int sum = 0;
            for(int k = j; k < s2.length(); k++){
                sum += int(s2[k]);
            }
            return sum;
        }else if(i != s1.length() && j >= s2.length()){
            int sum = 0;
            for(int k = i; k < s1.length(); k++){
                sum += int(s1[k]);
            }
            return sum;
        }

        int n1 = s1.length();
        int n2 = s2.length();

        int minCost = INT_MAX;
        if(s1[i] == s2[j]){
            minCost = 0 + getMinOperations(s1, s2, i + 1, j +1);
        }else{
            int cost1 = int(s1[i]) + getMinOperations(s1, s2, i + 1, j);
            int cost2 =  int(s2[j]) + getMinOperations(s1, s2, i, j + 1);
            minCost = min(minCost, min(cost1, cost2));
        }

        return minCost;
    }


    int getMinOperationsDP(string &s1, string &s2, int i, int j, vector<vector<int>> &dpArr){
        if(i >= s1.length() && j >= s2.length()){
            return 0;
        }else if(i >= s1.length() && j != s2.length()){
            int sum = 0;
            for(int k = j; k < s2.length(); k++){
                sum += int(s2[k]);
            }
            return sum;
        }else if(i != s1.length() && j >= s2.length()){
            int sum = 0;
            for(int k = i; k < s1.length(); k++){
                sum += int(s1[k]);
            }
            return sum;
        }

        if(dpArr[i][j] != INT_MAX){
            return dpArr[i][j];
        }

        int n1 = s1.length();
        int n2 = s2.length();

        int minCost = INT_MAX;
        if(s1[i] == s2[j]){
            minCost = 0 + getMinOperationsDP(s1, s2, i + 1, j +1, dpArr);
        }else{
            int cost1 = int(s1[i]) + getMinOperationsDP(s1, s2, i + 1, j, dpArr);
            int cost2 =  int(s2[j]) + getMinOperationsDP(s1, s2, i, j + 1, dpArr);

            minCost = min(minCost, min(cost1, cost2));
        }

        dpArr[i][j] = minCost;

        return minCost;
    }

    int minimumDeleteSum(string s1, string s2) {
        
        // return getMinOperations(s1, s2, 0, 0);
        
        vector<vector<int>> dpArr(s1.length(), vector<int>(s2.length(), INT_MAX));
        return getMinOperationsDP(s1, s2, 0, 0, dpArr);

        
        // return 0;
    }

*/


/*  
    5. Longest Palindromic Substring
    (https://leetcode.com/problems/longest-palindromic-substring/description/)

    string getPalindromicSubstr(string &s, int start, int end){
        string temp;
        while(start >= 0 && end < s.length() && s[start] == s[end]){
                string substring = s.substr(start, end - start +1);
                if(temp.length() < end - start + 1){
                   temp = substring;
                }
                start--;
                end++;
            }
        return temp;
    }

    string longestPalindrome(string s) {
        

        int i = 0;
        string ansStr;
        while(i < s.length()){
            
            // odd
            string tempStr = getPalindromicSubstr(s, i, i);
            if(ansStr.length() < tempStr.length()){
                ansStr = tempStr;
            }

            //even
            tempStr = getPalindromicSubstr(s, i, i + 1);
            if(ansStr.length() < tempStr.length()){
                ansStr = tempStr;
            }     
            i++;
            
        }

        return ansStr;
    }
*/


/*

    THe question is bit tricky, see different examples, {So we have to make sure all examples are substructre of the word}

    Ex: "catsanddog"  , ["cats","dog","sand","and","cat"]  -> False
        "leetcode", ["leet", "code"] -> True
        "abcd", ["a", "abc", "b", "cd"] -> True
        "aaaaaaa", ["aaaa", "aaa"] -> True


    139. Word Break
    (https://leetcode.com/problems/word-break/)


    bool check(string &partition, vector<string>& wordDict){
        for(auto val:wordDict){
            if(val == partition){
                return true;
            }
        }
        return false;
    }

    bool allpossibility(string &s, vector<string>& wordDict, int idx){
        if(idx >= s.length()){
            return true;
        }

        string partition = "";
        bool flag = false;
        for(int i = idx; i < s.length(); i++){
            partition += s[i];

            if(check(partition, wordDict)){
                flag = flag || allpossibility(s, wordDict, i+1);
            }
                
        }

        return flag;
    }


    bool allPossibilityDP(string &s, vector<string> &wordDict, int idx, vector<int> &dpArr){

        if(idx >= s.length()){
            return true;
        }

        if(dpArr[idx] != -1 ){
            return dpArr[idx];
        }

        string partiotion = "";
        bool flag = false;
        for(int i = idx; i < s.length(); i++){

            partiotion += s[i];

            if(check(partiotion, wordDict)){
                flag = flag || allPossibilityDP(s, wordDict, i + 1, dpArr) ;
            }
        }

        dpArr[idx] = flag;

        return flag;
    }


    bool wordBreak(string &s, vector<string>& wordDict) {
        int idx = 0;
        // return allpossibility(s, wordDict, 0);
        vector<int> dpArr(s.length(), -1);
        return allPossibilityDP(s, wordDict, 0, dpArr);
    }

*/

/*
    877. Stone Game
    (https://leetcode.com/problems/stone-game/description/)

    // alice, bob
    pair<int, int> selection(vector<int>& piles, int i, int j){
        if(i >= j){
            return {0, 0};
        }

        int aliceSum = 0;
        int aliceSumfirstpick = piles[i] + selection(piles, i+1, j).first; 
        int aliceSumlastpick = piles[j] + selection(piles, i, j - 1).first; 
        
        aliceSum = max(aliceSumfirstpick, aliceSumlastpick);

        int bobSum = 0;
        int bobSumfirstpick = piles[i] + selection(piles, i+1, j).second; 
        int bobSumlastpick = piles[j] + selection(piles, i, j - 1).second; 

        bobSum = max(bobSumfirstpick, bobSumlastpick);

        return {aliceSum, bobSum};

    }

    // alice, bob
    pair<int, int> selectionDP(vector<int>& piles, int i, int j, map<pair<int, int>, pair<int, int>> &dpMap){
        if(i >= j){
            return {0, 0};
        }

        if(dpMap.find({i, j}) != dpMap.end()){
            return dpMap[{i, j}];
        }

        int aliceSum = 0;
        if(piles[i] >= piles[j]){
            aliceSum = piles[i] + selectionDP(piles, i+1, j, dpMap).first; 
        }else{
            aliceSum = piles[j] + selectionDP(piles, i, j - 1, dpMap).first; 
        }

        int bobSum = 0;
        if(piles[i] < piles[j]){
            bobSum = piles[i] + selectionDP(piles, i+1, j, dpMap).second; 
        }else{
            bobSum = piles[j] + selectionDP(piles, i, j - 1, dpMap).second; 
        }

        dpMap[{i, j}] = {aliceSum, bobSum}; 

        return dpMap[{i, j}];

    }

    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        // vector<vector<int>> dpArr(n+1, vector<int>(n+1, -1));
        map<pair<int, int>, pair<int, int>> dpMap;
        // pair<int, int> valSum = selection(piles, 0, n-1);
        
        pair<int, int> valSum = selectionDP(piles, 0, n-1, dpMap);

        if(valSum.first > valSum.second){
            return true;
        }
        return false;
    }

*/