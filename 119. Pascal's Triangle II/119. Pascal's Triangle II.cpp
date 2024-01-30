class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);

        for (int j = 2; j < rowIndex + 1; ++j)
            for (int i = 1; i < j; ++i)
                res[j - i] += res[j - i - 1];

        return res;
    }
};