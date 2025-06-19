#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getKey(const string& s) {
        if (s.length() <= 1) return "single";
        string key;
        for (int i = 1; i < s.length(); ++i) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            key += to_string(diff) + ",";
        }
        return key;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strings) {
            string key = getKey(s);
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            sort(group.begin(), group.end());  // Optional: sort inside each group
            result.push_back(group);
        }
        return result;
    }
};


// https://leetcode.ca/all/249.html
