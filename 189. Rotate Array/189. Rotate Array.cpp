class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Get the number of elements in the vector
        int numElements = nums.size();

        // Ensure K is within the bounds of the vectors size
        k %= numElements;

        // Reverse the entrie vector
        // This puts the last K in front
        reverse(nums.begin(), nums.end());

        // Reverse first K to restore their original order
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining to restore their original order
        reverse(nums.begin() + k, nums.end());
    }
};