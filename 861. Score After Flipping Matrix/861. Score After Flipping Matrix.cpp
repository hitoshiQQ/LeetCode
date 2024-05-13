class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        // Num of rows / cols in the matrix
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        // Flip the rows where the first element is zero to maximize the leading digit
        for (int row = 0; row < num_rows; ++row) {
            if (grid[row][0] == 0) {
                for (int col = 0; col < num_cols; ++col) {
                    // XOR with 1 flip 0s to 1s and vice versa
                    grid[row][col] ^= 1;
                }
            }
        }

        // Number of total score
        int total_score = 0;

        // Iterate through columns to maximize the score
        for (int col = 0; col < num_cols; ++col) {
            // Count of 1s  in the current column
            int col_count = 0;

            // Count the number of 1s in the current column
            for (int row = 0; row < num_rows; ++row) {
                col_count += grid[row][col];
            }

            // Determine the value to add to the score for this col, we take the larger number between 'col_coiunt'
            // and 'num_rows - col_count'
            int max_col_value = max(col_count, num_rows - col_count);

            // The value of a set bit in the answer is equal to 2^(num_cols - col - 1)
            total_score += max_col_value * (1 << (num_cols - col - 1));
        }
        return total_score;
    }
};