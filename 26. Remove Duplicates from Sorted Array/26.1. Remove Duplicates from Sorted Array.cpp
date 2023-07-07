class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // ñreate an index for insertion 
        int index_ins = 1;

        // pass through the array by incrementing the indexing variable 
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[j - 1]) {
                nums[index_ins] = nums[j];
                index_ins++;
            }
        }
        return index_ins;
    }
};