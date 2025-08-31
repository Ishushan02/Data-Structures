/*
    Strongly Connected Components
    (https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

    void dfsTravel(int node,  stack<int> &store, vector<int> &visited, 
    vector<vector<int>> &adj){
        visited[node] = 1;
        for(auto v: adj[node]){
            if(visited[v]==0){
                dfsTravel(v, store, visited, adj);
            }
        }
        store.push(node);
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<vector<int>> reverseadj(n, vector<int>());
        for(int i = 0; i < n; i++){
            for(auto v: adj[i]){
                reverseadj[v].push_back(i);
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     cout << i << " : "<<endl;
        //     for(auto v: reverseadj[i]){
        //         cout << v << " ";
        //     }cout<<endl;
        // }
        
        vector<int> visited(n, 0);
        stack<int> store;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfsTravel(i, store, visited, adj);
            }
        }
        // for(auto v:store){
        //     cout << v<< " ";
        // }
        
        vector<int> reverseVisited(n, 0);
        int count = 0;
        int i = 0;
        while(!store.empty()){
            int v = store.top();
            if(reverseVisited[v] == 0){
                stack<int> p;
                dfsTravel(v, p, reverseVisited, reverseadj);
                count += 1;
            }
            store.pop();
        }
        
        return count;
    }
*/