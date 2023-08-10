class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int j = digits.size() - 1; j >= 0; --j) {
            if (digits[j] < 9) {
                ++digits[j];
                return digits;
            }
            digits[j] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};