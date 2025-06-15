/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue stores {node, index}
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = q.back().second;
            maxWidth = max(maxWidth, int(last - first + 1));

            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front(); q.pop();
                idx -= first; // prevent overflow by normalizing indices
                if (node->left) q.push({node->left, 2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
        }

        return maxWidth;
    }
};

// https://leetcode.com/problems/maximum-width-of-binary-tree/
