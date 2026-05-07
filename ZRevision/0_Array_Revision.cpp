/*
    Longest Subarray with Sum K
    (https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)
    // Make Note reupdating if the sum already exists, as the idx has to be at most left as possible to get max Len.

    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mapSum;
        int sum = 0;
        int maxLen = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            
            if(sum == k){
                maxLen = max(i + 1, maxLen);
            }
            
            int remSum = sum - k;
            if(mapSum.find(remSum) != mapSum.end()){
                maxLen = max(i - mapSum[remSum], maxLen);
            }
            
            if(mapSum.find(sum) == mapSum.end()){
                mapSum[sum] = i;
            }

        }
        
        return maxLen;
    }
*/