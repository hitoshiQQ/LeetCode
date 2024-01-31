class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int j = triangle.size() - 2; j >= 0; j--) {
            for (int i = 0; i <= j; ++i) {
                triangle[j][i] += min(triangle[j + 1][i], triangle[j + 1][i + 1]);
            }
        }
        return triangle[0][0];
    }
};