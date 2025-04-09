class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int num : nums){
            if (num < k) return -1;
            else if (num > k) s.insert(num);
        }
        return s.size();
    }
};

// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09
