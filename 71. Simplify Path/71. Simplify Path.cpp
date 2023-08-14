class Solution {
public:
    string simplifyPath(string path) {

        stack<string> str;
        string res;


        for (int j = 0; j < path.size(); ++j) {

            // skip by condition
            if (path[j] == '/') {
                continue;
            }
            string tmp;

            // build a temporary string without characters
            while (j < path.size() && path[j] != '/') {
                tmp += path[j];
                ++j;
            }

            // skip by condition && double-period
            if (tmp == ".") {
                continue;
            }
            else if (tmp == "..") {
                if (!str.empty()) {
                    str.pop();
                }
            }
            else {
                str.push(tmp);
            }
        }

        while (!str.empty()) {
            res = "/" + str.top() + res;
            str.pop();
        }
        if (res.size() == 0)
            return "/";
        return res;
    }
};