class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prepro = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prepro;
            prepro *= nums[i];
        }
        int sufpro = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= sufpro;
            sufpro *= nums[i];
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/product-of-array-except-self/
