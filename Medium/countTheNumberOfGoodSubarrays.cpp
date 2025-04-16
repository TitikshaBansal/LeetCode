class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        int left = 0;
        long long totalPairs = 0, res = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            totalPairs += freq[nums[right]];
            freq[nums[right]]++;

            while (totalPairs >= k) {
                res += nums.size() - right;
                freq[nums[left]]--;
                totalPairs -= freq[nums[left]]; 
                left++;
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/count-the-number-of-good-subarrays/?envType=daily-question&envId=2025-04-16
