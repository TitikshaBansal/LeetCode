class Solution {
public:
    int countSpecialNumbers(int n) {
        string num = to_string(n);
        int len = num.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(1024, vector<int>(2, -1))); // dp[pos][mask][tight]

        function<int(int, int, bool)> dfs = [&](int pos, int mask, bool tight) -> int {
            if (pos == len) return mask == 0 ? 0 : 1; // no leading zero-only numbers

            if (dp[pos][mask][tight] != -1) return dp[pos][mask][tight];

            int res = 0;
            int limit = tight ? num[pos] - '0' : 9;

            for (int d = 0; d <= limit; ++d) {
                bool isUsed = mask & (1 << d);
                if (isUsed) continue;
                if (mask == 0 && d == 0) {
                    // leading zero allowed
                    res += dfs(pos + 1, 0, tight && (d == limit));
                } else {
                    res += dfs(pos + 1, mask | (1 << d), tight && (d == limit));
                }
            }

            return dp[pos][mask][tight] = res;
        };

        return dfs(0, 0, true);
    }
};

// https://leetcode.com/problems/count-special-integers/
