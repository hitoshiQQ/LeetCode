class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> seen {nums.begin(), nums.end()};

        for (int num : nums) {
            if (seen.count(num - 1)) {
                continue;
            }

            int length = 1;
            while (seen.count(++num)) {
                ++length;
            }

            res = max(res, length);
        }
        return res;
    }
};