/*
if there are no redundant answer sets, if the numbers in the answer set are in non-decreasing order => no repetition of the same thing

      None-Recursive method
A three-dimensional vector where the first index is the sum, followed by a list of lists from lists.

*/
class Solution {

public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());

        // [sum] -->> lists of list
        vector<vector<vector<int>>> sum_lists(1 + target);
        for (int j : candidates) {
            if (j <= target) {
                sum_lists[j].push_back({ j });
            }
        }
        // loop through the sums (j)
        for (int j = 1; j < target; ++j) {
            for (auto& vec_rep : sum_lists[j]) {
                for (int i = (int)candidates.size() - 1; i >= 0 && candidates[i] >= vec_rep.back(); --i) {
                    if (j + candidates[i] <= target) {
                        vec_rep.push_back(candidates[i]);
                        sum_lists[j + candidates[i]].push_back(vec_rep);
                        vec_rep.pop_back();
                    }
                }
            }
        }

        // last element with index target
        return sum_lists.back();
    }
};