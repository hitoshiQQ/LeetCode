class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        const int cost_sum = accumulate(cost.begin(), cost.end(), 0);

        if (gas_sum - cost_sum < 0) {
            return -1;
        }

        int res = 0, sum = 0;
        // try to start from inedex's
        for (int j = 0; j < gas.size(); ++j) {
            sum += gas[j] - cost[j];

            if (sum < 0) {
                sum = 0;
                // start from next index
                res = j + 1;
            }
        }
        return res;
    }
};