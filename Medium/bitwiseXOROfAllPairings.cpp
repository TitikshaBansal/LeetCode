class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size(), n2 = nums2.size();
        int x1 =0, x2 =0;
        if(n2%2 != 0){
            for(int i : nums1) x1 ^= i;
        }
        if(n1%2 != 0){
            for(int i : nums2) x2 ^= i;
        }
        return x1 ^ x2;
    }
};

// https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16
