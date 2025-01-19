class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int l = nums[0].size();
        vector<int> result;

        for (auto& query : queries) {
            int k = query[0];
            int trim = query[1];\
            vector<pair<string, int>> trimmedNums;
            for (int i = 0; i < n; i++) {
                string trimmed = nums[i].substr(l - trim); 
                trimmedNums.push_back({trimmed, i});
            }
            nth_element(trimmedNums.begin(), trimmedNums.begin() + k - 1, trimmedNums.end(), [](auto& a, auto& b) {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
            result.push_back(trimmedNums[k - 1].second);
        }

        return result;
    }
};

// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
