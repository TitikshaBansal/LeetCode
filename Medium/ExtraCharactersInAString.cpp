class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};

// https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23
