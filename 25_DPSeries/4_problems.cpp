/*

    STOCK DP's

*/

/*
    121. Best Time to Buy and Sell Stock
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int maxPrice = 0;
        for(auto v:prices){

            if(st.empty()){
                st.push(v);
            }else{

                if(v >= st.top()){
                    int price = v - st.top();
                    maxPrice = max(maxPrice, price);
                }else{
                    st.push(v);
                }
            }
        }
        return maxPrice;
    }
        
*/

/*

    122. Best Time to Buy and Sell Stock II
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                sum += (prices[i] - prices[i-1]);
            }
        }

        return sum;
    }

    MEthod 2 which is BAD
    void getMaxProfit(vector<int> &prices, int profit, int prev, int idx, int &maxProfit){
        
        maxProfit = max(maxProfit, profit);
        for(int i = idx; i < prices.size(); i++){
            if(i > prev && prices[i] > prices[prev]){
                getMaxProfit(prices, profit + (prices[i] - prices[prev]), i, i+1, maxProfit);
            }
            prev = i;
        }
    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        getMaxProfit(prices, 0, 0, 1, maxProfit);

        return maxProfit;
    }

    Method 3
    int maxiMumBuy(vector<int> &prices, int i, bool buy, vector<vector<int>> dpArray){
        if(i >= prices.size()){
            return 0;
        }

        if(dpArray[i][buy] != -1){
            return dpArray[i][buy];
        }
        int profit = 0;
        if(buy){
            int includebuy = maxiMumBuy(prices, i+1, 0, dpArray) - prices[i];
            int excludebuy = maxiMumBuy(prices, i+1, 1, dpArray);
            profit = max(includebuy, excludebuy);
        }else{
            int includesell = prices[i] + maxiMumBuy(prices, i+1, 1, dpArray);
            int excludesell = maxiMumBuy(prices, i+1, 0, dpArray);
            profit = max(includesell, excludesell);
        }
        dpArray[i][buy] = profit;
        return dpArray[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dpArray(prices.size()+1, vector<int>(2, -1));
        return maxiMumBuy(prices, 0, 1, dpArray);
    }

    Method 4
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dpArray(prices.size()+1, vector<int>(2, 0));
        // return maxiMumBuy(prices, 0, 1, dpArray);

        for(int i = prices.size()-1; i >= 0; i--){
            int profit = 0;
            for(int j = 1; j>= 0; j--){
                if(j == 1){
                    int includebuy = dpArray[i+1][0] - prices[i];
                    int excludebuy = dpArray[i+1][1];
                    profit = max(includebuy, excludebuy);
                }else{
                    int includesell = prices[i] + dpArray[i+1][1];
                    int excludesell = dpArray[i+1][0];
                    profit = max(includesell, excludesell);
                }
                dpArray[i][j] = profit;
            }
        }

        return dpArray[0][1];
    }
        
*/

/*

    123. Best Time to Buy and Sell Stock III
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                for(int transaction = 1; transaction <= 2; transaction++){
                    if(j){
                        curr[j][transaction] = max(next[0][transaction] - prices[i], next[1][transaction]);
                    }else{
                        curr[j][transaction] = max(prices[i] + next[1][transaction-1], next[0][transaction]);
                    }
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
*/

/*
    188. Best Time to Buy and Sell Stock IV
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                for(int transaction = 1; transaction <= k; transaction++){
                    if(j){
                        curr[j][transaction] = max(next[0][transaction] - prices[i], next[1][transaction]);
                    }else{
                        curr[j][transaction] = max(prices[i] + next[1][transaction-1], next[0][transaction]);
                    }
                }
            }
            next = curr;
        }
        return curr[1][k];
    }

*/


/*
    309. Best Time to Buy and Sell Stock with Cooldown
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

    int maxProfit(vector<int>& prices) {
        

        // return getMaxProfit(prices, 1, 0);
        int n = prices.size();
        vector<vector<int>> dpArray(n+2, vector<int>(2, 0));

        for(int i = n -1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                if(j==1){
                    dpArray[i][j] = max(dpArray[i+1][0] - prices[i], dpArray[i+1][1]);
                }else{
                    dpArray[i][j] = max(dpArray[i+2][1] + prices[i], dpArray[i+1][0]);
                }
            }
        }
        return dpArray[0][1];

   
    }
*/

/*
    714. Best Time to Buy and Sell Stock with Transaction Fee
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dpArray(n + 1, vector<int>(2, 0));
        // return getMaxProfit(prices, fee, 1, 0, dpArray);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j>= 0; j--){
                if(j == 1){
                    dpArray[i][j] = max(dpArray[i+1][0] - prices[i], dpArray[i+1][1]);
                }else{
                    dpArray[i][j] = max(dpArray[i+1][1] + prices[i] - fee, dpArray[i+1][0]);
                }
            }
        }

        return dpArray[0][1];
    }
*/

/*
    (VVVV Important --- ; Good Tweak)
    3573. Best Time to Buy and Sell Stock V
    (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/)

    long long int getMaxProfit(vector<int>& prices, int k, int buy, int count, int i, vector<vector<vector<long long int>>> &dpArray){
        if(i > prices.size() || count >= k){
            return 0;
        }

        if(i == prices.size()-1){
            if(buy == 1){
                return prices[i];
            }else if(buy == 2){
                return -prices[i];
            }
            return 0;
        }

        if(dpArray[i][count][buy] != -1){
            return dpArray[i][count][buy];
        }

        long long int profit = 0;
        if(buy == 0){
            long long int buyProfit = getMaxProfit(prices, k, 1, count, i+ 1, dpArray) - prices[i];
            long long int ssProfit = getMaxProfit(prices, k, 2, count, i+ 1, dpArray) + prices[i];
            long long int buyskip = getMaxProfit(prices, k, 0, count, i+ 1, dpArray);
            profit = max({buyProfit, buyskip, ssProfit});
        }else if(buy == 1){
            long long int sell = getMaxProfit(prices, k, 0, count + 1, i+ 1, dpArray) + prices[i];
            long long int sellskip = getMaxProfit(prices, k, 1, count, i+ 1, dpArray);
            profit = max({sell, sellskip});
        }else if(buy == 2){
            long long int shortsell = getMaxProfit(prices, k, 0, count + 1, i+ 1, dpArray) - prices[i];
            long long int sellskip = getMaxProfit(prices, k, 2, count, i+ 1, dpArray);
            profit = max({shortsell, sellskip});
        }

        dpArray[i][count][buy] = profit;
        return profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long int>>> dpArray(n+1, vector<vector<long long int>>(k+1, vector<long long int>(3, -1)));
        return getMaxProfit(prices, k, 0, 0, 0, dpArray);
    }

*/