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

/*
    130. Surrounded Regions
    (https://leetcode.com/problems/surrounded-regions/description/)

    void getSurroundings(int m, int n, vector<vector<char>>& board,  queue<pair<int, int>> &que){
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();
            if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] !='O'){
                continue;
            }

            board[i][j] = 'T';

            que.push({i+1, j});
            que.push({i, j-1});
            que.push({i, j+1});
            que.push({i-1, j});
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                que.push({i, 0});
            }
            if(board[i][n - 1] == 'O'){
                que.push({i, n-1});
            }
        }

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                que.push({0, i});
            }
            if(board[m-1][i] == 'O'){
                que.push({m-1, i});
            }
        }
        
        cout <<que.size() << endl;
        getSurroundings(m, n, board, que);

    }

*/

/*
    1765. Map of Highest Peak
    (https://leetcode.com/problems/map-of-highest-peak/description/)

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, pair<int, int>>> que;
        vector<vector<int>> visited(m, vector<int>(n, 0));


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    que.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        } 
        
        vector<vector<int>> height(m, vector<int>(n, 0));

        while(!que.empty()){
            auto val = que.front();
            int cnt = val.first;
            int i = val.second.first;
            int j = val.second.second;

            height[i][j] = cnt;

            if(i+1 < m && visited[i+1][j] == 0){
                que.push({cnt+1, {i+1, j}});
                visited[i+1][j] = 1;
            }

            if(i-1 >= 0 && visited[i-1][j] == 0){
                que.push({cnt+1, {i-1, j}});
                visited[i-1][j] = 1;
            }
            if(j+1 < n && visited[i][j+1] == 0){
                que.push({cnt+1, {i, j+1}});
                visited[i][j+1] = 1;
            }
            if(j-1 >= 0 && visited[i][j-1] == 0){
                que.push({cnt+1, {i, j-1}});
                visited[i][j-1] = 1;
            }

            que.pop();
        }

        return height;

    }

*/

/*
    1020. Number of Enclaves
    (https://leetcode.com/problems/number-of-enclaves/description/)

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                que.push({i, 0});
            }
            if(grid[i][n-1] == 1){
                que.push({i, n-1});
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1){
                que.push({0, i});
            }
            if(grid[m-1][i] == 1){
                que.push({m-1, i});
            }
        }

        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();

            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
                continue;
            }

            grid[i][j] = 0;
            que.push({i+1, j});
            que.push({i-1, j});
            que.push({i, j+1});
            que.push({i, j-1});
        }

        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += 1;
                }
            }
        }

        return ans;

    }

*/

/*

    694. Number of Distinct Islands
    (https://leetcode.com/problems/number-of-distinct-islands/description/)
    (https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1)

    void colorIslands(int X, int Y, vector<vector<int>>& grid, int i, int j, 
    int m, int n, vector<vector<int>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return ;
        }
        visited.push_back({i-X, j-Y});
        grid[i][j] = 0;
        
        if(i + 1 < m && grid[i+1][j] == 1){
            colorIslands(X, Y, grid, i+1, j, m, n, visited);
        }
        
        if(j + 1 < n && grid[i][j+1] == 1 ){
            colorIslands(X, Y, grid, i, j+1, m, n, visited);
        }
        
        if(i - 1 >= 0 && grid[i-1][j] == 1 ){
            colorIslands(X, Y, grid, i-1, j, m, n, visited);
        }
        
        if(j - 1 >= 0 && grid[i][j-1] == 1){
            colorIslands(X, Y, grid, i, j-1, m, n, visited);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<vector<int>>> ans;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<vector<int>> visited;
                    colorIslands(i , j, grid, i, j, m, n, visited);
                    ans.insert(visited);
                }
            }
        }
        
        
        return ans.size();
    }
*/


