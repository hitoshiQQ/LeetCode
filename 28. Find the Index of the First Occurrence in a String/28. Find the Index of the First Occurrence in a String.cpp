class Solution {
public:
    int strStr(string haystack, string needle) {
        const int h = haystack.length();
        const int n = needle.length();

        for (int j = 0; j < h - n + 1; ++j) {
            if (haystack.substr(j, n) == needle) {
                return j;
            }
        }
        return -1;
    }
};