class Solution {
public:
    int hammingWeight(int n) {

        // Init a counter for the 'one' bits
        int count = 0;

        // Continue until all bits are traversed
        while (n) {

            // Clear the least significant 'one' bit
            n &= n - 1;
            ++count;
        }
        return count;
    }
};