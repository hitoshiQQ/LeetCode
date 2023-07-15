// acceleration
const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Checking each line for contradiction
        // line-by-line cycle
        for (int j = 0; j < 9; ++j) {
            bool isDigit[9] = {};
            for (int i = 0; i < 9; ++i) {
                char c = board[j][i];
                if (c == '.') {
                    continue;
                }

                int digit = c - '1';
                if (isDigit[digit]) {
                    return false;
                }
                isDigit[digit] = true;
            }
        }

        // column cycle
        for (int j = 0; j < 9; ++j) {
            bool isDigit[9] = {};
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                int digit = c - '1';
                if (isDigit[digit]) {
                    return false;
                }
                isDigit[digit] = true;
            }
        }

        for (int jb = 0; jb < 9; jb += 3) {
            for (int ib = 0; ib < 9; ib += 3) {
                bool isDigit[9] = {};
                for (int j = jb; j < jb + 3; ++j) {
                    for (int i = ib; i < ib + 3; ++i) {
                        char c = board[i][j];
                        if (c == '.') {
                            continue;
                        }

                        int digit = c - '1';
                        if (isDigit[digit]) {
                            return false;
                        }
                        isDigit[digit] = true;
                    }
                }
            }
        }
        return true;
    }
};