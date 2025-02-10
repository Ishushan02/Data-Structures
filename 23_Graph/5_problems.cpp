/*

    THIS FILE IS VERY IMPORTANT .... DO IT AGAIN
*/

/*

    Kosa Raju Algorithm
    - To Find Strongly Connected Component
    A strongly Connected component is that in which if we start 
    at one node of a graph we will successfully reach every other node of the graph.

    A Strongly Connected component will remain strongly connected eventhough the graph directions
    are reversed

    So, the idea is that {To find total number of Strongly Connected Graph}

    - First Step is to find the DSF traversal {Store it}
    - Reverse the direction of graph now
    - Do the DFS traversal along the stored Nodes and when the loop is stopped which means that 1 componenet 
    of strong connected graph is over.. similarily continue it.

    Strongly Connected
    (https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

    void dfsTraversal(int srcNode, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsPath){
        visited[srcNode] = true;
        
        for(auto neigh:adj[srcNode]){
            if(!visited[neigh]){
                dfsTraversal(neigh, adj, visited, dfsPath);
            }
        }
        
        dfsPath.push_back(srcNode);
        
    }
    
    void dfsTraversal2(int srcNode, vector<vector<int>> &reversedMap, vector<bool> &visited1){
        visited1[srcNode] = true;
        
        for(auto neigh:reversedMap[srcNode]){
            if(!visited1[neigh]){
                dfsTraversal2(neigh, reversedMap, visited1);
            }
        }
        
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        vector<bool> visited(adj.size(), false);
        vector<int> dfsPath;
        
        // store the dfs Traversal
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                dfsTraversal(i, adj, visited, dfsPath);
            }
        }
        
        // it should be stack right, so reversing it
        reverse(dfsPath.begin(), dfsPath.end());
        
        // reverse the map
        vector<vector<int>> reversedMap(adj.size(), vector<int>());
        
        for(int i = 0; i < adj.size(); i++){
            for(auto neigh: adj[i]){
                reversedMap[neigh].push_back(i);
            }
        }
        
        // do dfs traversal Again, with counting the Nodes
        vector<bool> visited1(adj.size(), false);
        int count = 0;
        for(int i = 0; i < dfsPath.size(); i++){
            if(!visited1[dfsPath[i]]){
                dfsTraversal2(dfsPath[i], reversedMap, visited1);
                count += 1;
            }
        }
        
        
        
        return count;
        
    }

*/

