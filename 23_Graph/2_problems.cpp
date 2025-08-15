#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

/*

Cycle Detection: 

    Directed Graph and Undirected Graph

    - So, the simple logic to find the cycle is that when you find any Node which is already Visited
    and is not the parent of current Node, hence we can conclude that Cycle Exist. {Just think that
    we are visitng a node again, which is not it's parent means that obviously cycle should be present
    there as it is being revisited. }

    - DO this for each Node
*/

/*
    Do it
    Find cycle in Directed and Undirected Graph using both BFS and DFS

*/


/*

    // Here Normal BFS won't work in Undirected graph, there are chances some disjoint nodes might be there, so
    // make sure that you loop into other nodes as well by looping all nodes

    Cycle in Undirected Graph using BFS
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

    bool bfsCycle(int sourceNode, vector<vector<int>>& adj){
        
        unordered_map<int, bool> visited;
        queue<int> que;
        unordered_map<int, int> parent;
        
        que.push(sourceNode);
        parent[sourceNode] = -1;
        while(!que.empty()){
            
            int frontNode = que.front();
            visited[frontNode] = true;
            
            for(auto neighbour:adj[frontNode]){
                
                if(visited[neighbour]== 0){
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    que.push(neighbour);
                }else if(neighbour != parent[frontNode]){
                    return true;
                }
            }
            
            que.pop();
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        for(int i = 0; i < adj.size(); i++){
            if(bfsCycle(i, adj)){
                return true;
            }
        }

        return false;
    }

*/

/*
    // We cannot check a Cycle in BFS by merely just Using BFS

    Cycle in a Directed Graph using BFS (Topological Sort)
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> ans;
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto neigh:adj[i]){
                indegree[neigh]++;
            }
        }
        
        queue<int> que;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        
        // topological Sort
        while(!que.empty()){
            
            int frontNode = que.front();
            ans.push_back(frontNode);
            que.pop();
            
            for(auto neigh:adj[frontNode]){
                
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    que.push(neigh);
                }
            }
        }
        
        if(ans.size() == V){
            return false;
        }
        
        return true;
        
    }
*/

/*
    Cycle in Undirected Graph using DFS
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)


    bool dfs(vector<vector<int>>& adj, unordered_map<int, int> &parent, int src, vector<int> &visited){
        
        visited[src] = 1;
        for(auto neigh: adj[src]){
            
            if(!visited[neigh]){
                parent[neigh] = src;
                if(dfs(adj, parent, neigh, visited)){
                    return true;
                }
            }else if(neigh != parent[src]){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, int> parent;
        vector<int> visited(adj.size(), 0);
        parent[0] = -1;
        
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                if(dfs(adj, parent, i, visited)){
                    return true;
                }
            }
        }
        
        return false;
    }

*/


/*

     Cycle in a Directed Graph using DFS
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

    (bool dfs(vector<vector<int>> &adj, int src, vector<int> &visited){
        visited[src] = 1;
        
        for(auto neighbour: adj[src]){
            if(visited[neighbour] == 0){
                if(dfs(adj, neighbour, visited)){
                    return true;
                }
            }else{
                return true;
            }
        }
        visited[src] = 0;
        // backtrack such that other nodes coming to it 
        // have to be marked non visited
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++){
            
            if(visited[i] == 0){
                if(dfs(adj, i, visited)){
                    return true;
                }
            }
        }
        
        return false;
    })

*/

/*

    Good Method (Method 2)
    Cycle in Directed Graph

    bool isCycle(int node, unordered_map<int, vector<int>> &edges, vector<int> &visited,
    vector<int> &pathVisited){
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto v:edges[node]){
            
            if(visited[v] == -1){
                bool val = isCycle(v, edges, visited, pathVisited);
                if(val){
                    return true;
                }
            }else if(pathVisited[v] == 1){
                return true;
            }
        }
        
        pathVisited[node] = -1;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> graph;
        vector<int> visited(V, -1);
        vector<int> pathVisited(V, -1);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i = 0; i < V; i++){
            if(visited[i] == -1){
                bool val = isCycle(i, graph, visited, pathVisited);
                if(val){
                    return true;
                }
            }
        }
        return false;
        
    }

*/

/*

    VVVIIII Question : Amazon (Do it )

    Find the Number Of Island's
    Rotten Oranges/ Rotten Tomatoes

*/

/*
    200. Number of Islands (Approach is Normal BFS)
    (https://leetcode.com/problems/number-of-islands/)


    void bfsTraversal(int m, int n, int i, int j, vector<vector<char>>& grid, map<pair<int, int>, bool > &visited){

        queue<pair<int, int> > que;
        que.push({i, j});

        while(!que.empty()){

            pair<int, int> front = que.front();

            int currRow = front.first;
            int currCol = front.second;

            visited[{currRow, currCol}] = true;
            
            // bottom
            if((currRow + 1 < m) && (grid[currRow+1][currCol] == '1') && (visited[{currRow+1, currCol}] == false)){
                que.push({currRow+1, currCol});
                visited[{currRow+1, currCol}] = true;
            }

            // top
            if((currRow - 1 >= 0) && (grid[currRow-1][currCol] == '1') && (visited[{currRow-1, currCol}] == false)){
                que.push({currRow-1, currCol});
                visited[{currRow-1, currCol}] = true;
            }
            
            //right
            if((currCol + 1 < n) && (grid[currRow][currCol+1] == '1') && (visited[{currRow, currCol + 1}] == false)){
                que.push({currRow, currCol+1});
                visited[{currRow, currCol+1}] = true;
            }

            // left
            if((currCol - 1 >= 0) && (grid[currRow][currCol-1] == '1') && (visited[{currRow, currCol-1}] == false)){
                que.push({currRow, currCol-1});
                visited[{currRow, currCol-1}] = true;
            }

            que.pop();
            
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        map<pair<int, int>, bool > visited;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                visited[{i, j}] == false;      
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout << grid[i][j] << " - " << visited[{i, j}] << endl;
                if((grid[i][j] == '1') && (visited[{i, j}] == false)){
                    ans += 1;
                    bfsTraversal(m, n, i, j, grid, visited);
                }
            }
        }

        return ans;

    }
*/

/*
    994. Rotting Oranges
    https://leetcode.com/problems/rotting-oranges/description/

    // We can do this as well similarily
*/