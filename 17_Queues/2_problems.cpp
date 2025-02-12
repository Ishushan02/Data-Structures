
/*

    134. Gas Station (VVII Question)
    (https://leetcode.com/problems/gas-station/description/)


    // Method 1 - NOT TLE but Time taken is very very High
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int balance = 0;
        int deficiet = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){

            balance = balance + gas[i] - cost[i];

            if(balance < 0){

                deficiet += abs(balance);
                start = i + 1;
                balance = 0;
            }
        }

        if(balance - deficiet >= 0){
            return start;
        }

        return -1;
    }


    // Method 2 -- great TLE 100%

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int balance = 0;
        int deficiet = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){

            if(balance + gas[i] < cost[i]){
                // deficiet case can't go further
                deficiet += balance + gas[i] - cost[i];
                start = i + 1;
                balance = 0;
            }else{
                // balance case
                balance = balance + gas[i] - cost[i];
            }
            
        }

        if(balance + deficiet >= 0 ){
            return start;
        }

        return -1;
    }

*/


/*
    // the important thing to remember here is the method vector[i].isInteger() --> bool output

    341. Flatten Nested List Iterator
    (https://leetcode.com/problems/flatten-nested-list-iterator/)

    class NestedIterator {
public:
    int ansidx = 0;
    int traverseidx = 0;
    vector<int> ans;
    bool intVal = false;

    void getElemt(vector<NestedInteger> &nestedList, vector<int>& ans){
        if(nestedList.size() == 0){
            return;
        }

        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                ans.push_back(nestedList[i].getInteger());
            }else{
                vector<NestedInteger> newlist = nestedList[i].getList();
                getElemt(newlist, ans);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        getElemt(nestedList, ans);
        
    }
    
    // cout << nestedList[0] << endl;
    
    int next() {
        int val =  ans[ansidx];
        ansidx++;
        return val;
    }
    
    bool hasNext() {
        if(ansidx < ans.size()){
            return true;
        }
        
        return false;
    }
};
*/


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
    

    // Method 2 
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

*/