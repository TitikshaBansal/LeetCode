class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto arr : descriptions) {
            children.insert(arr[1]);
            if (nodes.find(arr[0]) == nodes.end()) {
                nodes[arr[0]] = new TreeNode(arr[0]);
            }
            if (nodes.find(arr[1]) == nodes.end()) {
                nodes[arr[1]] = new TreeNode(arr[1]);
            }
            if (arr[2] == 1) {
                nodes[arr[0]]->left = nodes[arr[1]];
            } else {
                nodes[arr[0]]->right = nodes[arr[1]];
            }
        }

        int root = -1;
        for (auto arr : descriptions) {
            if (children.find(arr[0]) == children.end()) {
                root = arr[0];
                break;
            }
        }

        return nodes[root];
    }
};
