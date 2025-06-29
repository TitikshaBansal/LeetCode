class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        unordered_set<string> seen;
        string curr = "";

        for (char c : s) {
            curr += c;

            if (!seen.count(curr)) {
                ans.push_back(curr);
                seen.insert(curr);
                curr = "";
            }
        }

        return ans;
    }
};


// https://leetcode.com/problems/partition-string/
