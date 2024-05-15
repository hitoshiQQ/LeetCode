class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Deque to store indices of elements in the current window
        deque<int> windowIndices;
        // Vector to store the max value for each window
        vector<int> maxValues;

        for (int j = 0; j < nums.size(); ++j) {
            // Remove indices of elements not in the current window
            if (!windowIndices.empty() && j - k >= windowIndices.front()) {
                windowIndices.pop_front();
            }

            // Maintain the elements in decrasing order in the deque, pop elements from the back that are less than
            // or equal to the current element
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[j]) {
                windowIndices.pop_back();
            }

            // Push current elements index onto the deque
            windowIndices.push_back(j);

            // If reached the end of the first window, record the max for the current widnow
            if (j >= k - 1) {
                maxValues.emplace_back(nums[windowIndices.front()]);
            }
        }
        return maxValues;
    }
};