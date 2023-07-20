class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        /*
        if nums is [1,n],
        then the first missing positive number is n+1,
        otherwise there's some number in [`,n] missing in nums,
        so the first missing positive number is in [1,n].
        To summary, first missing positive number's range
        should be in 1 to n+1.
        */

        for (int j = 0; j < n; ++j) {

            /*
            swap every number in [1,n] to its correct position
            nums[j] should be put in the 'nums[j]-1'th position
            */
            while (nums[j] >= 1 && nums[j] <= n && nums[j] != nums[nums[j] - 1]) {
                swap(nums[j], nums[nums[j] - 1]);
            }
        }

        for (int j = 0; j < n; ++j) {

            /*
            the number i+1 is not in its correct position,
            so it must be missing
            */
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n + 1;
    }
};