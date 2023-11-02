class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m - 1;      // nums1's index (actual nums)
        int i = n - 1;      // nums2's index
        int k = m + n - 1;  // nums1's index (next filled position)

        while (i >= 0)
            if (j >= 0 && nums1[j] > nums2[i]) {
                nums1[k--] = nums1[j--];

            }
            else {
                nums1[k--] = nums2[i--];
            }
    }
};