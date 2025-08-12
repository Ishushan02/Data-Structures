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

/*
    200. Number of Islands
    (https://leetcode.com/problems/number-of-islands/description/)

    Done See, previous submissions or my Code
*/

/*
    733. Flood Fill
    (https://leetcode.com/problems/flood-fill/description/)

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> que;
        
        que.push({sr, sc});

        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!que.empty()){
            auto curr = que.front();
            que.pop();

            int i = curr.first;
            int j = curr.second;

            if(visited[i][j] == true){
                continue ;
            }

            visited[i][j] = true;
            int initialCol = image[i][j];
            image[i][j] = color;

            if(i + 1 < m && image[i+1][j] == initialCol && visited[i+1][j] == false){
                que.push({i+1, j});
            }
            if(j + 1 < n && image[i][j+1] == initialCol && visited[i][j+1] == false){
                que.push({i, j+1});
            }
            if(i - 1 >= 0 && image[i-1][j] == initialCol && visited[i-1][j] == false){
                que.push({i-1, j});
            }
            if(j - 1 >= 0 && image[i][j-1] == initialCol && visited[i][j-1] == false){
                que.push({i, j-1});
            }

        }

        return image;
    }
*/

/*
    994. Rotting Oranges
    (https://leetcode.com/problems/rotting-oranges/description/)

    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> que;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
            }
        }
        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        while(!que.empty()){
            int siz = que.size();
            for(int k = 0; k < siz; k++){
                auto front = que.front();
                que.pop();
                int i = front.first;
                int j = front.second;
                visited[i][j] = true;

                if(i + 1 < m && grid[i+1][j] == 1 && visited[i+1][j] == false){
                    grid[i+1][j] = 2;
                    que.push({i+1, j});
                }
                if(j + 1 < n && grid[i][j+1] == 1 && visited[i][j+1] == false){
                    grid[i][j+1] = 2;
                    que.push({i, j+1});
                }
                if(i - 1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == false){
                    grid[i-1][j] = 2;
                    que.push({i-1, j});
                }
                if(j - 1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == false){
                    grid[i][j-1] = 2;
                    que.push({i, j-1});
                }
            }
            count += 1;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        if(count == 0){
            return 0;
        }
        return count-1;

    }
*/

/*
    Undirected Graph Cycle - DFS
    (https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)
    
    bool dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int node, int parent, bool &cycle){
        visited[node] = true;

        for(auto v:graph[node]){
            if(visited[v] == false){
               if(dfs(graph, visited, v, node, cycle)){
                   return true;
               }
            }else if(v != parent){
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int n = V;
        vector<bool> visited(n, false);
        bool cycle = false;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                if(dfs(graph, visited, i, -1, cycle)){
                    return true;
                }
            }
            
        }
        return false;
    }

    -- BFS

    bool bfs(int V, unordered_map<int, vector<int>> &graph, int node, vector<bool> &visited){
        queue<int> que;
        que.push(node);
        vector<int> parents(V, -1);
        
        while(!que.empty()){
            
            int parent = que.front();
            visited[parent] = true;
            que.pop();
            for(auto v:graph[parent]){
                if(visited[v] == false){
                    parents[v] = parent;
                    // cout << parent << " , in que -> " << v << endl;
                    que.push(v);
                }else if(parents[parent] != v){
                    // cout << parent << " , Cycle -> " << v << endl;
                    return true;
                }
            }
            
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int n = V;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                if(bfs(V, graph, i, visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
*/

/*
    542. 01 Matrix
    (https://leetcode.com/problems/01-matrix/description/)

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ansMat(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, pair<int, int>>> queVal;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    queVal.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        while(!queVal.empty()){

            auto front = queVal.front();

            queVal.pop();

            int i = front.second.first;
            int j = front.second.second;
            int dist = front.first;
            ansMat[i][j] = dist;

            if(i + 1 < m && visited[i+1][j] == 0){
                visited[i+1][j] = 1;
                queVal.push({dist + 1, {i+1, j}});
            }

            if(j + 1 < n && visited[i][j+1] == 0){
                visited[i][j+1] = 1;
                queVal.push({dist + 1, {i, j + 1}});
            }
            if(i - 1 >= 0 && visited[i-1][j] == 0){
                visited[i-1][j] = 1;
                queVal.push({dist + 1, {i-1, j}});
            }
            if(j - 1 >= 0 && visited[i][j-1] == 0){
                visited[i][j-1] = 1;
                queVal.push({dist + 1, {i, j-1}});
            }

        }

        return ansMat;
    }
*/