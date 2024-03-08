class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        constexpr int k_max = 100;
        vector<int> count(k_max + 1);

        for (const int num : nums) {
            ++count[num];
        }

        const int max_frequency = ranges::max(count);
        return ranges::count(count, max_frequency) * max_frequency;
    }
};