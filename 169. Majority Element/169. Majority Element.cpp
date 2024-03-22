class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Counter for the number of times the current candidate is found
        int count = 0;
        // Variable to store the current potentaial majority elemet
        int candidate = 0;

        // Ieterate throught all the elements in the given array
        for (int num : nums) {

            if (count == 0) {
                // If count is zero, select the current element as our new candidate
                candidate = num;
                count = 1;

            }
            else {
                // If count isn't zero, increment or decrement the count
                // Inc if current element is the same as the candidate
                // Dec if it is different
                count += (candidate == num) ? 1 : -1;
            }
        }
        return candidate;
    }
};