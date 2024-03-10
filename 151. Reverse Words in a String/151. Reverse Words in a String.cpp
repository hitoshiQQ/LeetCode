class Solution {
public:
    string reverseWords(string s) {

        // Revers the whole string
        reverse(s.begin(), s.end());
        // Reveres each word
        reversWord(s, s.length());
        // clean-up spaces
        return cleanSpaces(s, s.length());
    }

private:
    void reversWord(string& s, int n) {

        int j = 0;
        int i = 0;

        while (j < n) {
            // skip spaces
            while (j < i || j < n && s[j] == ' ') {
                ++j;
            }
            // skip spaces
            while (i < j || i < n && s[i] != ' ') {
                ++i;
            }

            // Revers word
            reverse(s.begin() + j, s.begin() + i);
        }
    }

    string cleanSpaces(string& s, int n) {

        int j = 0;
        int i = 0;

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') {
                ++i;
            }

            // keep non spaces
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }

            // skip spaces
            while (i < n && s[i] == ' ') {
                ++i;
            }

            // keep only one space
            if (i < n) {
                s[j++] = ' ';
            }
        }
        return s.substr(0, j);
    }
};