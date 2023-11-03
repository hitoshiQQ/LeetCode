class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> grayString = generate(n);
        vector<int> res;

        for (auto j : grayString) {
            res.push_back(stoi(j, 0, 2));
        }
        return res;
    }

    vector<string> generate(int n) {

        if (n == 1) {
            return { "0","1" };
        }

        vector<string> res;
        vector<string> tmp = generate(n - 1);

        for (int j = 0; j < tmp.size(); ++j) {

            res.push_back("0" + tmp[j]);
        }
        for (int j = tmp.size() - 1; j >= 0; --j) {

            res.push_back("1" + tmp[j]);
        }

        return res;
    }
};