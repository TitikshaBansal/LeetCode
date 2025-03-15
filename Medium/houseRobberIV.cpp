class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mini = 1; 
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while (mini < maxi) {
            int mid = (mini + maxi) / 2;
            int curr = 0;

            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) {
                    curr++;
                    i++;  
                }
            }

            if (curr >= k) maxi = mid;
            else mini = mid + 1;
        }

        return mini;
    }
};

// https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15
