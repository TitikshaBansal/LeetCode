class Solution {
public:
    const int MOD = 1e9 + 7;

    bool isValid(const vector<int>& col) {
        for (int i = 1; i < col.size(); ++i) {
            if (col[i] == col[i - 1]) return false;
        }
        return true;
    }

    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        vector<vector<int>> states;

        int total = pow(3, m);
        for (int mask = 0; mask < total; ++mask) {
            vector<int> col(m);
            int temp = mask;
            for (int i = 0; i < m; ++i) {
                col[i] = temp % 3;
                temp /= 3;
            }
            if (isValid(col)) {
                states.push_back(col);
            }
        }

        int sz = states.size();

        vector<vector<int>> compat(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (isCompatible(states[i], states[j])) {
                    compat[i].push_back(j);
                }
            }
        }

        vector<int> dp(sz, 1); // for column 0
        for (int col = 1; col < n; ++col) {
            vector<int> new_dp(sz, 0);
            for (int i = 0; i < sz; ++i) {
                for (int j : compat[i]) {
                    new_dp[i] = (new_dp[i] + dp[j]) % MOD;
                }
            }
            dp = new_dp;
        }

        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }

        return result;
    }
};

// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/?envType=daily-question&envId=2025-05-18
