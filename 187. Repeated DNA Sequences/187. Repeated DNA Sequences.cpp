class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string, int> sequenceCount;

        // Calculate the number of possible stating indices for 10-letter sequences
        int possibleStarts = s.size() - 9;

        // Prepare a vector to store the resulting repeating sequences
        vector<string> repeats;

        // Loop throught the string to examine all possible 10-letter sequences
        for (int j = 0; j < possibleStarts; ++j) {

            // Extract a 10-letter substring starting at J
            string subsequence = s.substr(j, 10);

            // Increment the count for this particular sequence
            if (++sequenceCount[subsequence] == 2) {
                repeats.push_back(subsequence);
            }
        }
        return repeats;
    }
};