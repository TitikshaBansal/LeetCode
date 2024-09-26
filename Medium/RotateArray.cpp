class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k>nums.size()) return;
        //while(k>nums.size()) k-= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

// https://leetcode.com/problems/rotate-array/
