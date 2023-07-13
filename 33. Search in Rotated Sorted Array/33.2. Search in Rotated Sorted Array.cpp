/*
 Analogous to binary search.

If repeats are possible :
[2,2,2,....,2,2,2] ->
[2,2,2,2,2,2,2] || [2,2,2,3,2,2,2] || [2,2,2,0,2,2,2]

Inequality of the first and last elements.
 [4,5,6,7,0,1,2] target = 0; choose a value from the middle -> [4..in ascending order .7...2]
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int left = 0;
        int right = nums.size();

        // target can be in [left && right]
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            assert(mid != left && mid != right);

            int sort_left, sort_right, _left, _right;
            if (nums[left] < nums[mid]) {
                sort_left = left;
                sort_right = mid;

                // for the second range 
                _left = mid;
                _right = right;
            }
            else {
                sort_left = mid;
                sort_right = right;

                // for the second range
                _left = left;
                _right = mid;
            }
            if (nums[sort_left] <= target && target <= nums[sort_right - 1]) {
                left = sort_left;
                right = sort_right;
            }
            else {
                left = _left;
                right = _right;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        else {
            return -1;
        }
    }
};