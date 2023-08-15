class Solution {
public:
    int minDistance(string word1, string word2) {

        // function for finding the Levenshtein distance between strings 'X' and 'Y'
        // 'm' and 'n' are the total number of characters in 'X' and 'Y' respectively
        const int m = word1.length();
        const int n = word2.length();


        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        //  we can convert the original prefixes to an empty string by removing all characters
        for (int j = 1; j <= m; ++j) {
            dp[j][0] = j;
        }

        // we can get target prefixes from an empty source prefix by inserting each character
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }

        //  fill the interpolation table from bottom to top
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (word1[j - 1] == word2[i - 1]) {
                    dp[j][i] = dp[j - 1][i - 1];
                }
                else {
                    dp[j][i] = min({ dp[j - 1][i - 1], dp[j - 1][i], dp[j][i - 1] }) + 1;
                }
            }
        }
        return dp[m][n];
    }
};