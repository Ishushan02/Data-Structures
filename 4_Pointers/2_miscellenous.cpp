/*
    633. Sum of Square Numbers
    (https://leetcode.com/problems/sum-of-square-numbers/description/)

    bool judgeSquareSum(int c) {
        
        long long int start = 0;
        long long int end = sqrt(c);

        while(start <= end){
            long long int val = start*start + end * end;
            if( val == c){
                return true;
            }else if(val > c){
                end--;
            }else{
                start++;
            }
        }

        return false;
    }
        
*/