class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                if (j > 0 && i > 0)
                    grid[j][i] += min(grid[j - 1][i], grid[j][i - 1]);
                else if (j > 0)
                    grid[j][0] += grid[j - 1][0];
                else if (i > 0)
                    grid[0][i] += grid[0][i - 1];

        return grid[m - 1][n - 1];
    }
};