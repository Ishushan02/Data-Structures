/* 
    Problem 1
    1. Two Sum
    (https://leetcode.com/problems/two-sum/)

    struct comp{
        bool operator()(pair<int, int> &A, pair<int, int> &B){
            return A.second < B.second;
        }
    };

    int binarySearch(int n, vector<pair<int, int>> &dataPair, int key, int i){
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(dataPair[mid].second == key){
                if(dataPair[mid].first == i){
                    if(mid - 1 >= 0 && dataPair[mid-1].second == key){
                        return dataPair[mid-1].first;
                    }
                    if(mid + 1 < n && dataPair[mid+1].second == key){
                        return dataPair[mid+1].first;
                    }
                }

                return dataPair[mid].first;
            }else if(key > dataPair[mid].second){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> dataPair;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            dataPair.push_back({i, nums[i]});
        }

        sort(dataPair.begin(), dataPair.end(), comp());

        for(auto v: dataPair){
            int key = target - v.second;
            int i = v.first;
            int j = binarySearch(n, dataPair, key, i);
            if(j != -1){
                return {i, j};
            }
        }

        return {-1, -1};

    }
*/