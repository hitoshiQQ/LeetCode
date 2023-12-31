class Solution {
    void generateParenthesis(vector<char>& current, int open, int close, vector<string>& st) {
        if (open == 0 && close == 0) {
            st.push_back(string(current.begin(), current.end()));
            return;
        }
        if (open > 0) {
            current.push_back('(');
            generateParenthesis(current, open - 1, close + 1, st);
            current.pop_back();

        }
        if (close > 0) {
            current.push_back(')');
            generateParenthesis(current, open, close - 1, st);
            current.pop_back();
        }
    }

    double factorial(int n) {
        if (n == 0) {
            return 1;
        }
        else {
            return n * factorial(n - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        int st_size = round(factorial(2 * n) / factorial(n) / factorial(n) / (n + 1));
        vector<string> st;
        st.reserve(st_size);
        vector<char> current;
        generateParenthesis(current, n, 0, st);
        assert(st.size() == st_size);
        return st;
    }
};