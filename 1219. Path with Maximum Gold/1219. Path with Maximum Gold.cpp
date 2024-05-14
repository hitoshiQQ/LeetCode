class Solution {
private:
    // Helpler DFS func to explore the grid for gold collection
    int dfs(int x, int y, vector<vector<int>>& grid) {
        // Boundary check and cell with zero gold check
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }

        // Store the gold in the current cell
        int gold = grid[x][y];
        // Mark the current cell as visited by setting it to zero
        grid[x][y] = 0;

        // Store the max gold
        int maxGoldFromHere = 0;

        // Explore all four adjacent cells
        for (int j = 0; j < 4; ++j) {
            // Recursively collect the gold by going in one direction
            int nextGold = dfs(x + directions[j], y + directions[j + 1], grid);

            //Update the max gold collected from the current path
            maxGoldFromHere = max(maxGoldFromHere, gold + nextGold);
        }

        // Reset the cell to its original gold value
        grid[x][y] = gold;

        return maxGoldFromHere;
    }

public:
    // Directions array representing the 4 possible movements
    vector<int> directions = { -1, 0, 1, 0, -1 };

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;

        // Iterate over each cell in the grid
        for (int j = 0; j < grid.size(); ++j) {
            for (int i = 0; i < grid[0].size(); ++i) {
                // Compute the max gold recursively starting from the current cell
                maxGold = max(maxGold, dfs(j, i, grid));
            }
        }
        return maxGold;
    }
};