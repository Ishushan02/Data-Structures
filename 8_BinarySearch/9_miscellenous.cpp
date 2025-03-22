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

/*
    1346. Check If N and Its Double Exist
    (https://leetcode.com/problems/check-if-n-and-its-double-exist/description/)

    bool binarySearch(vector<int>& nums, int key, int start, int end){

        int mid = (start + end)/2;

        while(start <= end){
            if(nums[mid] == key){
                return true;
            }else if(key > nums[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return false;
    }

    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for(int i = 0; i < arr.size(); i++){
            int elem = arr[i];

            if(binarySearch(arr, 2 * elem, i + 1, n - 1) || binarySearch(arr, 2 * elem, 0, i - 1)){
                return true;
            }
        }
        return false;

    }

*/

/*
    1351. Count Negative Numbers in a Sorted Matrix
    (https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

    int binarySearch(vector<int>& nums){
        
        int start = 0;
        int end = nums.size()-1;
        int mid = (start + end)/2;
        int ans = -1;
        while(start <= end){
            if(nums[mid] < 0){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }

            mid = (start + end)/2;
        }

        return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            int n = grid[0].size();
            int id = binarySearch(grid[i]);
            if(id != -1){
                ans += (n - id);
            }
        }

        return ans;
    }
        
*/

/*
    1608. Special Array With X Elements Greater Than or Equal X
    (https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/)

    int getTotalGreaterCount(vector<int> &nums, int key, int n){
        
        int start = 0;
        int end = n -1;
        int mid = (start + end)/2;

        int ans = n;

        while(start <= end){
            if(key <= nums[mid]){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        return n - ans;
    }

    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums[n-1];
        int mid = (start + end)/2;

        while(start <= end){
            int greaterCount = getTotalGreaterCount(nums, start, n);
            if(greaterCount == start){
                return start;
            }

            start += 1;
        }

        return -1;
    }

*/

/*  
    2389. Longest Subsequence With Limited Sum
    (https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/)

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 0; i < queries.size(); i++){

            int maxelem = queries[i];
            int count = 0;
            int sum = 0;

            for(int j = 0; j < nums.size(); j++){
                if(sum + nums[j] <= maxelem){
                    count += 1;
                    sum += nums[j];
                }else{
                    break;
                }
            }
            ans.push_back(count);
        }


        if(ans.size() == 0){
            ans.push_back(0);
            return ans;
        }

        return ans;
    }

*/

/*
    2540. Minimum Common Value
    (https://leetcode.com/problems/minimum-common-value/)

    bool binarySearch(vector<int> &nums, int key){
        
        int start = 0;
        int end = nums.size() -1;
        int mid = (start + end)/2;

        while(start <= end){
            if(key == nums[mid]){
                return true;
            }else if(key < nums[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        return false;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0; i < nums1.size(); i++){
            if(binarySearch(nums2, nums1[i])){
                return nums1[i];
            }
        }

        return -1;

    }
        
*/

/*
    2970. Count the Number of Incremovable Subarrays I
    (https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/)

    bool isIncreasing(int n, vector<int>& nums, int i, int j){
        
        int prev = 0;
        if(i >= 1){
            prev = nums[0];
        }
        for(int k = 1; k <= i - 1; k++){
            if(prev >= nums[k]){
                return false;
            }
            prev = nums[k];
        }

        for(int k = j + 1; k < n; k++){
            if(prev >= nums[k]){
                return false;
            }
            prev = nums[k];
        }

        // cout << " Ispossible " << endl;
        return true;

    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                // cout << nums[i] << " , " << nums[j] << endl;
                if(isIncreasing(n, nums, i, j)){
                    ans += 1;
                }
            }
        }

        return ans;
    }

*/

/*
    81. Search in Rotated Sorted Array II
    (https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

    int getPivotIdx(vector<int>& nums){
        int n = nums.size();
        int start = 0; 
        int end = n-1;
        int mid = (start + end)/2;

        while(start <= end){
            // cout << "STart: "<< start << " Mid: " << mid << " End: "<< end << endl;
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
                return mid;
            }else if(mid + 1 < n && nums[mid] > nums[mid+1]){
                return mid + 1;
            }else if(nums[mid] == nums[start] && nums[mid] == nums[end]){
                // important
                start++;
                end--;
            }else if(nums[mid] > nums[0]){
                start = mid + 1;
            }else if(nums[mid] < nums[0]){
                end = mid - 1;
            }else if(nums[mid] == nums[0]){
                start = mid + 1;
            }else if(nums[mid] == nums[end]){
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return start;
    }

    bool binarySearch(vector<int>&nums, int start, int end, int key){
        int mid = (start + end)/2;

        while(start <= end){
            if(nums[mid] == key){
                return true;
            }else if(key > nums[mid]){
                start = mid +1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target){
                return true;
            }
            return false;
        }

        

        int pivot = getPivotIdx(nums);
        cout << pivot << endl;

        if(pivot - 1 >= 0 && binarySearch(nums, 0, pivot-1, target)){
            return true;
        }else if(binarySearch(nums, pivot, n-1, target)){
            return true;
        }
        return false;
    }
*/

/*
    153. Find Minimum in Rotated Sorted Array
    (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

    int getPivot(vector<int> &nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;
        int ans = 0;

        while(start <= end){
            if(mid - 1 >= 0 && nums[mid-1] > nums[mid]){
                return mid;
            }else if(mid + 1 < n && nums[mid + 1] < nums[mid]){
                return mid + 1;
            }else if(nums[mid] > nums[0]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }

        // cout << start << endl;
        if(start >= n){
            return 0;
        }
        return start;
    }

    int findMin(vector<int>& nums) {
        cout << getPivot(nums) << endl;
        int idx = getPivot(nums);
        return nums[idx];
    }

*/

/*
    274. H-Index
    (https://leetcode.com/problems/h-index/description/)

    int totalCites(vector<int>& citations, int numCite){
        
        int count = 0;
        for(auto v:citations){
            if(v - numCite >= 0){
                count++;
            }
        }

        return count;
    }

    int hIndex(vector<int>& citations) {
        
        int maxCite = 0;
        for(auto v:citations){
            maxCite = max(maxCite, v);
        }

        int start = 0;
        int end = maxCite;
        int mid = (start + end)/2;
        int ans = 0;

        while(start <= end){
            int val = totalCites(citations, mid);

            if(val >= mid){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid =  (start + end)/2;
        }

        return ans;
    }
*/

/*
    275. H-Index II
    (https://leetcode.com/problems/h-index-ii/)

    int totalCites(vector<int>& citations, int numCite){
        
        int ans = 0;
        int n = citations.size();
        int start = 0;
        int end = n - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(citations[mid] >= numCite){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        

        return n - ans;
    }

    int hIndex(vector<int>& citations) {
        
        int maxCite = 0;
        for(auto v:citations){
            maxCite = max(maxCite, v);
        }

        int start = 0;
        int end = maxCite;
        int mid = (start + end)/2;
        int ans = 0;

        while(start <= end){
            int val = totalCites(citations, mid);

            if(val >= mid){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid =  (start + end)/2;
        }

        return ans;
    }
        
*/