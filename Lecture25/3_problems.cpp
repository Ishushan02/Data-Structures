/*
    Array Subset
    (https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1)

    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int m = a.size();
        int n = b.size();
        
        unordered_map<int, int> valMap;
        
        for(auto val:a){
            valMap[val]++;
        }
        
        for(auto val:b){
            valMap[val]++;
        }
        
        if(m < n){
            for(auto val:a){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }else{
            for(auto val:b){
                if(valMap[val] <= 1){
                    return false;
                }
            }
        }
        
        return true;
    }

*/