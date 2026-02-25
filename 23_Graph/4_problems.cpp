#include<iostream>
#include<unordered_map>

using namespace std;


/*

    Remeber this if you do INTMAX + 1 --> this will go to -INT_MAX
    This error which you couldn't figure out and took so much of your time.
*/


/*
Shortest path Algorithms

    - First get the Parent Nodes of each node by doing BFS Traversal
    - From the parent Nodes of each we can find out a path from Source Node to Destination Node.
    // {Remember the below functionality}
*/

class Graph{

    public:
    unordered_map<int , vector<int> > nodes;

    void add_edge(bool direction, int u, int v){
        if(direction == 0){
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }else{
            nodes[u].push_back(v);
        }
    }

    void shortestPath(int source, int destination){
        unordered_map<int, int> parentNode;
        unordered_map<int, bool> visited;
        queue<int> que;

        que.push(source);
        parentNode[source] = -1;
        visited[source] = true;

        while(!que.empty()){

            int frontNode = que.front();
            que.pop();

            for(auto neighbour:nodes[frontNode]){

                if(visited[neighbour] == 0){
                    visited[neighbour] = true;
                    parentNode[neighbour] = frontNode;
                    que.push(neighbour);
                }
            }
        }

        // get shortest path
        int tempDest = destination;
        vector<int> ansPath;
        while(tempDest != -1){
            ansPath.push_back(tempDest);
            int parent = parentNode[tempDest];
            tempDest = parent;
        }

        // as path will be stored in opposite direction
        reverse(ansPath.begin(), ansPath.end());

        for(auto path:ansPath){
            cout << path << " ->";
        }


    }

    void printAdjacency(int n){

            for(int i = 0; i < n; i++){
                cout <<  i << " : [ ";
                for(auto vertices:nodes[i]){
                    cout << "{" << vertices << " }, ";
                }
                cout << "]" << endl;
            }
    }

};


int main(){

    Graph g;

    g.add_edge(0, 0, 1);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 3);
    g.add_edge(0, 2, 4);
    g.add_edge(0, 4, 5);
    g.add_edge(0, 5, 3);

    g.shortestPath(0, 3);

}


/*
    (Shortest Path in Undirected)
    (https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int vertices = adj.size();
        unordered_map<int, int> parentNode;
        unordered_map<int, bool> visited;
        queue<int> que;
        visited[src] = true;
        parentNode[src] = -1;
        que.push(src);
        
        while(!que.empty()){
            
            int frontNode = que.front();
            que.pop();
            
            for(auto neighbour:adj[frontNode]){
                if(visited[neighbour] == 0){
                    visited[neighbour] = true;
                    parentNode[neighbour] = frontNode;
                    que.push(neighbour);
                }
            }
        }
        
        vector<int> ans(vertices, 0);
        
        for(int i = 0; i < vertices; i++){
            
            
            if(i == src){
                ans[i] = 0;
            }else if(parentNode.find(i) == parentNode.end()){
                ans[i] = -1;
            }else{
                int tempDest = i;
                int cost= 0;
                while(tempDest != -1){
                    cost += 1;
                    tempDest = parentNode[tempDest];
                }
                ans[i] = cost-1;
            }
            
        }
        
        return ans;
        
    }

*/

/*

    Now to Find the Minimum distance from one of the Node to all the Nodes in the weighted Graph


    - So let's say we have a Node
    - From that source Node, get all the vertices connected to them
    - get the minimum weighted edge and update the distance
    - now traverse the next Node based on Topological sort
    // (as this will make sure that the upcoming node doesn't have any dependency)

    Good Logic

    Same Question GFG is implemented below
*/


/*

    Shortest path in Directed Acyclic Graph
    (https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0)

    void dfs(int src, unordered_map<int, vector<pair<int, int>> >& adjList, vector<int> &visited, vector<int> &ans){
        visited[src] = 1;
        
        
        for(auto neigh:adjList[src]){
            if(visited[neigh.first] == 0){
                dfs(neigh.first, adjList, visited, ans);
            }
        }
        
        ans.push_back(src);
    }
    
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int, vector<pair<int, int> > > adjList;
        
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> topOrder;
        vector<int> visited(V, 0);
        
        dfs(0, adjList, visited, topOrder);
        
        reverse(topOrder.begin(), topOrder.end());

        vector<int> distAns(V, INT_MAX);
        
        int element = topOrder[0];
        distAns[element] = 0;
        
        
        for(int i = 0; i < topOrder.size(); i++)
        {
            int node = topOrder[i];
            
            for(auto &neigh : adjList[node]){
                
                int neighbourNode = neigh.first ;
                int wt = neigh.second ;
                if(distAns[node] + wt < distAns[neighbourNode]){
                    distAns[neighbourNode] = distAns[node] + wt;
                }
            }
        }
        
        for(auto &val:distAns){
            if(val == INT_MAX){
                val = -1;
            }
        }
        
        return distAns;
    }
*/


