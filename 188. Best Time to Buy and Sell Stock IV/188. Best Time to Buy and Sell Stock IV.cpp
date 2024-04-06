class Solution {
public:
    int maxProfit(int numTransactions, vector<int>& stockPrices) {

        int numDays = stockPrices.size();
        if (numDays == 0) {
            return 0;
        }

        // Create 2D dp array with numTransactions + 1 rows + 2 columns
        // dp[transactions][holding] represents the maximum profit that can be made
        // after 'transactions' transactions and whether we are 'holding' a stock (1) or not (0)
        int dp[numTransactions + 1][2];

        // Init dp array to zeros
        memset(dp, 0, sizeof(dp));

        // For each possiblle number of transactions set an initial state indicating
        // we bought one stock at the first day's price
        for (int j = 1; j <= numTransactions; ++j) {
            dp[j][1] = -stockPrices[0];
        }

        // Iterate throught all days of stock prices
        for (int j = 1; j < numDays; ++j) {
            // Iterate throught all transactions in revers oreder
            for (int i = numTransactions; i > 0; --i) {

                // Update dp array for the 2 states:
                // 1. Not holding a stock after selling on the ith day
                dp[i][0] = max(dp[i][1] + stockPrices[j], dp[i][0]);

                // 2. Holding a stock after buying on the ith day
                dp[i][1] = max(dp[i - 1][0] - stockPrices[j], dp[i][1]);
            }
        }
        return dp[numTransactions][0];
    }
};