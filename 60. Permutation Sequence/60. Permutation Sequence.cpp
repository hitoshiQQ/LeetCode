class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";

        // fill the vector with increasing values 
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        int factorial = 1;
        for (int j = 1; j <= n; ++j) {
            factorial *= j;
        }
        --k;

        // there could be (n-1)! permutations 
        // if we exclude one char
        for (int j = 0; j < n; ++j) {
            factorial /= (n - j);

            // the [j] permutation belongs to what group
            int group = k / factorial;
            res += (nums[group] + '0');
            nums.erase(nums.begin() + group);


            // there are "group" groups before the visited group
            k -= factorial * group;
        }
        return res;
    }
};