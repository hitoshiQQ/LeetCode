class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;

        for (const int num : nums)
            if (j < 2 || num > nums[j - 2])
                nums[j++] = num;

        return j;
    }
};