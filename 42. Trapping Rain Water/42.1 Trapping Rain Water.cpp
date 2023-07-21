class Solution {
public:
    int trap(vector<int>& height) {

        int res = 0;
        int n = height.size();

        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);
        vector<int> rightMax(n);


        // let's pass an increasing cycle along the vector of values finding the left maximal boundary
        leftMax[0] = height[0];
        for (int j = 1; j < n; ++j) {
            leftMax[j] = max(leftMax[j - 1], height[j]);
        }

        // then let's run a decreasing cycle through the vector of values to find the right maximal boundary
        rightMax[n - 1] = height[n - 1];
        for (int j0 = n - 2; j >= 0; --j) {
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }

        // the minimum values are summarized in the answer
        for (int j = 1; j < n - 1; ++j) {
            res += min(leftMax[j], rightMax[j]) - height[j];
        }

        return res;
    };