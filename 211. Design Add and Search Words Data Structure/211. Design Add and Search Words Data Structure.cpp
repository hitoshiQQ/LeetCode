class TrieNode {
public:
    // Children nodes for each character
    vector<TrieNode*> children;

    // Flag to check if a node represents the end of a word
    bool isWordEnd;

    // Constructor: init children pointers to nullptr and isWordEnd is false
    TrieNode() : children(26, nullptr), isWordEnd(false) {

    }

    void insert(const string& word) {
        TrieNode* current = this;
        for (char ch : word) {
            // Calculate the index of the characte 'a' to 'z'
            int index = ch - 'a';

            // If there isn't TrieNode at index, create a new one
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode;
            }
            // move to the next node
            current = current->children[index];
        }
        // Mark the end of the word
        current->isWordEnd = true;
    }
};

class WordDictionary {
private:
    // Root node of the Tree
    TrieNode* root;

    // DFS Search
    bool dfsSearch(const string& word, int index, TrieNode* node) {

        // If end of word is reached, return true if current node isWordEnd
        if (index == word.size()) {
            return node->isWordEnd;
        }

        // Get the character at the current index
        char ch = word[index];

        // If the character isn't a wildcard
        if (ch != '.') {
            TrieNode* child = node->children[ch - 'a'];

            // Recurse for the next index if child isn't null
            if (child && dfsSearch(word, index + 1, child)) {
                return true;
            }

        }
        else {
            // if the character is a wildcard, check all possible nodes
            for (TrieNode* child : node->children) {
                // Recurse with each existing child node and move to the next index
                if (child && dfsSearch(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Constructor: init the root node
    WordDictionary() : root(new TrieNode()) {

    }

    // Public method to add a word to the Tree
    void addWord(string word) {

        root->insert(word);
    }

    // Public method to search for a word in the Tree
    bool search(string word) {

        return dfsSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */