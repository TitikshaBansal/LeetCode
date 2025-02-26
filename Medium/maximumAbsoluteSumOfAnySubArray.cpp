class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, maxEndingHere = 0;
        int minSum = 0, minEndingHere = 0;
        for(int i = 0; i < nums.size(); i++){
            maxEndingHere = max(nums[i], nums[i] + maxEndingHere);
            maxSum = max(maxSum, maxEndingHere);

            minEndingHere = min(nums[i], nums[i] + minEndingHere);
            minSum = min(minSum, minEndingHere);
        }

        return max(maxSum, abs(minSum));
    }
};

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2025-02-26
