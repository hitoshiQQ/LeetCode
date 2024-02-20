class Solution {
public:
    int minCut(string s) {

        const int n = s.length();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        vector<int> dp(n, n);

        for (int q = 2; q <= n; ++q) {
            for (int j = 0, i = q - 1; i < n; ++j, ++i) {
                isPalindrome[j][i] = s[j] == s[i] && isPalindrome[j + 1][i - 1];
            }
        }

        for (int j = 0; j < n; ++j) {
            if (isPalindrome[0][j]) {
                dp[j] = 0;
                continue;
            }

            for (int i = 0; i < j; ++i) {
                if (isPalindrome[i + 1][j]) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp.back();
    }
};