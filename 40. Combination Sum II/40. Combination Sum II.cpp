/*
Recursive method.

We follow the vector, bypassing the base cases, substituting the values we need into the representing vector
*/
class Solution {
public:
    void foo(const vector<int>& candidates, vector<vector<int>>& res, vector<int> temp, int current_index, int target) {
        // base case:
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        if (target < 0 || current_index >= candidates.size()) {
            return;
        }

        for (int j = current_index; j < candidates.size(); ++j) {

            // smart way to avoid duplicates
            if (j != current_index && candidates[j] == candidates[j - 1]) {
                continue;
            }
            temp.push_back(candidates[j]);
            foo(candidates, res, temp, j + 1, target - candidates[j]);
            temp.pop_back();

        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        foo(candidates, res, temp, 0, target);
        return res;
    }
};