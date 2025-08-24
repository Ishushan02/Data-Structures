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