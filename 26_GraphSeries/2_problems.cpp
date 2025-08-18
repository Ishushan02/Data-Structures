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

/*
    Shortest path in Directed Acyclic Graph
    (https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> pathCost(V, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < E; i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            indegree[edges[i][1]] += 1;
        }
        
        queue<pair<int, int>> que;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                que.push({i, 0});
            }
        }
        vector<int> topOrder;
        pathCost[0] = 0;
        while(!que.empty()){
            auto fr = que.front();
            int node = fr.first;
            int wt = fr.second;
            que.pop();
            topOrder.push_back(node);
            for(auto &v:graph[node]){
                indegree[v.first]--;
                if(indegree[v.first] == 0){
                    que.push(v);
                }
            }
        }
        
        for(auto v:topOrder){
            int wt = pathCost[v];
            if(wt != INT_MAX){
                for(auto eachNode:graph[v]){
                    int node = eachNode.first;
                    int cost = eachNode.second;
                    if (wt + cost < pathCost[node]) {
                        pathCost[node] = cost + wt;
                    }
                }
            }
            
        }
        
        for(int i = 0; i < V; i++){
            if(pathCost[i] == INT_MAX){
                pathCost[i] = -1;
            }
        }
        
        return pathCost;
    }
*/