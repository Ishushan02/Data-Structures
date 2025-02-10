/*
    Topological Sort

    - Only on Directed Acyclic Graph

    - Main Logic of BFS is put those nodes into queue which has indegree as 0
    - Main Logic of DFS is backtracking, which we put elements after all oeprations

    (https://www.geeksforgeeks.org/problems/topological-sort/1)

    void topologicalSortDfs(int src, vector<vector<int>>& adj, unordered_map<int, bool> &visited, vector<int> &ans){
        
        visited[src] = true;
        for(auto neighbour: adj[src]){
            if(!visited[neighbour]){
                topologicalSortDfs(neighbour, adj, visited, ans);
            }
        }
        
        ans.push_back(src);
        // storing it here such that all goes in stacks it
        
    }


  void topologicalSortBfs(vector<vector<int>>& adj, vector<int> &ans){
       
       vector<int> indegree(adj.size() ,0);
       queue<int> que;
       for(int i = 0; i < adj.size(); i++){
           for(auto neighbour:adj[i]){
               indegree[neighbour]++;
           }
       }
       
       for(int i = 0; i < adj.size(); i++){
           if(indegree[i]==0){
               que.push(i);
           }
       }
       
       while(!que.empty()){
           int frontNode = que.front();
           que.pop();
           ans.push_back(frontNode);
           
           for(auto neighbour: adj[frontNode]){
               indegree[neighbour]--;
               if(indegree[neighbour] == 0){
                   que.push(neighbour);
               }
           }
        }
       
       
        
    }
  
    
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        
        vector<int> ans;
        
        // unordered_map<int, bool> visited;
        
        // Even for DFS you have to start from that vertex whose indegree is 0, remember this
        // for(int i = 0; i < adj.size(); i++){
        //     if(!visited[i]){
        //         // topologicalSortDfs(i, adj, visited, ans);
        //     }
        // }
        
        // reverse(ans.begin(), ans.end());
        
        
        topologicalSortBfs(adj, ans);
        return ans;
    }

*/


/*

Do Cycle Detection Using Topological Sort 

See previous all cycle detections using BFS and DFS

*/

/*
    207. Course Schedule
    (https://leetcode.com/problems/course-schedule/description/)

    // The main Logic is that, when we create graph and if there is a cycle which means that we won't be 
    // able to finish all the courses as each one of them will in depenedent on each other, whereas 
    // if cycle doen't exist which means we will be able to complete the courses independently

    // If you do Cycle Detection using DFS, it will give TLE


    void topologicalBfs(int n, map<int, vector<int>> &adjList, vector<int> &ans){

        queue<int> que;
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto val: adjList[i]){
                indegree[val]++;
            }
        }
    
        for(int i = 0; i < n; i++){
           if(indegree[i]==0){
               que.push(i);
           }
        }

        while(!que.empty()){
            int frontNode = que.front();
            ans.push_back(frontNode);

            for(auto val:adjList[frontNode]){
                indegree[val]--;

                if(indegree[val] == 0){
                    que.push(val);
                }
            }

            que.pop();

        }


    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adjList;

        for(auto val:prerequisites){
            adjList[val[1]].push_back(val[0]);
        }

        vector<int> ans;
        

        topologicalBfs(numCourses, adjList, ans);

        if(ans.size() == numCourses){
            return true;
        }

        return false;
    }

*/


/*
    210. Course Schedule II 
    (https://leetcode.com/problems/course-schedule-ii/description/)

    // Same as Above just that you have to return the answer

    void topologicalBfs(int n, map<int, vector<int>> adjList, vector<int> &ans){

        vector<int> indegree(n, 0);
        queue<int> que;

        for(int i = 0; i < n; i++){
            for(auto val:adjList[i]){
                indegree[val]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }

        while(!que.empty()){

            int frontNode = que.front();
            ans.push_back(frontNode);
            que.pop();

            for(auto val:adjList[frontNode]){
                indegree[val]--;

                if(indegree[val] == 0){
                    que.push(val);
                }
            }
        }

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> adjList;

        for(auto val:prerequisites){
            adjList[val[1]].push_back(val[0]);
        }

        vector<int> ans;
        

        topologicalBfs(numCourses, adjList, ans);

        if(ans.size() == numCourses){
            return ans;
        }
        ans = {};
        return ans;
    }

*/


/*

    // The idea is that just as you run Indegree for Topological Sort, 
    // execute outdegree the same way

    // first create all Outdegree Graph
    // count the Outdegree Nodes, if outdegree is 0, store that in que

    // BFS on queue element, append ans on once element is popped, each time you visite a neigh
    // decrement the outdegree count of that neigh
    // if outdegree count is 0 push that or else leave it

    802. Find Eventual Safe States
    (https://leetcode.com/problems/find-eventual-safe-states/description/)

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        queue<int> que;
        // normal graph is an outdegree graph

        vector<vector<int>> outdegreegraph(graph.size(), vector<int>());


        for(int i = 0; i < graph.size(); i++){
            for(auto neigh: graph[i]){
                outdegreegraph[neigh].push_back(i);
            }
        }

        vector<int> outDegree;

        for(int i = 0; i < graph.size(); i++){
            outDegree.push_back(graph[i].size());
        }

        for(int i = 0; i < outDegree.size(); i++){
            if(outDegree[i] == 0){
                que.push(i);
            }
        }
        vector<int> ans;

        while(!que.empty()){

            int front = que.front();
            ans.push_back(front);
            que.pop();

            for(auto neigh: outdegreegraph[front]){
                outDegree[neigh]--;
                if(outDegree[neigh] == 0){
                    que.push(neigh);
                }
            }

        }
        sort(ans.begin(), ans.end());
        return ans;
    }
*/