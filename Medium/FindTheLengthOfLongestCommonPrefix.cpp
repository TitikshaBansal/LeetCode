class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefixMap;
        for (auto const& num : arr1) {
            string str1 = to_string(num);
            string prefix = "";
            for (auto const& ch : str1) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }
        int maxi = 0;
        for (auto const& num : arr2) {
            string str2 = to_string(num);
            string prefix = "";
            for (auto const& ch : str2) {
                prefix += ch;
                if (prefixMap.count(prefix) > 0) {
                    maxi = max(maxi, (int)prefix.size());
                }
            }
        }
        return maxi;
    }
};

// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24
