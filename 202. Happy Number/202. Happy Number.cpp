class Solution {
public:
    bool isHappy(int n) {

        // Lambda function to calculate the next number by summing of the digits
        auto getNextNumber = [](int currentNumber) {

            int  sumOfSquares = 0;
            while (currentNumber > 0) {
                // Get last digit
                int digit = currentNumber % 10;

                // Add square of the digit to sum
                sumOfSquares += std::pow(digit, 2);

                // Remove the last digit
                currentNumber /= 10;
            }
            return sumOfSquares;
        };

        // Init two pointers for the cycle detection
        // slow pointer moves one step
        int slowPointer = n;

        // Fast pointer moves two steps
        int fastPointer = getNextNumber(n);

        // Continue moving the pointers until they meet or find a happy number
        while (slowPointer != fastPointer) {

            // Move pointers
            slowPointer = getNextNumber(slowPointer);
            fastPointer = getNextNumber(getNextNumber(fastPointer));
        }
        return slowPointer == 1;
    }
};