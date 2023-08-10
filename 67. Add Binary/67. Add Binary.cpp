class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int transpos = 0;

        int j = a.length() - 1;
        int i = b.length() - 1;

        while (j >= 0 || i >= 0 || transpos) {
            if (j >= 0) {
                transpos += a[j--] - '0';
            }
            if (i >= 0) {
                transpos += b[i--] - '0';
            }
            res += transpos % 2 + '0';
            transpos /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};