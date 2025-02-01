#include<iostream>
#include<unordered_map>

using namespace std;

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

        // The only change is that for negative nodes we run the 
        // dijkstra's loop for V times and by any chances in between 
        // the loop if the ans vector is not modified then that's the 
        // shortest path from the source node or else even after V
        // iterations the ans vector is modifying then there is a negative weight
        // that is present in the graph


    int isModified = false;
    void bellmanFordItr(pair<int, int> src, unordered_map<int, vector<pair<int, int> > >& adjList, vector<int> &ans){
        
        queue< pair<int, int> > que;
        
        que.push(src);
        
        int count = 0;
        while(!que.empty()){
            if(count >= 10 * adjList.size()){
                isModified = true;
                return ;
            }
            pair<int, int> front = que.front();
            que.pop();
            
            int node = front.second;
            int wt = front.first;
            
            for(auto &neigh:adjList[node]){
                int currnode = neigh.first;
                int currwt = neigh.second;
                if(wt + currwt < ans[currnode]){
                    ans[currnode] = wt + currwt;
                    que.push({ans[currnode], currnode});
                }
            }
            count += 1;
        }
        
        
    }
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        unordered_map<int, vector<pair<int, int> > > adjList;
        
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> ans(V, 100000000);
        ans[src] = 0;
        
        for(int i = 0; i < V; i++){
            // isModified = false;
            bellmanFordItr({ans[src], src}, adjList, ans);
            if(isModified == true){
                return {-1};
            }
        }
        
       
        return ans;
        
    }

*/