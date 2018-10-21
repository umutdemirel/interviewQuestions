//
//  BestTimeToBuyAndSellStock.h
//  
//
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//

#ifndef BestTimeToBuyAndSellStock_h
#define BestTimeToBuyAndSellStock_h

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int currentMin = INT_MAX;
        int currentMinIndex = 0;
        int currentMaxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currentMin) {
                currentMin = prices[i];
                currentMinIndex = i;
            }
            if (i > currentMinIndex) {
                if (prices[i] - currentMin > currentMaxProfit) {
                    currentMaxProfit = prices[i] - currentMin;
                }
            }
        }
        
        return currentMaxProfit;
    }
};

#endif /* BestTimeToBuyAndSellStock_h */
