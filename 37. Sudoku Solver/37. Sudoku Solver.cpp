class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int s) {
        if (s == 81) {
            return true;
        }

        const int j = s / 9;
        const int i = s % 9;

        if (board[j][i] != '.')
            return solve(board, s + 1);


        for (char c = '1'; c <= '9'; ++c)
            if (isValid(board, j, i, c)) {
                board[j][i] = c;
                if (solve(board, s + 1))
                    return true;
                board[j][i] = '.';
            }

        return false;
    }

    // check all
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int j = 0; j < 9; ++j)
            if (board[j][col] == c || board[row][j] == c ||
                board[3 * (row / 3) + j / 3][3 * (col / 3) + j % 3] == c)
                return false;
        return true;
    }
};