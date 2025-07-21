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