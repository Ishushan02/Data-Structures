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

    - It is not necessary that all vertices of Grpah need to be connected {Connected and Disconnected Graph}

    - There are 2 ways of representing a Graph
        - Adjacency List
        - Adjacency Matrix
    
    - Most Cases are in 
        BFS(Queue same as Level Order Traversal mark visited whenever you visit the Node),
        DFS(recursion and just mark visited whenever you visit the Node), 
        and Topological Sorting


*/

class Graph{
    public: 
        // edge -> {connected edge, weight}, {}, {}, ...
        unordered_map<int, vector< pair<int, int> > > adjList;



        void addEdge(int u, int v, int weight, bool direction){
            // direction 0 -> undirected Graph
            // direction 1 -> Directed Graph

            if(direction == 0){
                pair<int, int> pr1 ;
                pr1.first = v;
                pr1.second = weight;
                pair<int, int> pr2 ;
                pr2.first = u;
                pr2.second = weight;

                adjList[u].push_back(pr1);
                adjList[v].push_back(pr2);
            }else{
                pair<int, int> pr1 ;
                pr1.first = v;
                pr1.second = weight;
                adjList[u].push_back(pr1);
            }

        }

        void printAdjacency(){

            for(auto &[key, value] : adjList){
                cout <<  key << " : [ ";
                for(auto vertices:value){
                    cout << "{" << vertices.first << " ," << vertices.second << " }, ";
                }
                cout << "]" << endl;
            }
        }

};

int main(){

    Graph gr;
    gr.addEdge(1, 2, 1,true);
    gr.addEdge(1, 3, 2,true);
    gr.addEdge(2, 3, 3,true);
    gr.addEdge(2, 5, 2,true);
    gr.addEdge(3, 1, 2, true);
    gr.addEdge(5, 1, 1, true);

    gr.printAdjacency();


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