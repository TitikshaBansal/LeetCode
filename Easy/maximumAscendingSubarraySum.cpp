class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int curr_sum = nums[0];
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] > nums[i-1]) curr_sum += nums[i];
            else {
                sum = max(sum, curr_sum);
                curr_sum = nums[i];
            }
        }
        sum = max(sum, curr_sum);
        return sum;
    }
};

// https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04
