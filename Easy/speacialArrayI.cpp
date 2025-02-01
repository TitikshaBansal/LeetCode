class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int comp = nums[0]%2;
        for(int i=1; i<nums.size(); i++){
            int rem = nums[i]%2;
            if(rem == comp) return false;
            comp = rem;
        }
        return true;
    }
};

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
