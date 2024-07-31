class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& per, vector<bool>& selected){
        if(per.size() == nums.size()) ans.push_back(per);
        for(int i=0; i<nums.size(); i++){
            if(!selected[i]){
                selected[i]= true;
                per.push_back(nums[i]);
                solve(nums, ans, per, selected);
                per.pop_back();
                selected[i]= false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per;
        vector<bool> selected(nums.size(), false);
        solve(nums, ans, per, selected);
        return ans;
    }
};
