/*

    Kosa Raju Algorithm
    - To Find Strongly Connected Component
    A strongly Connected component is that in which if we start 
    at one node of a graph we will successfully reach every other node of the graph.

    A Strongly Connected component will remain strongly connected eventhough the graph directions
    are reversed

    So, the idea is that {To find total number of Strongly Connected Graph}

    - First Step is to find the DSF traversal {Store it}
    - Reverse the direction of graph now
    - Do the DFS traversal along the stored Nodes and when the loop is stopped which means that 1 componenet 
    of strong connected graph is over.. similarily continue it.

    Strongly Connected
    (https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

    void dfsTraversal(int srcNode, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsPath){
        visited[srcNode] = true;
        
        for(auto neigh:adj[srcNode]){
            if(!visited[neigh]){
                dfsTraversal(neigh, adj, visited, dfsPath);
            }
        }
        
        dfsPath.push_back(srcNode);
        
    }
    
    void dfsTraversal2(int srcNode, vector<vector<int>> &reversedMap, vector<bool> &visited1){
        visited1[srcNode] = true;
        
        for(auto neigh:reversedMap[srcNode]){
            if(!visited1[neigh]){
                dfsTraversal2(neigh, reversedMap, visited1);
            }
        }
        
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        vector<bool> visited(adj.size(), false);
        vector<int> dfsPath;
        
        // store the dfs Traversal
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                dfsTraversal(i, adj, visited, dfsPath);
            }
        }
        
        // it should be stack right, so reversing it
        reverse(dfsPath.begin(), dfsPath.end());
        
        // reverse the map
        vector<vector<int>> reversedMap(adj.size(), vector<int>());
        
        for(int i = 0; i < adj.size(); i++){
            for(auto neigh: adj[i]){
                reversedMap[neigh].push_back(i);
            }
        }
        
        // do dfs traversal Again, with counting the Nodes
        vector<bool> visited1(adj.size(), false);
        int count = 0;
        for(int i = 0; i < dfsPath.size(); i++){
            if(!visited1[dfsPath[i]]){
                dfsTraversal2(dfsPath[i], reversedMap, visited1);
                count += 1;
            }
        }
        
        
        
        return count;
        
    }

*/