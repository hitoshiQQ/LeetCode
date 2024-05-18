class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the strings aren't of the same size, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Create a vector of 26 elements to count the occurrences of each letter
        vector<int> charCounts(26, 0);

        // Increment and decrement counts for each character in both strings respectively
        for (int j = 0; j < s.size(); ++j) {
            ++charCounts[s[j] - 'a'];
            --charCounts[t[j] - 'a'];
        }

        // Check if all counts are zero, if so, strings are anagrams, otherwise, they aren't
        return all_of(charCounts.begin(), charCounts.end(), [](int count) {
            return count == 0;
            });
    }
};
