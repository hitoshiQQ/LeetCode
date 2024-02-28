class Solution {
public:
    unordered_map<string, vector<string>> dp;

    vector<string> wordBreakHelper(string s, vector<string>& wordDict) {
        // default case
        if (s.length() == 0) {
            return { "" };
        }

        if (dp.count(s)) {
            return dp[s];
        }

        // recursive case
        vector<string> firstResult, finalResult;
        for (auto word : wordDict) {
            int wordLen = word.length();
            if (s.substr(0, wordLen) == word) {
                firstResult = wordBreakHelper(s.substr(wordLen), wordDict);

                for (auto y : firstResult) {
                    string space = y.length() ? " " : "";
                    finalResult.push_back(word + space + y);
                }
            }
        }
        return dp[s] = finalResult;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res = wordBreakHelper(s, wordDict);
        return res;
    }
};