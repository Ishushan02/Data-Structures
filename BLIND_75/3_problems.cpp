/*
    Problem 31
    190. Reverse Bits
    (https://leetcode.com/problems/reverse-bits/)

    uint32_t reverseBits(uint32_t n) {
        
        int s = 0;
        uint32_t ans = 0;
        while(n){
            ans = ans << 1;
            if(n & 1){
                ans += 1;
            }else{
                ans += 0;
            }
            s++;
            n = n >> 1;
        }

        // cout << s << endl;
        for(int i = s; i < 32; i++){
            ans = ans << 1;
        }
        

        return ans;
    }
*/

/*
    Problem 32
    191. Number of 1 Bits
    (https://leetcode.com/problems/number-of-1-bits/)

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