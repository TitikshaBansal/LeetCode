class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo; 
        return dfs(price, special, needs, memo);
    }
private:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        string key;
        for (int n : needs) {
            key += to_string(n) + ",";
        }
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += needs[i] * price[i];
        }
        for (const vector<int>& s : special) {
            vector<int> clone = needs;
            int j = 0;
            for (; j < needs.size(); j++) {
                int diff = clone[j] - s[j];
                if (diff < 0) {
                    break; 
                }
                clone[j] = diff;
            }
            if (j == needs.size()) { 
                sum = min(sum, s[j] + dfs(price, special, clone, memo));
            }
        }
        return memo[key] = sum;
    }
};

// https://leetcode.com/problems/shopping-offers/
