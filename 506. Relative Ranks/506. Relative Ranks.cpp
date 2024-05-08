class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& scores) {

        int numOfScores = scores.size();

        // Use a vector of pairs to keep track of the scores and their original indices
        vector<pair<int, int>> indexedScores;

        for (int j = 0; j < numOfScores; ++j) {
            indexedScores.push_back(make_pair(scores[j], j));
        }

        // Sort the indexed scores in desceding oreder using a custom compartor lambda func
        sort(indexedScores.begin(), indexedScores.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first; });

        // Init the answer vector with the same size as the number of scores
        vector<string> ranks(numOfScores);

        // Define medals for the top 3 scores
        vector<string> medals = { "Gold Medal", "Silver Medal", "Bronze Medal" };

        // Assign ranks to the athletes based on sorted order
        for (int j = 0; j < numOfScores; ++j) {
            if (j < 3) {
                // Assign medals to the top 3 scores
                ranks[indexedScores[j].second] = medals[j];
            }
            else {
                // For others, assign the rank as a string
                ranks[indexedScores[j].second] = to_string(j + 1);
            }
        }
        return ranks;
    }
};