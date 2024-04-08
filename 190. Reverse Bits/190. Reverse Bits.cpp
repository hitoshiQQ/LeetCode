class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        // Init the result to represent the reversed number
        uint32_t reversedNumber = 0;

        // Loop through all 32 bites of the input number
        for (int bitPos = 0; bitPos < 32; ++bitPos) {

            // Isolate the least-sinification bit of 'n' and shift it to the correct pos in 'reversedNumber'
            reversedNumber |= (n & 1) << (31 - bitPos);

            // Shift input number right by one bit ti process the next bit in the next iteration
            n >>= 1;
        }
        return reversedNumber;
    }
};