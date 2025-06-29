class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Compute prefix XOR
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] ^ nums[i];
        }

        // Step 2: Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;

        // Step 3: Fill DP
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                for (int t = 0; t < i; ++t) {
                    if (dp[t][j - 1] != INT_MAX) {
                        int subXor = pre[i] ^ pre[t];
                        dp[i][j] = min(dp[i][j], max(dp[t][j - 1], subXor));
                    }
                }
            }
        }

        return dp[n][k];
    }
};


// https://leetcode.com/problems/partition-array-to-minimize-xor/
