class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // Init the counter for beatiful subsets to -1
        int countBeautifulSubsets = -1;
        // Array to keep track of the frequency of each number
        int countNums[1010]{};
        // Store the size of the input vector 'nums'
        int size = nums.size();

        // Define a recursive lambda func to perform dfs for beatiful subsets
        function<void(int)> dfs = [&](int index) {
            // BASE CASE: if the end of the array is reached, increment the count of b. subsets
            if (index >= size) {
                ++countBeautifulSubsets;
                return;
            }

            // Recursive call to continue without including the current number
            dfs(index + 1);

            // Check if the number is considered b. in the context of the subset being formed
            bool isBIncrement = nums[index] + k >= 1010 || countNums[nums[index] + k] == 0;
            bool isBDecrement = nums[index] - k < 0 || countNums[nums[index] - k] == 0;

            // If both conditions are true, the number can be included in the subset
            if (isBIncrement && isBDecrement) {
                ++countNums[nums[index]];
                dfs(index + 1);
                --countNums[nums[index]];
            }
        };

        dfs(0);
        return countBeautifulSubsets;
    }
};