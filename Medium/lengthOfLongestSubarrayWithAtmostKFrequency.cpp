class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int s = 0, i = 0;
        map<int,int> m;
        int len = 0;
        for(; i<nums.size(); i++){
            if(++m[nums[i]] > k){
                len = max(len, i-s);
                while(m[nums[i]] >k) m[nums[s++]]--;
            }
        }
        len= max(len, i-s);
        return len;
    }
};

// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
