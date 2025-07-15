class Solution {
public:
    bool check(vector<int>& nums, int k, int maxSum){
        int sub = 1;
        int last = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxSum) return false;
            if(last + nums[i] > maxSum){
                sub++;
                last = nums[i];
            }
            else last += nums[i];
            if(sub > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int ans = -1;
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);

        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(nums, k, mid)){
                ans=mid;
                e = mid-1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};

// https://leetcode.com/problems/split-array-largest-sum/
