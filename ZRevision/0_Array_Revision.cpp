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


/*
    560. Subarray Sum Equals K
    (https://leetcode.com/problems/subarray-sum-equals-k/description)

    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mapSum;
        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                count += 1;
            }

            int rem = sum - k;
            if(mapSum.find(rem) != mapSum.end()){
                count += mapSum[rem];
            }
            mapSum[sum] += 1;
        }

        return count;
    }
        
*/