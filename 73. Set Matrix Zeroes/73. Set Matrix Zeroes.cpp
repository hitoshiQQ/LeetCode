// use two arrays to track whether the i-th row / j-th column need to be zeroed
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                rows[j] |= (matrix[j][i] == 0);
                cols[i] |= (matrix[j][i] == 0);
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (rows[j] || cols[i]) matrix[j][i] = 0;
            }
        }
    }
};