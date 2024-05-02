class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        // Init a set to keep track of values in the window defined by indexDiff
        set<long> windowSet;

        for (int j = 0; j < (int)nums.size(); ++j) {
            // Find the lower bound of the acceptable value difference
            auto lower = windowSet.lower_bound((long)nums[j] - valueDiff);

            // If an element is found within the value range, ret true
            if (lower != windowSet.end() && *lower <= (long)nums[j] + valueDiff) {
                return true;
            }

            // Insert the current element into the set
            windowSet.insert((long)nums[j]);

            // If our window exceeds the permitted index difference, remove the oldest value
            if (j >= indexDiff) {
                windowSet.erase((long)nums[j - indexDiff]);
            }
        }
        return false;
    }
};