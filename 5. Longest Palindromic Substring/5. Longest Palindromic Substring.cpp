class Solution {
public:
    string expand(const string& s, int left, int right) {
        const size_t _size = s.length();
        while (left >= 0 && right < _size && s[left] == s[right]) {
            left--, right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        const size_t _size = s.length();
        if (_size == 0) {
            return "";
        }
        string res = s.substr(0, 1), temp;
        for (int j = 0; j < _size - 1; ++j) {
            temp = expand(s, j, j);
            if (temp.length() > res.length()) {
                res = temp;
            }
            temp = expand(s, j, j + 1);
            if (temp.length() > res.length()) {
                res = temp;
            }
        }
        return res;
    }
};