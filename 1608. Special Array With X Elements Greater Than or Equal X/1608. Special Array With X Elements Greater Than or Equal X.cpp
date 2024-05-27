class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Calc the size of the array
        int size = nums.size();

        // Sort the array in non-decreasing oreder
        sort(nums.begin(), nums.end());

        // Iterate for each potential special value 'j' starting from 1 to size of array
        for (int j = 0; j <= size; ++j) {
            // Calc the count of numbers greater than or equal to 'j' using lower_bound 
            // which returns an iterator to the first element that isn't less than 'j'
            int count = size - (lower_bound(nums.begin(), nums.end(), j) - nums.begin());

            // If the number of elements greater than or equal to 'j'  is exactly 'j',
            // Then we found the specical value 'j' and return it
            if (count == j) {
                return j;
            }
        }
        return -1;
    }
};