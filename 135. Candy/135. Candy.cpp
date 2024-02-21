class Solution {
public:
    int candy(vector<int>& ratings) {

        const int n = ratings.size();
        int res = 0;
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // Left rat
        for (int j = 1; j < n; ++j) {
            if (ratings[j] > ratings[j - 1]) {
                left[j] = left[j - 1] + 1;
            }
        }

        // Right rat
        for (int j = n - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                right[j] = right[j + 1] + 1;
            }
        }

        for (int j = 0; j < n; ++j) {
            res += max(left[j], right[j]);
        }

        return res;
    }
};