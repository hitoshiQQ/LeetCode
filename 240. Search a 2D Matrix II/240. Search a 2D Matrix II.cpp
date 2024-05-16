class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows / columns
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Start from the bottom-left corner of the matrix
        int current_row = rows - 1;
        int current_col = 0;

        // While the positions is within the bounds of the matrix
        while (current_row >= 0 && current_col < cols) {
            // If the current element is the target, ret true
            if (matrix[current_row][current_col] == target) {
                return true;
            }

            // If the current element is larger than the target, move up one row
            if (matrix[current_row][current_col] > target) {
                --current_row;

            }
            else {
                // If the current element is smaller than the target, move right one col
                ++current_col;
            }
        }
        return false;
    }
};