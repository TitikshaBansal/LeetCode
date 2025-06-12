class Solution {
public:
    pair<TreeNode*, TreeNode*> find(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current) {
            if (current->val == key)
                return { parent, current };
            parent = current;
            current = (key < current->val) ? current->left : current->right;
        }
        return { nullptr, nullptr };
    }

    void replaceChild(TreeNode* parent, TreeNode* oldChild, TreeNode* newChild) {
        if (!parent) return;
        if (parent->left == oldChild) parent->left = newChild;
        else if (parent->right == oldChild) parent->right = newChild;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        auto [parent, nodeToDelete] = find(root, key);
        if (!nodeToDelete) return root;

        // Case 1: No children or one child
        if (!nodeToDelete->left || !nodeToDelete->right) {
            TreeNode* child = nodeToDelete->left ? nodeToDelete->left : nodeToDelete->right;
            if (!parent) {
                // Deleting root
                delete nodeToDelete;
                return child;
            }
            replaceChild(parent, nodeToDelete, child);
            delete nodeToDelete;
            return root;
        }

        // Case 2: Two children — find inorder successor
        TreeNode* sucParent = nodeToDelete;
        TreeNode* successor = nodeToDelete->right;
        while (successor->left) {
            sucParent = successor;
            successor = successor->left;
        }

        // Copy successor's value to the node we want to delete
        nodeToDelete->val = successor->val;

        // Delete successor node
        TreeNode* sucChild = successor->right;  // successor can't have left child
        replaceChild(sucParent, successor, sucChild);
        delete successor;

        return root;
    }
};

// https://leetcode.com/problems/delete-node-in-a-bst/
