class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int N = s.size();
        for (int j = 0; j < N; ++j) {
            if (s[j] != s[N - 1 - j]) {
                return false;
            }
        }
        return true;
    }
};
