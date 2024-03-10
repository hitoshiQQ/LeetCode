class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int j = 0;
        int i = 0;

        while ((j < nums1.size()) && (i < nums2.size())) {
            if (nums1[j] < nums2[i]) {
                j++;

            }
            else if (nums1[j] > nums2[i]) {
                i++;

            }
            else {
                s.insert(nums1[j]);
                j++, i++;
            }
        }
        vector<int> res(s.begin(), s.end());
        return res;
    }
};