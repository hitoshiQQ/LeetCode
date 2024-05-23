class Solution {
public:
    int addDigits(int num) {
        // If the number is zero, digital root is zero
        if (num == 0) {
            return 0;

        }
        else {
            // Subtract 1 from num to handle the multiplie of 9 scenario,
            // then mod by 9 to get the reminder
            return (num - 1) % 9 + 1;
        }
    }
};