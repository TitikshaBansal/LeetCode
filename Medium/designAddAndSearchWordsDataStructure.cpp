class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode() : isEnd(false) {}
    };

    TrieNode* root;

    bool searchInNode(const string& word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];
        if (ch == '.') {
            // Check all children
            for (auto& [key, childNode] : node->children) {
                if (searchInNode(word, childNode, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            // Check the specific character
            if (node->children.find(ch) != node->children.end()) {
                return searchInNode(word, node->children[ch], index + 1);
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


// https://leetcode.com/problems/design-add-and-search-words-data-structure/
