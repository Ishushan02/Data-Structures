
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

*/