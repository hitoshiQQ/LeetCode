class Solution {
public:
    int calculate(std::string s) {
        // Initialize the current value and the total size of the string
        int currentValue = 0;
        int stringSize = s.size();

        // Set the initial sign to '+'
        char operationSign = '+';

        // Stack to hold intermediate results
        stack<int> calculationStack;

        for (int j = 0; j < stringSize; ++j) {
            char currentChar = s[j];

            // If character is a digit, build the number by multiplying the current value by 10 and adding the digit's integer value
            if (std::isdigit(currentChar)) {
                currentValue = currentValue * 10 + (currentChar - '0');
            }

            // If we reach the end of the string or encounter an operation 
            if (j == stringSize - 1 || currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
                switch (operationSign) {
                    // If the sign is '+', push the current value to the stack
                case '+':
                    calculationStack.push(currentValue);
                    break;
                    // If the sign is '-', push the negative of the current value to the stack
                case '-':
                    calculationStack.push(-currentValue);
                    break;
                    // If the sign is '*', multiply the top element of the stack with the current value and push the result back to the stack
                case '*':
                {
                    int topValue = calculationStack.top();
                    calculationStack.pop();
                    calculationStack.push(topValue * currentValue);
                }
                break;
                // If the sign is '/', divide the top element of the stack by the current value and push the result back to the stack
                case '/':
                {
                    int topValue = calculationStack.top();
                    calculationStack.pop();
                    calculationStack.push(topValue / currentValue);
                }
                break;
                }
                // Update the operation sign for the next operation
                operationSign = currentChar;
                // Reset the current value
                currentValue = 0;
            }
        }

        int res = 0;

        // Add up all values in the stack to get the final result
        while (!calculationStack.empty()) {
            res += calculationStack.top();
            calculationStack.pop();
        }
        return res;
    }
};