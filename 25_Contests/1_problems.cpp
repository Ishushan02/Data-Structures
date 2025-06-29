/*

Weekly Contest 400

    3168. Minimum Number of Chairs in a Waiting Room
    int minimumChairs(string s) {

        int requiredChairs = 0;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'E'){
                if(count == 0){
                    requiredChairs += 1;
                    count = 0;
                }else{
                    count -= 1;
                }
            }else{
                count += 1;
            }
        }

        return requiredChairs;
    }


    3169. Count Days Without Meetings
    struct sortFn{
        bool operator()(vector<int>& a, vector<int> &b){
            if(a[0] < b[0]){
                return true;
            }else{
                if(a[0] == b[0]){
                    return a[1] <= b[1];
                }
                return false;
            }
        }
    };
    
    int countDays(int days, vector<vector<int>>& meetings) {
    
        sort(meetings.begin(), meetings.end(), sortFn());
        int freeDays = 0;
        int endTime = meetings[0][1];
        freeDays = 0;
        // cout << freeDays << endl;
        for(int i = 1; i < meetings.size(); i++){
            int initial = meetings[i][0];
            meetings[i][0] = max(meetings[i][0], endTime);
            endTime = max(endTime, meetings[i][1]);
            // cout << meetings[i][0] << " , " << meetings[i][1] << endl;
        }

        int prev = -1;
        for(int i = 0; i < meetings.size(); i++){
            // cout << meetings[i][0] << " , " << meetings[i][1] << endl;
            if(meetings[i][1] >= meetings[i][0] ){
                if(meetings[i][0] > prev){
                    freeDays += (meetings[i][1] - meetings[i][0] + 1);
                }else {
                    freeDays += (meetings[i][1] - meetings[i][0]);
                }
                prev = meetings[i][1];
            }
            
        }
        cout << freeDays << endl;
        return days - freeDays;
    }

*/


/*

    Weekly Contest 401

    3178. Find the Child Who Has the Ball After K Seconds
    (https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

    int placement(int N, int n, int k, char s){
        // cout << n << ", " << k << " , " << s << endl;
        if(n > k){
            if(s == 'l'){
                return (n - k) - 1;
            }
            return k + 1;
        }
        if(s == 'r'){
            return placement(N, N-1, k - n, 'l');
        }
        
        return placement(N, N-1, k - n, 'r');
        
    }
    int numberOfChild(int n, int k) {
        if(k < n){
            return k;
        }
        return placement(n, n, k, 'r');
    }


    3179. Find the N-th Value After K Seconds
    (https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/)

    int valueAfterKSeconds(int n, int k) {
        if(n == 1){
            return 1;
        }

        vector<vector<long long int>> dpArray(k+1, vector<long long int>(n, 0));

        for(int i = 0; i < n; i++){
            dpArray[0][i] = 1;
        }

        for(int i = 0; i < k; i++){
            dpArray[i][0] = 1;
        }

        // ans = n;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j < n; j++){
                dpArray[i][j] = (dpArray[i-1][j] + dpArray[i][j-1]) % 1000000007;
                // ans = dpArray[i][j];
            }
        }


        return (dpArray[k][n-1] + 1)% 1000000007;
    }

    3180. Maximum Total Reward Using Operations I
    int getMaxReward(vector<int> &rewardValues, int reward, int idx, vector<unordered_map<int, int>> &dpArray) {
    if (idx >= rewardValues.size()) {
        return reward;
    }

    if(dpArray[idx].count(reward) > 0){
        return dpArray[idx][reward];
    }

    int includeReward = reward;
    int maxInclude = reward; 

    if (rewardValues[idx] > reward) {
        includeReward += rewardValues[idx];
        int currReward = rewardValues[idx];
        rewardValues[idx] = -1; 
        maxInclude = getMaxReward(rewardValues, includeReward, idx + 1, dpArray);
        rewardValues[idx] = currReward; 
    }

    int maxExclude = getMaxReward(rewardValues, reward, idx + 1, dpArray);

    dpArray[idx][reward] = max(maxInclude, maxExclude);

    return dpArray[idx][reward];
}
    
    
    int maxTotalReward(vector<int>& rewardValues) {

        int maxReward = 0;
        sort(rewardValues.begin(), rewardValues.end());
        vector<unordered_map<int, int>> dpArray(rewardValues.size() + 1);
        return getMaxReward(rewardValues, 0, 0, dpArray);
        // return maxReward;
    }
        
*/

/*

    Weekly Contest 402

    3184. Count Pairs That Form a Complete Day I
    (https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/)

    void getCountDays(vector<int> &hours, int count, long long int day, int &ans, int i){
        if(i >= hours.size()){
            if(count == 2){
                if(day % 24 == 0){
                ans += 1;
                }
            }
            return ;
        }
        if(count > 2){
            return ;
        }

        getCountDays(hours, count+1, day + hours[i], ans, i+1);
        getCountDays(hours, count, day, ans, i+1);
        
    }
    
    int countCompleteDayPairs(vector<int>& hours) {

        int ans = 0;
        getCountDays(hours, 0, 0, ans, 0);
        return ans;
    }


    3185. Count Pairs That Form a Complete Day II
    (https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/)

    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> countMap;
        long long int ans = 0;
        for(auto hour: hours){
            hour = hour % 24;
            if(hour == 0){
                ans += countMap[hour];
            }else{
                ans += countMap[24 - hour];
            }

            countMap[hour] += 1;
        }

        return ans ;
    }

*/

/*

    Weekly Contest 456
    3597. Partition String 
    (https://leetcode.com/problems/partition-string/description/)

    vector<string> partitionString(string s) {

        unordered_map<string, bool> segments;
        vector<string> ansVal;
        string st;
        for(auto c: s){
            // st += c;
            if(segments.find(st) == segments.end()){
                ansVal.push_back(st);
                segments[st] = true;
                st = "";
            }else{
                segments[st] = true;
            }
            st += c;
        }
        if(segments.find(st) == segments.end()){
            ansVal.push_back(st);
            segments[st] = true;
            st = "";
        }
        
        ansVal.erase(ansVal.begin());

        return ansVal;
    }


*/

/*

    Weekly Contest 403

    3194. Minimum Average of Smallest and Largest Elements
    (https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/)

    double minimumAverage(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;

        double minSort = (double)nums[j];
        while(i <= j){
            double avg = ((double)nums[i] + (double)nums[j])/2;
            minSort = min(minSort, avg);
            i++;
            j--;
        }

        return minSort;
    }

    
*/