class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occ;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == x) occ.push_back(i);
        }
        if (occ.empty()) return vector<int>(queries.size(), -1);

        int n = occ.size();

        vector<int> ans;
        for(int q : queries){
            if(q>n) ans.push_back(-1);
            else ans.push_back(occ[q-1]);
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/
