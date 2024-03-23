class Solution {
public:
    int titleToNumber(string columnTitle) {

        // Init result to zero to store the column number
        int res = 0;

        // Iterate over each character pf the column title
        for (char c : columnTitle) {

            // Convert char to its position in the alphabet and add it to the result
            // 'A' maps to 1, 'B' maps to 2, ... etc.
            // Multiply the current result by 26
            res = res * 26 + (c - 'A' + 1);
        }
        return res;
    }
};