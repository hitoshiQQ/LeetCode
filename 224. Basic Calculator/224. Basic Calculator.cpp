class Solution {
public:
    int calculate(string s) {
        // Stack to hold numbers and signs (as integer)
        stack<int> operands;
        // Accumulator for the current result
        int result = 0;
        // Current sign, starts with positive      
        int sign = 1;
        // Size of the input string     
        int n = s.size();

        for (int j = 0; j < n; ++j) {
            // If the character is a digit, it could be part of a multi-digit number.
            if (isdigit(s[j])) {
                int num = 0; // Initialize the number to be 0
                // Construct the number from the subsequent digits
                while (j < n && isdigit(s[j])) {
                    num = num * 10 + (s[j] - '0');
                    ++j;
                }
                // Add/Subtract the number to/from the current result
                result += sign * num;
                // Since the loop will increment i after, we decrease it here
                --j;
            }
            else if (s[j] == '+') {
                sign = 1;  // Set sign to positive for the next number
            }
            else if (s[j] == '-') {
                sign = -1; // Set sign to negative for the next number
            }
            else if (s[j] == '(') {
                // When encountering '(', push the current result and sign onto the stack
                operands.push(result);
                operands.push(sign);
                // Reset result and sign for the new sub-expression inside the parentheses
                result = 0;
                sign = 1;
            }
            else if (s[j] == ')') {
                // Ending a sub-expression, pop sign from stack and multiply it with the current result
                result *= operands.top();
                operands.pop();
                // Add the result of the sub-expression to the result up to the '('
                result += operands.top();
                operands.pop();
            }
            // Ignore whitespace and other non-math characters
        }
        return result; // Return the final result
    }
};