class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stack;

        for (int j = 0; j <= heights.size(); ++j) {
            while (!stack.empty() &&
                (j == heights.size() || heights[stack.top()] > heights[j])) {
                const int h = heights[stack.top()];
                stack.pop();
                const int w = stack.empty() ? j : j - stack.top() - 1;
                res = max(res, h * w);
            }
            stack.push(j);
        }
        return res;
    }
};