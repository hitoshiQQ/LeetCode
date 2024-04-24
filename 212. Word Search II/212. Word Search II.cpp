class Trie {
public:
    // Vector holding pointers to child Trie nodes
    vector<Trie*> children;

    // Stores the index of the word in the 'words' vector if the end of a word is reached
    int wordIndex;

    // Constructor: init Trie node
    Trie()
        : children(26, nullptr), wordIndex(-1) {}

    // Inserts a word into the Trie with a reference index
    void insert(const string& word, int index) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->wordIndex = index;
    }
};

class Solution {
public:
    // Func to find words on the board given a list of words
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trieRoot = new Trie();
        // Construct trie from words list
        for (int j = 0; j < words.size(); ++j) {
            trieRoot->insert(words[j], j);
        }
        vector<string> foundWords;
        int rows = board.size();
        int cols = board[0].size();

        // DFS search in the board starting from (j, i) pos
        function<void(Trie*, int, int)> dfs = [&](Trie* node, int j, int i) {
            int charIndex = board[j][i] - 'a';

            // Early return if no child exists for the current character
            if (!node->children[charIndex]) {
                return;
            }

            node = node->children[charIndex];

            // Avoid duplicate entries in the results
            if (node->wordIndex != -1) {
                foundWords.emplace_back(words[node->wordIndex]);
                node->wordIndex = -1;
            }
            // Up, Right, Down, Left
            int directions[5] = { -1, 0, 1, 0, -1 };

            // Save current character
            char tempChar = board[j][i];

            // Mark current cell as visited
            board[j][i] = '#';

            // Explore neighbors
            for (int q = 0; q < 4; ++q) {
                int x = j + directions[q];
                int y = i + directions[q + 1];
                if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] != '#') {
                    dfs(node, x, y);
                }
            }
            // Reset the current cell to its original value
            board[j][i] = tempChar;
        };
        // Start dfs from every cell in the board
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                dfs(trieRoot, j, i);
            }
        }
        return foundWords;
    }
};