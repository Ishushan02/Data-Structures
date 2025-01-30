/*
    Topological Sort

    - Only on Directed Acyclic Graph

    (https://www.geeksforgeeks.org/problems/topological-sort/1)

    void topologicalSortDfs(int src, vector<vector<int>>& adj, unordered_map<int, bool> &visited, vector<int> &ans){
        
        visited[src] = true;
        for(auto neighbour: adj[src]){
            if(!visited[neighbour]){
                topologicalSortDfs(neighbour, adj, visited, ans);
            }
        }
        
        ans.push_back(src);
        // storing it here such that all goes in stacks it
        
    }


  void topologicalSortBfs(vector<vector<int>>& adj, vector<int> &ans){
       
       vector<int> indegree(adj.size() ,0);
       queue<int> que;
       for(int i = 0; i < adj.size(); i++){
           for(auto neighbour:adj[i]){
               indegree[neighbour]++;
           }
       }
       
       for(int i = 0; i < adj.size(); i++){
           if(indegree[i]==0){
               que.push(i);
           }
       }
       
       while(!que.empty()){
           
           int frontNode = que.front();
           que.pop();
           ans.push_back(frontNode);
           
           for(auto neighbour: adj[frontNode]){
               indegree[neighbour]--;
               if(indegree[neighbour] == 0){
                   que.push(neighbour);
               }
           }
       }
       
       
        
    }
  
    
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        
        vector<int> ans;
        
        // unordered_map<int, bool> visited;
        
        
        // for(int i = 0; i < adj.size(); i++){
        //     if(!visited[i]){
        //         // topologicalSortDfs(i, adj, visited, ans);
        //         topologicalSortBfs(i, adj, visited, ans);
        //     }
        // }
        
        // reverse(ans.begin(), ans.end());
        
        
        topologicalSortBfs(adj, ans);
        return ans;
    }

*/