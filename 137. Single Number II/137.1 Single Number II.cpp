/*
    We can enumerate each binary bit, and for each binary bit,
    we calculate the sum of all numbers on that bit.

    If the sum of the numbers on that bit can be divided by 3,
    then the number that only appears once on that bit is 0,
    otherwise it is 1.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;

        for (int bit = 0; bit < 32; ++bit) {
            int sum = 0;

            for (const int num : nums) {
                sum += num >> bit & 1;

            }

            sum %= 3;
            res |= sum << bit;
        }
        return res;
    }
};