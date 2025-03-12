class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, right = n - 1, posIndex = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                posIndex = mid;
                right = mid - 1;
            } else 
                left = mid + 1;
        }
        int posCount = n - posIndex;

        left = 0, right = n - 1;
        int negIndex = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                negIndex = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        int negCount = negIndex + 1;

        return max(posCount, negCount);
    }
};

// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=daily-question&envId=2025-03-12
