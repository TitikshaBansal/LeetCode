class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = "";
        int index = 0;       
        while (true) {
            for (auto str : strs) {
                if (index >= str.length() || str[index] != strs[0][index]) return ans;
            }
            ans.push_back(strs[0][index]);
            index++;
        }
        return ans;
    }
};
