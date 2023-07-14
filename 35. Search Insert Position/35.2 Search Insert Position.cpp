/*
Binary search O(log n) time, O(1) memory.

Ask n questions can answer yes || no - nums[j] -> target
Asking n questions - all answers are 2^elem;
2^n >= elem +1
Taking two bounds where right = elem, left = -1;
while(right - left > 1).
*/

// acceliration
const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // we are not going to change the array, we can take a constant reference
    size_t searchInsert(const vector<int>& nums, int target) {
        size_t left = (size_t)0 - 1;
        size_t right = nums.size();

        while (right - left > 1) {
            size_t mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};