/*
    374. Guess Number Higher or Lower
    (https://leetcode.com/problems/guess-number-higher-or-lower/description/)

    int guessNumber(int n) {
        
        int start = 1;
        int end = n;
        int mid = start+((end-start)/2);

        while (start <= end){
            int val = guess(mid);

            if (val == -1){
                end = mid-1;
            }else if (val == 1){
                start = mid+1;
            }else{
                return mid;
            }
            mid = start+((end-start)/2);
        }
        return n;
    }

*/