class Solution {
public:
    void solve(vector<int>&nums, set<vector<int>>& s, vector<int>& sub, int index){
        if(index == nums.size()){
            s.insert(sub);
            return;
        }

        solve(nums, s, sub, index+1);
        sub.push_back(nums[index]);
        solve(nums, s, sub, index+1);
        sub.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<int> sub;
        solve(nums, s, sub, 0);

        return vector<vector<int>>(s.begin(), s.end());
    }
};

// https://leetcode.com/problems/subsets-ii/
