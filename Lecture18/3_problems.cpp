#include <iostream>
#include <vector>

using namespace std;

/*

THE VERY IMPORTANT THING IS TO REMOVE THE DUPLICACY PLEASE FOCUS ON THAT IN THIS .CPP NOTEBOOK

{Try using Sorting to remove Duplicacy}

*/

/*

53. Maximum Subarray
(https://leetcode.com/problems/maximum-subarray/description/)

- We can do this using Kadane's Algorithm, but doing it using Divide and Conquer

    int divide(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }

        int maxLeftBordersum = INT_MIN;
        int maxRightBordersum = INT_MIN;
        int mid = (start + end)/2;

        int leftSum = divide(nums, start, mid);
        int rightSum = divide(nums, mid+1, end);

        int leftBorderSum = 0;
        int rightBorderSum = 0;

        for(int i = mid; i >= start; i--){
            leftBorderSum += nums[i];
            maxLeftBordersum = max(maxLeftBordersum, leftBorderSum);
        }

        for(int i = mid+1; i <= end; i++){
            rightBorderSum += nums[i];
            maxRightBordersum = max(maxRightBordersum, rightBorderSum);
        }

        int crossBordersum = maxLeftBordersum + maxRightBordersum;
        return max(leftSum, max(crossBordersum, rightSum));
    }

    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }

*/


/*


39. Combination Sum
(https://leetcode.com/problems/combination-sum/description/)

- The catch here is the index which helps in removing the Duplicacy of the array.

    void recurssion(vector<int>& candidates, int target, vector<int> ans, vector<vector<int>>& res, int index){
        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i = index; i < candidates.size(); i++){

            if (target >= candidates[i]){
                ans.push_back(candidates[i]);
                recurssion(candidates, target - candidates[i], ans, res, i);
                ans.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<vector<int>> result;
        vector<int> ans;

        recurssion(candidates, target, ans, res, 0);
        
        // val.insert(res);

        return res;
    }

*/

/*

40. Combination Sum II
(https://leetcode.com/problems/combination-sum-ii/description/)


    Method 1 (Memory Limit Exceeded due to Set usage)

    void recurrsion(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res, int index){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if (target < 0){
            return;
        }
        if(index >= candidates.size()){
            return;
        }
        
        for(int i = index; i< candidates.size(); i++){
            ans.push_back(candidates[i]);
            recurrsion(candidates, target - candidates[i], ans, res, i+1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> ans;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        recurrsion(candidates, target, ans, res, 0);

        // for duplicacy
        set<vector<int>> unq;

        for(auto val:res){
            unq.insert(val);
        }

        res.clear();

        for(auto val:unq){
            res.push_back(val);
        }

        return res;
    }


    Method 2

    void recurrsion(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res, int index){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if (target < 0){
            return;
        }
        if(index >= candidates.size()){
            return;
        }
        
        for(int i = index; i< candidates.size(); i++){

            // not picking those elements in which prev iteration is already taken
            // because we already have solution from prev element if it is same, 
            // if we don't do it we will get repetetive Solution for same candidate
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            
            ans.push_back(candidates[i]);
            recurrsion(candidates, target - candidates[i], ans, res, i+1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> ans;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        recurrsion(candidates, target, ans, res, 0);


        return res;
    }

*/

/*

47. Permutations II
(https://leetcode.com/problems/permutations-ii/description/)


    void traverse(vector<int>& nums, int index, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        

        for(int i = index; i<nums.size();i++){
            if(visited.find(nums[i])!= visited.end()){
                continue; // so the same number is already been swapped with itself earlier
                          // hence I am not swapping it again. 
            }

            visited[nums[i]] = true;
            swap(nums[i], nums[index]);
            traverse(nums, index+1, res);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        traverse(nums, 0, res);

        return res;
    }

    // We can do the unique thing even using Set, but it will again take high time and space.

    Method 2.(Solution 1 is better)

    void allPerm(vector<int>& nums, vector<vector<int>> &sol, int index){

        if(index >= nums.size()){
            if(find(sol.begin(), sol.end(), nums) == sol.end()){
                sol.push_back(nums);
            }
            return ;
        }

        for(int i = index; i < nums.size(); i++){

            swap(nums[i], nums[index]);
            allPerm(nums, sol, index + 1);
            swap(nums[i], nums[index]);

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        allPerm(nums, sol, 0);

        return sol;
    }

*/

