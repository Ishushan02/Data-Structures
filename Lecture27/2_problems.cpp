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
    Undirected Graph Cycle
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

    bool cyclePresent(vector<vector<int>>& adj, int src) {
        // Code here
        
        // vector<int> ans;
        int node = src;
        vector<int> visited;
        queue<int> que;
        unordered_map<int, int> parent;
        que.push(node);
        visited.push_back(node);
        parent[src] = -1;
        
        
        while(!que.empty()){
            int frontNode = que.front();
            // cout << frontNode << " ";
            // ans.push_back(frontNode);
            
            for(auto each_nodes: adj[frontNode]){
                
                if(find(visited.begin(), visited.end(), each_nodes) == visited.end() ){
                    visited.push_back(each_nodes);
                    que.push(each_nodes);
                    parent[each_nodes] = frontNode;
                    // cout << frontNode <<", "<< each_nodes << " " << parent[each_nodes] << endl;
                    
                }else if(find(visited.begin(), visited.end(), each_nodes) != visited.end() && each_nodes != parent[frontNode] ){
                    // cout << "cycle: "<<frontNode <<", "<< each_nodes << " " << parent[each_nodes] << endl;
                    return true;
                }
            }
            
            que.pop();
            
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        for(int i = 0; i < adj.size(); i++){
            
            if(cyclePresent(adj, i)){
                return true;
            }
        }
        
        return false;
    }
*/

/*
    Cycle in a Directed Graph
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

    bool dfsTraversal(vector<vector<int>>& adj, int &initialnode, int node, vector<int> &visited){
        
        for(auto each_node: adj[node]){
            if(each_node == node){
                return true; // self cycle
            }
            if(initialnode == each_node){
                return true; // same to source Node
            }
            
            if(find(visited.begin(), visited.end(), each_node) == visited.end()){
                visited.push_back(each_node);
                bool ans =  dfsTraversal(adj, initialnode, each_node, visited);
                if(ans){
                    return true;
                }
            }

            
            
        }

        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {

        for(int i = 0; i < V; i++){
            
                vector<int> visited;
                visited.push_back(i);
                if(dfsTraversal(adj, i, i, visited)){
                    return true;
                }

        }
        
        return false;
        
    }
*/