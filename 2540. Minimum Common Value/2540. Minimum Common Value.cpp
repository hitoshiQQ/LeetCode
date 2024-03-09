class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        for (int j = 0, i = 0; j < m && i < n;) {

            if (nums1[j] == nums2[i]) {
                return nums1[j];
            }

            if (nums1[j] < nums2[i]) {
                ++j
            }
            else {
                ++i;
            }
        }
        return -1;
    }
};