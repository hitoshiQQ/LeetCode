class Solution {
public:
    string minRemoveToMakeValid(string s) {

        // Simulates a stack to hold valid characters
        string tempStack;

        // Counter for unmatched '('
        int openCount = 0;

        // First pass: Remove any ')' that doesn't have a matching '('
        for (char& c : s) {

            // Skip invalid ')'
            if (c == ')' && openCount == 0) {
                continue;
            }

            // Increment && decrement open counter
            if (c == '(') {
                openCount++;
            }
            else if (c == ')') {
                openCount--;
            }

            // Add the character to the stack
            tempStack.push_back(c);
        }

        // String that will store the valid parentheses sequence
        string res;

        // Reset counter for the next pass
        openCount = 0;

        // Second pass: Remove any '(' that doesn't have a matching ')' from the end
        while (!tempStack.empty()) {

            // Take the last character from the stack
            char c = tempStack.back();

            // Remove that character from the stack
            tempStack.pop_back();

            // Skip invalid '('
            if (c == '(' && openCount == 0) {
                continue;
            }

            // Increment && decrement open counter
            if (c == ')') {
                openCount++;
            }
            else if (c == '(') {
                openCount--;
            }
            res.push_back(c);
        }
        // Result is built in reverse oreder, so we need to reverse it
        reverse(res.begin(), res.end());
        return res;
    }
};