/*
    347. Top K Frequent Elements
    (https://leetcode.com/problems/top-k-frequent-elements/description/)


    class Info{
        public: 
        int key;
        int val;

        Info(int a, int b){
            key = a;
            val = b;
        }
    };

    class Solution {
    public:

        struct comp{
            bool operator()(Info* a, Info* b){
                return a->val < b->val;
            }
        };

        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> ans;
            unordered_map<int, int> mapVal;
            for(int i = 0; i<nums.size(); i++){
                mapVal[nums[i]]++;
            }

            priority_queue<Info*, vector<Info*>, comp> que;
            
            for(auto data:mapVal){
                Info* temp = new Info(data.first, data.second);
                que.push(temp);
            }

            while(k){
                Info* top = que.top();
                que.pop();
                ans.push_back(top->key);
                k--;
            }
            

            return ans;
        }
    };


    Method 2 - Easiest Method
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> sortOrder;
        unordered_map<int, int> freuency;

        for(int i = 0; i < nums.size(); i++){
            freuency[nums[i]]++;
        }

    
        int count = 0;
        vector<int> ans;

        for(auto &[key, val]: freuency){
            sortOrder.push({val, key});
        }

        while(count < k && !(sortOrder.empty())){
            pair<int, int> val = sortOrder.top();
            sortOrder.pop();
            ans.push_back(val.second);
            count++;
        }

        return ans;

    }
*/

/*
    1753. Maximum Score From Removing Stones
    (https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

    int maximumScore(int a, int b, int c) {
        priority_queue<int> que;

        que.push(a);
        que.push(b);
        que.push(c);

        int ans = 0;

        while(true && que.size() > 1){
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            a = a - 1;
            b = b - 1;
            ans += 1;
            if(a != 0){
                que.push(a);
            }
            if(b != 0){
                que.push(b);
            }
            
        }

        return ans;
    }
*/


/*
    355. Design Twitter
    (https://leetcode.com/problems/design-twitter/description/)
*/

/*
    621. Task Scheduler
    (https://leetcode.com/problems/task-scheduler/description/)
*/

/*
    Merge two binary Max heaps
    (https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/0)

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < a.size() && j < b.size()){
            if(a[i] > b[j]){
                ans.push_back(a[i]);
                i++;
            }else if(b[j] > a[i]){
                ans.push_back(b[j]);
                j++;
            }else{
                ans.push_back(a[i]);
                ans.push_back(b[j]);
                i++;
                j++;
            }
        }
        
        while(i < a.size()){
            ans.push_back(a[i]);
            i++;
        }
        
        while(j < b.size()){
            ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
*/


/*
    973. K Closest Points to Origin
    (https://leetcode.com/problems/k-closest-points-to-origin/description/)

    class Info{
        public:
        vector<int> point;
        double dist;

        Info(vector<int> &a, double b){
            point = a;
            dist = b;
        }
    };

    class Solution {
    public:

        struct cmp{
            bool operator()(Info* a, Info* b){
                return a->dist > b->dist;
            }
        };
        
        double getDistance(vector<int> &each_point){
            int x = each_point[0];
            int y = each_point[1];

            return sqrt(pow(x, 2) + pow(y, 2));
        }

        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            
            vector<vector<int>> ans;
            priority_queue<Info*, vector<Info*>, cmp> minHeap;

            for (int i = 0; i<points.size(); i++ ){
                
                vector<int> each_point = points[i];
                double dist = getDistance(each_point);
                Info* temp = new Info(each_point, dist);
                minHeap.push(temp);
            }


            while(k){
                Info* top = minHeap.top();
                minHeap.pop();
                ans.push_back(top->point);
                k--;
            }

            return ans;
        }
    };
*/

