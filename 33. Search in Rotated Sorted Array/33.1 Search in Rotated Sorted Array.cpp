/*
 Analogous to binary search.

If repeats are possible :
[2,2,2,....,2,2,2] ->
[2,2,2,2,2,2,2] || [2,2,2,3,2,2,2] || [2,2,2,0,2,2,2]

Inequality of the first and last elements.
 [4,5,6,7,0,1,2] target = 0; choose a value from the middle -> [4..in ascending order .7...2]
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        // The element sought is strictly between the boundaries, not inclusive
        if (nums[0] == target) {
            return 0;
        }
        if (nums.size() == 1) {
            return -1;
        }
        if (nums.back() == target) {
            return (int)nums.size() - 1;
        }


        int left = 0;
        int right = (int)nums.size() - 1;
        while (left + 1 < right) {

            // mid is never unequal to left or right
            int mid = (left + right) / 2;
            assert(mid != left && mid != right);

            // for sorted half
            if (nums[left] < nums[right]) {
                if (target < nums[left] || target > nums[right]) {
                    return -1;
                }

                // exclusionary options  
                assert(nums[left] < target && target < nums[right]);
                if (target < nums[mid]) {
                    right = mid;
                }
                else if (target > nums[mid]) {
                    left = mid;
                }
                else {
                    return mid;
                }
            }
            else {
                if (target == nums[mid]) {
                    return mid;
                }

                // for sorted && shifted
                assert(nums[left] > nums[right]);


                if (nums[left] < nums[mid]) {
                    // left-half sorted
                    if (nums[left] < target && target < nums[mid]) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
                else {
                    assert(nums[mid] < nums[right]);
                    // right-half sorted
                    if (nums[mid] < target && target < nums[right]) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
            }
        }
        return -1;
    }
};