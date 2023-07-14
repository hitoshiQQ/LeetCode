/*
 binary search.
[5,7,7,7,8,8,8,10] - let's look at "8" start index is 3, end index is 4.

If our number is not in the array, return [-1,-1].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {

                // mid can be any found element
                int j = mid;
                while (j >= 0 && nums[j] == target) {
                    --j;
                }
                res.push_back(++j);

                j = mid;
                while (j < nums.size() && nums[j] == target) {
                    ++j;
                }
                res.push_back(--j);

                break;
            }
        }
        if (res.empty()) {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};