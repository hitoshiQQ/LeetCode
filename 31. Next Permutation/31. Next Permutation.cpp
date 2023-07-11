class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        int temp;

        // select the minidx;
        // nums[minidx] > nums[j] and is the smallest among nums[j+1]
        for (int j = n - 2; j >= 0; --j) {
            if (nums[j] < nums[j + 1]) {
                int min_ind = j + 1;
                for (int i = j + 1; i < n; ++i) {
                    if (nums[i] > nums[j]) {
                        min_ind = (nums[j] < nums[min_ind]) ? i : min_ind;
                    }
                }

                //this wrong
                // auto it = min_element(nums.begin()+i+1, nums.end());
                swap(nums[j], nums[min_ind]);
                sort(nums.begin() + j + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};