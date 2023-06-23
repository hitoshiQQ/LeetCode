class Solution {
public:
    bool check(char a, char b) {
        return ((a == '{' && b == '}' || a == '(' && b == ')' || a == '[' && b == ']'));
    }

    bool isValid(string s) {
        stack<char> st;

        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
                st.push(s[j]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (check(st.top(), s[j])) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};