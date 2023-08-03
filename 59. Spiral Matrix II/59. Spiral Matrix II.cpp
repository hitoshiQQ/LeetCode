// let's go through the matrix with a nested loop, inserting the necessary value at the right moment
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n));
        int count = 1;

        for (int min = 0; min < n / 2; ++min) {
            const int max = n - min - 1;

            for (int j = min; j < max; ++j) {
                res[min][j] = count++;
            }
            for (int j = min; j < max; ++j) {
                res[j][max] = count++;
            }
            for (int j = max; j > min; --j) {
                res[max][j] = count++;
            }
            for (int j = max; j > min; --j) {
                res[j][min] = count++;
            }
        }
        if (n & 1)
            res[n / 2][n / 2] = count;

        return res;
    }
};