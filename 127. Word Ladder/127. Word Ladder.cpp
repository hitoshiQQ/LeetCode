class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (!word_set.count(endWord)) {
            return 0;
        }

        int res = 0;
        queue<string> q {{beginWord}};

        while (!q.empty()) {
            ++res;
            for (int sz = q.size(); sz > 0; --sz) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.length(); ++j) {
                    const char cache = word[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (word == endWord) {
                            return res + 1;
                        }

                        if (word_set.count(word)) {
                            q.push(word);
                            word_set.erase(word);
                        }
                    }
                    word[j] = cache;
                }
            }
        }
        return 0;
    }
};