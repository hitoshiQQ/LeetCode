class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {

        vector<int> res(nums.size());
        res[0] = 1;

        for (int j = 1; j < (int)nums.size(); j++) {
            res[j] = res[j - 1] * nums[j - 1];
        }

        int suffix = 1;
        for (int j = (int)nums.size() - 2; j >= 0; j--) {
            suffix *= nums[j + 1];
            res[j] *= suffix;
        }
        return res;
    }
};