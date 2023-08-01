// sorting intervals by potential association 
// sorting by left boundary (minimum value of the left boundary) - if not merged with index j , then j + n (n >= 1) will definitely not merge
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.reserve(intervals.size());

        res.push_back(move(intervals[0]));
        for (int j = 1; j < intervals.size(); ++j) {

            // intersection search
            if (res.back()[1] >= intervals[j][0]) {

                // replace one of the bounds by the maximum
                res.back()[1] = max(res.back()[1], intervals[j][1]);
            }
            else {

                // new segment
                res.push_back(move(intervals[j]));
            }
        }
        return res;
    }
};