class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<bool>> dp(m + 1, vector(n + 1, false));

        //base case - empty string
        dp[m][n] = true;


        for (int j = m; j >= 0; --j) {

            for (int i = n - 1; i >= 0; --i) {

                bool first_match = (j < m) && (p[i] == '.' || p[i] == s[j]);

                if (i + 1 < n && p[i + 1] == '*') {

                    dp[j][i] = (first_match && dp[j + 1][i]) || dp[j][i + 2];
                }
                else {
                    dp[j][i] = first_match && dp[j + 1][i + 1];
                }
            }
        }
        //whole string of s && whole string of p
        return dp[0][0];
    }
};