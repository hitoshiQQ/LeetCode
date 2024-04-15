class Solution {
public:
    // @brief Function to count the number of islands in a given grid
    int numIslands(vector<vector<char>>& grid) {

        // Number of rows / columns / islands
        int rowCount = grid.size();
        int columnCount = grid[0].size();
        int islandCount = 0;

        // Directions arrray for moving up, right, down, left
        int directions[5] = { -1, 0, 1, 0, -1 };

        // DFS to traverse the island and mark visited parts
        function<void(int, int)> dfs = [&](int row, int col) {

            // Mark the current cell as visited
            grid[row][col] = '0';

            // Traverse adjacent cells
            for (int j = 0; j < 4; ++j) {

                int newRow = row + directions[j];
                int newCol = col + directions[j + 1];

                // Check if the new pos is within bounds and has a '1'
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 && newCol < columnCount && grid[newRow][newCol] == '1') {
                    dfs(newRow, newCol);
                }
            }
        };

        // Iterate through the entrie grid
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {

                // If the cell contains a '1', it is a new island
                if (grid[row][col] == '1') {
                    dfs(row, col);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};