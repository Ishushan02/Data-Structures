#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

/*

Cycle Detection: 

    Directed Graph and Undirected Graph

    - So, the simple logic to find the cycle is that when you find any Node which is already Visited
    and is not the parent of current Node, hence we can conclude that Cycle Exist. {Just think that
    we are visitng a node again, which is not it's parent means that obviously cycle should be present
    there as it is being revisited. }
*/

class Graph{
    public :
        unordered_map<int, vector<int> > adjList;

        void addEdge(int u, int v, bool direction){
            // direction is 0 undirected, 
            // direction is 2 directed

            if(direction == 0){
                adjList[u].push_back(v);
                adjList[v].push_back(u);

            }else{
                adjList[u].push_back(v);
            }

        }

        void printList(){
            for(auto &[key, value]:adjList){
                cout << key << " ";
                for(auto each_val:value){
                    cout << each_val << " ";
                }
                cout<<endl;
            }
        }

        bool containdCycleBFS(int currNode){
            queue<int> que;
            vector<int> visited;
            unordered_map<int, int> parent;

            que.push(currNode);
            visited.push_back(currNode);

            while(!que.empty()){
                int frontNode = que.front();
                vector<int> adjacentNodes = adjList[frontNode];

                for(auto node:adjacentNodes){
                    // cout << " Node: " << node << endl;
                    if(find(visited.begin(), visited.end(), node) == visited.end()){
                        visited.push_back(node);
                        parent[node] = frontNode;
                        que.push(node);
                    }else if((find(visited.begin(), visited.end(), node) != visited.end()) && (parent[frontNode] != node)){
                        // cout << "Here: "<< parent[frontNode] << endl;
                        return true;
                    }

                }
                que.pop();
            }


            return false;

        }
};


int main(){


    Graph gr;

    gr.addEdge(0, 1, 0);
    gr.addEdge(0, 2, 0);
    gr.addEdge(1, 3, 0);
    gr.addEdge(2, 3, 0);

    // gr.printList();
    
    cout << gr.containdCycleBFS(0) << endl;

}