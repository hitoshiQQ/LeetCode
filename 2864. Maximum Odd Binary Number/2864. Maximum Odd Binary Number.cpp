class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        const int zero = ranges::count(s, '0');
        const int one = s.length() - zero;

        return string(one - 1, '1') + string(zero, '0') + '1';
    }
};