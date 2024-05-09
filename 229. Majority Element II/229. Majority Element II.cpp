class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Init counters for two potential majority elements
        int count1 = 0;
        int count2 = 0;

        // Init holders for two potential majority elements
        int candidate1 = 0;
        int candidate2 = 0;

        // Use Boyer-Moore Voting Algo to find potential majority elements
        for (int num : nums) {
            // If the current element is the same as candidate1, increment count1
            if (num == candidate1) {
                ++count1;

                // If the current element is the same as candidate2, increment count2
            }
            else if (num == candidate2) {
                ++count2;
                // If   count1 is zero, replace candidate1 with the current element and reset count1
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
                // If count2 is zero, replace candidate2 with the current element and reset count2
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
                // If the current element isn't equal to either candidate and both counts are non-zero, decrement both counts
            }
            else {
                --count1;
                --count2;
            }
        }

        // Init an empty result vector
        vector<int> res;

        // Check if the candidates are indeed majority elements
        if (count(nums.begin(), nums.end(), candidate1) > nums.size() / 3) {
            // If candidate1 occurrence is more than a third of the array length
            // Add to the result
            res.push_back(candidate1);
        }

        // If candidate2 is different from candidate1 and occurs more than a third of the array length
        // add to the result, check candidate1 != candidate2 to avoid counting the same element
        // twice in case of duplicates
        if (candidate1 != candidate2 && count(nums.begin(), nums.end(), candidate2) > nums.size() / 3) {
            res.push_back(candidate2);
        }
        return res;
    }
};