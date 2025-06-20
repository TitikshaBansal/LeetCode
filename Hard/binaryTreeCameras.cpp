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
    int cameras = 0;
    // 0 -> has camera
    // 1 -> covered
    // 2 -> needs camera
    int dfs(TreeNode* root) {
        if (!root) return 1;  // Null nodes are covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 2 || right == 2) {
            cameras++;
            return 0;  // Place camera at this node
        }

        if (left == 0 || right == 0) {
            return 1;  // This node is covered
        }

        return 2;  // This node needs a camera
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 2) cameras++;  // If root still needs camera
        return cameras;
    }
};

// https://leetcode.com/problems/binary-tree-cameras/