/*
    Dijkstra Algorithm
    (https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> ans(adj.size(), INT_MAX);
        
        ans[src] = 0;
        minHeap.push({0, src});
        vector<int> visited(adj.size(), 0);
        
        while(!minHeap.empty()){
            
            pair<int, int> frontElem = minHeap.top();
            minHeap.pop();
            
            int dist = frontElem.first;
            int node = frontElem.second;
            for(auto &neigh: adj[node]){
                int elem = neigh.first;
                int weight = neigh.second;
                if(dist + weight < ans[elem]){
                    ans[elem] = dist + weight;
                    minHeap.push({ans[elem], elem});
                }
            }
        }
        
        
        return ans;
    }
*/


/*  
    Bellman-Ford
    (https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)

    // SO procedure is run the weight updation for V times, 
    // If the weight doesn't have any negative cycle it will be staurated in V times updation
    // else run it once again, if it still updates then we have a negative cycle 

    Method 1. (This is better )
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int> ans(V, 1e8);
        ans[src] = 0;
        
        for(int i = 0; i < V; i++){
            
            for(auto neigh:edges){
                int node = neigh[0];
                int desNode = neigh[1];
                int weight = neigh[2];
                
                if((ans[node] != 1e8) && (ans[node] + weight < ans[desNode])){
                    ans[desNode] = ans[node] + weight;
                }
                
            }
        }
        
        // checking once again if this happens then we have negative cycle
        for(auto neigh:edges){
            int node = neigh[0];
            int desNode = neigh[1];
            int weight = neigh[2];
            
            if((ans[node] != 100000000) && ans[node] + weight < ans[desNode]){
                return {-1};
            }
                
        }
        
        return ans;
        
    }


    Method 2. (Oo Bhai this is also good)
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        unordered_map<int, vector<pair<int, int>>> graph;
        int E = edges.size();
        for(int i = 0; i < E; i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        vector<int> ans(V, 1e8);
        queue<pair<int, int>> que;
        que.push({src, 0});
        vector<int> negCycle(V, 0);
        
        while(!que.empty()){
            auto [nd, dt] = que.front();
            ans[nd] = min(ans[nd], dt);
            que.pop();
            
            for(auto val:graph[nd]){
                auto [v, wt] = val;
                
                if(ans[v] == 1e8 || wt + dt < ans[v]){
                    if(ans[v] < 0) negCycle[v] += 1;
                    
                    if(negCycle[v] >= 2) return {-1};
                    que.push({v, wt + dt});
                }
            }
        }
        
        return ans;
    }
   

*/


/*

    Multiple source shortest Path(MSSP)
    Floyd Warshall Algorithm

    It's not that important but still see it once, what it is
    (https://www.youtube.com/watch?v=oNI0rf2P9gE)

    - We can use Dijkstra's ALgorithm for all Nodes, hence the TC: O(n3)

    - We will solve this by DP

    - let's say we have to find the min Distance from U to V,
    - What you do is find the min distance from U to V through an intermediate Node..alignas

    - U and V are all possible vertices of Graph also the Intermediate nodes are all possible vertices of Graph

    Floyd Warshall
    (https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        
        int n = mat.size();
        for(int U = 0; U < n; U++){
            for(int V = 0; V < n; V++){
                if(mat[U][V] == -1){
                    mat[U][V] = 1e8;
                }
            }
        }
        
        
        for(int intermediate = 0; intermediate < n; intermediate++){
            
            for(int U = 0; U < n; U++){
                for(int V = 0; V < n; V++){
                    if(mat[U][intermediate] + mat[intermediate][V] < mat[U][V]){
                        mat[U][V] = mat[U][intermediate] + mat[intermediate][V];
                    }
                }
            }
        }
        
        for(int U = 0; U < n; U++){
            for(int V = 0; V < n; V++){
                if(mat[U][V] == 1e8){
                    mat[U][V] = -1;
                }
            }
        }
    }

*/

/*
    Do All Of it. Floyd Warsall Application
    https://leetcode.com/problem-list/9idenloe/
*/

/*
    399. Evaluate Division
    (https://leetcode.com/problems/evaluate-division/description/)

    double getValue(unordered_map<string, vector<pair<string, double>>>& graph, string &src, string &des){
        double ansVal = 1.0;

        queue<pair<string, double>> que;
        unordered_map<string, bool> visited;
        que.push({src, ansVal});
        visited[src] = true;

        while(!que.empty()){
            auto [strVal, temp] = que.front();
            que.pop();

            for(auto vals: graph[strVal]){
                auto [s, w] = vals;
                if(s == des) return w * temp;
                if(!visited[s]){
                    que.push({s, w * temp});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, bool> uniqueStrings;
        unordered_map<string, vector<pair<string, double>>> graph;

        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double wt = values[i];
            double negWt = 1/values[i];
            graph[b].push_back({a, wt});
            graph[a].push_back({b, negWt});
            uniqueStrings[a] = true;
            uniqueStrings[b] = true;
        }

        vector<double> ans;

        for(int i = 0; i < queries.size(); i++){
            string src = queries[i][1];
            string des = queries[i][0];
            
            if(uniqueStrings[src] && uniqueStrings[des]){
                auto x = getValue(graph, src, des);
                ans.push_back(x);
            }else{
                ans.push_back(-1.0);
            }

        }

        return ans;

    }
        
*/