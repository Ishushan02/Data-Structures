
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


