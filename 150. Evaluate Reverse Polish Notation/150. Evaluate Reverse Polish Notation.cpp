class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> nums;
        for (int j = 0; j < tokens.size(); j++) {
            string s = tokens[j];

            if (isdigit(s[0]) || s.size() > 1) {
                nums.push(stoi(s));
                continue;
            }

            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();

            if (s == "+") {
                nums.push(a + b);

            }
            else if (s == "-") {
                nums.push(b - a);

            }
            else if (s == "*") {
                nums.push(a * b);

            }
            else {
                nums.push(b / a);
            }
        }
        return nums.top();
    }
};