/*

    ALL DISJOINT SET APPLICATIONS AND MOREE

    - It takes a constant time
    - It is mostly used in Dynamic Graphs, Dynamic Graphs mean the graph which keeps on changing configuration
    - 2 Fns, Find Parent, and Union
    - Union can be found either by rank or by size

    KEEP THIS IN  IND IF THERE IS CHANGE IN THE GRAPH EVERY TIME, OF THE GRAPH IS 
    DYNAMIC USE DISJOINT, UNION SET..
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

/*
    721. Accounts Merge
    (https://leetcode.com/problems/accounts-merge/)

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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);


        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        unordered_map<string, int> stringMap;

        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(stringMap.find(email) == stringMap.end()){
                    // int pu = getParent(parent, i);
                    stringMap[email] = i;
                }else{
                    int pu = getParent(parent, i);
                    int pv = getParent(parent, stringMap[email]);

                    unionFun(parent, rank, pu, pv);
                }
            }
        }

        // for(auto v:parent){
        //     auto c = getParent(parent, v);
        //     cout << v << " ";
        // }
        cout<<endl;
        vector<int> todelete;
        unordered_map<int, set<string>> ansMap;

        for(int i = 0; i < n; i++){
                int pNode = getParent(parent, i);
                ansMap[pNode].insert(accounts[i].begin()+1, accounts[i].end());
        }

        vector<vector<string>> ans;
        for(auto [k, val]:ansMap){
            vector<string> temp;
            // cout << k << " : ";
            temp.push_back(accounts[k][0]);
            for(auto v:val){
                temp.push_back(v);
                // cout << v << " ";
            }
            // cout<<endl;
            ans.push_back(temp);
        }

        return ans;
    }
*/

/*
    VVVVV IIIIIIII Question, Please do Again
    (https://www.geeksforgeeks.org/problems/number-of-islands/1)

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
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        vector<int> parent(n * m, 0);
        vector<int> rank(n * m, 1);
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i = 0; i < n*m; i++){
            parent[i] = i;
        }
        // cout <<"Size: " <<n*m << endl;
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> ans;
        for(int i = 0; i < operators.size(); i++){
            int x = operators[i][0];
            int y = operators[i][1];
            // cout << x << " , " << y << endl;
            if(visited[x][y] == 1){
                ans.push_back(count);
                continue;
            }
            
            visited[x][y] = 1;
            int u = x * m + y;
            count++;
            
            for(int l = 0; l < 4; l++){
                int p = x + dx[l];
                int q = y + dy[l];
                if(p >= 0 && p < n && q >= 0 && q < m && visited[p][q] == 1){
                    int v = p * m + q;
                    int pu = getParent(parent, u);
                    int pv = getParent(parent, v);
                    if(pu != pv){
                        count--;
                        unionFun(rank, parent, pu, pv);
                        
                    }
                    
                    
                }
            }
            ans.push_back(count);
            
        }
        
        return ans;
        
        
    }
*/

/*
    827. Making A Large Island
    (https://leetcode.com/problems/making-a-large-island/description/)

    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = getParent(parent, parent[node]);
    }

    void UnionSet(vector<int> &parent, vector<int> &rank, int U, int V){
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

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<int> parent(n * n, 0);
        vector<int> rank(n * n, 1);

        for(int i = 0; i < n * n; i++){
            parent[i] = i;
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int U = n * i + j;
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int V = n * x + y;
                        if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1){
                            UnionSet(parent, rank, U, V);
                        }
                    }
                    // grid[i][j] = 0;
                }
            }
        }
        // for(auto v:rank){
        //     cout << v << " ";
        // }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                set<int> allParents;
                if(grid[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int V = n * x + y;
                        if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1){
                            int p = getParent(parent, V);
                            allParents.insert(p);
                        }
                    }
                    int size = 1;
                    for(auto v:allParents){
                        size += rank[v];
                    }
                    maxArea = max(maxArea, size);
                }
            }
        }

        // for(auto v:rank){
        //     cout << v << " ";
        // }

        for(auto v:rank){
            maxArea = max(maxArea, v);
        }

        return maxArea;
    }
*/

/*
    (In this the only important point is making the indexing which is 0, ... row, for rows and for cols col[0] + col...) this is important
    947. Most Stones Removed with Same Row or Column
    (https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/)

    int getParent(vector<int>& parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = getParent(parent, parent[node]);
    }

    void unionFun(vector<int> &parent, vector<int> &rank, int U, int V){
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

    int removeStones(vector<vector<int>>& stones) {
        
        int row = 0;
        int col = 0;
        for(auto v:stones){
            row = max(row, v[0]);
            col = max(col, v[1]);
        }

        
        int n = col + row + 2;
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int colStart = row + 1;

        for(auto v:stones){
            int U = v[0];
            int V = v[1] + colStart;
            unionFun(parent, rank, U, V);
        }

        unordered_set<int> st;

        for(auto v:stones){
            int x = v[0];
            int y = colStart + v[1];
            int node = getParent(parent, x);
            st.insert(node);
        }

        return stones.size() - st.size();
    }


*/


/*
    2685. Count the Number of Complete Components
    (https://leetcode.com/problems/count-the-number-of-complete-components/description/)

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
            if(rank[pU] > rank[pV]){
                parent[pV] = pU;
                rank[pU] += rank[pV];
            }else{
                parent[pU] = pV;
                rank[pV] += rank[pU];
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        int count = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> rank(n, 1);
        vector<int> parent(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto &[u, val]:graph){
            for(auto v: val){
                int pU = getParent(parent, u);
                int pV = getParent(parent, v);
                unionFun(parent, rank, pU, pV);
            }
        }

        // for(int i = 0; i < n; i++){
        //     if(graph.find(i) == graph.end()){
        //         graph[i] = {};
        //     }
        // }

        unordered_map<int, int> uniqueSet;
        unordered_map<int, int> uniqueEdge;

        for(int i = 0; i < n; i++){
            int v = getParent(parent, parent[i]);
            // cout << v << " ";
            uniqueSet[v] += 1;
            uniqueEdge[v] += graph[i].size();
        }
        // cout<<endl;


        for(auto &[k,v]:uniqueEdge){
            int edges = v/2;
            int m = uniqueSet[k];
            int requiredEdges = m * (m-1)/2;
            if(requiredEdges == edges){
                count += 1;
            }

            // cout << k << " : " << v/2 << endl;
        }

        return count;

    }
*/