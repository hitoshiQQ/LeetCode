class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // Get the size of the input grid
        int size = grid.size();

        // Init the result grid with dimensions(size - 2) x (size - 2) to accommodate the 3x3 window reduction
        vector<vector<int>> res(size - 2, vector<int>(size - 2));

        // Loop through each cell where a 3x3 grid can start
        for (int row = 0; row < size - 2; ++row) {
            for (int col = 0; col < size - 2; ++col) {
                // Iterate rhtough each cell within the current 3x3 window
                for (int local_row = row; local_row <= row + 2; ++local_row) {
                    for (int local_col = col; local_col <= col + 2; ++local_col) {
                        // Update the corresponding cell in the result grid with the max value seen so far in the 3x3 window
                        res[row][col] = max(res[row][col], grid[local_row][local_col]);
                    }
                }
            }
        }
        return res;
    }
};