class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));

        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                ans = max(ans, dp[i][mod]);
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/?envType=daily-question&envId=2025-07-17
