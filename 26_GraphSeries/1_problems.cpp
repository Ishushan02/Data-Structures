/*
    841. Keys and Rooms (BFS Traversal)
    (https://leetcode.com/problems/keys-and-rooms/description/)

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> que;
        bool ans;
        unordered_map<int, bool> roomKeys;

        que.push(0);

        while(!que.empty()){
            int key = que.front();
            que.pop();

            if(roomKeys[key] == true){
                continue;
            }

            roomKeys[key] = true;
            for(auto keys:rooms[key]){
                que.push(keys);
            }

        }

        return rooms.size()==roomKeys.size();
    }
*/

/*
    DFS Traversal
    (https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

    void dfsTraversal(vector<vector<int>>& adj, int node, unordered_map<int, bool> &visited, vector<int> &ans){
        visited[node] = true;
        ans.push_back(node);
        for(int v: adj[node]){
            if(visited[v] == false){
                dfsTraversal(adj, v, visited, ans);
            }
        }
        
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        for(int i = 0; i < adj.size(); i++){
            if(visited[i] == false){
                dfsTraversal(adj, i, visited, ans);
            }
        }
        
        return ans;
        
    }

*/

/*  

    547. Number of Provinces
    (https://leetcode.com/problems/number-of-provinces/description/)

    void dfsTraversal(int n, vector<vector<int>>& isConnected, int node, vector<bool> &visited){

        visited[node] = true;
        for(int i = 0; i < n; i++){
            if(isConnected[node][i] == 1 && visited[i] == false){
                dfsTraversal(n, isConnected, i, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfsTraversal(n, isConnected, i, visited);
                count += 1;
            }
        }

        return count;
    }
*/