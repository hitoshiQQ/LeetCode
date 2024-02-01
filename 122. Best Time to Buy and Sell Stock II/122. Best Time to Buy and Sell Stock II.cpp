class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy_day = 0, sell_day = 0;
        int profit = 0;

        for (int j = 1; j < prices.size(); j++) {
            if (prices[j] >= prices[j - 1]) {
                sell_day++;

            }
            else {
                profit += prices[sell_day] - prices[buy_day];
                buy_day = sell_day = j;
            }
        }
        profit += prices[sell_day] - prices[buy_day];
        return profit;
    }
};