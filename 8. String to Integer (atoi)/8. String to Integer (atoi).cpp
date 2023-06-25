class Solution {
public:
    int myAtoi(string_view s) {
        int j = 0;
        while (j < (int)s.size() && s[j] == ' ') {
            j++;
        }

        // negative num's
        if (j < (int)s.size() && s[j] == '-') {
            j++;
            int f = 0;
            while (j < (int)s.size() && '0' <= s[j] && s[j] <= '9') {
                int d = s[j] - '0';
                j++;
                if (f > INT_MIN / 10 || (f == INT_MIN / 10 && d <= -(INT_MIN % 10))) {
                    f = f * 10 - d;
                }
                else {
                    return INT_MIN;
                }
            }
            return f;
        }
        else {
            // positive num's 
            if (j < (int)s.size() && s[j] == '+') {
                j++;
            }
            int f = 0;

            while (j < (int)s.size() && '0' <= s[j] && s[j] <= '9') {
                int d = s[j] - '0';
                j++;
                if (f < INT_MAX / 10 || f == INT_MAX / 10 && d <= INT_MAX % 10) {
                    f = f * 10 + d;
                }
                else {
                    return INT_MAX;
                }
            }
            return f;
        }
    }
};