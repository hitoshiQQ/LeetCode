class Solution {
public:
    string convert(string s, int numRows) {

        // if string has 1 line - return original string
        if (numRows == 1) {
            return s;
        }

        // init vector && curr string && direction of movement
        vector<string> rows(numRows);
        int row = 0, direction = 1;

        for (char c : s) {
            rows[row] += c;

            // change's flag of direction
            if (row == 0) {
                direction = 1;
            }
            else if (row == numRows - 1) {
                direction = -1;
            }
            row += direction;
        }

        //creat result string
        string res = "";
        for (string rowStr : rows) {
            res += rowStr;
        }
        return res;
    }
};