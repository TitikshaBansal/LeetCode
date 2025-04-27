class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count =0;
        for(int i= 2; i<nums.size(); i++){
            double sum = nums[i] + nums[i-2];
            double comp = (double)nums[i-1]/2;
            if(sum == comp) count++;
        }
        return count;
    }
};

// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27
