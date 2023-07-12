class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int max_len = 0;

        //  go through the line in ascending order of indices
        for (int j = 0; j < n; ++j) {
            if (s[j] == '(') {
                ++left;
            }
            else {
                ++right;
            }


            if (right == left) {
                // close equal to open
                max_len = max(max_len, 2 * left);

            }
            else if (right > left) {
                // close more than open
                left = right = 0;
            }
        }

        //go through the line in reverse order
        left = right = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] == '(') {
                ++left;
            }
            else {
                ++right;
            }

            if (left == right) {
                // close equal to open
                max_len = max(max_len, 2 * left);

            }
            else if (left > right) {
                // close more than open
                left = right = 0;
            }
        }
        return max_len;
    }
};