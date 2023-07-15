class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // first index - row, second index - digit
        bool jIsDigit[9][9] = {};
        bool iIsDigit[9][9] = {};
        bool jiIsDigit[3][3][9] = {};

        for (int j = 0; j < 9; ++j) {
            for (int i = 0; i < 9; ++i) {
                char c = board[j][i];
                if (c == '.') {
                    continue;
                }

                // digit = symbol - unit code
                int digit = c - '1';

                // repetition check
                if (jIsDigit[j][digit]) {
                    return false;
                }
                jIsDigit[j][digit] = true;

                if (iIsDigit[i][digit]) {
                    return false;
                }
                iIsDigit[i][digit] = true;

                if (jiIsDigit[j / 3][i / 3][digit]) {
                    return false;
                }
                jiIsDigit[j / 3][i / 3][digit] = true;
            }
        }
        return true;
    }
};