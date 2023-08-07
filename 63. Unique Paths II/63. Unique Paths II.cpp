/*
Each cell in oG (oG[i][j]) can potentially reached by only two previously-visited cells (oG[j-1][i] & oG[j][i-1]), so the number of ways to reach the current cell (dp[j][i]) should be the sum of the ways to reach those other two cells (dp[j-1][i] + dp[j][i-1]), should they exist.

Since any cell representing an obstacle cannot be a part of a path, its value in dp should be 0. We'll also need to seed the initial starting position with a value of 1 to represent the single initial path. Once we're done building dp, the value of the bottom-right cell should be our answer.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        if (oG[0][0] == 1) {
            return 0;
        }

        int m = oG.size(), n = oG[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                if (oG[j][i] == 1 || (j == 0 && i == 0)) {
                    continue;
                }
                else dp[j][i] = (j > 0 ? dp[j - 1][i] : 0) + (i > 0 ? dp[j][i - 1] : 0);
        return dp[m - 1][n - 1];
    }
};