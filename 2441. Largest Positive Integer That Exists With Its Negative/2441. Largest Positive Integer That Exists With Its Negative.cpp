class Solution {
public:
    int findMaxK(vector<int>& nums) {

        // Create an unordered set with all elements from 'nums' to facilitate faster lookups
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Init the answer variable to store the max K found
        int maxK = -1;

        // Iterate over each number in the set
        for (int num : numSet) {
            // Check if the negative of the current number exists in the set
            if (numSet.count(-num)) {
                // If both 'num' and '-num' are present, update 'maxK' with the max so far
                maxK = max(maxK, num);
            }
        }
        return maxK;
    }
};