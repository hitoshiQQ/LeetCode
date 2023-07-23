class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.size(), n = p.size();
        int last_match = -1;
        int  starj = -1;

        while (i < m) {

            if (j < n && (p[j] == s[i] || p[j] == '?')) {

                //match one
                i++;
                j++;
            }
            else if (j < n && p[j] == '*') {

                //greedily match one
                starj = j;
                last_match = i;
                j++;
            }
            else if (starj != -1) {

                //not match, fallback to use previous found '*'
                //the previous star now matches s[last_match+1]
                //now start from the next char of previous '*'
                last_match++;
                i = last_match;
                j = starj + 1;
            }
            else {

                //current char not match, and cannot fallback
                // cout << endl;
                return false;
            }
        }
        //if the remaining char in p are all '*', we think it's a match
        return p.substr(j) == string(p.size() - j, '*');
    }
};