/*
    374. Guess Number Higher or Lower
    (https://leetcode.com/problems/guess-number-higher-or-lower/description/)

    int guessNumber(int n) {
        
        int start = 1;
        int end = n;
        int mid = start+((end-start)/2);

        while (start <= end){
            int val = guess(mid);

            if (val == -1){
                end = mid-1;
            }else if (val == 1){
                start = mid+1;
            }else{
                return mid;
            }
            mid = start+((end-start)/2);
        }
        return n;
    }

*/

/*
    1337. The K Weakest Rows in a Matrix
    (https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/)

    struct comp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            if(a.second == b.second){
                if(a.first < b.first){
                    return true;
                }
                return false;
            }else if(a.second < b.second){
                return true;
            }
            return false;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> valPair;

        for(int i = 0; i < mat.size(); i++){
            int col = mat[0].size();
            int count = 0;
            for(auto v : mat[i]){
                if(v == 1){
                    count++;
                }else{
                    // because 1's are only on the left
                    break;
                }
            }
            valPair.push_back({i, count});
        }
        sort(valPair.begin(), valPair.end(), comp());
        vector<int> ans;

        for(int i = 0; i < k; i++){
            ans.push_back(valPair[i].first);
        }

        return ans;
    }

*/

