class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int nonZeroIndex = 0;
        for (int iterateIndex = 0; iterateIndex < n; iterateIndex++) {
            if (nums[iterateIndex] != 0) nums[nonZeroIndex++] = nums[iterateIndex];
        }
        while (nonZeroIndex < n) {
            nums[nonZeroIndex++] = 0;
        }

        return nums;
    }
};

// https://leetcode.com/problems/apply-operations-to-an-array/?envType=daily-question&envId=2025-03-01
