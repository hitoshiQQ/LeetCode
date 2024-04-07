class Solution {
public:
    bool checkValidString(string s) {

        // Track balance of the parentheses
        int balance = 0;

        // Store the size of the string
        int n = s.size();

        // Forward pass to ensure there aren't too many closing parentheses
        for (int j = 0; j < n; ++j) {

            //Increment balance for an opening parenthesis or an asterisk
            if (s[j] != ')') {
                ++balance;

            }
            else if (balance > 0) {
                // Decrement balance for a closing parenthesis if balance is pos
                --balance;

            }
            else {
                // if balance is zero, too many closing parentheses are encountered
                return false;
            }
        }

        // If only counting opening parentheses and asteriks, balance might be pos
        // Checked in the reverse order for the opposite scenario
        // reset balance
        balance = 0;
        for (int j = n - 1; j >= 0; --j) {
            // Increment balance for opening parenthesis or an asterisk
            if (s[j] != '(') {
                ++balance;

            }
            else if (balance > 0) {
                // Decrement balance for an opening parenthesis if balance is pos
                --balance;

            }
            else {
                // if balance is zero, too many opening parentheses are encountered
                return false;
            }
        }
        return true;
    }
};