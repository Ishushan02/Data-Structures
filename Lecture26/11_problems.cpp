/*
    121. Best Time to Buy and Sell Stock
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

    int maxProfit(vector<int>& prices) {
        

        if(prices.size() == 1){
            return 0;
        }

        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }

*/


/*
    122. Best Time to Buy and Sell Stock II
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)




    Method 2. Best Method
    int maxProfit(vector<int>& prices) {
        
        int profit  = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] >= prices[i - 1]){
                profit += prices[i] - prices[i -1];
            }
        }

        return profit;
    }


*/