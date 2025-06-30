class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                ans = max(ans, count + freq[num + 1]);
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/longest-harmonious-subsequence/?envType=daily-question&envId=2025-06-30
