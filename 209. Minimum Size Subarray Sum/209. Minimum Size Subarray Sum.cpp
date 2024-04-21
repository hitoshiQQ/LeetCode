class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // Size of the input array
        int n = nums.size();

        // Long long to avoid overflow when summing up
        long long sum = 0;

        // Init the result to the max possible len + 1
        int res = n + 1;

        // 2 Pointers J is the end of the current subarray, I is the start of the current subarray
        for (int j = 0, i = 0; j < n; ++j) {
            // Increase the sum by the current element
            sum += nums[j];

            // If sum isn't smaller than the target and start pointer I hasn't reached the end
            while (i < n && sum >= target) {
                // Update the result with the new min len
                res = min(res, j - i + 1);

                // Subtract the first element of the subarray and move I right
                sum -= nums[i++];
            }
        }
        // If result change, no valid subarray was found, ret 0
        // Otherwise, return len of the shortest subarray
        return res == n + 1 ? 0 : res;
    }
};