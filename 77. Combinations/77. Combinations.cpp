class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(n, k, 1, {}, res);
        return res;
    }

private:
    void dfs(int n, int k, int s, vector<int>&& path, vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int j = s; j <= n; ++j) {
            path.push_back(j);
            dfs(n, k, j + 1, move(path), res);
            path.pop_back();
        }
    }
};