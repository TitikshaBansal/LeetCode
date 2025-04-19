class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lower - nums[i];
            int right = upper - nums[i];
            
            // Find range of valid nums[j] for j > i
            int low = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();

            ans += (high - low);
        }

        return ans;
    }
};

// https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2025-04-19
