class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, F = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F += i * nums[i];
        }

        long long maxF = F;
        for (int k = 1; k < n; ++k) {
            F = F + sum - n * nums[n - k];
            maxF = max(maxF, F);
        }

        return maxF;
    }
};

// https://leetcode.com/problems/rotate-function/
