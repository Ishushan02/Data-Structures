#include <iostream>
using namespace std;

/*

    Combinationation of Nodes/Vertices and Edges is known as Graph
    Application - any Network connection, 

    All Tree is Graph, but te vice versa is not True.

    Now there are 2 types - DIrected Edge and Undirected Edge

    Some Imortant Questions:
        Clone a Graph
        Clone a Tree
        Check Whether a Graph is a Tree or Not

    
    - Indegree - The incoming Nodes from a Vertex
    - OutGegree - The Outgoing Nodes from  a Vertex

    - Cyclic Graph, Acyclic Graph
    - Weighted Graph, Unweighted Graph

    - Path in a given Graph

    - It is not necessary that all vertices of Grpah need to be connected 
        {Connected and Disconnected Graph}

    - There are 2 ways of representing a Graph
        - Adjacency List
        - Adjacency Matrix
    
    - Most Cases are in 
        BFS(Queue same as Level Order Traversal mark visited whenever you visit the Node),
        DFS(recursion and just mark visited whenever you visit the Node), 
        and Topological Sorting


    IMPORTAANT QUESTIONS
        Clone a Graph
        Clone a Tree
        Check Whether Graph is A Tree or Not



*/

class Graph{
    public: 
        // edge -> {connected edge, weight}, {}, {}, ...
        unordered_map<int, vector<int> > adjList;
        unordered_map<int, vector<pair<int, int> > > weightedadjList;




        void addEdge(int u, int v, bool direction){
            // direction 0 -> undirected Graph
            // direction 1 -> Directed Graph

            if(direction == 0){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }else{
                adjList[u].push_back(v);
            }

        }


        void addWeightedEdge(int u, int v, int weight, bool direction){
            // direction 0 -> undirected Graph
            // direction 1 -> Directed Graph

            if(direction == 0){
                pair<int, int> temp1 ;
                temp1.first = v;
                temp1.second = weight;
                pair<int, int> temp2 ;
                temp2.first = v;
                temp2.second = weight;

                weightedadjList[u].push_back(temp1);
                weightedadjList[v].push_back(temp2);
            }else{
                pair<int, int> temp1;
                temp1.first = v;
                temp1.second = weight;
                weightedadjList[u].push_back(temp1);
            }

        }

        
        
        void printAdjacency(int n){

            for(int i = 0; i < n; i++){
                cout <<  i << " : [ ";
                for(auto vertices:adjList[i]){
                    cout << "{" << vertices << " }, ";
                }
                cout << "]" << endl;
            }
        }

        void printWeightedAdjacency(int n){

            for(int i = 0; i < n; i++){
                cout <<  i << " : [ ";
                vector<pair<int, int> > pairVal = weightedadjList[i];
                for(auto each_val:pairVal){
                    cout << "(" << each_val.first << ", "<< each_val.second << " ), ";
                }
                cout << "]" << endl;
            }
        }

};

int main(){

    Graph gr;
    // gr.addEdge(1, 2, true);
    // gr.addEdge(1, 3, true);
    // gr.addEdge(2, 3, true);
    // gr.addEdge(2, 5, true);
    // gr.addEdge(3, 1, true);
    // gr.addEdge(5, 1, true);
    // gr.addEdge(4, 2, true);

    // gr.printAdjacency(6);

    gr.addWeightedEdge(1, 2, 2, true);
    gr.addWeightedEdge(1, 3, 3, true);
    gr.addWeightedEdge(2, 3, 1, true);
    gr.addWeightedEdge(2, 5, 6, true);
    gr.addWeightedEdge(3, 1, 1, true);
    gr.addWeightedEdge(5, 1, 0, true);
    gr.addWeightedEdge(4, 2, 1, true);

    gr.printWeightedAdjacency(6);


}

/*

When implementing via Matrix - 
        Time Complexity : O(n2)
        Space Complexity : O(n2)

When implementing via Adj list - 
        Time Complexity : O(V + E)
        Space Complexity : O(V + E)

BFS and DFS
        Time Complexity : O(V + E)
        Space Complexity : O(V )


*/


/*
    BFS of graph
    (https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        
        vector<int> ans;
        int node = 0;
        vector<int> visited;
        queue<int> que;
        que.push(node);
        visited.push_back(node);
        
        
        while(!que.empty()){
            int frontNode = que.front();
            // cout << frontNode << " ";
            ans.push_back(frontNode);
            
            for(auto each_nodes: adj[frontNode]){
                
                if(find(visited.begin(), visited.end(), each_nodes) == visited.end() ){
                    visited.push_back(each_nodes);
                    que.push(each_nodes);
                }
            }
            
            que.pop();
            
        }
        
        return ans;
    }

*/