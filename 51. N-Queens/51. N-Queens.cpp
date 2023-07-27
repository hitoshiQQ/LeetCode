class Solution {
public:
    bool isCanGo(int row, int col, vector<string>& table, int n) {

        // check upper left && lower left diagonal's, left row
        int copy_row = row;
        int copy_col = col;
        while (row >= 0 && col >= 0) {
            if (table[row][col] == 'Q') {
                return false;
            }
            --row; --col;
        }

        row = copy_row;
        col = copy_col;
        while (col >= 0) {
            if (table[row][col] == 'Q') {
                return false;
            }
            --col;
        }

        row = copy_row;
        col = copy_col;
        while (row < n && col >= 0) {
            if (table[row][col] == 'Q') {
                return false;
            }
            ++row;
            --col;
        }
        return true;
    }

    void process(int col, vector<string>& table, vector<vector<string>>& res, int n) {
        if (col == n) {
            res.push_back(table);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isCanGo(row, col, table, n)) {
                table[row][col] = 'Q';
                process(col + 1, table, res, n);
                table[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> table(n);
        string str(n, '.');

        for (int j = 0; j < n; ++j) {
            table[j] = str;
        }
        process(0, table, res, n);
        return res;
    }
};