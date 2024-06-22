class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=0, e=0;
        int count=0;
        long long  pro=1;
        while(s<nums.size() && e< nums.size()){
            pro*= nums[e];
            while(s<=e && pro>=k){
                pro /= nums[s];
                s++;
            }
            count += e-s+1;
            e++;
        }
        return count;
    }
};
