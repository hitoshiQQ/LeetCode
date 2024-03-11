class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (!nums.size()) {
            return 0;
        }

        int res = nums[0];
        int Max = res;
        int Min = res;

        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] < 0) {
                swap(Max, Min);
            }

            Max = max(nums[j], nums[j] * Max);
            Min = min(nums[j], nums[j] * Min);
            res = max(Max, res);
        }
        return res;
    }
};