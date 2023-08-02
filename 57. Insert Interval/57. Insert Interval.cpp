/* find the first and last interval index to merge(j,i) and merge them
by creating a new interval with (min(firstInterval.start, newInterval.start), max(lastInterval.end, newInterva.end),
and adding other intervals that is not merged

 collect the intervals strictly left or right of the new interval,
 then merge the new one with the middle ones before inserting it between left and right ones
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int curr = 0;
        int n = intervals.size();

        // no intersection - for smaller
        while (curr < n && intervals[curr][1] < newInterval[0]) {
            res.push_back(intervals[curr]);
            ++curr;
        }

        // have intersection
        int start = newInterval[0];
        int end = newInterval[1];
        while (curr < n && intervals[curr][0] <= end) {
            start = min(intervals[curr][0], start);
            end = max(intervals[curr][1], end);
            ++curr;
        }
        res.push_back({ start,end });

        while (curr < n) {
            res.push_back(intervals[curr]);
            ++curr;
        }
        return res;
    }
};