/*

526. Beautiful Arrangement
(https://leetcode.com/problems/beautiful-arrangement/)

    Method 1 - TLE

    void allPerm(vector<int>& arr, int& count, int n, int index){
        if(index == arr.size()){
            bool check = true;
            for(int i = 1; i<=n; i++){
                if((arr[i] % i == 0) || (i % arr[i] == 0)){
                    check = true;
                }else{
                    check = false;
                    break;
                }
            }
            if(check) count+=1;

            return;
        }

        for(int i = index; i <= n; i++){
            swap(arr[i], arr[index]);
            allPerm(arr, count, n, index + 1);
            swap(arr[i], arr[index]);
        }
    }


    int countArrangement(int n) {
        vector<int> arr;
        arr.push_back(99);
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        
        int count = 0;
        allPerm(arr, count, n, 1);

        
        return count;
    }


    Method - 2 
               {1, 2, 3}
              /     |   \
             /      |    \
             1      1    1
        /      |     \
       2(*)     2      2(*)
            /   |    \  
           /    |      \
          3(*)   3(*)   3 

    void traverse(vector<int>& arr, int n, int currentNum, int& count){
        if(currentNum >= n+1){
            count += 1;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(arr[i] == 99 && (currentNum % i == 0 || i % currentNum == 0)){
                arr[i] = currentNum;
                traverse(arr, n, currentNum+1, count);
                arr[i] = 99;
            }
        }

    }

    int countArrangement(int n) {
        vector<int> arr(n+1, 99);
        int count = 0;
        traverse(arr, n, 1, count);
        return count;
    }

*/

/*

(VVI Question, Interview Question)
1655. Distribute Repeating Integers
(https://leetcode.com/problems/distribute-repeating-integers/description/)

    bool distribute( vector<int>& quantity, vector<int>& data, int index){
        if(index == quantity.size()){
            return true;
        }

        for(int i = 0; i < data.size();i++){
            if(data[i] >= quantity[index]){
                data[i] = data[i] - quantity[index];
                if(distribute(quantity, data, index+1)){
                    return true;
                }
                data[i] = data[i] + quantity[index];
            }
        }

        return false;

    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        
        unordered_map <int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<int> data;
        for (auto i : freq){
            data.push_back(i.second);
        }

        sort(quantity.rbegin(), quantity.rend()); // now we can get false conditions quickly 
                                                  // decrease in Time 
        return distribute(quantity, data, 0);
    }
*/

/*

78. Subsets
(https://leetcode.com/problems/subsets/description/)

    void traverse(vector<int>& nums, vector<int>& ans, vector<vector<int>> & res, int index){
        if(index == nums.size()){
            res.push_back(ans);
            return;
        }
        
        ans.push_back(nums[index]);
        traverse(nums, ans, res, index+1);
        ans.pop_back();

        traverse(nums, ans, res, index+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        traverse(nums, ans, res, 0);

        return res;
    }
*/

/*

90. Subsets II
(https://leetcode.com/problems/subsets-ii/description/)

    void traverse(vector<int>& nums, vector<int>& ans, vector<vector<int>> & res, int index){
        if(index == nums.size()){
            if(find(res.begin(), res.end(), ans)== res.end()){
                res.push_back(ans);
            }
            return;
        }
        
        ans.push_back(nums[index]);
        traverse(nums, ans, res, index+1);
        ans.pop_back();

        traverse(nums, ans, res, index+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        traverse(nums, ans, res, 0);

        return res;
    }

    Method 2 Important Method

    void traverse(vector<int>& nums, vector<int>& ans, vector<vector<int>> & res, int index){
        res.push_back(ans);        
        
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            ans.push_back(nums[i]);
            traverse(nums, ans, res, i+1);
            ans.pop_back();
        }
        

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        traverse(nums, ans, res, 0);

        return res;
    }


*/