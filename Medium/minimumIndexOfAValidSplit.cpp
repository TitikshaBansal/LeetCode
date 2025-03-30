class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (int i : nums) {
            m[i]++;
        }
        int dominant = -1;
        for (auto i : m) {
            if (i.second * 2 > n) {
                dominant = i.first;
                break;
            }
        }
        if (dominant == -1) return -1;
        int leftCount = 0, rightCount = m[dominant];
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant) {
                leftCount++;
                rightCount--;
            }
            if (leftCount * 2 > i + 1 && rightCount * 2 > n - i - 1) {
                return i;
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/minimum-index-of-a-valid-split/
