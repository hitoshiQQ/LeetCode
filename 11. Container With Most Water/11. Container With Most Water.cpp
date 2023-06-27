class Solution {
public:
    int maxArea(vector<int>& h) {
        int start = 0;
        int end = h.size() - 1;
        int area;
        int max_area = 0;

        while (start < end) {
            area = min(h[start], h[end]) * (end - start);
            if (area > max_area) {
                max_area = area;
            }
            if (min(h[start], h[end]) == h[start]) {
                start++;
            }
            else {
                end--;
            }
        }
        return max_area;
    }
};