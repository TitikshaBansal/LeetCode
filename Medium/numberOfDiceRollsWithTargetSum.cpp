class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0 with 0 dice
        
        for (int i = 1; i <= n; i++) {
            vector<int> new_dp(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k && j - face >= 0; face++) {
                    new_dp[j] = (new_dp[j] + dp[j - face]) % MOD;
                }
            }
            dp = new_dp;
        }
        
        return dp[target];
    }
};

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
