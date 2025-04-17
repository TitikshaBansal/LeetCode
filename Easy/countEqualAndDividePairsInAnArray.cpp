class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17
