class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int r = nums1.size();
        int l = nums2.size();

        if (r > l) {
            swap(nums1, nums2);
            swap(r, l);
        }

        int start = 0;
        int end = r;

        while (start <= end) {

            int x_middle = (start + end) / 2;
            int y_middle = (r + l + 1) / 2 - x_middle;

            if (x_middle < r && y_middle > 0 && nums2[y_middle - 1] > nums1[x_middle]) {
                start = x_middle + 1;

            }
            else if (x_middle > 0 && y_middle < l && nums1[x_middle - 1] > nums2[y_middle]) {
                end = x_middle - 1;

            }
            else {
                int maxL = max(x_middle > 0 ? nums1[x_middle - 1] : INT_MIN,
                    y_middle > 0 ? nums2[y_middle - 1] : INT_MIN);

                if ((r + l) % 2 == 1) {
                    return maxL;
                }

                int minR = min(x_middle < r ? nums1[x_middle] : INT_MAX,
                    y_middle < l ? nums2[y_middle] : INT_MAX);

                return (maxL + minR) / 2.0;
            }
        }
        return 0.0;
    }
};