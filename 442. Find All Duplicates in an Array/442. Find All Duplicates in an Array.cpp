class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        // Init size
        int size = nums.size();

        // Recorder the array such that the number "j" is a placed at the index "j - 1"
        for (int j = 0; j < size; ++j) {

            // Swap elements until the current element is at its corrct position
            while (nums[j] != nums[nums[j] - 1]) {
                std::swap(nums[j], nums[nums[j] - 1]);
            }
        }

        // Vector to hold the duplicates found
        std::vector<int> duplicates;
        for (int j = 0; j < size; ++j) {

            // If current element isn't at its correct position, it must be a duplicate
            if (nums[j] != j + 1) {
                // record the duplicate
                duplicates.push_back(nums[j]);
            }
        }
        // Return the vector containing all the duplicates
        return duplicates;
    }
};