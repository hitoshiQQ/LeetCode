class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        // Variable to store the list of farmlands found
        vector<vector<int>> farmlands;

        // Number of row/columns in the input matrix
        int rows = land.size();
        int cols = land[0].size();

        // Loop through each cell in the matrix
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                // Skip the cell if isn't part of farmland or if it is already part of an identified farmland
                if (land[j][i] == 0 || (i > 0 && land[j][i - 1] == 1) || (j > 0 && land[j - 1][i] == 1)) {
                    continue;
                }

                // Init the top-left corner of the current farmland
                int topLeftX = j;
                int topLeftY = i;
                int bottomRightX = j;
                int bottomRightY = i;

                // Expand in the downward direction
                while (bottomRightX + 1 < rows && land[bottomRightX + 1][i] == 1) {
                    bottomRightX++;
                }

                // Expand in the rightward direction
                while (bottomRightY + 1 < cols && land[bottomRightX][bottomRightY + 1] == 1) {
                    bottomRightY++;
                }


                // Store the coord of the current farmland
                farmlands.push_back({ topLeftX, topLeftY, bottomRightX, bottomRightY });
            }
        }
        return farmlands;
    }
};