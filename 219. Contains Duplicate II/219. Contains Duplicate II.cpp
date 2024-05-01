class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Create a hashmap to store the most recent index of each value observed
        unordered_map<int, int> valueToIndexMap;

        for (int j = 0; j < (int)nums.size(); ++j) {
            // Check if the current value exists in the map, it has been encountered before
            if (valueToIndexMap.count(nums[j])) {
                // If the previous occurrence is within K indices from the current index , ret true
                if (j - valueToIndexMap[nums[j]] <= k) {
                    return true;
                }
            }

            // Update the hashmap with the current index for this value
            valueToIndexMap[nums[j]] = j;
        }
        // If no duplicate elements are within the given K indices, ret false
        return false;
    }
};