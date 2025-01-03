class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans =0;
        long long sum =0;
        int n = nums.size()-1;
        long long currSum=0;
        for(int num : nums) sum += num;
        for(int i=0; i< n; i++){
            currSum += nums[i];
            sum -= nums[i];
            if(currSum >= sum) ans++;
        }
        return ans;
    }
};

// https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03
