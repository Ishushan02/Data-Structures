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
  
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        
        int startkey = 0;
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                topologicalSortDfs(i, adj, visited, ans);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

*/