class Solution {
public:
    string customSortString(string order, string s) {

        string res;
        vector<int> count(128);

        for (const char c : s) {
            ++count[c];
        }

        for (const char c : order) {
            while (count[c]-- > 0) {
                res += c;
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            while (count[c]-- > 0) {
                res += c;
            }
        }
        return res;
    }
};