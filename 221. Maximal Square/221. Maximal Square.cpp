class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        // Get the number of rows (m) and columns(n) in the matrix
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        // Create a 2D DP table with an extra row and col set to zero
        vector<vector<int>> dp(numRows + 1, vector<int>(numCols + 1, 0));

        // Init the max square size found to zero
        int maxSize = 0;

        // Iterate through the matrixm starting from the top-left corner
        for (int j = 0; j < numRows; ++j) {
            for (int i = 0; i < numCols; ++i) {
                // If the current element is '1', calculate the size of the square
                if (matrix[j][i] == '1') {
                    //  The size of the square ending at (j, i) is the min of the three neighboring squares plus 1
                    dp[j + 1][i + 1] = min(min(dp[j][i + 1], dp[j + 1][i]), dp[j][i]) + 1;

                    // Update the max size found so far
                    maxSize = max(maxSize, dp[j + 1][i + 1]);
                }
            }
        }
        // Ret the area of the largest square found
        return maxSize * maxSize;
    }
};