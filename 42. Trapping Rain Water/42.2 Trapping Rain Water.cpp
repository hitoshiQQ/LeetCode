// 2 pointer's method
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        if (n == 0) {
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;

        while (left < right) {
            if (height[left] > left_max) {
                left_max = height[left];
            }
            if (height[right] > right_max) {
                right_max = height[right];
            }
            if (left_max < right_max) {

                //use leftMax to substract because leftMax is min(leftMax, rightMax)
                res += max(0, left_max - height[left]);
                ++left;
            }
            else {
                res += max(0, right_max - height[right]);
                --right;
            }
        }
        return res;
    }
};