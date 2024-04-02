class Solution {
public:
    bool isIsomorphic(string source, string target) {

        // create mappings for characters in 'Source' and 'Target'
        int mappingSource[256] = { 0 };
        int mappingTarget[256] = { 0 };

        // Get size of the strings
        int length = source.size();

        // Loop through each character in both string
        for (int j = 0; j < length; ++j) {

            // Character from string SOURCE
            char charSource = source[j];

            // Character from string TARGET
            char charTarget = target[j];

            // Check if the current mapping dsn't match
            if (mappingSource[charSource] != mappingTarget[charTarget]) {

                // if strings are not isomorphic
                return false;
            }

            // Updaate the mappings for the current characters
            mappingSource[charSource] = mappingTarget[charTarget] = j + 1;
        }
        // If all mappings matched, strings are isomorphic
        return true;
    }
};