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

    Method 1 (focus on just method, this might be of use the methodology, for solution refer down)
    int getMaxProfit(vector<int>& prices, int i, int buy){
        if(i >= prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){
                            // sell - price
            int buyProfit = getMaxProfit(prices, i+1, 0) - prices[i];
            int skipbuy = getMaxProfit(prices, i+1, 1); // don't buy or sell anything
            profit = max(buyProfit, skipbuy);
        }else{

                          // price + buy 
            int sellProfit = prices[i] + getMaxProfit(prices, i+1, 1);
            int skipsell = getMaxProfit(prices, i+1, 0); // don't buy or sell anything
            profit = max(sellProfit, skipsell);
        }

        return profit;
    }

    int getMaxProfitDP(vector<int>& prices, int i, int buy, vector<vector<int>> &dpArr){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArr[i][buy] != -1){
            return dpArr[i][buy];
        }
        int profit = 0;
        if(buy){
                            // sell - price
            int buyProfit = getMaxProfitDP(prices, i+1, 0, dpArr) - prices[i];
            int skipbuy = getMaxProfitDP(prices, i+1, 1, dpArr); // don't buy or sell anything
            profit = max(buyProfit, skipbuy);
        }else{

                          // price + buy 
            int sellProfit = prices[i] + getMaxProfitDP(prices, i+1, 1, dpArr);
            int skipsell = getMaxProfitDP(prices, i+1, 0, dpArr); // don't buy or sell anything
            profit = max(sellProfit, skipsell);
        }
        dpArr[i][buy] = profit;
        return dpArr[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        
        // return getMaxProfit(prices, 0, true);
        vector<vector<int>> dpArr(prices.size() + 1, vector<int>(3, -1));
        return getMaxProfitDP(prices, 0, true, dpArr);

    }


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