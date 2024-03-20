class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Init 2 pointers: one at the start and one at the end of the vector
        int left = 0;
        int right = numbers.size() - 1;

        // Loop until the condition is true, which is an indefinite loop here because we expcet to always find a solution
        while (true) {

            // Calculate the sum of the elements
            int sum = numbers[left] + numbers[right];

            // If the sum is equal to the target, return 2 pointers
            if (sum == target) {
                return { left + 1, right + 1 };
            }

            // If sum less than the target, move "left" pointer to the right to increase the sum
            if (sum < target) {
                left++;

            }
            else {
                // if sum greater than the target, move "right" pointer to the left to decrease the sum
                right--;
            }
        }
    }
};