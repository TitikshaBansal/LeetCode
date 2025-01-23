class ThroneInheritance {
private:
    string king;  // Store the name of the king
    unordered_map<string, vector<string>> familyTree;  // Adjacency list to store parent-child relationships
    unordered_set<string> deceased;  // Set to store names of deceased individuals

    // Helper function to perform DFS and construct the inheritance order
    void dfs(string current, vector<string>& order) {
        if (deceased.find(current) == deceased.end()) {
            order.push_back(current);  // Add current to order if they are not deceased
        }
        for (const string& child : familyTree[current]) {
            dfs(child, order);  // Recursive call for each child
        }
    }

public:
    // Constructor
    ThroneInheritance(string kingName) : king(kingName) {}

    // Add a child to the family tree
    void birth(string parentName, string childName) {
        familyTree[parentName].push_back(childName);
    }

    // Mark a person as deceased
    void death(string name) {
        deceased.insert(name);
    }

    // Get the current inheritance order
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);  // Start DFS from the king
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

// https://leetcode.com/problems/throne-inheritance/
