class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;

        // run down the row, up to the empty cell, set the boundary of the last index
        while (n >= 0 && s[n] == ' ') {
            --n;
        }

        // check the row in the reverse direction
        const int last_ind = n;
        while (n >= 0 && s[n] != ' ') {
            --n;
        }
        return last_ind - n;
    }
};