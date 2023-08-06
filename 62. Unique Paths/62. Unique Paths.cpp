/*
Combinatorial method

The path can be described as a right-down passage, hence right( column-wise - 1);
down (row by row - 1);

Any path is a sequence of (n + m - 2) moves "right and down".
Any such sequence will give an acceptable path.
*/
class Solution {
    int func(int n, int k) {
        k = min(k, n - k);
        uint32_t res = 1;

        for (int j = 1; j <= k; ++j) {
            res = res * (n - k + j) / j;
        }
        return (int)res;
    }
public:
    int uniquePaths(int m, int n) {
        return func(n + m - 2, m - 1);
    }
};