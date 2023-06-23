class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int res = INT_MAX;

        for (int j = 0; j < strs.size() - 1; ++j) {
            res = min(res, (int)min(strs[j].size(), strs[j + 1].size()));
            while (strs[j].substr(0, res) != strs[j + 1].substr(0, res)) {
                res--;
            }

            if (res == 0) {
                return "";
            }
        }
        return strs[0].substr(0, res);
    }
};