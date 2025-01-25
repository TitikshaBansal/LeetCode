class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;

        for (int i = 0; i < n; ++i) {
            indexedNums.emplace_back(nums[i], i);
        }
        sort(indexedNums.begin(), indexedNums.end()); 

        vector<vector<int>> groups;
        vector<int> currentGroup = {indexedNums[0].second}; 
        
        for (int i = 1; i < n; ++i) {
            if (abs(indexedNums[i].first - indexedNums[i - 1].first) <= limit) {
                currentGroup.push_back(indexedNums[i].second);
            } else {
                groups.push_back(currentGroup); 
                currentGroup = {indexedNums[i].second}; 
            }
        }
        groups.push_back(currentGroup); 
        vector<int> result(nums); 
        for (const auto& group : groups) {
            vector<int> groupValues;
            for (int idx : group) {
                groupValues.push_back(nums[idx]);
            }
            sort(groupValues.begin(), groupValues.end()); 
            vector<int> sortedIndices = group;
            sort(sortedIndices.begin(), sortedIndices.end());
            
            for (size_t i = 0; i < groupValues.size(); ++i) {
                result[sortedIndices[i]] = groupValues[i];
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2025-01-25
