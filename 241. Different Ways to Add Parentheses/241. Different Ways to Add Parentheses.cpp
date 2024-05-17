class Solution {
private:
    // Memorization map to store previously calc results for subexoressions
    unordered_map<string, vector<int>> memo;

    // Recursive func to compute all posible results from the input expression
    vector<int> dfs(const string& exp) {
        // If the result of this subexp is already computed, ret it
        if (memo.count(exp)) {
            return memo[exp];
        }

        // Result vector
        vector<int> res;

        // Check if the expression is a simple number
        if (isNumber(exp)) {
            res.push_back(stoi(exp));
            return res;
        }

        // Size
        int n = exp.size();

        // Itereate over each character of the expression
        for (int j = 0; j < n; ++j) {
            char c = exp[j];

            // Check the current character is an operator
            if (c == '-' || c == '+' || c == '*') {
                // Recursively solve subexpression to the left of the operator
                vector<int> left_res = dfs(exp.substr(0, j));

                // Recursively solve subexpression to the right of the operator
                vector<int> right_res = dfs(exp.substr(j + 1));

                // Combine the results from both subexpressions based on the operator
                for (int a : left_res) {
                    for (int b : right_res) {
                        if (c == '-') {
                            res.push_back(a - b);

                        }
                        else if (c == '+') {
                            res.push_back(a + b);

                        }
                        else {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        // Store the computed results in the memoization map before returning
        memo[exp] = res;
        return res;
    }

    // Helper func to determine if a given string is a nubmer
    bool isNumber(const string& str) {
        return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
};