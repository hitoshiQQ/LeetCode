class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> position(128, -1);
        int res = 0;

        for (int j = 0, i = 0; i < n; i++) {
            if (position[s[i]] != -1) {
                j = max(j, position[s[i]] + 1);
            }
            res = max(res, i - j + 1);
            position[s[i]] = i;
        }
        return res;
    }
};