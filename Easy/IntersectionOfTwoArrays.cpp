class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setA(nums1.begin(), nums1.end());
        unordered_set<int> setB(nums2.begin(), nums2.end());
        vector<int> ans;

        for (const int& element : setA) {
            if (setB.find(element) != setB.end()) {
                ans.push_back(element);
            }
        }
        return ans;
    }
};
