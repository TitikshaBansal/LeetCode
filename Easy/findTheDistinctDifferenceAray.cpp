class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0), ans(n, 0);
        unordered_set<int> seenPrefix, seenSuffix;
        for (int i = 0; i < n; i++) {
            seenPrefix.insert(nums[i]);
            prefix[i] = seenPrefix.size();
        }

        for (int i = n - 1; i >= 0; i--) {
            seenSuffix.insert(nums[i]);
            suffix[i] = seenSuffix.size();
        }

        for (int i = 0; i < n; i++) {
            int suffixCount = (i + 1 < n) ? suffix[i + 1] : 0;
            ans[i] = prefix[i] - suffixCount;
        }

        return ans;
    }
};

// https://leetcode.com/problems/find-the-distinct-difference-array/
