/*
    1851. Minimum Interval to Include Each Query
    (https://leetcode.com/problems/minimum-interval-to-include-each-query/)

    struct comp{
        bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>>&b){
            if(a.first == b.first){
                return a.second.first < b.second.first;
            }
            return a.first < b.first;
        }
    };

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        vector<pair<int, pair<int, int>>> interValArr;

        for(int i = 0; i < intervals.size(); i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            interValArr.push_back({r - l + 1, {l, r}});
        }

        sort(interValArr.begin(), interValArr.end(), comp());

        vector<int> ans;

        for(auto query: queries){
            bool isavail = false;
            for(int i = 0; i < interValArr.size(); i++){
                int l = interValArr[i].second.first;
                int r = interValArr[i].second.second;
                int diff = interValArr[i].first;
                if(l <= query && query <= r){
                    isavail = true;
                    ans.push_back(diff);
                    break;
                }
            }
            if(!isavail){
                ans.push_back(-1);
            }
        }

        return ans;
    }
        
*/