class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        while(nums[i]!=0 && i<nums.size()-1) i++;
        for(int j=i; j<nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[i++], nums[j]);
            }
        }
    }
};

// https://leetcode.com/problems/move-zeroes/
