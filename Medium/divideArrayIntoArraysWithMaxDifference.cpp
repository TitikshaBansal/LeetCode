class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i+=3){
            if(nums[i+2] - nums[i] <= k){
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else break;
        }
        if(ans.size() != nums.size()/3) return {};
        return ans;
    }
};

// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2025-06-18
