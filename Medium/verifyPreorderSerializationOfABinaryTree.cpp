class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; 
        vector<string> nodes;
        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }

        for (const string& node : nodes) {
            slots--; 
            if (slots < 0) return false;
            if (node != "#") slots += 2;
        }

        return slots == 0;
    }
};

// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
