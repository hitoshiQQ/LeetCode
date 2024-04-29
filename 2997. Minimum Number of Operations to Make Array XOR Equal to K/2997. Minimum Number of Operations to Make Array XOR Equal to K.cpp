class Solution {
public:
    // Func to find the min number of operations to convert a vector of integers 
    // that the XOR of all elements is equal to a given integer K
    // each operation can flip a bit in an integer of the vector
    int minOperations(vector<int>& nums, int k) {

        int xorRes = k;

        // Calculate the XOR of all elements in nums with K
        for (int num : nums) {
            xorRes ^= num;
        }

        // __builtin_popcount - return the number of set bits (1-bits)
        // in an integer
        // Which represents the number of different bits from the desired XOR res
        return __builtin_popcount(xorRes);
    }
};