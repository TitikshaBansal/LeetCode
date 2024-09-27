class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        long long sum = n*(n+1)/2;
        long long curr=0;
        for(int num : nums) curr+=num;
        return (int)sum-curr;
    }
};

// https://leetcode.com/problems/missing-number/
