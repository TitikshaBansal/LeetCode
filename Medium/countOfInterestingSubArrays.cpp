class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;  // Initial prefix sum is 0
        long long count = 0;
        int cur = 0;

        for (int num : nums) {
            if (num % modulo == k) cur++;
            int modCur = cur % modulo;
            int needed = (modCur - k + modulo) % modulo;
            count += prefixCount[needed];
            prefixCount[modCur]++;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-of-interesting-subarrays/?envType=daily-question&envId=2025-04-25
