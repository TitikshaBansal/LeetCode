class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1]; // sort by endDay
        });

        int n = events.size();
        // dp[i][j]: max value using first i events, attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Build an array of just end times for binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = events[i][1];
        }

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int value = events[i - 1][2];

            // Binary search to find the last event that ends before start
            int l = 0, r = i - 1;
            int prev = 0;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][1] < start)
                    l = mid + 1;
                else
                    r = mid;
            }
            if (events[l][1] < start) prev = l + 1;
            else prev = l;

            for (int j = 1; j <= k; ++j) {
                // skip event or take event i-1
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value);
            }
        }

        return dp[n][k];
    }
};

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/?envType=daily-question&envId=2025-07-08
