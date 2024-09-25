class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        int count = 0;
    };
    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
                node->count++;
            }
        }
        int getPrefixScore(const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char c : word) {
                int index = c - 'a';
                node = node->children[index];
                score += node->count;
            }
            return score;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> ans;
        for (const string& word : words) {
            trie.insert(word);
        }
        for (const string& word : words) {
            ans.push_back(trie.getPrefixScore(word));
        }
        return ans;
    }
};

// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=daily-question&envId=2024-09-25
