class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int j = 0; j < numRows; ++j)
            res.push_back(vector<int>(j + 1, 1));

        for (int j = 2; j < numRows; ++j)
            for (int i = 1; i < res[j].size() - 1; ++i)
                res[j][i] = res[j - 1][i - 1] + res[j - 1][i];

        return res;
    }
};