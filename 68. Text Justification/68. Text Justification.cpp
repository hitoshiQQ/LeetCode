class Solution {
public:
    vector<string> fullJustify(vector<string>& words, size_t maxWidth) {
        vector<string> res;
        vector<string> row;
        size_t rowLetters = 0;

        for (const string& word : words) {

            // If we put the word in this row, it'll exceed the maxWidth,
            // So we cannot put the word to this row and have to pad spaces to

            if (rowLetters + row.size() + word.length() > maxWidth) {
                const int spaces = maxWidth - rowLetters;

                if (row.size() == 1) {

                    // Pad all spaces after row[0]
                    for (int i = 0; i < spaces; ++i)
                        row[0] += " ";
                }
                else {

                    // Evenly pad spaces to each word (expect the last one) in this row
                    for (int j = 0; j < spaces; ++j)
                        row[j % (row.size() - 1)] += " ";
                }
                res.push_back(join(row, ""));
                row.clear();
                rowLetters = 0;
            }
            row.push_back(word);
            rowLetters += word.length();
        }
        res.push_back(ljust(join(row, " "), maxWidth));

        return res;
    }

private:
    string join(const vector<string>& words, const string& s) {
        string join;
        for (int j = 0; j < words.size(); ++j) {
            join += words[j];
            if (j != words.size() - 1)
                join += s;
        }
        return join;
    }

    string ljust(string s, int width) {
        for (int j = 0; j < s.length() - width; ++j)
            s += " ";
        return s;
    }
};