/*
    785. Is Graph Bipartite?
    (https://leetcode.com/problems/is-graph-bipartite/description/)

    void colorGraph(int node, vector<vector<int>>& graph, vector<bool>& visited, unordered_map<int, char>& coloredGraph, char color){

        char nextCol;
        if(color == 'r'){
            nextCol = 'g';
        }else{
            nextCol = 'r';
        }
        visited[node] = true;
        coloredGraph[node] = color;

        for(auto v:graph[node]){
            if(visited[v] == false){
                colorGraph(v, graph, visited, coloredGraph, nextCol);
            }
        }

        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        char col = 'r';
        unordered_map<int, char> coloredGraph;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                colorGraph(i, graph, visited, coloredGraph, col);
            }
        }

        for(int i = 0; i < n; i++){
            int col = coloredGraph[i];

            for(auto v:graph[i]){
                if(coloredGraph[v] == col){
                    return false;
                }
            }
        }

        return true;
        
    }

*/

/*
    886. Possible Bipartition
    (https://leetcode.com/problems/possible-bipartition/description/)

    bool colorGraph(int vertex, unordered_map<int, vector<int>> &graph, vector<int> &colored){
        
        queue<pair<int, int>> que;
        que.push({vertex, 0});

        while(!que.empty()){
            auto front = que.front();
            int node = front.first;
            int col = front.second;
            que.pop();
            colored[node] = col;

            int nextCol = 0;
            if(col == 0){
                nextCol = 1;
            }else{
                nextCol = 0;
            }

            for(auto v:graph[node]){
                if(colored[v] == col){
                    return false;
                }else if(colored[v] == -1){
                    que.push({v, nextCol});
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> colored(n+1, -1);
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < dislikes.size(); i++){
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= n; i++ ){
            if(colored[i] == -1){
                if(!colorGraph(i, graph, colored)){
                    return false;
                }
            }
        }

        return true;

    }
        
*/

/*
    802. Find Eventual Safe States
    (https://leetcode.com/problems/find-eventual-safe-states/description/)

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        unordered_map<int, int> outdegree;
        unordered_map<int, vector<int>> indegreeMap;
        int n = graph.size();
        vector<int> ans;
        queue<int> que;

        for(int i = 0; i < n; i++){
            for(auto val:graph[i]){
                indegreeMap[val].push_back(i);
            }

            outdegree[i] = graph[i].size();
            if(outdegree[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();
            ans.push_back(node);

            for(auto v:indegreeMap[node]){
                outdegree[v]--;
                if(outdegree[v] == 0){
                    que.push(v);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
    

    Method II

    bool isCycle(int node, vector<vector<int>> &edges, vector<int> &visited,
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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<int> pathVisited(n, -1);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                bool val = isCycle(i, graph, visited, pathVisited);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(pathVisited[i] == -1){
                ans.push_back(i);
            }
        }
        return ans;
    }

*/

/*

    2360. Longest Cycle in a Graph
    (https://leetcode.com/problems/longest-cycle-in-a-graph/)

    void isCycle(int node, unordered_map<int, int> &graph, vector<int> &pathVisited, vector<int> &visited, int count, unordered_map<int, int> &countGraph, int &maxLength){
        visited[node] = 1;
        pathVisited[node] = 1;
        countGraph[node] = count;

        int nextNode = graph[node];
        if(nextNode != -1){
            if(visited[nextNode] == -1){
                isCycle(nextNode, graph, pathVisited, visited, count+1, countGraph, maxLength);
            }else if(pathVisited[nextNode] == 1){
                int cnt = count - countGraph[nextNode] + 1;
                maxLength = max(maxLength, cnt);
            }
        }
        pathVisited[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int, int> graph;
        for(int i = 0; i < n; i++){
            graph[i] = edges[i];
        }
        
        vector<int> visited(n, -1);
        vector<int> pathVisited(n, 0);
        

        int maxCount = -1;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> countGraph;
            if(visited[i] == -1){
                isCycle(i, graph, pathVisited, visited, 1, countGraph, maxCount);
            }
        }

        return maxCount;

    }

*/

/*

    207. Course Schedule
    (https://leetcode.com/problems/course-schedule/description/)

    210. Course Schedule II
    (https://leetcode.com/problems/course-schedule-ii/description/)

*/