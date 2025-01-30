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

    VVVIIII Question : Amazon (Do it )

    Find the Number Of Island's
    Rotten Oranges/ Rotten Tomatoes

*/