class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int res = 0;
        vector<int> hist(matrix[0].size());

        for (const vector<char>& row : matrix) {
            for (int j = 0; j < row.size(); ++j)
                hist[j] = row[j] == '0' ? 0 : hist[j] + 1;
            res = max(res, largestRectangleArea(hist));
        }

        return res;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
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