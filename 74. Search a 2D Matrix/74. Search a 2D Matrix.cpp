class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (target >= matrix[j][0] && target <= matrix[j][matrix[j].size() - 1]) {
                return find(matrix[j].begin(), matrix[j].end(), target) != matrix[j].end() ? true : false;
            }
        }
        return false;
    }
};