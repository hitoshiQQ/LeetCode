class Solution {
public:
    int minimumLength(string s) {
        int j = 0;
        int i = s.length() - 1;

        while (j < i && s[j] == s[i]) {

            const char c = s[j];

            while (j <= i && s[j] == c) {
                ++j;

                while (j <= i && s[i] == c) {
                    --i;
                }
            }
        }
        return i - j + 1;
    }
};