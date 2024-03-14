class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // find all subarray prefix sum
        // in two sum, we use unordered_map to recored every appeared num
        int res = 0;
        int current = 0;

        unordered_map<int, int> map;
        for (int j = 0; j < nums.size(); j++) {
            current += nums[j];

            if (map.find(current - goal) != map.end()) {
                res += map[current - goal];
            }

            if (current == goal) {
                res++;
            }
            map[current]++;
        }
        return res;
    }
};