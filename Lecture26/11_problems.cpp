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


/*
    123. Best Time to Buy and Sell Stock III
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

    // if total transaction is 2 hence total buy and sell would be 4 so I added that condition
    int getMaxProfit(vector<int>& prices, int i, int buy, int count, vector<vector<vector<int>>> &dpArr){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArr[i][buy][count] != -1){
            return dpArr[i][buy][count];
        }
        int profit = 0;
        if(buy && count < 4){

            int buyProfit = getMaxProfit(prices, i+1, 0, count+1, dpArr) - prices[i];
            int keepProfit = getMaxProfit(prices, i+1, 1, count, dpArr);
            profit = max(buyProfit, keepProfit);

        }else if(buy == 0 && count < 4){

            int sellProfit = getMaxProfit(prices, i+1, 1, count+1, dpArr) + prices[i];
            int keepProfit = getMaxProfit(prices, i+1, 0, count, dpArr);
            profit = max(sellProfit, keepProfit);

        }
        dpArr[i][buy][count] = profit;

        return dpArr[i][buy][count];
    }

    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dpArr(prices.size()+1, vector<vector<int>>(3, vector<int>(5, -1)));
        return getMaxProfit(prices, 0, true, 0, dpArr);
    }

*/


/*

    // only difference between top and current question is that here
    // the buy and sell operation will take place 2 * k times(K Transactions)

    188. Best Time to Buy and Sell Stock IV
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

    int getMaxProfit(vector<int>& prices, int k, int i, int buy, int count, vector<vector<vector<int>>> &dpArr){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArr[i][buy][count] != -1){
            return dpArr[i][buy][count];
        }
        int profit = 0;
        if(buy && count < k){

            int buyProfit = getMaxProfit(prices, k, i+1, 0, count+1, dpArr) - prices[i];
            int keepProfit = getMaxProfit(prices, k, i+1, 1, count, dpArr);
            profit = max(buyProfit, keepProfit);

        }else if(buy == 0 && count < k){

            int sellProfit = getMaxProfit(prices, k, i+1, 1, count+1, dpArr) + prices[i];
            int keepProfit = getMaxProfit(prices, k, i+1, 0, count, dpArr);
            profit = max(sellProfit, keepProfit);

        }
        dpArr[i][buy][count] = profit;

        return dpArr[i][buy][count];
    }

    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<vector<int>>> dpArr(prices.size()+1, vector<vector<int>>(3, vector<int>((2 * k)+1, -1)));
        return getMaxProfit(prices, 2 * k, 0, true, 0, dpArr);
    }

*/

/*
    714. Best Time to Buy and Sell Stock with Transaction Fee (714. Best Time to Buy and Sell Stock V)
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

    int getMaxProfit(vector<int>& prices, int fee, int i, int buy, vector<vector<int>> &dpArr){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArr[i][buy] != -1){
            return dpArr[i][buy];
        }
        int profit = 0;
        if(buy){
            int buyProfit = getMaxProfit(prices, fee, i+1, 0, dpArr) - prices[i] - fee;
            int stayProfit = getMaxProfit(prices, fee, i+1, 1, dpArr);
            profit = max(buyProfit, stayProfit);
        }else{
            int sellProfit = getMaxProfit(prices, fee, i+1, 1, dpArr) + prices[i];
            int stayProfit = getMaxProfit(prices, fee, i+1, 0, dpArr);
            profit = max(sellProfit, stayProfit);
        }

        dpArr[i][buy] = profit;
        return dpArr[i][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dpArr(prices.size(), vector<int>(3, -1));
        return getMaxProfit(prices, fee, 0, true, dpArr);
    }

*/

/*
    309. Best Time to Buy and Sell Stock with Cooldown
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

    int getMaxProfit(vector<int>& prices, int i, int buy, vector<vector<int>> &dpArr){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArr[i][buy] != -1){
            return dpArr[i][buy];
        }
        int profit = 0;
        if(buy){
            int buyProfit = getMaxProfit(prices, i+1, 0, dpArr) - prices[i];
            int stayProfit = getMaxProfit(prices, i+1, 1, dpArr);
            profit = max(buyProfit, stayProfit);
        }else{// only diff after selling add 1 extra days for buying as of cooldown day
            int sellProfit = getMaxProfit(prices, i+2, 1, dpArr) + prices[i];
            int stayProfit = getMaxProfit(prices, i+1, 0, dpArr);
            profit = max(sellProfit, stayProfit);
        }

        dpArr[i][buy] = profit;
        return dpArr[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dpArr(prices.size(), vector<int>(3, -1));
        return getMaxProfit(prices, 0, true, dpArr);
    }

    
*/