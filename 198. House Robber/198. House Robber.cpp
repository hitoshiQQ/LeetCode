class Solution {
public:
    int rob(vector<int>& nums) {

        // Init previous and before previous to store the max rob amounts
        int previous = 0;
        int beforePrevious = 0;

        // Loop through each house represented in the nums vector
        for (int num : nums) {

            // Temporarily hold the max amount robbed so far
            int temp = max(previous, beforePrevious);

            // Update beforePrevious to the new amount robbed includingthe current house
            beforePrevious = previous + num;

            // Update previous to the amount stored in temp
            previous = temp;
        }
        // Return the max amount that can be robbed without alerting the police
        return max(previous, beforePrevious);
    }
};