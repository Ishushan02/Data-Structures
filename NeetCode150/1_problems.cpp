/*
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