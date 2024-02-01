class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0) {
            return 0;
        }

        int res = 0;

        int start = prices[0], end = prices[0];

        for (int j = 0; j < prices.size(); j++) {
            if (prices[j] < start) {

                //restart as session
                res = max(res, end - start);
                start = prices[j];
                end = prices[j];
            }
            else {
                //continue current session
                end = max(end, prices[j]);
            }
        }
        res = max(res, end - start);
        return res;
    }

};