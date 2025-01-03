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