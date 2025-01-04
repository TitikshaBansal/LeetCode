class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        for (int ch = 0; ch < 26; ch++) {
            if (first[ch] != -1 && last[ch] != -1 && first[ch] < last[ch]) {
                unordered_set<char> middleChars;
                for (int i = first[ch] + 1; i < last[ch]; i++) {
                    middleChars.insert(s[i]);
                }
                result += middleChars.size();
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04
