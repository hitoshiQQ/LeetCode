/*
bring all rows to the same form
Then group them using a hash table, for a key, go through the string to find its hash
*/

class Solution {
public:
    // we won't change the vector, we'll make it immutable
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> an_groups;

        // pass through each line and create an array-histogram for it
        for (const string& str : strs) {
            int massive[26] = {};

            // run through the symbols 
            // letter enlargement
            for (char c : str) {
                massive[c - 'a']++;
            }
            string key = "";
            for (char c = 'a'; c <= 'z'; ++c) {
                int co = massive[c - 'a'];

                // If co = 1, then we add this letter
                // otherwise we add the number as well
                if (co > 0) {
                    key += c;
                }
                if (co > 1) {
                    key += to_string(co);
                }
            }
            an_groups[key].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(an_groups.size());

        // we'll go through the key-value pairs
        for (auto& pr : an_groups) {
            res.push_back(move(pr.second));
        }
        return res;
    }
};