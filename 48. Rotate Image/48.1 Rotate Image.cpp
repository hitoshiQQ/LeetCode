class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // line item reflection
        reverse(matrix.begin(), matrix.end());
        int n = (int)matrix.size();

        // transposition
        for (int j = 0; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};