/*
    1046. Last Stone Weight
    (https://leetcode.com/problems/last-stone-weight/)

    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()> 1){
            sort(stones.rbegin(), stones.rend());
            
            int wt1 = stones[0];
            int wt2 = stones[1];

            stones.erase(stones.begin() + 0);
            stones.erase(stones.begin() + 0);

            if(wt2 > wt1){
                stones.push_back(wt2 - wt1);
            }else if(wt1 > wt2){
                stones.push_back(wt1 - wt2);
            }

        }

        if(stones.size() == 0){
            return 0;
        }

        return stones[0];
    }

*/