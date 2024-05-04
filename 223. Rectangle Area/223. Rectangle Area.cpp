class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
        int bx1, int by1, int bx2, int by2) {
        // Compute the area of the first rectangle: AreaA
        int area_a = (ax2 - ax1) * (ay2 - ay1);

        // Compute the area of the second rectangle: AreaB
        int area_b = (bx2 - bx1) * (by2 - by1);

        // Calculate the width of the overlapping area
        int overlap_width = std::min(ax2, bx2) - std::max(ax1, bx1);

        // Calculate the height of the overlapping area
        int overlap_height = std::min(ay2, by2) - std::max(ay1, by1);

        // Calculate the area of the overlapping region, guarding against no overlap scenario
        int overlap_area = std::max(overlap_height, 0) * std::max(overlap_width, 0);

        // Return the sum of both areas minus the overlapping area
        return area_a + area_b - overlap_area;
    }
};