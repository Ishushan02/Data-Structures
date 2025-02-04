/*

Minimum Spanning Tree, A graphg with V vertices and E edges
    will have |V| - 1 edges

Total Number of Spanning Trees are  nCr => vCv' - total_cycles where v' is |V|- 1  

So, get the minimum cost out of all the possible Spanning Trees, that's MST

    Algorithms to Find MST
        - Prims Algorithm
        So, take one initial edge connecting to 2 vertices, now what you do is itterate to those edges
        in which has the minimum cost of the edge

        Continue it untill all vertices are covered

        - Kruskal's Algorithm

        Select all the edges in sorted way, and while doing so make sure that any edge is not
        forming any of the cycle

        Continue it untill all vertices are covered


*/


/*
    MST Using Prims Algorithm
    (https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1)

    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // node, - [ {wt, node}, {wt, node}, ... ]
        unordered_map< int, vector<pair<int, int>> > adjList;
        
        for (int i = 0; i < V; i++) {
            for (auto v : adj[i]) {
                adjList[i].push_back({v[1], v[0]});
            }
        }
        
        vector<int> visited;
        // vector<int> mst<V, 0>;
        int node = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que;
        que.push({0, 0});
        int totalCost = 0;

        while(visited.size() < V){
            
            pair<int, int> topelem = que.top();
            int wt = topelem.first;
            int node = topelem.second;
            if(find(visited.begin(), visited.end(), node) != visited.end()){
                // if these node is already visited, pop it, and continue
                que.pop();
                continue;
            }
            visited.push_back(node);
            totalCost += wt;
            que.pop();
            
            for(neigh: adjList[node]){
                if(find(visited.begin(), visited.end(), neigh.second) == visited.end()){
                    que.push({neigh.first, neigh.second});
                }
            }
 
        }

        
        return totalCost;
    }
*/