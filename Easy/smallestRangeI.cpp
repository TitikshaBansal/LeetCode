class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int num : nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        return max(maxi-mini - (2*k), 0);
    }
};


// https://leetcode.com/problems/smallest-range-i/
