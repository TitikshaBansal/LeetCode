class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        if (node->right) {
            pushLeft(node->right); 
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


// https://leetcode.com/problems/binary-search-tree-iterator/
