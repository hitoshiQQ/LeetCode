class Solution {
public:
    long long wonderfulSubstrings(string word) {

        // Array to count the number of times each bit mask appers
        // Init with 1 at index 0 to handle the empty substring scenraio
        int count[1024] = { 1 };
        // Total count of wonderful substrings
        long long totalSubstrings = 0;
        // Currents state of bit mask representing character frequency parity
        int state = 0;

        // Iterate over each character in the string
        for (char ch : word) {
            // Update the state: Flip the bit corresponding to the current character
            state ^= 1 << (ch - 'a');

            // Add the count of the current state to the total substrings count
            totalSubstrings += count[state];

            // Check for states that differ by exactly one bit from the current state
            for (int j = 0; j < 10; ++j) {
                totalSubstrings += count[state ^ (1 << j)];
            }

            // Increment the count for the current state
            ++count[state];
        }
        // Ret the total count of wonderful substrings
        return totalSubstrings;
    }
};