/*
    
    1878. Get Biggest Three Rhombus Sums in a Grid
    (https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

    bool checkBoundary(int m, int n, int i, int j, int a, int b, int c, int d, int e, int f){
        if(i < 0 || i >= m || j < 0 || j >= n || a < 0 || a >= m || b < 0 || b >= n || c < 0 || c >= m || d < 0 || d >= n || e < 0 || e >= m || f < 0 || f >= n ){
            return false;
        }
        return true;
    }

    void getSum(int &m, int &n, int &currX, int &currY, set<int> &s1, vector<vector<int>>& grid, int unit){

        int upX = currX - unit;
        int upY = currY;
        int leftX = currX;
        int leftY = currY - unit;
        int downX = currX + unit;
        int downY = currY;
        int rightX = currX;
        int rightY = currY + unit;
        int sum = 0;
        if(checkBoundary(m, n, upX, upY, leftX, leftY, downX, downY, rightX, rightY)){
            // cout << currX << " , " << currY << endl;
            int tempX = upX;
            int tempY = upY;
            // all points from up to left
            while(tempX < leftX && tempY > leftY ){
                // cout << grid[tempX][tempY] << " ";
                sum = sum + grid[tempX][tempY];
                tempX = tempX + 1;
                tempY = tempY - 1;
            }
            // cout << endl;


            // all points from left to bottom
            tempX = leftX;
            tempY = leftY;
            while(tempX < downX && tempY < downY ){
                // cout << endl << grid[tempX][tempY] << " ";
                sum = sum + grid[tempX][tempY];
                tempX = tempX + 1;
                tempY = tempY + 1;
            }
            // cout << endl;


            // all points from bottom to right
            tempX = downX;
            tempY = downY;
            while(tempX > rightX && tempY < rightY ){
                // cout<< endl << grid[tempX][tempY] << " ";
                sum = sum + grid[tempX][tempY];
                tempX = tempX - 1;
                tempY = tempY + 1;
            }
            // cout << endl;


            // all points from right to top
            tempX = rightX;
            tempY = rightY;
            while(tempX > upX && tempY > upY ){
                // cout << endl << grid[tempX][tempY] << " ";
                sum = sum + grid[tempX][tempY];
                tempX = tempX - 1;
                tempY = tempY - 1;
            }
            // cout << endl;


            // cout << currX << " , " << currY << " : "<< sum << endl;
            s1.insert(sum);
            getSum(m, n, currX, currY, s1, grid, unit + 1);

        }else{
            return ;
        }


    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<int> maxHeap;
        set<int> s1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                s1.insert(grid[i][j]);
                getSum(m, n, i, j, s1, grid, 1);
            }
        }

        int i = 0;

        for (auto i : s1){
            maxHeap.push(i);
        }


        while(!maxHeap.empty() && i < 3){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
            i++;
        }


        return ans;
        
    }

*/


/*
    2163. Minimum Difference in Sums After Removal of Elements (VVV Good Question)
    (https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/)

    long long minimumDifference(vector<int>& nums) {
        // Mehod 1. get n, and get all subsequence, and find min (TLE)

        long long ans = LONG_MAX;
        int n = nums.size()/3;
        priority_queue<long long> maxHeap;
        priority_queue<long long, vector<long long >, greater<long long >> minHeap;
        int size = nums.size();
        vector<long long> minSum(nums.size(), -1);
        vector<long long> maxSum(nums.size(), -1);

        long long sum = 0;
        for(int i = 0; i< size; i++){
            sum = sum + nums[i];
            if(i + 1 >= n){ // more than n elements
                int size = maxHeap.size();
                if(size < n){
                    maxHeap.push(nums[i]);
                }else{ // equal or greater
                    int top = maxHeap.top();
                    if(top > nums[i]){
                        sum = sum - top;
                        maxHeap.pop();
                        maxHeap.push(nums[i]);
                    }else{
                        sum = sum - nums[i];
                    }
                    
                }
                minSum[i] = sum;
                // minSum[i] = sum;
            }else{
                maxHeap.push(nums[i]);
            }
        }

        sum = 0;
        for(int i = size-1; i >= 0; i--){
            sum = sum + nums[i];
            if(size - i >= n){ // more than n elements
                int size = minHeap.size();
                if(size < n){
                    minHeap.push(nums[i]);
                }else{ // equal or greater
                    int top = minHeap.top();
                    if(top < nums[i]){
                        sum = sum - top;
                        minHeap.pop();
                        minHeap.push(nums[i]);
                    }else{
                        sum = sum - nums[i];
                    }
                    
                }
                maxSum[i] = sum;
                // minSum[i] = sum;
            }else{
                minHeap.push(nums[i]);
            }
        }

        // getMin Difference
        int i = 0; 
        int j = i + 1;

        while(i < size && j < size){
            if(minSum[i] != -1 && maxSum[j] != -1){
                ans = min(ans, minSum[i] - maxSum[j]);
            }

            i = i + 1;
            j = j + 1;
        }

        return ans;
    }
*/

/*

    871. Minimum Number of Refueling Stops
    (https://leetcode.com/problems/minimum-number-of-refueling-stops/description/)

*/