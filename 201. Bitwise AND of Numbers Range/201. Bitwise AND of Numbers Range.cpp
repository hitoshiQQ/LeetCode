class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        // Loop until left is no longer less than right
        while (left < right) {

            // Idead is to remove the rightmost bit of 'right' to make it smaller
            // This helps move 'right' closer to 'right' without affecting the result of bitwice && of the range
            right = right & (right - 1);
        }
        return right;
    }
};