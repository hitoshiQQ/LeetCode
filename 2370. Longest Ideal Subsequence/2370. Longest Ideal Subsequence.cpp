class Solution {
public:
    int longestIdealString(string s, int k) {

        // The length of the input string
        int stringLength = s.size();

        // Init the longest length with 1, as the min ideal string length is 1
        int longestLength = 1;

        // Dynamic progaramming table with a base case of 1 for each character
        vector<int> dp(stringLength, 1);

        // Stores the last occurrence index of each character encountered
        unordered_map<char, int> lastOccurrence;

        // Init the last occurrence for the first character in the string
        lastOccurrence[s[0]] = 0;

        // Iterate over the string starting from the second  character
        for (int j = 1; j < stringLength; ++j) {
            // Current character being processed
            char currentChar = s[j];

            // Try extending the ideal string including all character within K distance of current character
            for (char otherChar = 'a'; otherChar <= 'z'; ++otherChar) {
                // If the other character is more than K distance away, skip it
                if (abs(currentChar - otherChar) > k) {
                    continue;
                }

                // Check if we have seen the other character before and extend the ideal string length if possible
                if (lastOccurrence.count(otherChar)) {
                    dp[j] = max(dp[j], dp[lastOccurrence[otherChar]] + 1);
                }
            }
            // Update the last occurrence index for the current character
            lastOccurrence[currentChar] = j;

            // Update the longest length found so far
            longestLength = max(longestLength, dp[j]);
        }
        return longestLength;
    }
};