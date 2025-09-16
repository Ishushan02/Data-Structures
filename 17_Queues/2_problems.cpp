

/*

    // See method 2 my Method

    649. Dota2 Senate
    (https://leetcode.com/problems/dota2-senate/)

    string predictPartyVictory(string senate) {
        deque<int> dr;
        deque<int> rd;
        string ans = "Radiant";

        for(int i = 0; i < senate.length(); i++){
            if(senate[i] == 'R'){
                rd.push_back(i);
            }else{
                dr.push_back(i);
            }
        }

        int lastIndex = senate.size();
        while(rd.size() != 0 && dr.size()!= 0){
            int drid = dr.front();
            int rdid = rd.front();
            dr.pop_front();
            rd.pop_front();

            if(drid<rdid){
                dr.push_back(lastIndex);
            }else{
                rd.push_back(lastIndex);
            }

            lastIndex += 1;   
        }


        if(rd.size() == 0){
            return "Dire";
        }

        if(dr.size() == 0){
            return "Radiant";
        }

        return "Dire"; // simply this line
    }
    

    Method 2  (very easy method.. and just focus on the question clearly)
    // Logic is:
    //      keep count of all R and D

    //      loop on i
    
    //      if count of anyone is 0 return the other one

    //      if i == 'R'
    //         --> mark the first coming 'D' and decrease count of D
    //      if i == 'D'
    //         --> mark the first coming 'R' and decrease count of R
    //      else if i == B
    //         --> increase pointer
    
    string predictPartyVictory(string senate) {
        
        unordered_map<char, int> count;

        for(auto v:senate){
            count[v]++;
        }
        int n = senate.length();

        int i = 0;
        while(i >= 0){

            if(count['R'] == 0){
                return "Dire";
            }
            if(count['D'] == 0){
                return "Radiant";
            }

            char curr = senate[i];
            if(senate[i] == 'B'){
                i++;
            }else if(senate[i] == 'D'){
                // D
                // cout <<" here " << endl;
                int j = (i + 1) % n;
                while(j >= 0){
                    if(senate[j] == 'R'){
                        senate[j] = 'B';
                        count['R']--;
                        if(count['R'] == 0){
                            return "Dire";
                        }
                        break;
                    }
                    j += 1;
                    if(j >= n){
                        j = j % n;
                    }
                    
                }
                i++ ;
            }else{
                // R
                int j = (i + 1) % n;
                while(j >= 0){
                    if(senate[j] == 'D'){
                        senate[j] = 'B';
                        count['D']--;
                        if(count['D'] == 0){
                            return "Radiant";
                        }
                        break;
                    }
                    j += 1;
                    if(j >= n){
                        j = j % n;
                    }
                }
                i++ ;
            }

            if(i >= n){
                i = i % n;
            }

            // cout << senate << " i: " << i << endl;

        }

        return "Dire";
    }


*/


/*

Steps by Knight (https://www.geeksforgeeks.org/problems/steps-by-knight5927/1)

It is Very Very IMPORTANT which intakes BFS and Queue IMPLEMENTATION, so complete it. 

int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        queue<pair<int, pair<int, int>>> que;
        
        int steps = 1e9;
        que.push({0, {knightPos[0]-1, knightPos[1]-1}});
        vector<int> visited(n * n + 10, 0);
        while(!que.empty()){
            
            auto [dist, pos] = que.front();
            int i = pos.first;
            int j = pos.second;
            if(i == targetPos[0]-1 && j == targetPos[1]-1){
                // steps = min(steps, dist);
                return dist;
            }
            int idx = i * n + j;
            que.pop();

            int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
            int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

            for(int k = 0; k < 8; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                int idx = x * n + y;
                if(x < n && x >= 0 && y < n && y >= 0 && visited[idx] == 0){
                    visited[idx] = 1;
                    que.push({dist + 1, {x, y}});
                }
                
            }
            
        }
        
        return steps;
        
    }

*/

/*
    Very Good Question, Do it again n again

    Procedure: (Simple thinking, maxSum is totalSum - minSum)
    // Use Kadanes Algorithm
        - get totalSum of the Array
        - get maxSum of the Array
        - get minSum of the Array

    if(maxSum < 0 && totSum < 0) -- >this means that all elements are negative
        - hence return the max(totalSum, maxSum)

    check max(totalSum - minSum, maxSum) --> return ans;


    918. Maximum Sum Circular Subarray
    https://leetcode.com/problems/maximum-sum-circular-subarray/

    int maxSubarraySumCircular(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int minsum = 0;
        int maxsum = 0;

        for(int i = 0; i < n; i++){

            minsum += nums[i];
            maxsum += nums[i];

            maxSum = max(maxSum, maxsum);
            minSum = min(minSum, minsum);

            if(maxsum < 0){
                maxsum = 0;
            }

            if(minsum > 0){
                minsum = 0;
            }
        }

        // cout << "Total Sum: " << totalSum << " MinSum: " << minSum << " MaxSum: " << maxSum << endl;

        if(totalSum < 0 && maxSum < 0){
            return max(totalSum, maxSum);
        }

        int ans = max(totalSum - minSum, maxSum);
        return ans;
    }


*/
