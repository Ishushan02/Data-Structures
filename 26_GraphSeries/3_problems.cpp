/*

    ALL DISJOINT SET APPLICATIONS AND MOREE

    - It takes a constant time
    - It is mostly used in Dynamic Graphs, Dynamic Graphs mean the graph which keeps on changing configuration
    - 2 Fns, Find Parent, and Union
    - Union can be found either by rank or by size

*/

/*

    MST USING KRUSKAL's ALGORITHM
    (https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1)

    struct comp{
        bool operator()(vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        }
    };
    
    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = getParent(parent, parent[node]);
    }
    
    void Union(vector<int> &rank, vector<int> &parent, int U, int V){
        
        int pareU = getParent(parent, U);
        int pareV = getParent(parent, V);
        
        if(pareU != pareV){
            if(rank[pareU] > rank[pareV]){
                parent[pareV] = pareU;
                rank[pareU] = rank[pareU] + rank[pareV];
            }else{
                parent[pareU] = pareV;
                rank[pareV] = rank[pareV] + rank[pareU];
            }
        }
    }
    
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> rank(V+1, 1);
        vector<int> parent(V+1, 0);
        
        for(int i = 0; i< V + 1; i++){
            parent[i] = i;
        }
        
        sort(edges.begin(), edges.end(), comp());
        int minSum = 0;
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            int parU = getParent(parent, u);
            int parV = getParent(parent, v);
            
            if(parU != parV){
                minSum += w;
            }
          
            Union(rank, parent, u, v);
    
        }
        
        return minSum;
    }
*/

/*
    547. Number of Provinces
    (https://leetcode.com/problems/number-of-provinces/)

    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = getParent(parent, parent[node]);
    }

    void unionFun(vector<int> &parent, vector<int> &rank, int U, int V){

        int pareU = getParent(parent, U);
        int pareV = getParent(parent, V);
        
        if(pareU != pareV){
            if(rank[pareU] > rank[pareV]){
                parent[pareV] = pareU;
                rank[pareU] = rank[pareU] + rank[pareV];
            }else{
                parent[pareU] = pareV;
                rank[pareV] = rank[pareV] + rank[pareU];
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int parenti = getParent(parent, i + 1);
                int parentj = getParent(parent, j + 1);

                if(j > i && isConnected[i][j] == 1 && parenti != parentj){
                    unionFun(parent, rank, parenti, parentj);
                }
                
            }
        }

        unordered_set<int> st(parent.begin(), parent.end());

        return st.size() - 1;
    }
*/

/*
    684. Redundant Connection
    (https://leetcode.com/problems/redundant-connection/description/)

    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = getParent(parent, parent[node]);
    }

    void unionFun(vector<int> &rank, vector<int> &parent, int U, int V){

        int pU = getParent(parent, U);
        int pV = getParent(parent, V);

        if(pU != pV){
            if(rank[pU] > rank[pV]){
                parent[pV] = pU;
                rank[pU] += rank[pV];
            }else{
                parent[pU] = pV;
                rank[pV] += rank[pU];
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = 1;
        for(auto v:edges){
            n = max({v[0], n, v[1]});
        }
        vector<int> parent(n+1, 0);
        vector<int> rank(n+1, 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        vector<int> ans(2, 1);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int pU = getParent(parent, u);
            int pV = getParent(parent, v);

            if(pU != pV){
                unionFun(rank, parent, pU, pV);
            }else{
                ans[0] = u;
                ans[1] = v;
            }
        }

        return ans;
    }
        
*/

/*
    1319. Number of Operations to Make Network Connected
    (https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)

    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = getParent(parent, parent[node]);
    }

    void unionFun(vector<int> &parent, vector<int> &rank, int U, int V){

        int pU = getParent(parent, U);
        int pV = getParent(parent, V);

        if(pU != pV){
            if(rank[pV] > rank[pU]){
                parent[pU] = pV;
                rank[pV] += rank[pU];
            }else{
                parent[pV] = pU;
                rank[pU] += rank[pV];
            }
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1){
            return -1;
        }
        vector<int> rank(n, 1);
        vector<int> parent(n, 1);
        for(int i = 0; i <n; i++){
            parent[i] = i;
        }

        set<int> uniqueNodes;
        int connectionsReq = 0;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            uniqueNodes.insert(u);
            uniqueNodes.insert(v);

            int pU = getParent(parent, u);
            int pV = getParent(parent, v);
            if(pU != pV){
                unionFun(parent, rank, pU, pV);
            }
        }

        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                connectionsReq += 1;
            }
        }

        return connectionsReq-1;
    }
        
*/