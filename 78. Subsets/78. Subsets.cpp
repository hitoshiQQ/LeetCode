class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int k) {
        if (subset.size() == k) {
            res.push_back(subset);
        }
        else {

            //set "start" so that the elements in subset are in ascending order
            int start = 0;
            if (subset.size() > 0) {
                //start from the next element of subset[subset.size()-1]
                start = find(nums.begin(), nums.end(), subset[subset.size() - 1]) - nums.begin() + 1;
            }

            for (int j = start; j < nums.size(); ++j) {
                int e = nums[j];
                // cout << start << " " << i << endl;
                subset.push_back(e);
                backtrack(res, subset, nums, k);
                subset.pop_back();
            }
        }
    };

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        //from empty set to itself
        for (int j = 0; j <= nums.size(); ++j) {
            backtrack(res, subset, nums, j);
        }
        return res;
    }
};