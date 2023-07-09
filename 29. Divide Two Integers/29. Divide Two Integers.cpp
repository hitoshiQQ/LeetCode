class Solution {
public:
    int divide(int a, int b) {
        int res = 0;
        int sign = a > 0 == b > 0 ? 1 : -1;
        if (b == INT_MIN) {
            return a == b;
        }
        if (a == INT_MIN) {
            if (b == 1) {
                return INT_MIN;
            }
            else if (b == -1) {
                return INT_MIN;
            }
            else {
                a += abs(b);
                ++res;
            }
        }
        a = abs(a);
        b = abs(b);

        for (int j = 0; a >= b; j = 0) {
            while (a >> j >= b) {
                j++;
            }
            a -= b << j - 1;
            res += 1 << j - 1;
        }
        return sign < 0 ? -res : res;
    }
};