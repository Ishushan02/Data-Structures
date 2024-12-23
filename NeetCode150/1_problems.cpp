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