/*

Bridge in a Graph
    Bridge in a Graph is defined as any edge, when removed makes the graph disconected
    {More precisely, when bridge is remove the number of connected components in graph increases}

    // Please remeber the procedure
    We have 4 array's and a time counter
    discovered time -> first time that node is discovered , initialize with -1
    lowest time -> the min possible time in which it can be discovered, initialize with -1
    visited
    parent, initialize with -1

    // start DFS traversal
     - if node is visiting for first time; i.e disc and low is -1.. update counter value to it, and increse counter time
        {do this for all first time and mark it as visited}

        - come to neigh nodes of that current node
            - if neigh is parent 
                do nothing
            - if not visited..
                -> visit it by recursively calling dfs traversal

                // backtrack here 
                check the discovered time of node, and lowest time of neigh
                if (lowest time of node is > lowest time of neigh) --> update it
                low[node] = min(low[node], low[neigh])
                which means that there is alternate ways by which current node can be reached 

                // now if the above update doesn't take place which means 
                // the lowest time of neigh > discovered time of node
                    matlab I cannot reach the neigh node via any other means that's why it didn't get updated right ?
                    hence that is the bridge.. neigh and node

                
            - else visited
                check low time of current node and discovered time of neigh
                if the discovered time neigh is less than low time of node update it.
                 Because it means that we can reach neigh via the alternate as well, hence
                    low[node] = min(low[node], discovered[neigh])

    

    // What I did wrong in this question was while making graph I forgot to created it as undirected graph

    1192. Critical Connections in a Network
    (https://leetcode.com/problems/critical-connections-in-a-network/description/)


    vector<vector<int>> bridges;

    void dfsTraversal(int node, vector<int> &visited, vector<int> &lowestDiscovered, 
        vector<int> &discovered, vector<int> &parent, int &counter, unordered_map<int, vector<int>> &graph){
            discovered[node] = counter;
            lowestDiscovered[node] = counter;
            counter += 1;
            visited[node] = 1;

            for(auto neigh: graph[node]){

                if(neigh == parent[node]){
                    continue;
                }

                if(visited[neigh] == 0){
                    parent[neigh] = node;
                    dfsTraversal(neigh, visited, lowestDiscovered, discovered, parent, counter, graph);

                    //backtrack
                    lowestDiscovered[node] = min(lowestDiscovered[node], lowestDiscovered[neigh]);

                    if(lowestDiscovered[neigh] > discovered[node]){
                        vector<int> temp;
                        temp.push_back(node);
                        temp.push_back(neigh);
                        bridges.push_back(temp);
                    }

                }else{
                    lowestDiscovered[node] = min(lowestDiscovered[node], discovered[neigh]);
                }
            }


    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < connections.size(); i++){
            int src = connections[i][0];
            int des = connections[i][1];

            graph[src].push_back(des);
            graph[des].push_back(src);
        }

        vector<int> visited(n, 0);
        vector<int> lowestDiscovered(n, -1);
        vector<int> discovered(n, -1);
        vector<int> parent(n, -1);
        int counter = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfsTraversal(i, visited, lowestDiscovered, discovered, parent, counter, graph);
            }
        }

        return bridges;


    }



*/

/*
    127. Word Ladder
    (https://leetcode.com/problems/word-ladder/description/)

    So, the procedure is something like
        start with begin word... and end with endWord .. and count the dist or words you got to reach there
        let's write BFS
        
        create a set such that the words doesn't get repeated.. like 
            hot->hat again it shouldnot be converted to hot.. hence once the word is found delete it
            for this we use set
        
        add all wordList into Set


        create a que{word, distance} of beginWord
        delete beginWord from set

        traverse along until que is empty.. 

            get the fron elemt, dist and pop the que

            check if front word is endword then return distance as we reached end word

            else:
                replace each character from 'a' to 'z' and check whether it is present in set or not
                    if it is present append it to que with {word, front dist + 1}
                    delete it from set as it's used
                
                // remeber while reverting change the original word to it's original value.
    



    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>> que;
        que.push({beginWord, 1});

        unordered_set<string> stringSet(wordList.begin(), wordList.end());

        // removing begin word as it's entered in the que
        stringSet.erase(beginWord);

        while(!que.empty()){

            pair<string, int> top = que.front();
            que.pop();
            string currWord = top.first;
            int dist = top.second;

            if(currWord == endWord){
                return dist;
            }else{

                for(int i = 0; i< currWord.length(); i++){
                    char originalChar = currWord[i];

                    // change it with all 26 characters
                    for(char  each_char= 'a'; each_char <= 'z'; each_char++){
                        currWord[i] = each_char;
                        if(stringSet.find(currWord) != stringSet.end()){
                            // string is present
                            que.push({currWord, dist+1});
                            stringSet.erase(currWord);
                        }
                    }

                    //replace the original char
                    currWord[i] = originalChar;
                }
            }

        }

        return 0;

    }


    Method 1 (My method, first create the graph and then calculate the distance)
    // Important thing is WOrdSet ... it makes the search to O(1) using count hence it's useful

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        unordered_map<string, vector<string>> stringMap;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, bool> visited;

        if(wordSet.count(endWord) == 0){
            return 0;
        }        

        queue<string> que;

        que.push(beginWord);

        // creating the graph
        while(!que.empty()){

            string curr = que.front();
            visited[curr] = true;
            que.pop();
            stringMap[curr] = {};
            string temp = curr;
            for(int i = 0; i < temp.length(); i++){
                char prev = temp[i];
                for(int ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;

                    if(ch == prev){
                        continue; // skipping the same word
                    }
                    // cout << temp << endl;
                    if(temp != endWord && wordSet.count(temp) > 0 && visited[temp] == false){
                        que.push(temp);
                        stringMap[curr].push_back(temp);
                    }

                    // for end word, as it was not creating correct map in actual above condition
                    // and it should be there in the wordList
                    if(temp == endWord && wordSet.count(temp) > 0){
                        stringMap[curr].push_back(temp);
                    } 
                }
                temp[i] = prev;
            }
        }

        // seeing the graph
        // for(auto &[key, val]:stringMap){
        //     cout << key << " ";
        //     for(auto each_str: val){
        //         cout << each_str << " ";
        //     }cout << endl;
        // }

        // Now you have graph, just do traversal

        queue<pair<string, int>> queans;

        queans.push({beginWord, 1});
        unordered_map<string, bool> visit;
        // visited = {};

        while(!queans.empty()){

            pair<string, int> queuetop = queans.front();
            queans.pop();
            string curr = queuetop.first;
            int dist = queuetop.second;

            visit[curr] = true;

            if(curr == endWord){
                return dist;
            }else{
                for(auto neigh:stringMap[curr]){
                    if(visit[neigh] == false){
                        queans.push({neigh, dist + 1});
                    }
                }
            }
        }

        

        return 0;

    }


*/


