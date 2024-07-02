class Solution {
private:
    vector<int> FindIntersection(vector<int> nums1, vector<int> nums2){
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> ans;
        for (int num : set1) {
            if (set2.find(num) != set2.end()) {
                ans.push_back(num);
            }
        }
        return ans;
    }
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        if(nums.size()==1) {
            sort(nums[0].begin(), nums[0].end());
            return nums[0];
        }
        vector<int> ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans= FindIntersection(ans, nums[i]);
        }
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};
