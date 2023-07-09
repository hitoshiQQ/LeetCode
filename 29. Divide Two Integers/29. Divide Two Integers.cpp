class Solution {
public:
    int divide(int a, int b) {
        int sign = 1;
        if (a < 0 ^ b < 0) {
            sign = -1;
        }

        auto x = abs(static_cast<long long>(a));
        auto y = abs(static_cast<long long>(b));
        auto t = 0ll;
        while (x >= y) {
            int c = 0;
            while (x >= (y << (c + 1))) {
                ++c;
            }
            t += 1ll << c;
            x -= y << c;
        }

        auto res = sign * t;
        if (res >= INT32_MIN && res <= INT32_MAX) {
            return static_cast<int>(res);
        }
        return INT32_MAX;
    }
};