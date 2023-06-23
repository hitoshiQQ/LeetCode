class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        int N = nums.size(), L = 0, R = N - 1;
        for (int j = 0; j < N; ++j) {
            vec.push_back({ nums[j],j });
        }
        sort(begin(vec), end(vec));
        while (L < R) {
            int sum = vec[L][0] + vec[R][0];
            if (sum == target) {
                return { vec[L][1],vec[R][1] };
            }
            if (sum < target) {
                ++L;
            }
            else {
                --R;
            }
        }
        return {};
    }
};