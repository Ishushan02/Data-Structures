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