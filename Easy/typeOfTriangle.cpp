class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) 
            return "none";
        else if (nums[0] == nums[2]) 
            return "equilateral";
        else if (nums[0] == nums[1] || nums[1] == nums[2]) 
            return "isosceles";
        else 
            return "scalene";
    }
};

// https://leetcode.com/problems/type-of-triangle/?envType=daily-question&envId=2025-05-19
