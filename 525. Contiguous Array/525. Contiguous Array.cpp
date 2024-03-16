class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int res = 0;
        int prefix = 0;
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int j = 0; j < nums.size(); ++j) {
            prefix += nums[j] ? 1 : -1;

            if (const auto iter = prefixToIndex.find(prefix); iter != prefixToIndex.cend()) {
                res = max(res, j - iter->second);
            }
            else {
                prefixToIndex[prefix] = j;
            }
        }
        return res;
    }
};