/*
    Find the Number of Copy Arrays
    (https://leetcode.com/contest/biweekly-contest-151/problems/find-the-number-of-copy-arrays/description/)

    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int ans = 0;
        int n = original.size();

        int low = bounds[0][0];
        int high = bounds[0][1];
        

        for(int i = 1; i < original.size(); i++){

            int diff = original[i] - original[i-1];

            low = max(bounds[i][0], low + diff);
            high = min(bounds[i][1], high + diff);

            if(low > high){
                return 0;
            }
            
        }

        return high - low + 1;
    }
*/

/*

    1010. Pairs of Songs With Total Durations Divisible by 60
    (https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/)

    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> timeMap;
        int count = 0;

        for(auto t: time){

            t = t % 60;

            if(t == 0){
                count += timeMap[t];
            }else{
                count += timeMap[60 - t];
            }
            timeMap[t] += 1;
        }

        return count;
    }
        
*/

/*
    1186. Maximum Subarray Sum with One Deletion
    (https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)

    int maximumSum(vector<int>& arr) {
        
        int maxOneDeletion = -100000;
        int maxNoDeletion = arr[0];
        int maxSum = arr[0];

        for(int i = 1; i < arr.size(); i++){
            maxOneDeletion = max(maxOneDeletion + arr[i], maxNoDeletion);
            maxNoDeletion = max(maxNoDeletion + arr[i], arr[i]);

            maxSum = max({maxSum, maxOneDeletion, maxNoDeletion});
        }

        return maxSum;
    }
        
*/