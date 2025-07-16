class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int x : nums) {
            if (x % 2 == 0) even++;
            else odd++;
        }
        int altLen = 1;
        int lastParity = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++) {
            int p = nums[i] % 2;
            if (p != lastParity) {
                altLen++;
                lastParity = p;
            }
        }

        return max({odd, even, altLen});
    }
};

// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/?envType=daily-question&envId=2025-07-16
