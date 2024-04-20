class Trie {
private:
    // Array representing the alphabet for trie nodes
    std::vector<Trie*> children;

    // Flag indicating end of word
    bool isEndOfWord;

    // Helper func to traverse the trie up to the end of the given prefix
    Trie* searchPrefix(const  std::string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            // Calculate the index of the child
            int index = c - 'a';

            // Not found prefix
            if (!node->children[index]) {
                return nullptr;
            }

            // Move to next node
            node = node->children[index];
        }
        return node;
    }

public:
    // Constructr init children vector and sets isEndOfWord to false for the root
    Trie() : children(26, nullptr), isEndOfWord(false) {}

    // Insert a word into the trie data structure
    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            int index = c - 'a';

            // If childe doesn't exist, create a new Trie node
            if (!node->children[index]) {
                node->children[index] = new Trie();
            }

            // Move to the next node
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie and return true if the word exist
    bool search(const string& word) {
        Trie* node = searchPrefix(word);

        // True if word found and it is an end of a word
        return node != nullptr && node->isEndOfWord;
    }

    // Check if there 
    bool startsWith(const string& prefix) {
        Trie* node = searchPrefix(prefix);

        // true is prefix found
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */