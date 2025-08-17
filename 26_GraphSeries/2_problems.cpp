/*
    Alien Dictionary
    (https://www.geeksforgeeks.org/problems/alien-dictionary/1)

    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> charOrder;
        unordered_map<char, int> indegree;
        string ans;
        int i = 0;
        int j = 1;
        
        for (auto word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }
        
        while(j < words.size() && i < j){
            string a = words[i];
            string b = words[j];
            
            int ptr = 0;
            bool larger = false;
            int len = min(a.length(), b.length());
            while(ptr < len){
                if(a[ptr] != b[ptr]){
                    charOrder[a[ptr]].push_back(b[ptr]);
                    indegree[b[ptr]] += 1;
                    larger = true;
                    break;
                }
                ptr += 1;
            }
            
            if(larger == false && a.length() > b.length()){
                // ek edge case hai bhais
                return "";
            }
            i++;
            j++;
        }
        
        // for(auto &[k, v]:charOrder){
        //     cout << k << " : ";
        //     for(auto s: v){
        //         cout << s << " , ";
        //     }cout<<endl;
        // }
        
        // for(auto &[k, v]:charOrder){
        //     for(auto val:v){
        //         indegree[val] += 1;
        //     }
        // }
        
        queue<char> que;
        for(auto &[k, v]:indegree){
            if(v == 0){
                que.push(k);
            }
        }
        
        while(!que.empty()){
            char c = que.front();
            que.pop();
            ans += c;
            
            for(auto v:charOrder[c]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        
        // cout << ans << endl;
        if(ans.length() == indegree.size()){
            return ans;
        }
        
        return "";
    }
        
*/