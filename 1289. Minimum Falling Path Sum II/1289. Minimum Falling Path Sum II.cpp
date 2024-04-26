class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        // Size of the grid
        int n = grid.size();

        // Using descriptive names for variables to indicate their usage
        // Stores the min sum of the first path
        int minFirstPathSum = 0;
        // Stores the min sum of the second best path
        int minSecondPathSum = 0;
        // Index of the col resulting in the min sum in the previous row
        int prevMinPathCol = -1;

        // Infinity substitue for init
        const int kInfinity = INT_MAX;

        // Iterate over each row in the input grid
        for (auto& row : grid) {
            // new min sum of 1 path
            int newMinFirstPathSum = kInfinity;
            // New min sum of 2 path
            int newMinSecondPathSum = kInfinity;
            // Col index for the new min sum
            int newMinPathCol = -1;

            // Iterate element in the current row
            for (int j = 0; j < n; ++j) {
                int currentSum = (prevMinPathCol != j ? minFirstPathSum : minSecondPathSum) + row[j];

                // If the current sum is less than the new min, update both the first and second best sums
                if (currentSum < newMinFirstPathSum) {
                    // Prev min becomes second best
                    newMinSecondPathSum = newMinFirstPathSum;
                    // Current sum becvomes the new min
                    newMinFirstPathSum = currentSum;
                    // Update the col index for new min
                    newMinPathCol = j;
                }
                else if (currentSum < newMinSecondPathSum) {
                    // Update the second best path sum if current less than it
                    newMinSecondPathSum = currentSum;
                }
            }

            // Update the path sums and the col index for the next row iteration
            minFirstPathSum = newMinFirstPathSum;
            minSecondPathSum = newMinSecondPathSum;
            prevMinPathCol = newMinPathCol;
        }
        return minFirstPathSum;
    }
};