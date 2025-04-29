class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        long long count =0;
        int left = 0;
        int maxCount =0;
        for(int right =0; right<nums.size(); right++){
            if(nums[right] == maxi) maxCount++;
            while(maxCount == k){
                if(nums[left] == maxi) maxCount--;
                left++;
            }
            count+= left;
        }
        return count;
    }
};

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29
