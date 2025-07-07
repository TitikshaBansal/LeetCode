class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        const int MOD = 1e9 + 7;

        dp[n - 1][n - 1] = {0, 1};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X') continue;

                for (auto [di, dj] : vector<pair<int, int>>{{1, 0}, {0, 1}, {1, 1}}) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= n || nj >= n || board[ni][nj] == 'X') continue;

                    int val = dp[ni][nj].first;
                    int cnt = dp[ni][nj].second;

                    if (cnt == 0) continue;

                    int curVal = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : board[i][j] - '0';

                    if (val + curVal > dp[i][j].first) {
                        dp[i][j] = {val + curVal, cnt};
                    } else if (val + curVal == dp[i][j].first) {
                        dp[i][j].second = (dp[i][j].second + cnt) % MOD;
                    }
                }
            }
        }

        return {dp[0][0].first, dp[0][0].second};
    }
};

// https://leetcode.com/problems/number-of-paths-with-max-score/
