class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        const int m = board.size();
        const int n = board[0].size();

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (j * i == 0 || j == m - 1 || i == n - 1) {
                    depthFirstSearch(board, j, i);
                }
            }
        }

        for (vector<char>& row : board) {
            for (char& c : row) {
                if (c == '*') {
                    c = 'O';
                }
                else if (c == 'O') {
                    c = 'X';
                }
            }
        }
    }

private:
    void depthFirstSearch(vector<vector<char>>& board, int j, int i) {
        if (j < 0 || j == board.size() || i < 0 || i == board[0].size()) {
            return;
        }
        if (board[j][i] != 'O') {
            return;
        }
        board[j][i] = '*';
        depthFirstSearch(board, j + 1, i);
        depthFirstSearch(board, j - 1, i);
        depthFirstSearch(board, j, i + 1);
        depthFirstSearch(board, j, i - 1);
    }

};