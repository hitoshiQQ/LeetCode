class Solution {
public:
    // Variables
    int digits[12];
    int memo[12][12];

    // Methods
    // method calculates the number of digit '1's that appear when counting from 1 to the given number N
    int countDigitOne(int n) {
        // Init the length to store the number of digits in N
        int length = 0;

        // Store the digits of N in reveerse order
        while (n) {
            // Store the last digit of N
            digits[++length] = n % 10;

            // Remove the last digit from N
            n /= 10;
        }

        // Init the memorization array to -1
        memset(memo, -1, sizeof memo);

        // Start dfs from the most significant digit
        return dfs(length, 0, true);
    }

    // Method uses dfs to count the number of occurrences of the digit '1'
    int dfs(int pos, int count, bool limit) {
        // BASE CASE: If all positions are traversed
        if (pos <= 0) {
            return count;
        }

        // If we aren't at the limit and we have a memorized result
        if (!limit && memo[pos][count] != -1) {
            return memo[pos][count];
        }

        // Init the result for the current recursion level
        int res = 0;

        // Detremine the upper bound for the current digit
        int upperBound = limit ? digits[pos] : 9;

        // Enumerate possibilities for the current digit
        for (int j = 0; j <= upperBound; ++j) {
            // calc the count of '1' for the next position, updating count if the current digit is '1'
            res += dfs(pos - 1, count + (j == 1), limit && j == upperBound);
        }

        // If not at the limit, memorize the result
        if (!limit) {
            memo[pos][count] = res;
        }
        return res;
    }
};