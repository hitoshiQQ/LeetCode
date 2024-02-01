class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // cash in hand when we have bought 1 || 2 stocks
        //init hold1 && hold2 to INT_MIN
        int hold1 = INT_MIN, hold2 = INT_MIN;

        // cash in hand when we have sold 1 || 2 stocks
        int release1 = 0, release2 = 0;

        for (int price : prices) {
            // their values depend on the value in previous iter,
            // their order is required to be like this

            // release2 is always >= release1
            release2 = max(release2, hold2 + price);

            // hold2 is always >= hold1
            hold2 = max(hold2, release1 - price);

            //release1 is always >= 0
            release1 = max(release1, price + hold1);
            hold1 = max(hold1, -price);
        }

        // release2 is always max(release1, release2)
        return release2;
    }
};