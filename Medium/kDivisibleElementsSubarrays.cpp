class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> uniqueSubarrays; 
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int divisibleCount = 0;
            vector<int> currentSubarray;
            
            for (int j = i; j < n; ++j) {
                currentSubarray.push_back(nums[j]);
                if (nums[j] % p == 0) ++divisibleCount;
                
                if (divisibleCount > k) break;
                
                uniqueSubarrays.insert(currentSubarray);
            }
        }
        return uniqueSubarrays.size();
    }
};

// https://leetcode.com/problems/k-divisible-elements-subarrays/
