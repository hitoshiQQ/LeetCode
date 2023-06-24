class Solution {
public:
    int reverse(int x) {
        //create variable for result; long - overflow
        long res = 0;

        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return (int)res;
    }
};