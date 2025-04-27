class Solution {
public:
    bool recursion(int mask, int reminder, int n, vector<int> &nums, int k, vector<vector<int>> &dp) {
        if(mask == (1 << n) - 1) {
            if(reminder == 0) return true;
            return false;
        }
        
        if(dp[mask][reminder] != -1) {
            return dp[mask][reminder];
        } 
        
        bool res = false;
        for(int i = 0; i < n; i++) {
            if(!(1 & (mask >> i))) {
                int num = nums[i], multiplier = 1;
                while(num > 0) {
                    multiplier *= 10, num /= 10;
                }
                
                int newReminder = ((1LL * reminder * multiplier) + nums[i]) % k;                
                res |= recursion(mask | (1 << i), newReminder, n, nums, k, dp);
            }
        }
        
        return dp[mask][reminder] = res;
    }
    
    void buildArray(int pos, int mask, int reminder, int n, vector<int> &nums, int k, vector<int> &ans, vector<vector<int>> &dp) {
        if(pos == n) return;
        
        int newMask = mask, nextReminder = reminder;
        for(int i = 0; i < n; i++) {
            if(!(1 & (mask >> i))) {
                int num = nums[i], multiplier = 1;
                while(num > 0) {
                    multiplier *= 10, num /= 10;
                }
                
                int newReminder = ((1LL * reminder * multiplier) + nums[i]) % k;
                bool res = recursion(mask | (1 << i), newReminder, n, nums, k, dp);
                
                if(res && ans[pos] > nums[i]) {
                    newMask = mask | (1 << i);
                    nextReminder = newReminder;
                    
                    ans[pos] = nums[i];
                }
            }
        }
        
        buildArray(pos + 1, newMask, nextReminder, n, nums, k, ans, dp);
    }
    
    vector<int> concatenatedDivisibility(vector<int> &nums, int k) {
        int n = nums.size();
        
        vector<vector<int>> dp(1 << n, vector<int> (k, -1));
        bool exist = recursion(0, 0, n, nums, k, dp);
        if(!exist) return {};
        
        vector<int> ans(n, INT_MAX);
        buildArray(0, 0, 0, n, nums, k, ans, dp);
        
        return ans;
    }
};

// https://leetcode.com/problems/concatenated-divisibility/
