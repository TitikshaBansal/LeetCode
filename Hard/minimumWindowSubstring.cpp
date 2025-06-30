class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tFreq, windowFreq;
        for (char c : t) tFreq[c]++;

        int required = tFreq.size();  // number of unique characters in t to match
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX, minStart = 0;

        while (right < s.length()) {
            char c = s[right];
            windowFreq[c]++;

            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try to contract the window
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};

// https://leetcode.com/problems/minimum-window-substring/
