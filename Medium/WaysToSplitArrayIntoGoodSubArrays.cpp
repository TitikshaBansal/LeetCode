class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int mod = 1'000'000'007;
        vector<int> index;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) index.push_back(i);
        }
        if(index.size()==1) return 1;
        if(index.size()==0) return 0;
        long long ans=1;
        for(int i=1; i< index.size(); i++){
            ans = (ans * (index[i] - index[i - 1])) % mod;
        }
        return (int)ans;
    }
};
