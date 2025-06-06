class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1000000007, l=0, r= nums.size()-1;
        vector<int> pre{1};
        for(int i=0; i<= nums.size(); i++){
            pre.push_back((pre.back()<<1)%mod);
        }

        sort(nums.begin(), nums.end());

        while(l<=r){
            if(nums[l]+nums[r] > target) r--;
            else res = (res + pre[r-l++])%mod;
        }
        return res;
    }
};

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
