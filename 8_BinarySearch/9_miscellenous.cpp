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