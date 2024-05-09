class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        // Vector contain the final list of ranges in string format
        vector<string> ranges;

        // Lambda func that formates a ranges string based on the start and end inices
        auto formatRange = [&](int start, int end) {
            return start == end ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[end]);
        };

        // Total number of elements in the input vector
        int n = nums.size();

        // Iterate through all the numbers in the vector
        for (int startIndex = 0, endIndex; startIndex < n; startIndex = endIndex + 1) {
            // Init endIndex to be the same as startIndex
            endIndex = startIndex;

            // Continue to increment endIndex as long as cosecutive numbers  are sequential
            while (endIndex + 1 < n && nums[endIndex + 1] == nums[endIndex] + 1) {
                ++endIndex;
            }

            // Append the formatted range to the ranges resul vector
            ranges.emplace_back(formatRange(startIndex, endIndex));
        }
        return ranges;
    }
};