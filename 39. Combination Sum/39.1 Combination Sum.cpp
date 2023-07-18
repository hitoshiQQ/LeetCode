/*
if there are no redundant answer sets, if the numbers in the answer set are in non-decreasing order => no repetition of the same thing

      Recursive method
There is the current one and select the next number to be added.
New number >= max. number of the set
*/
class Solution {
private:
    void recursive(const vector<int>& c, int target,
        vector<int>& current_rep, int min_index,
        int current_sum, vector<vector<int>>& res) {

        // base cases
        if (current_sum > target) {
            return;
        }
        if (current_sum == target) {
            res.push_back(current_rep);
            return;
        }
        assert(current_sum < target);

        // recursive cases
        for (
            int j = min_index;
            j < (int)c.size() && current_sum + c[j] <= target;
            ++j
            ) {
            current_rep.push_back(c[j]);
            recursive(c, target, current_rep, j, current_sum + c[j], res);
            current_rep.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current_rep;

        recursive(candidates, target, current_rep, 0, 0, res);
        return res;
    }
};