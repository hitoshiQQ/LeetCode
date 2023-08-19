class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128);
        int required = t.length();
        int left = -1;
        int min_length = s.length() + 1;

        for (const char c : t) {
            ++count[c];
        }


        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (--count[s[r]] >= 0) {
                --required;
            }
            while (required == 0) {
                if (r - l + 1 < min_length) {
                    left = l;
                    min_length = r - l + 1;
                }
                if (++count[s[l++]] > 0) {
                    ++required;
                }

            }
        }
        return left == -1 ? "" : s.substr(left, min_length);
    }
};