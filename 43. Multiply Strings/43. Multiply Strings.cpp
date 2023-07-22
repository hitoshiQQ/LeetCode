class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');

        for (int j = num1.size() - 1; j >= 0; --j) {
            int carry = 0;
            for (int i = num2.size() - 1; i >= 0; --i) {
                int sum = (res[j + i + 1] - '0') + (num1[j] - '0') * (num2[i] - '0') + carry;
                res[j + i + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[j] += carry;
        }
        size_t pos = res.find_first_not_of('0');
        if (pos != string::npos) {
            return res.substr(pos);
        }
        else {
            return "0";
        }
    }
};