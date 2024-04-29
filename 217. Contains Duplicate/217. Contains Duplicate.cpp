class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Init an unordered set with the elements from the nums vector
        unordered_set<int> numSet(nums.begin(), nums.end());

        // If the size of the set is smaller than the size of the original vector,
        // it means there were duplicates which were removed in the set creation process
        return numSet.size() < nums.size();
    }
};