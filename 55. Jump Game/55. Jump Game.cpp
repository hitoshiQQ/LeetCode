// there is always exactly a line, between attainable and unattainable indices.
// from 0 indexes can jump to all places up to nums[0] (inclusive)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_ind = 0;
        int previous_max_ind = -1;

        // if it turns out to be the same as it was
        while (max_ind > previous_max_ind && max_ind < nums.size() - 1) {
            int curr_ind = max_ind;

            // Go from the previous maximum value to max_ind
            for (int j = previous_max_ind + 1; j <= max_ind; ++j) {

                // if better - change current max index(curr_ind)
                curr_ind = max(curr_ind, j + nums[j]);
            }



            previous_max_ind = max_ind;
            max_ind = curr_ind;
        }
        return max_ind >= nums.size() - 1;
    }
};