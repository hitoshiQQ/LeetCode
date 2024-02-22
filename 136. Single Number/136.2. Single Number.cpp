/*
   We only iterate through nums, so the time complexity is the number of elements in nums.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int num : nums) {
            res ^= num;
        }

        return res;
    }
};