// method of subtraction through a loop with exceptions and bitwise shift
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        }

        double res = 1.0;

        if (n == INT_MIN) {

            //take -1 power away
            res /= x;
            ++n;
            n *= -1;
            x = 1.0 / x;

        }
        else if (n < 0) {
            n *= -1;
            x = 1.0 / x;
        }

        while (n) {
            if (n & 1) {
                res *= x;
            }

            x *= x;
            n >>= 1;
        }

        return res;
    }
};