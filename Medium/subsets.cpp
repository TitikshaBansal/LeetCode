class Solution {
public:
    void solve(vector<int>&nums, vector<vector<int>>& ans, vector<int>& sub, int index){
        if(index == nums.size()){
            ans.push_back(sub);
            return;
        }

        solve(nums, ans, sub, index+1);
        sub.push_back(nums[index]);
        solve(nums, ans, sub, index+1);
        sub.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums, ans, sub, 0);

        return ans;
    }
};

// https://leetcode.com/problems/subsets/
