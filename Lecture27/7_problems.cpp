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


/*
    Kruskal's Algorithm Implementation

    // See the Procedure
    // create a parent vector and assign parents to itself
    // create a rank vector and assign ranks to 0
    // creat union function and find parent function
    findParent()
        - in this you have to find the parent of node U,
        - also do the compression part of assgining the root value(parent)
         directly to the node when found such that we don;t have to do the procedure again
    
    union(u, v)
        - get parent of u and v
        - if they have same rank make any 1 of them parent and increase rank of other
        - if rank of u > rank of v
            assign parent[v] = parent[u] 
          else if  rank of v > rank of u
            assign parent[u] = parent[v]



    struct cmp {
        // you always forget const
        bool operator()(vector<int> &a, vector<int> &b) const{
            return a[0] < b[0];
        }
    };
  
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int findParent(vector<int> &parent, int node){
        
        if(parent[node] == node){
            return node;
        }
        
        // Not to check and find the parent multiple time
        // I am just updating the parents
        return parent[node] = findParent(parent, parent[node]);
    
    }
    
    void unionMat(int u, int v, vector<int> &parent, vector<int> &rank){
        
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if(rank[u] < rank[v]){
            parent[u] = parent[v];
        }else if(rank[u] > rank[v]){
            parent[v] = parent[u];
        }else{
            // ranks are equal make any og them parent
            parent[u] = v;
            rank[v]++;
        }
    }
        
    
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        // create parent and rank amtrix
        vector<int> rank(V, 0);
        vector<int> parent(V, 0);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        // create function findParent
        // done
        
        // MST Operation creating a linear DS
        // wt, node1, node 2
       
      vector<vector<int>> edges;
        
        for (int i = 0; i < V; i++) {
            for (auto vt : adj[i]) {
                
                int v = vt[0];
                int wt = vt[1];
                // int wt = vt[2];
                // cout << i << v << wt << endl;
                edges.push_back({wt, i, v});
            }
        }
        
        // sorting based on weight
        sort(edges.begin(), edges.end(), cmp());
        
        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            
            int wt = edges[i][0];
            int u = findParent(parent, edges[i][1]);
            int v = findParent(parent, edges[i][2]);
            if(u != v){
                ans += wt;
                unionMat(u, v, parent, rank);
            }
            
        }
        
        return ans;
        
    }
        
        
    }

*/


/*

    Really Really Good Question

    // We can also solve this by Normal recursion, but it will increase the Time COmplexity and the Memory
    // limit to agrat extent.. hence we use BFS.

    // See that as we increae the number of iteration in  queue, the total freq of prods will also increase
    // hence whenever we get the product that will be the minimum count hence return it.

    // Procedure is treat it like a graph problem
    // take que<prod, count>, visited{}, 
        // start with startelement;
        // push it in queue{start, 0}, and also mark it visited

        // loop untill que is empty
        //     - num, count
        //     pop()

            // check if num is end -> return count if it is end

            // multiply it with all the array elements treating it as neighbour elements
            // {prod * newelem, count + 1}
            // see if visited has it, or else push it in que

   //  return -1;

    Minimum Multiplications to reach End
    (https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0)


    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        unordered_map<int, int> visited;
        queue<pair<int, int>> que;
        
        que.push({start, 0});
        visited[start] = 0;
        
        while(!que.empty()){
            
            pair<int, int> curr = que.front();
            que.pop();
            int num = curr.first;
            int count = curr.second;
            
            if(num == end){
                return count;
            }
            
            for(auto neigh: arr){
                int prod = (num * neigh) % 100000;
                int newCount = count + 1;
                
                if(visited.find(prod) == visited.end()){
                    visited[prod] = newCount;
                    que.push({prod, newCount});
                }
            }
        }
        
        return -1;
    }
*/


/*
    1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
    (https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)


    // SO, the key idea is get all the distances from src Node, chunk out only those nodes which
    // has atmost threshold.. get the count and return it. {Do it for all Nodes}

    // Now, return the minimum count city.. and if there is a tie return the city with max key Val


    map<int, int> reachableCity;

    int getDistance(unordered_map<int, vector<pair<int, int>>> &graph, int src, int distanceThreshold){
        vector<int> distance(graph.size(), 1e8);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que;

        distance[src] = 0;

        que.push({0, src});

        while(!que.empty()){
            pair<int, int> data = que.top();
            int dist = data.first;
            int node = data.second;

            que.pop();

            for(auto neigh: graph[node]){
                int wt = neigh.first;
                int nd = neigh.second;
                if(dist + wt < distance[nd]){
                    distance[nd] = wt + dist;
                    que.push({distance[nd], nd});
                }
            }

        }
        
        int count = 0;
        for(int i = 0; i< distance.size(); i++){
            // cout << distance[i] << " ";
            if(src != i && distance[i] <= distanceThreshold){
                count+= 1;
            }
        }

        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int, vector<pair<int, int>>> graph;
        

        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int des = edges[i][1];
            int wt = edges[i][2];
            graph[src].push_back({wt, des});
            graph[des].push_back({wt, src});
        }

        // Assigning empty values Nodes with no edges
        for(int i = 0; i < n; i++){
            vector<pair<int, int>> temp;
            if(graph.find(i) == graph.end()){
                graph[i] = temp;
            }
        }

        int minAns = INT_MAX;
        int city = 0;
        for(int i = 0; i < n; i++){
            int citiesreachable = getDistance(graph, i, distanceThreshold);

            if(citiesreachable <= minAns){
                minAns = citiesreachable;
                city = i;
            }
        }

        
        return city;
    }
*/


/*

    Good APplication of Kruskal's Algorithm, See the procedure

    1319. Number of Operations to Make Network Connected
    (https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)

    int getParents(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = getParents(parent, parent[node]);
    }

    void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank){

        u = getParents(parent, u);
        v = getParents(parent, v);

        if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u]++;
        }else if(rank[v] > rank[u]){
            parent[u] = v;
            rank[v]++;
        }else{
            parent[u] = v;
            rank[v]++;
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1){
            return -1;
        }

        vector<int> parent(n, 0);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int extraedges = 0;
        for(int i = 0; i < connections.size(); i++){

            int u = getParents(parent, connections[i][0]);
            int v = getParents(parent, connections[i][1]);

            if(u != v){
                makeUnion(u, v, parent, rank);
            }else{
                extraedges += 1;
            }

        }

        int independentNodes = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                independentNodes++;
            }
        }
        int num_etherNet = independentNodes - 1;

        return num_etherNet;
    }


*/