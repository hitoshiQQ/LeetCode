class Solution {

    /*
    *   1 + 2 + 3 .... + X ... + N
    *   (1 + X) * X / 2 = (X + N) * (N - X + 1) / 2
    *    X + X^2 = NX - X^2 + X + N^2 - NX + N
    *    2 * X^2 = N^2 + N
    *    x = sqrt((N^2 + N) / 2)
    *
    */
public:
    int pivotInteger(int n) {

        const int y = (n * n + n) / 2;
        const int x = sqrt(y);

        return x * x == y ? x : -1;
    }
};