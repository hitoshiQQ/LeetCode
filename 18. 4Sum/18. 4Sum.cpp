/*
    sorting with two pointers
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > res;
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            if (j > 0 && nums[j] == nums[j - 1])
                continue;
            for (int i = j + 1; i < n; i++) {
                if (i > (j + 1) && nums[i] == nums[i - 1])
                    continue;
                int l = i + 1, r = n - 1;
                while (l < r) {
                    long curr_sm = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    if (curr_sm == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                    }
                    else if (curr_sm > target)
                        r--;
                    else
                        l++;
                }
            }
        }
        return res;
    }
};