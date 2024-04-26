class Solution {
public:
    string shortestPalindrome(string s) {

        // Define constants and init values
        // Base for polynomial hashing
        const int kBase = 131;
        // Hash value for the prefix
        unsigned long long prefixHash = 0;
        // Hash value for the suffix
        unsigned long long suffixHash = 0;
        // Used to compute hash values
        unsigned long long currentMplier = 1;
        // Index marking the end of the longest palindrome starting at position 0
        int palindromeEndIndex = 0;
        // Size of input string
        int n = s.size();

        // Loop through the string character by character
        for (int j = 0; j < n; ++j) {
            // Convert char to int
            int charValue = s[j] - 'a' + 1;

            // Update prefix
            prefixHash = prefixHash * kBase + charValue;
            // Update suffix
            suffixHash = suffixHash + currentMplier * charValue;
            // Update the base multiplier for the next character
            currentMplier *= kBase;

            // If the current prefix is palindrome
            if (prefixHash == suffixHash) {
                // Update the end index of the longest palindorme found
                palindromeEndIndex = j + 1;
            }
        }
        // If the whole string is a palindrome, return it as it
        if (palindromeEndIndex == n) {
            return s;
        }

        // Otherwise, construct the shortest palidnrome by appending the reverse  of the remaining substring
        string remainingSubstring = s.substr(palindromeEndIndex, n - palindromeEndIndex);
        reverse(remainingSubstring.begin(), remainingSubstring.end());

        // Concatenate the reversed substring with the original string
        return remainingSubstring + s;
    }
};