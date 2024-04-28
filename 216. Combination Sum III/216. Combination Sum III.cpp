class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        // Result stores all the unique combinations
        vector<vector<int>> res;

        // Temp stores the current combination
        vector<int> temp;

        // Define DFS func to find combinations
        function<void(int, int)> dfs = [&](int start, int sum) {
            // If the remaining sum is zero and the current combination has K numbers, add to result
            if (sum == 0 && temp.size() == k) {
                res.emplace_back(temp);
                return;
            }

            // Prune the search space if the current number exceeds the needed sum,
            // or the size of the combination exceeds or if the current number is greater than 9
            if (start > 9 || start > sum || temp.size() >= k) {
                return;
            }

            // Included the current number and move to the next number
            temp.emplace_back(start);
            dfs(start + 1, sum - start);

            // Exclude the current number and move to the next number
            temp.pop_back();
            dfs(start + 1, sum);
        };
        // Begin DFS with number 1 and target sum N
        dfs(1, n);
        return res;
    }
};