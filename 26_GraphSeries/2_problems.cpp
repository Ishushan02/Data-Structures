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

/*
    797. All Paths From Source to Target
    (https://leetcode.com/problems/all-paths-from-source-to-target/description/)

    void dfsPath(int node, vector<vector<int>>& graph, int src, int des, vector<int> &path, vector<vector<int>> &res){
        // cout << node << endl;
        if(node == des){
            res.push_back(path);
            return ;
        }

        for(auto v:graph[node]){
            path.push_back(v);
            dfsPath(v, graph, src, des, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;

        int src = 0;
        int des = n - 1;
        path.push_back(src);
        dfsPath(0, graph, src, des, path, res);

        return res;
    }
*/

/*
    Shortest Path in Undirected Graph
    (https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> distance(n, INT_MAX);
        // dfs(src, adj, visited, pathVisited, 0, distance);
        
        queue<pair<int, int>> que;
        que.push({src, 0});
        while(!que.empty()){
            auto fr = que.front();
            int node = fr.first;
            int dist = fr.second;
            que.pop();
            distance[node] = dist;
            for(auto v:adj[node]){
                if(distance[v] > dist + 1){
                    distance[v] = dist + 1;
                    que.push({v, dist + 1});
                }
            }
        }
        
        for(auto &v:distance){
            if(v == INT_MAX){
                v = -1;
            }
        }
        
        return distance;
    }
        
*/


/*
    127. Word Ladder
    (https://leetcode.com/problems/word-ladder/)

    bool diffOne(string &a, string &b){
        if(a == b) return false;
        if (a.length() != b.length()) return false;

        int count = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]){
                count += 1;
            }
            if(count > 1){
                return false;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> wordDist;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()){
            wordList.push_back(beginWord);
        }
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        int n = wordList.size();
        for(int i = 0; i < n; i++){
            wordDist[wordList[i]] = INT_MAX;
            for(int j = 0; j < n; j++){
                if(diffOne(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                }
            }
        }        
        
        queue<pair<string, int>> que;
        // wordDist[beginWord] = 0;

        que.push({beginWord, 1});

        while(!que.empty()){
            auto front = que.front();
            que.pop();
            string word = front.first;
            int dist = front.second;
            wordDist[word] = min(wordDist[word],dist);
            for(auto v:graph[word]){
                if(wordDist[v] > dist + 1){
                    que.push({v, dist + 1});
                }
            }
        }

        if(wordDist[endWord] == INT_MAX) return 0;
        
        return wordDist[endWord];
    }


    Method 2

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, bool> visited;
        unordered_map<int, vector<string>> dataStore;
        unordered_set<string> stringSet(wordList.begin(), wordList.end());

        queue<pair<string, int>> que;
        que.push({beginWord, 1});

        if(stringSet.count(endWord) == 0){
            return {};
        }

        int ans = 0;
        bool endWordReached = false;
        while(!que.empty()){
            auto front = que.front();
            que.pop();
            string s = front.first;
            int count = front.second;
            dataStore[count].push_back(s);
            visited[s] = true;
            // cout << s << " : " << endl;
            string temp = s;
            for(int i = 0; i < temp.length(); i++){
                char prev = temp[i];
                for(auto j = 'a'; j <= 'z'; j++){
                    temp[i] = j;
                    if(j == prev){
                        continue;
                    }

                    if(visited[temp] == false && stringSet.count(temp) > 0){
                        visited[temp] = true;
                        que.push({temp, count + 1});
                        if(temp == endWord){
                            ans = count + 1;
                            endWordReached = true;
                        }
                    }
                }
                temp[i] = prev;
            }
        }

        // for(auto &[k, v]:dataStore){
        //     cout << k << " : ";
        //     for(auto val:v){
        //         cout << val << " ";
        //     }cout<<endl;
        // }

        if(endWordReached){
            return ans;
        }

        return 0;

    }
*/

/*
    126. Word Ladder II
    (https://leetcode.com/problems/word-ladder-ii/description/)

    Try DOing this, I tried multiple Approaches, try again.
*/

/*
    Dijkstra Algorithm
    (https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> distances(V, 1e9);
        unordered_map<int, vector<pair<int, int>>> graph;
        // cout << edges.size() << endl;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        
        que.push({0, src});
        
        while(!que.empty()){
            auto front = que.top();
            que.pop();
            int node = front.second;
            int dist = front.first;
            distances[node] = min(distances[node], dist);
            for(auto v:graph[node]){
                int nd = v.first;
                int wt = v.second;
                if(distances[nd] > dist + wt){
                    que.push({dist + wt, nd});
                }
            }
        }
        
        return distances;
    }
*/