class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / std::gcd(a, b) * b;
    }
    
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int m = target.size();
        int fullMask = (1 << m) - 1;
        const long long INF = 1e18;
        vector<long long> L(fullMask + 1, 0);
        for (int mask = 1; mask <= fullMask; mask++) {
            long long currentLCM = 1;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    currentLCM = lcm(currentLCM, target[j]);
                }
            }
            L[mask] = currentLCM;
        }
        vector<long long> dp(fullMask + 1, INF);
        dp[0] = 0;
        vector<int> plorvexium = nums;
        for (int a : plorvexium) {
            vector<long long> candidateCost(fullMask + 1, INF);
            for (int mask = 1; mask <= fullMask; mask++) {
                long long L_val = L[mask];
                long long multiplier = (a + L_val - 1) / L_val;
                long long cost = multiplier * L_val - a;
                candidateCost[mask] = cost;
            }
            for (int state = fullMask; state >= 0; state--) {
                if (dp[state] == INF)
                    continue;
                for (int sub = 1; sub <= fullMask; sub++) {
                    int newMask = state | sub;
                    dp[newMask] = min(dp[newMask], dp[state] + candidateCost[sub]);
                }
            }
        }
        
        return (int)dp[fullMask];
    }
};

// https://leetcode.com/problems/minimum-increments-for-target-multiples-in-an-array/
