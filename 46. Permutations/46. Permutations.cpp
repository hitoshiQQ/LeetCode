class Solution {
public:
    void foo(vector<vector<int>>& res, vector<int>& per, vector<int>& nums) {
        if (per.size() == nums.size()) {
            res.push_back(per);
        }
        else {
            for (int j : nums) {
                if (find(per.begin(), per.end(), j) != per.end()) {
                    continue;
                }
                per.push_back(j);
                backtrack(res, per, nums);
                per.pop_back();
            }
        }
    };

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> per;
        foo(res, per, nums);

        return res;
    }
};