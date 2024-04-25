class Solution {
public:
    // Func to calculate the max amount of money that can be robbed
    int rob(vector<int>& nums) {

        int n = nums.size();

        // If there only one house, return its value
        if (n == 1) {
            return nums[0];
        }

        // Compare and return max amount between robbing the first house or the second one
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    // Helper func to calculate max amount from a range of houses
    int robRange(vector<int>& nums, int left, int right) {

        // This will store the max amount including / excluding the current house
        int inclusive = 0;
        int exclusive = 0;

        // Iterate from the left to the right indices of the house range
        for (; left <= right; ++left) {
            // Compute the new exclusive amount, which is the max of the previous inclusive and exclusive amounts
            int newExclusive = max(inclusive, exclusive);

            // Update inclusive to be the sum of the old exclusive and current house value
            inclusive = exclusive + nums[left];

            // Update exclusive to the newly computed value
            exclusive = newExclusive;
        }
        return max(inclusive, exclusive);
    }
};