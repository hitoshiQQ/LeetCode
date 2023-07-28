class Solution {
public:
    int n;

    void backtrack(vector<int>& used, int r, int& res) {
        if (r == n) {
            ++res;
        }
        else {
            for (int c = 0; c < n; ++c) {
                // base case
                if (!used[c] && !used[n + r - c + n - 1] && !used[n + 2 * n - 1 + r + c]) {
                    used[c] = used[n + r - c + n - 1] = used[n + 2 * n - 1 + r + c] = true;

                    // recursive case's
                    backtrack(used, r + 1, res);
                    used[c] = used[n + r - c + n - 1] = used[n + 2 * n - 1 + r + c] = false;
                }
            }
        }
    };

    int totalNQueens(int n) {
        this->n = n;
        int res = 0;
        vector<int> used(n + 2 * n - 1 + 2 * n - 1, false);

        backtrack(used, 0, res);

        return res;
    }
};