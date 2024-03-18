class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        ranges::sort(points, [](const auto& a, const auto& b) {return a[1] < b[1]; });

        int res = 1;
        int arrow_X = points[0][1];

        for (int j = 1; j < (int)points.size(); ++j) {

            if (points[j][0] > arrow_X) {
                arrow_X = points[j][1];
                ++res;
            }
        }
        return res;
    }
};