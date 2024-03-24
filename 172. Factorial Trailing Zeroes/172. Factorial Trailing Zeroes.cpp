class Solution {
public:
    int trailingZeroes(int n) {

        // Negative number edge case
        if (n < 0) {
            return -1;
        }

        // init result
        int res = 0;

        // Keep dividing N by powers of 5 & update result
        for (int j = 5; n / j >= 1; j *= 5) {
            res += n / j;
        }

        return res;
    }
};