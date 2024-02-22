/*
    Two identical numbers in a sequence can be eliminated without changing the result
    When a number occurs twice, we use modulo two addition for each bit
*/
class Solution {
public:
    static const int EQ_COUNT = 2;

    int singleNumber(const vector<int>& nums) {

        const int INT_BIT_SIZE = sizeof(int) * 8;
        size_t countOne[INT_BIT_SIZE] = {};

        for (unsigned int x : nums) {
            for (int bit = 0; bit < INT_BIT_SIZE; bit++) {
                countOne[bit] += x & 1;
                x >>= 1;
            }
        }
        unsigned int res = 0;
        for (int bit = 0; bit < INT_BIT_SIZE; bit++) {
            res |= (unsigned int)(countOne[bit] % EQ_COUNT) << bit;
        }
        return res;
    }
};