class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        // Find the max value in the array
        int maxValue = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        // This will store the final count of subarrays
        long long answer = 0;

        //Counts the number of max elements in the current subarray
        int countMax = 0;

        // pointer to extend the right boundary of the subarray
        int right = 0;

        // Iterate throught the array
        for (int j = 0; j < n; ++j) {

            // Extend the subarray until we either run out of elements || we have K instance of the max element
            while (right < n && countMax < k) {
                countMax += nums[right] == maxValue;
                ++right;
            }

            // If we have less than K
            if (countMax < k) {
                break;
            }

            // Add the number of possible subarrays that start with the current element
            answer += n - right + 1;

            // Prepare for the next iteration by decrementing the count if the current
            // element is the max value
            countMax -= nums[j] == maxValue;
        }
        return answer;
    }
};