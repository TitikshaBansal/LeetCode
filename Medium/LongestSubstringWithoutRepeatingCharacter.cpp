class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> charMap;
        int left = 0;
        int maxLength = 0; 
        for (int right = 0; right < n; ++right) {
            char currentChar = s[right];
            if (charMap.find(currentChar) != charMap.end()) left = max(left, charMap[currentChar] + 1);
            charMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
