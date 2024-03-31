class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        // Sort input array
        sort(nums.begin(), nums.end());

        // Init a vector of vectors to store the resulting subarrays
        vector<vector<int>> res;

        // Size of the input array
        int n = nums.size();

        // Iterate over the array in steps of 3 since we are creating trinary subarrays
        for (int j = 0; j < n; j += 3) {

            // Check if there are enough elements remaining to create a subarryas
            if (j + 2 >= n) {
                return {};
            }

            // Creating a temporary vector for the current subarrays
            vector<int> currentSub = { nums[j], nums[j + 1], nums[j + 2] };

            // Check if the differenct between the largest and smallest
            // numbers in the curent subarrays greater than K
            if (currentSub[2] - currentSub[0] > k) {
                return {};
            }

            // Add the current subarrays to the reuslt
            res.emplace_back(currentSub);
        }
        return res;
    }
};