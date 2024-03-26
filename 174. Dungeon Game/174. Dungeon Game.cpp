class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        // Init number of rows / number of columns / create DP table of size (m+1)x(n+1)
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m + 1][n + 1];

        // Init the dp array with a very large value
        memset(dp, 0x3f, sizeof dp);

        // Set the health needed at the dungeons exit
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        // loop throught the dungeon starting from the bottom right corner
        for (int j = m - 1; j >= 0; --j) {
            for (int i = n - 1; i >= 0; --i) {

                dp[j][i] = max(1, min(dp[j + 1][i], dp[j][i + 1]) - dungeon[j][i]);
            }
        }
        return dp[0][0];
    }
};