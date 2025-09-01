/*
    Strongly Connected Components - Graph Important TOPIC
*/

/*
    Strongly Connected Components
    (https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

    void dfsTravel(int node,  stack<int> &store, vector<int> &visited, 
    vector<vector<int>> &adj){
        visited[node] = 1;
        for(auto v: adj[node]){
            if(visited[v]==0){
                dfsTravel(v, store, visited, adj);
            }
        }
        store.push(node);
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<vector<int>> reverseadj(n, vector<int>());
        for(int i = 0; i < n; i++){
            for(auto v: adj[i]){
                reverseadj[v].push_back(i);
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     cout << i << " : "<<endl;
        //     for(auto v: reverseadj[i]){
        //         cout << v << " ";
        //     }cout<<endl;
        // }
        
        vector<int> visited(n, 0);
        stack<int> store;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfsTravel(i, store, visited, adj);
            }
        }
        // for(auto v:store){
        //     cout << v<< " ";
        // }
        
        vector<int> reverseVisited(n, 0);
        int count = 0;
        int i = 0;
        while(!store.empty()){
            int v = store.top();
            if(reverseVisited[v] == 0){
                stack<int> p;
                dfsTravel(v, p, reverseVisited, reverseadj);
                count += 1;
            }
            store.pop();
        }
        
        return count;
    }
*/

/*
    Bridge edge in a graph
    (https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1)

    void dfsTravel(int node, vector<int> &visited, unordered_map<int, 
    vector<int>> &graph){
        visited[node] = 1;
        for(auto v: graph[node]){
            if(visited[v] == 0){
                dfsTravel(v, visited, graph);
            }
        }
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        unordered_map<int, vector<int>> graph;
        unordered_map<int, vector<int>> removedGraph;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            if((u == c && v == d) || (u == d && v == c)){
                
            }else{
                removedGraph[u].push_back(v);
                removedGraph[v].push_back(u);
            }
        }
        
        int comp1 = 0;
        int comp2 = 0;
        
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                comp1 += 1;
                dfsTravel(i, visited, graph);
            }
        }
        
        vector<int> revVisited(V, 0);
        for(int i = 0; i < V; i++){
            if(revVisited[i] == 0){
                comp2 += 1;
                dfsTravel(i, revVisited, removedGraph);
            }
        }
        
        if(comp2 > comp1){
            return true;
        }
        
        return false;
    }

*/

/*
    TARJAN's ALGORITHM
    1192. Critical Connections in a Network
    (https://leetcode.com/problems/critical-connections-in-a-network/)

    void dfsTraversal(int node, int parent, vector<int> &visited, vector<int> &discovered, vector<int> &lowest, unordered_map<int, vector<int>>& connections, int &count, vector<vector<int>> &ans){
        discovered[node] = count;
        visited[node] = 1;
        lowest[node] = count;
        count += 1;

        for(auto v:connections[node]){
            if(v == parent){
                continue;
            }

            if(visited[v] == 0){
                dfsTraversal(v, node, visited, discovered, lowest, connections, count , ans);
                lowest[node] = min(lowest[node], lowest[v]);
                if(lowest[v] > discovered[node]){
                    ans.push_back({node, v});
                }
            }else{
                lowest[node] = min(lowest[v], lowest[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, vector<int>> graph;
        for(auto v:connections){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> discovered(n, 0);
        vector<int> lowest(n, 0);
        vector<int> visited(n, 0);
        vector<vector<int>> ans;
        int count = 1;
        dfsTraversal(0, -1, visited, discovered, lowest, graph, count, ans);

        return ans;
    }
*/

/*
    Articulation Point - I
    (https://www.geeksforgeeks.org/problems/articulation-point-1/1)

    void trajansAlgo(int node, int parent, vector<int> &visited, vector<int> &discovered,
    vector<int> &lowest, int &time, vector<int> adj[], vector<int> &mark){
        visited[node] = 1;
        discovered[node] = time;
        lowest[node] = time;
        time += 1;
        int child = 0;
        for(auto v: adj[node]){
            if(v == parent){
                continue ;
            }
            
            if(visited[v] == 0){
                trajansAlgo(v, node, visited, discovered, lowest, time, adj, mark);
                
                lowest[node] = min(lowest[node], lowest[v]);
                if(lowest[v] >= discovered[node] && parent != -1){
                    mark[node] = 1;
                }
                child += 1;
            }else{
                lowest[node] = min(lowest[node], discovered[v]);
            }
        }
        
        if(parent == -1 && child > 1){
            mark[node] = 1;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V, 0);
        vector<int> discovered(V, 0);
        vector<int> lowest(V, 0);
        int time = 1;
        vector<int> mark(V, 0);
        
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                trajansAlgo(i, -1, visited, discovered, lowest, time, adj, mark);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
        
*/