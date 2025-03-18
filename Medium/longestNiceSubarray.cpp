class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s =0;
        int mask = 0;
        int len = 0;
        for(int e =0; e< nums.size(); e++){
            while((mask & nums[e]) != 0) mask ^= nums[s++];
            mask |= nums[e];
            len = max(len, e-s+1);
        }
        return len;
    }
};

// https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18
