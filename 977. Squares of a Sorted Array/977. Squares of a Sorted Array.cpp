class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        int j = n - 1;

        for (int left = 0, right = n - 1; left <= right;) {
            if (abs(nums[left]) > abs(nums[right])) {

                res[j--] = nums[left] * nums[left++];
            }
            else {
                res[j--] = nums[right] * nums[right--];
            }
        }
        return res;
    }
};