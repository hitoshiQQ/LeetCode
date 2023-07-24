class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int jump = 0;

        //while we cannot reach n-1
        while (end < n - 1) {
            int next_end = end;

            // calculate the farthest position we can jump from current range
            for (int j = start; j <= min(end, n - 1); ++j) {
                next_end = max(next_end, j + nums[j]);
            }

            //assume we just jump one position from last end
            start = end + 1;
            end = next_end;
            ++jump;
        }
        return jump;
    }
};