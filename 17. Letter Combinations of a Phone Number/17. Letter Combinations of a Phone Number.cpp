/*
  1. We get the answer for each prefix;
  2. We take the first digit and add to each prefix all variants       corresponding to the digit;
  3. O(output size);
  */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> letters = {
            "abc", "def","ghi",
            "jkl","mno","pqrs",
            "tuv","wxyz"
        };

        vector<string> set(1, "");
        for (char sym : digits) {

            // create new set 
            vector<string> newSet;
            for (const string& pref : set) {

                // from prefix to set
                for (char letter : letters[sym - '2']) {
                    newSet.push_back(pref + letter);
                }
            }
            newSet.swap(set);
        }
        return set;
    }
};