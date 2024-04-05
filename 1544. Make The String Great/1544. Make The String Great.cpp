class Solution {
public:
    string makeGood(string s) {

        // String to simulate a stack
        string stack;

        // Iterate over each character in the input string
        for (char c : s) {

            // If the stack is empty or the absolute difference
            // between the ASCII values of the top character in the stack && the current character isn't 32
            if (stack.empty() || abs(stack.back() - c) != 32) {

                stack += c;
            }
            else {
                // If the top character of the stack is of opposite case but same letter as the current character
                // pop the top character from the stack
                stack.pop_back();
            }
        }
        return stack;
    }
};