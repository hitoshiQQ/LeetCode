class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.length();
        const int max_length = getMaxLength(wordDict);
        const unordered_set<string> word_set {wordDict.begin(), wordDict.end()};

        vector<int> dp(n + 1);
        dp[0] = true;

        for (int j = 1; j <= n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                if (j - i > max_length) {
                    break;
                }
                // can be segmented
                if (dp[i] && word_set.count(s.substr(i, j - i))) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

private:
    int getMaxLength(const vector<string>& wordDict) {
        return ranges::max_element(wordDict, [](const string& a, const string& b) {
            return a.length() < b.length();
            })->length();
    }
};