/*
    ALL THIS PROBLEMS I FOUND IT DIFFICULT PLEASE SEE THIS AGAIN ISHAN JI
*/


/*
    1482. Minimum Number of Days to Make m Bouquets
    (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

    bool totFlowers(vector<int>& bloomDay, int m, int k, int days){
        
        int count = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            
            // if currday is less than given day
            if(bloomDay[i] <= days){
                count+= 1;
            }

            // count
            if(count == k){
                m = m - 1;
                count = 0;
                if(m == 0){
                    break; // requirement completed
                }
            }

            // it's not adjacent
            if(bloomDay[i] > days){
                count = 0;
            }
        }

        if(m == 0){
            return true;
        }

        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = INT_MAX;
        int end = INT_MIN;

        for(int i = 0; i < bloomDay.size(); i++){
            start = min(start, bloomDay[i]);
            end = max(end, bloomDay[i]);
        }

        int mid = (start + end)/2;
        int ans = -1;
        while(start <= end){
            if(totFlowers(bloomDay, m, k, mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        return ans;
    }

*/

/*
    658. Find K Closest Elements
    (https://leetcode.com/problems/find-k-closest-elements/description/)

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        int start = 0; 
        int end = arr.size()-1;
        while(end - start >= k){
            int lowdiff = x - arr[start];
            int highdiff = arr[end] - x;
            
            if(lowdiff > highdiff){
                start = start + 1;
            }else{
                end = end - 1;
            }
        }

        for(int i = start; i <= end; i++){
            ans.push_back(arr[i]);
        }

        return ans;
        
    }

    
*/