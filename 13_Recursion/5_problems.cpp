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

/*
    VVVIII Question (Convert in to blocks, get the index, check if it's 0 or not, and then again update k.. untill n == 1)
    60. Permutation Sequence
    (https://leetcode.com/problems/permutation-sequence/)

    int factorial(int n){
        if(n == 1 || n == 0){
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    void permuteStringSeq(int n, int k, string &ans, string &s){
        if(n == 1){
            ans += s[0];
            return ;
        }

        int fct = factorial(n-1);
        int idx = k / fct;
        if(k % fct == 0){
            idx--;
        }

        ans += s[idx];
        s.erase(idx, 1);
        k = k - (idx * fct);
        permuteStringSeq(n-1, k, ans, s);
    }

    string getPermutation(int n, int k) {

        string s;
        for(auto i = '1'; i <= n + '0'; i++){
            s += i;
        }
        cout << s << endl;
        string ans;
        permuteStringSeq(n, k, ans, s);
        return ans;
    }

*/