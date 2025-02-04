/*
547. Number of Provinces
(https://leetcode.com/problems/number-of-provinces/)

    void dfsTraversal(int node, vector<int> &visited, vector<vector<int> > &graph){
        visited[node] = 1;

        for(auto neigh: graph[node]){
            if(visited[neigh] == 0){
                dfsTraversal(neigh, visited, graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
         vector<vector<int> > graph(n, vector<int>());
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                }
                
            }
        }

        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                count += 1;
                dfsTraversal(i, visited, graph);
            }
        }

        return count;
    }


*/


/*
    994. Rotting Oranges
    (https://leetcode.com/problems/rotting-oranges/description/)

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();        
        queue<pair<int, int>> que;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int count = 0;
        int freshOranges = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    que.push({i, j});
                }else if(grid[i][j] == 1){
                    freshOranges += 1;
                }
            }
        }

        // the zero case
        if(freshOranges == 0){
            return 0;
        }

        while(!que.empty()){
            int qsize = que.size();

            for(int p = 0; p < qsize; p++){
                pair<int, int> curr = que.front();
                int i = curr.first;
                int j = curr.second;
                que.pop();
                vector<int> dx = {0, 0, 1, -1};
                vector<int> dy = {1, -1, 0, 0};

                for(int k = 0; k < 4; k++){
                    int x = dx[k] + i;
                    int y = dy[k] + j;

                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        que.push({x, y});
                        freshOranges--;
                    }

                }
            }
            count += 1;


        }

        if(freshOranges == 0){
            return count - 1;
        }

        return -1;
    }

*/


/*
    Do it Again
    (https://leetcode.com/problems/cheapest-flights-within-k-stops/)
*/

/*
    2360. Longest Cycle in a Graph
    (https://leetcode.com/problems/longest-cycle-in-a-graph/description/)


    Method 1 Memory Limit Exceeded

    void dfsTraversal(int node, int sourceNode, vector<vector<int>> &adjList, vector<int> visited, int edgeCount, int &ans){
        visited[node] = 1;
        

        for(auto neigh:adjList[node]){
            
            if(neigh == sourceNode){
                // cycle exist
                ans = max(ans, edgeCount+1);
                return ;
            }
            if(visited[neigh] == 0){
                dfsTraversal(neigh, sourceNode, adjList, visited, edgeCount + 1, ans);
            }

            
        }

    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n, vector<int>());

        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                adjList[i].push_back(edges[i]);
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout << i << " ";
        //     for(auto neigh:adjList[i]){
        //         cout << neigh << " ";
        //     }cout << endl;
        // }

        vector<int> visited(n, 0);
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfsTraversal(i, i, adjList, visited, 0, ans);
            }
        }


        return ans;
    }
*/