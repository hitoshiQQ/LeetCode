class Solution {
public:
    string removeKdigits(string num, int k) {

        // Usings 'stack' to store characters representing the smallest number
        string stack;

        // Iterate through each character in the input number
        for (char& digit : num) {
            // Check if the current digit < than the last digit in 'stack'
            // whether we have still digits to remove
            while (k > 0 && !stack.empty() && stack.back() > digit) {
                // remove the last digit to maintaint the smallest number
                stack.pop_back();
                --k;
            }
            // Add the current digit to 'stack'
            stack += digit;
        }

        // Further remove digits from the end if we haven't removed enough K digits
        while (k > 0) {
            // Remove the last digit from 'stack'
            stack.pop_back();
            --k;
        }

        // Remove leading zeros from the 'stack'
        int startIndex = 0;
        while (startIndex < stack.size() && stack[startIndex] == '0') {
            // Increment index to skip the leading zero
            ++startIndex;
        }

        // Extract the non-zero starting substring as result
        string res = stack.substr(startIndex);

        // If result is empty, return zero, otherwise return the result
        return res.empty() ? "0" : res;
    }
};