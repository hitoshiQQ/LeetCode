class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // Init the answer
        int count = 0;

        // Init 2 pointers defining the sliding window
        // J is the right pointers , I is left pointer
        // and product keeps the product of all elements
        for (int j = 0, i = 0, product = 1; j < nums.size(); ++j) {

            // Update product by multiplying
            product *= nums[j];

            // While product is equal to or larget than K
            // increment the left pointer to reduce the product
            while (i <= j && product >= k) {
                product /= nums[i++];
            }

            // Number of subarrays with a product less than K
            count += j - i + 1;
        }
        return count;
    }
};