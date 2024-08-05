class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        for ( string s : arr) {
            countMap[s]++;
        }
        int distinctCount = 0;
        for (string s : arr) {
            if (countMap[s] == 1) distinctCount++;
            if (distinctCount == k) return s;
        }
        return "";
    }
};
