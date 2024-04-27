class Solution {
public:
    int findRotateSteps(string ring, string key) {

        // Length of the key
        int keyLength = key.size();
        // Length of the ring
        int ringLength = ring.size();
        // Array of vectors to hold the pos of each character
        vector<int> position[26];

        // Populate the position array with the indices of each character in the ring
        for (int j = 0; j < ringLength; ++j) {
            position[ring[j] - 'a'].push_back(j);
        }

        // Init the dynamic programming table
        int dpTable[keyLength][ringLength];
        memset(dpTable, 0x3f, sizeof(dpTable));

        // BASE CASE: fill in the first row of the dynamic programming table
        for (int index : position[key[0] - 'a']) {
            dpTable[0][index] = min(index, ringLength - index) + 1;
        }

        // Fill in the remainder of the dpTable
        for (int j = 1; j < keyLength; ++j) {
            for (int i : position[key[j] - 'a']) {
                for (int q : position[key[j - 1] - 'a']) {
                    // Calculate min steps
                    int stepDiff = min(abs(i - q), ringLength - abs(i - q)) + 1;
                    dpTable[j][i] = min(dpTable[j][i], dpTable[j - 1][q] + stepDiff);
                }
            }
        }

        // Find the min steps needed to spell the last character of the key
        int minSteps = INT_MAX;
        for (int index : position[key[keyLength - 1] - 'a']) {
            minSteps = min(minSteps, dpTable[keyLength - 1][index]);
        }
        return minSteps;
    }
};