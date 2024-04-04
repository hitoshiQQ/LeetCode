class Solution {
public:
    int maxDepth(string s) {

        // Store the max depth
        int maxDepth = 0;

        // Track the current depth of open parentheses
        int currentDepth = 0;

        // Iterate throught each character in the string
        for (char& c : s) {

            if (c == '(') {

                // Increment the current depth when an opening parenthesis is encountered
                currentDepth++;

                // Update the max depth encountered so far
                maxDepth = std::max(maxDepth, currentDepth);

            }
            else if (c == ')') {

                // Decrement the current depth when a closing parenthesis is encountered
                currentDepth--;
            }
        }
        return maxDepth;
    }
};