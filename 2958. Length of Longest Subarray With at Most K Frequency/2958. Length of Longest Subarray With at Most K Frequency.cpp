class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        // Dictionary to keep track of the count of each number in the current window
        unordered_map<int, int> countMap;

        // Variable to store max length
        int maxLength = 0;

        // 2 Pointers defining the current window's boundaries
        for (int left = 0, right = 0; right < nums.size(); ++right) {

            // Increment the count of the rightmost element in the current window
            ++countMap[nums[right]];

            // If the count of the current elem exceeds K, shrink he window from the left
            while (countMap[nums[right]] > k) {
                --countMap[nums[left]];
                ++left;
            }

            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};