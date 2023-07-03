// acceleration
const int ZERO = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    void generateParenthesis(vector<char>& current, int open, int close, vector<string>& st) {
        if (open == 0 && close == 0) {
            st.push_back(string(current.begin(), current.end()));
            return;
        }
        
        // the number of how many brackets to open
        if (open > 0) {
            current.push_back('(');
            generateParenthesis(current, open - 1, close + 1, st);
            current.pop_back();
        }
        
        // the number of how many parentheses to close
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
        
        // acceleration due to memory redundancy
        st.reserve(st_size);
        vector<char> current;
        generateParenthesis(current, n, 0, st);
        assert(st.size() == st_size);
        return st;
    }
};
