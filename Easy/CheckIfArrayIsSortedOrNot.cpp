class Solution {
public:
    bool check(vector<int>& nums) {
        int need =0;
        if (nums[nums.size() - 1] > nums[0]) need++;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) {
                need++;
            }
            if(need == 2) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
