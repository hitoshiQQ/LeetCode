class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if (n == 0) st.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int j = 0; j < a.size(); ++j) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + j + 1, '(');
                        a.insert(a.begin() + j + 2, ')');
                        st.insert(a);
                        a.erase(a.begin() + j + 1, a.begin() + j + 3);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};