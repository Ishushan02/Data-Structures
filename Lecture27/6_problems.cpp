/*
547. Number of Provinces
(https://leetcode.com/problems/number-of-provinces/)

    void dfsTraversal(int node, vector<int> &visited, vector<vector<int> > &graph){
        visited[node] = 1;

        for(auto neigh: graph[node]){
            if(visited[neigh] == 0){
                dfsTraversal(neigh, visited, graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
         vector<vector<int> > graph(n, vector<int>());
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                }
                
            }
        }

        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                count += 1;
                dfsTraversal(i, visited, graph);
            }
        }

        return count;
    }

    
*/