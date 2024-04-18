class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        // Number of rows in the grid
        int rowCount = grid.size();

        // Number of columns in the grid
        int columnCount = grid[0].size();

        // Init the perimeter result to 0
        int perimeter = 0;

        // Iterate over each cell in the grid
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {

                // Check if the current cell is part of an island
                if (grid[row][col] == 1) {

                    // Each island cell contributes 4 to the perimeter
                    perimeter += 4;

                    // If the cell below the current one is also part of the island
                    // reduce the perimeter by 2
                    if (row < rowCount - 1 && grid[row + 1][col] == 1) {
                        perimeter -= 2;
                    }

                    // If the cell to the right of the current one is also part of the island
                    // reduce the perimeter by 2 for the same reason
                    if (col < columnCount - 1 && grid[row][col + 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
    }
};