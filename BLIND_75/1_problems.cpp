/*
    BLIND 75
    The Notebook Questions
    (https://leetcode.com/problem-list/oizxjoit/)
*/

/*
    Problem 1
    128. Longest Consecutive Sequence
    (https://leetcode.com/problems/longest-consecutive-sequence/description/)

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        map<int, bool> mapVal;
        for(auto v:nums){
            mapVal[v] = true;
        }

        int maxConsecutive = 0;
        int valCount = 0;
        long long int prev = -100000000000;
        for(auto &[key, val]: mapVal){
            if(prev == 100000000000){
                valCount = 1;
                maxConsecutive = max(maxConsecutive, valCount);
            }else if(prev + 1 == key){
                valCount += 1;
                maxConsecutive = max(maxConsecutive, valCount);
            }else{
                valCount = 0;
            }
            prev = key;
        }

        return maxConsecutive+1;
    }
*/

/*
    Problem 2
    1. Two Sum
    (https://leetcode.com/problems/two-sum/description/)

    struct valueSort{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> valuePair;
        for(int i = 0; i < nums.size(); i++){
            valuePair.push_back({nums[i], i});
        }

        sort(valuePair.begin(), valuePair.end(), valueSort());

        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){  
            pair<int, int> num1 = valuePair[i];
            pair<int, int> num2 = valuePair[j];
            int sumVal = num1.first + num2.first;

            if(sumVal == target){
                return {num1.second, num2.second};
            }

            if(sumVal > target){
                j--;
            }else{
                i++;
            }

        }

        return {0, 1};

    }

*/

/*
    Problem 3
    3. Longest Substring Without Repeating Characters
    (https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

    int lengthOfLongestSubstring(string s) {
        int uniqueMax = 0;
        int i = 0;
        unordered_map<char, bool> charCount;
        while(i < s.length()){
            int curridx = i;
            int j = i;
            int count = 0;
            while(j < s.length() && !(charCount[s[j]])){
                charCount[s[j]] = true;
                count++;
                j++;
            }
            charCount.clear();
            uniqueMax = max(uniqueMax, count);
            i = curridx + 1;
        }        

        return uniqueMax;
    }
        
*/