class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s =0;
        int maxi = 1;
        long long curr = 0;
        for(int i =0; i<nums.size(); i++){
            curr += nums[i];
            while((long long)nums[i]*(i-s +1) - curr > k){
                curr-= nums[s++];
            }
            maxi = max(maxi, i-s+1);
        }
        return maxi;
    }
};

// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