/*
    126. Word Ladder II
    (https://leetcode.com/problems/word-ladder-ii/description/)

    // Try Doing both of them using Trie ..

*/


/*

    // The main focus of the question is to understand that we have to find the maximum abs difference between heights
    // and all in the minimum of all of that.
    // Rest is simple BFS (or you acn say is Dijkstra's Algorithm.)

    1631. Path With Minimum Effort
    (https://leetcode.com/problems/path-with-minimum-effort/description/)

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();
        // absdiff, coordinates
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > minHeap;
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        
        distance[0][0] = 0;
        minHeap.push({0, {0, 0}});

        while(!minHeap.empty()){

            pair<int, pair<int, int>> values = minHeap.top();
            int currWt = values.first;
            int i = values.second.first;
            int j = values.second.second;
            minHeap.pop();

            // traverse along neighbours

            if(i == row -1 && j == col -1){
                return distance[i][j];
            }
                // right
                if(j+1 < col){
                    int diff = abs(heights[i][j] - heights[i][j+1]);
                    int newMaxDiff = max(currWt, diff);
                    if(newMaxDiff < distance[i][j+1]){
                        distance[i][j+1] = newMaxDiff;
                        minHeap.push({distance[i][j+1], {i, j+1}});
                    }
                    
                }

                // left 
                if(j - 1 >= 0){
                    int diff = abs(heights[i][j] - heights[i][j-1]);
                    int newMaxDiff = max(currWt, diff);
                    if(newMaxDiff < distance[i][j-1]){
                        distance[i][j-1] = newMaxDiff;
                        minHeap.push({distance[i][j-1], {i, j-1}});
                    }
                }

                // up 
                if(i - 1 >= 0){
                    int diff = abs(heights[i][j] - heights[i-1][j]);
                    int newMaxDiff = max(currWt, diff);
                    if(newMaxDiff < distance[i-1][j]){
                        distance[i-1][j] = newMaxDiff;
                        minHeap.push({distance[i-1][j], {i-1, j}});
                    }
                }
                
                // down
                if(i + 1 < row){
                    int diff = abs(heights[i][j] - heights[i+1][j]);
                    int newMaxDiff = max(currWt, diff);
                    if(newMaxDiff < distance[i+1][j]){
                        distance[i+1][j] = newMaxDiff;
                        minHeap.push({distance[i+1][j], {i+1, j}});
                    }
                
            }

            

        }



        return 0;
    }

*/