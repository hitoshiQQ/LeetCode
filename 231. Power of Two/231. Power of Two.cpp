class Solution {
public:
    bool isPowerOfTwo(int number) {
        // Power of 2 has only one bit set in binary representation
        // Substracting one from such a number flips all the bits after the set bit
        // Performing an AND operation between the number and number - 1 would then result in zero
        // Additionally, the number must be positive to be a power of two
        return number > 0 && (number & (number - 1)) == 0;
    }
};