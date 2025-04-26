class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
                minPos = maxPos = -1;
            }
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            
            if (minPos != -1 && maxPos != -1) {
                ans += max(0, min(minPos, maxPos) - leftBound);
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2025-04-26
