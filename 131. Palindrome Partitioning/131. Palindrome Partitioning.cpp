class Solution {
public:
    vector<vector<string>> partition(const string& s) {
        // [first] list of lasts where string is palindrome
        vector<vector<int>> lasts(s.size());
        for (int first = (int)s.size() - 1; first >= 0; first--) {
            lasts[first].push_back(first);

            if (first < (int)s.size() - 1 && s[first + 1] == s[first]) {
                lasts[first].push_back(first + 1);
            }
            if (first > 0) {
                for (int last : lasts[first]) {
                    if (last + 1 < (int)s.size() && s[first - 1] == s[last + 1]) {
                        lasts[first - 1].push_back(last + 1);
                    }
                }
            }
        }
        vector<vector<string>> res;
        vector<string_view> curr;
        generate(s, lasts, 0, curr, res);
        return res;
    }

private:
    void generate(const string& s, const vector<vector<int>>& lasts,
        const int first, vector<string_view>& curr,
        vector<vector<string>>& res) {

        if (first == (int)s.size()) {
            res.emplace_back(curr.begin(), curr.end());
            return;
        }

        for (int last : lasts[first]) {
            curr.emplace_back(&s[first], last - first + 1);
            generate(s, lasts, last + 1, curr, res);
            curr.pop_back();
        }

    }

};