class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        
        unordered_set<int> allSet(nums.begin(), nums.end());
        int totalUnique = allSet.size();
        
        unordered_map<int, int> freq;
        int left = 0;
        int uniqueInWindow = 0;
        
        for (int right = 0; right < n; ++right) {
            if (++freq[nums[right]] == 1) uniqueInWindow++;
            
            // shrink the window from the left to maintain all unique elements
            while (uniqueInWindow == totalUnique) {
                // all subarrays starting from left to right are valid
                total += (n - right);
                
                if (--freq[nums[left]] == 0) uniqueInWindow--;
                left++;
            }
        }
        
        return total;
    }
};

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=2025-04-24
