/*
    3470. Permutations IV
    (https://leetcode.com/problems/permutations-iv/)

    (TIME LIMIT EXCEEDED)

    void traverse(int idx, int n, vector<int>& tempAns, vector<vector<int>>& res, unordered_map<int, bool> &visited){
        
        if(tempAns.size() == n){
            res.push_back(tempAns);
            return;
        }

        for(int i = 1; i <= n;i++){
            if(visited[i] == false){
                if(tempAns.size() > 0){
                    int back = tempAns.back();
                    if(abs(back-i) & 1){ // difference of odd and even is always odd
                        visited[i] = true;
                        tempAns.push_back(i);
                        traverse(i+1, n, tempAns, res, visited);
                        tempAns.pop_back();
                        visited[i] = false;

                    }
                        
                }else{
                    visited[i] = true;
                    tempAns.push_back(i);
                    traverse(i+1, n, tempAns, res, visited);
                    tempAns.pop_back();
                    visited[i] = false;
                }
                
            }
        }
    }

    vector<int> permute(int n, long long k) {
        unordered_map<int, bool> visited;
        vector<int> tempAns;
        vector<vector<int>> res;
        traverse(1, n, tempAns, res, visited);
        if(k > res.size()){
            return {};
        }

        return res[k-1];
    }

*/