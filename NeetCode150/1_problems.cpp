/*
    std::map::lower_bound() is a built-in method used to find the first element 
    in the map whose key is either equal to or greater than the given key. 
    In this article, we will learn about std::map::lower_bound() function in C++.


    981. Time Based Key-Value Store {I didn't know lower_bound function, remember it.. focus on it}
    (https://leetcode.com/problems/time-based-key-value-store/)

    class TimeMap {
public:
    map< int, unordered_map<string, string>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        unordered_map<string, string> valuePair;
        valuePair[key] = value;
        timeMap[timestamp] = valuePair;
        
    }
    
    string get(string key, int timestamp) {

        if(timeMap.find(timestamp) != timeMap.end()){
            unordered_map<string, string> valuePair = timeMap[timestamp];
            if(valuePair.find(key) != valuePair.end()){
                return valuePair[key];
            }
            
        }else{
            int tempt = timestamp;
            auto it = timeMap.lower_bound(tempt); 
            while (it != timeMap.begin()) {  
                --it;
                auto& valuePair = it->second;
                auto keyIt = valuePair.find(key);
                if (keyIt != valuePair.end()) {
                    return keyIt->second;
                }
            }
        }

        return "";
    }
};

*/


/*
    543. Diameter of Binary Tree
    (https://leetcode.com/problems/diameter-of-binary-tree/description/)

    int diam(TreeNode* root, int &diameter){
        if(root == NULL){
            return 0;
        }

        int lh = diam(root->left, diameter);
        int rh = diam(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int x = diam(root, diameter);

        return diameter;
    }

*/


/*  
    Encode and Decode Strings
    (https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1)

    class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string ans;
        
        for(auto val:s){
            ans += val;
            ans += " ";
        }
        return ans;
    }

    vector<string> decode(string& s) {
        // code here
        vector<string> ans;
        string prefix = "";
        for(auto val:s){
            if(val == ' '){
                ans.push_back(prefix);
                prefix = "";
            }else{
                prefix += val;
            }
        }
        return ans;
    }
};

*/

/*
    90. Subsets II
    (https://leetcode.com/problems/subsets-ii/)

    void getSubset(vector<int>& nums, int index, vector<int> tempAns, vector<vector<int>> &res ){
        if(index >= nums.size()){
            if(find(res.begin(), res.end(), tempAns) == res.end()){
                res.push_back(tempAns);
            }
            return ;
        }

        tempAns.push_back(nums[index]);
        getSubset(nums, index + 1, tempAns, res);
        tempAns.pop_back();

        getSubset(nums, index + 1, tempAns, res);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tempAns;
        getSubset(nums, 0, tempAns, res);

        return res;
    }
*/


/*
    46. Permutations
    (https://leetcode.com/problems/permutations/)

    void permutation(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            permutation(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums, ans, 0);

        return ans;
    }


*/

/*
    1448. Count Good Nodes in Binary Tree
    (https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)

    void getMax(TreeNode* root, int currMax, int &count){
        if(root == NULL){
            return;
        }

        cout << root->val << " , " << currMax << " , " << count << endl;
        if(root->val >= currMax){
            count += 1;
            currMax = root->val;
        }

        getMax(root->left, currMax, count);
        getMax(root->right, currMax, count);

    }

    int goodNodes(TreeNode* root) {

        if(root == NULL){
            return 0;
        }
        int count = 0;
        getMax(root, root->val, count);

        return count;
    }

*/

/*
    66. Plus One
    (https://leetcode.com/problems/plus-one/description/)

    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        for(int i = n - 1; i >=0; i--){
            int sum = carry + digits[i];
            carry = sum/10;
            digits[i] = sum % 10;
        }

        if(carry != 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }

*/

/*  
    50. Pow(x, n)
    (https://leetcode.com/problems/powx-n/description/)

    double powFn(double x, long long int n){
        
        double ans = 1;
        while(n > 0){

            if (n & 1) {// odd
                ans = ans * x ;
            }

            x = x * x ;
            n = n >> 1; // b/2
        }
        return ans;

    }

    double myPow(double x, long long int n) {
        double ans = 0;
        if(n < 0){
            ans = powFn(x, abs(n));
            ans = 1 / ans;
        }else{
            ans = powFn(x, n);
        }
        
        return ans;
    }

*/

/*
    191. Number of 1 Bits
    (https://leetcode.com/problems/number-of-1-bits/description/)

    int hammingWeight(int n) {
        
        int count = 0;

        while(n){

            if(n & 1){
                count = count + 1;
            }
            n = n >> 1;
        }

        return count;
    }
    
*/

/*
    338. Counting Bits
    (https://leetcode.com/problems/counting-bits/)

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<= n; i++){
            int count = 0;
            int temp = i;
            while(temp){
                if(temp & 1){
                    count += 1;
                }
                temp = temp >> 1;
            }
            ans.push_back(count);
        }

        return ans;
    }
    
*/

/*
    217. Contains Duplicate
    (https://leetcode.com/problems/contains-duplicate/description/)

    unordered_map<int, int> valMap;

        for(auto val:nums){
            valMap[val]++;

            if(valMap[val]>1){
                return true;
            }
        }
    
        return false;
        
*/